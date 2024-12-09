### IH

The driver setups ih, ih1 and soft_ih. Driver can enable interrupts for some events (like ThermalAlert).

### PSP

Loads KDB, SYS_DRV, sOS using bootloader. Sets up a ring to talk with sOS (ring entry: `psp_gfx_rb_frame`, commands: `psp_gfx_cmd_resp`).
TMR is allocated using ring. FW blobs is loaded into TMR.

```
[ 2222.309993] amdgpu 0000:83:00.0: amdgpu: Loading firmware RS64_PFP
[ 2222.313750] amdgpu 0000:83:00.0: amdgpu: Loading firmware RS64_ME
[ 2222.318316] amdgpu 0000:83:00.0: amdgpu: Loading firmware RS64_MEC
[ 2222.323748] amdgpu 0000:83:00.0: amdgpu: Loading firmware RS64_PFP_P0_STACK
[ 2222.326747] amdgpu 0000:83:00.0: amdgpu: Loading firmware RS64_PFP_P1_STACK
[ 2222.329750] amdgpu 0000:83:00.0: amdgpu: Loading firmware RS64_ME_P0_STACK
[ 2222.332748] amdgpu 0000:83:00.0: amdgpu: Loading firmware RS64_ME_P1_STACK
[ 2222.335751] amdgpu 0000:83:00.0: amdgpu: Loading firmware RS64_MEC_P0_STACK
[ 2222.338747] amdgpu 0000:83:00.0: amdgpu: Loading firmware RS64_MEC_P1_STACK
[ 2222.341749] amdgpu 0000:83:00.0: amdgpu: Loading firmware RS64_MEC_P2_STACK
[ 2222.344748] amdgpu 0000:83:00.0: amdgpu: Loading firmware RS64_MEC_P3_STACK
[ 2222.347752] amdgpu 0000:83:00.0: amdgpu: Loading firmware CP_MES
[ 2222.351857] amdgpu 0000:83:00.0: amdgpu: Loading firmware CP_MES_DATA
[ 2222.355429] amdgpu 0000:83:00.0: amdgpu: Loading firmware CP_MES_KIQ
[ 2222.359102] amdgpu 0000:83:00.0: amdgpu: Loading firmware CP_MES_KIQ_DATA
[ 2222.362858] amdgpu 0000:83:00.0: amdgpu: Loading firmware IMU_I
[ 2222.366751] amdgpu 0000:83:00.0: amdgpu: Loading firmware IMU_D
[ 2222.370211] amdgpu 0000:83:00.0: amdgpu: Loading firmware RLC_RESTORE_LIST_GPM_MEM
[ 2222.373211] amdgpu 0000:83:00.0: amdgpu: Loading firmware RLC_RESTORE_LIST_SRM_MEM
[ 2222.376534] amdgpu 0000:83:00.0: amdgpu: Loading firmware RLC_IRAM
[ 2222.380101] amdgpu 0000:83:00.0: amdgpu: Loading firmware RLC_DRAM
[ 2222.383316] amdgpu 0000:83:00.0: amdgpu: Loading firmware RLC_P
[ 2222.386316] amdgpu 0000:83:00.0: amdgpu: Loading firmware RLC_V
[ 2222.389428] amdgpu 0000:83:00.0: amdgpu: Loading firmware RLC_G
```

## VM

Page table hierarchy: PDB2->PDB1->PDB0->PTB

```
/*
 * PTE format:
 * 63:59 reserved
 * 58:57 reserved
 * 56 F
 * 55 L
 * 54 reserved
 * 53:52 SW
 * 51 T
 * 50:48 mtype
 * 47:12 4k physical page base address
 * 11:7 fragment
 * 6 write
 * 5 read
 * 4 exe
 * 3 Z
 * 2 snooped
 * 1 system
 * 0 valid
 *
 * PDE format:
 * 63:59 block fragment size
 * 58:55 reserved
 * 54 P
 * 53:48 reserved
 * 47:6 physical base address of PD or PTE
 * 5:3 reserved
 * 2 C
 * 1 system
 * 0 valid
 */
```

512 entries for non-ptbs. PTBs can be bigger.

Most are obvious, these are:
AMDGPU_PTE_SNOOPED - snooper? cache coherancy thing? (used with system)
AMDGPU_PTE_SYSTEM - system mem
AMDGPU_PDE_PTE - Handle leaf PDEs as PTEs. (true if huge page) like a terminating entry.
AMDGPU_PDE_BFS - BFS=Block Fragment Size??? (0x9 for gfx11 pdb1)

Setup vmid0. Setting this regs:
`regGCVM_CONTEXT0_PAGE_TABLE_BASE_ADDR_LO32` = PT physical memory.
`regGCVM_CONTEXT0_PAGE_TABLE_START_ADDR_LO32` = Start vaddr that covered by the page table.
`regGCVM_CONTEXT0_CNTL` = vm controls
    * Can enable interrupts...
    * The driver sets `ENABLE_CONTEXT=1, PAGE_TABLE_DEPTH=0, RETRY_PERMISSION_OR_INVALID_PAGE_FAULT=0`
    * The driver sets 512mb covered with pagetables.

2 page tables to setup (?):
* MMHUB
* GFXHUB

The driver sets:
This looks to be only gart? Only system pages to kernel memory?
`regGCVM_CONTEXT0_CNTL` = 0x1fffe01 (PAGE_TABLE_DEPTH=0, INTERRUPTS ON FAULT, ENABLE_CONTEXT=1)
`regGCVM_CONTEXT0_PAGE_TABLE_BASE_ADDR` = 0x5feb00001
`regGCVM_CONTEXT0_PAGE_TABLE_START_ADDR` = 0x7fff00000
`regGCVM_CONTEXT0_PAGE_TABLE_END_ADDR` = 0x7fff1ffff

vmid8:
`regGCVM_CONTEXT8_CNTL` = 0x1fffe07 (PAGE_TABLE_DEPTH=3, INTERRUPTS ON FAULT, ENABLE_CONTEXT=1)
`regGCVM_CONTEXT8_PAGE_TABLE_BASE_ADDR` = 0x5feaf3001
`regGCVM_CONTEXT8_PAGE_TABLE_START_ADDR` = 0x0
`regGCVM_CONTEXT8_PAGE_TABLE_END_ADDR` = 0xfffffffff

Saw some `regGCUTC_GPUVA_VMID_TRANSLATION_ASSIST_REQUEST_*`. Wish they could debug VM (but I could't make them work)...

### MMHUB
Serving clients:
```
[0][0] = "VMC",
[4][0] = "DCEDMC",
[5][0] = "DCEVGA",
[6][0] = "MP0",
[7][0] = "MP1",
[8][0] = "MPIO",
[16][0] = "HDP",
[17][0] = "LSDMA",
[18][0] = "JPEG",
[19][0] = "VCNU0",
[21][0] = "VSCH",
[22][0] = "VCNU1",
[23][0] = "VCN1",
[32+20][0] = "VCN0",
[2][1] = "DBGUNBIO",
[3][1] = "DCEDWB",
[4][1] = "DCEDMC",
[5][1] = "DCEVGA",
[6][1] = "MP0",
[7][1] = "MP1",
[8][1] = "MPIO",
[10][1] = "DBGU0",
[11][1] = "DBGU1",
[12][1] = "DBGU2",
[13][1] = "DBGU3",
[14][1] = "XDP",
[15][1] = "OSSSYS",
[16][1] = "HDP",
[17][1] = "LSDMA",
[18][1] = "JPEG",
[19][1] = "VCNU0",
[20][1] = "VCN0",
[21][1] = "VSCH",
[22][1] = "VCNU1",
[23][1] = "VCN1",
```

Collect faults status: `MMVM_L2_PROTECTION_FAULT_STATUS`

### GFXHUB
Serving clients:
```
"CB/DB",
"Reserved",
"GE1",
"GE2",
"CPF",
"CPC",
"CPG",
"RLC",
"TCP",
"SQC (inst)",
"SQC (data)",
"SQG",
"Reserved",
"SDMA0",
"SDMA1",
"GCR",
"SDMA2",
"SDMA3",
```

Collect faults status: `GCVM_L2_PROTECTION_FAULT_STATUS`


## GFX

LDS = private
Scratch = shared
CSB = clear state block

```c
/*
* Configure apertures:
* LDS:         0x60000000'00000000 - 0x60000001'00000000 (4GB)
* Scratch:     0x60000001'00000000 - 0x60000002'00000000 (4GB)
* GPUVM:       0x60010000'00000000 - 0x60020000'00000000 (1TB)
*/
sh_mem_bases = (LDS_APP_BASE << SH_MEM_BASES__SHARED_BASE__SHIFT) |
        SCRATCH_APP_BASE;
```

## Doorbells
pci bar 2.

set `regCP_RB_DOORBELL_RANGE_LOWER` (graphics range), `regCP_MEC_DOORBELL_RANGE_LOWER` (compute range)

```c
enum AMDGPU_NAVI10_DOORBELL_ASSIGNMENT {

	/* Compute + GFX: 0~255 */
	AMDGPU_NAVI10_DOORBELL_KIQ			= 0x000,
	AMDGPU_NAVI10_DOORBELL_HIQ			= 0x001,
	AMDGPU_NAVI10_DOORBELL_DIQ			= 0x002,
	AMDGPU_NAVI10_DOORBELL_MEC_RING0		= 0x003,
	AMDGPU_NAVI10_DOORBELL_MEC_RING1		= 0x004,
	AMDGPU_NAVI10_DOORBELL_MEC_RING2		= 0x005,
	AMDGPU_NAVI10_DOORBELL_MEC_RING3		= 0x006,
	AMDGPU_NAVI10_DOORBELL_MEC_RING4		= 0x007,
	AMDGPU_NAVI10_DOORBELL_MEC_RING5		= 0x008,
	AMDGPU_NAVI10_DOORBELL_MEC_RING6		= 0x009,
	AMDGPU_NAVI10_DOORBELL_MEC_RING7		= 0x00A,
	AMDGPU_NAVI10_DOORBELL_MES_RING0	        = 0x00B,
	AMDGPU_NAVI10_DOORBELL_MES_RING1		= 0x00C,
	AMDGPU_NAVI10_DOORBELL_USERQUEUE_START		= 0x00D,
	AMDGPU_NAVI10_DOORBELL_USERQUEUE_END		= 0x08A,
	AMDGPU_NAVI10_DOORBELL_GFX_RING0		= 0x08B,
	AMDGPU_NAVI10_DOORBELL_GFX_RING1		= 0x08C,
	AMDGPU_NAVI10_DOORBELL_GFX_USERQUEUE_START	= 0x08D,
	AMDGPU_NAVI10_DOORBELL_GFX_USERQUEUE_END	= 0x0FF,

	/* SDMA:256~335*/
	AMDGPU_NAVI10_DOORBELL_sDMA_ENGINE0		= 0x100,
	AMDGPU_NAVI10_DOORBELL_sDMA_ENGINE1		= 0x10A,
	AMDGPU_NAVI10_DOORBELL_sDMA_ENGINE2		= 0x114,
	AMDGPU_NAVI10_DOORBELL_sDMA_ENGINE3		= 0x11E,
	/* IH: 376~391 */
	AMDGPU_NAVI10_DOORBELL_IH			= 0x178,
	/* MMSCH: 392~407
	 * overlap the doorbell assignment with VCN as they are  mutually exclusive
	 * VCE engine's doorbell is 32 bit and two VCE ring share one QWORD
	 */
	AMDGPU_NAVI10_DOORBELL64_VCN0_1			= 0x188, /* lower 32 bits for VNC0 and upper 32 bits for VNC1 */
	AMDGPU_NAVI10_DOORBELL64_VCN2_3			= 0x189,
	AMDGPU_NAVI10_DOORBELL64_VCN4_5			= 0x18A,
	AMDGPU_NAVI10_DOORBELL64_VCN6_7			= 0x18B,

	AMDGPU_NAVI10_DOORBELL64_VCN8_9			= 0x18C,
	AMDGPU_NAVI10_DOORBELL64_VCNa_b			= 0x18D,
	AMDGPU_NAVI10_DOORBELL64_VCNc_d			= 0x18E,
	AMDGPU_NAVI10_DOORBELL64_VCNe_f			= 0x18F,

	AMDGPU_NAVI10_DOORBELL64_VPE			= 0x190,

	AMDGPU_NAVI10_DOORBELL64_FIRST_NON_CP		= AMDGPU_NAVI10_DOORBELL_sDMA_ENGINE0,
	AMDGPU_NAVI10_DOORBELL64_LAST_NON_CP		= AMDGPU_NAVI10_DOORBELL64_VPE,

	AMDGPU_NAVI10_DOORBELL_MAX_ASSIGNMENT		= AMDGPU_NAVI10_DOORBELL64_VPE,
	AMDGPU_NAVI10_DOORBELL_INVALID			= 0xFFFF
};
```

That's how they call in kernel: `WDOORBELL64(ring->doorbell_index, ring->wptr);`. That's just `atomic64_set((atomic64_t *)(adev->doorbell.cpu_addr + index), v);`. `doorbell.cpu_addr` is likely to be a MMIO to bar2. Using AMDGPU_NAVI10_DOORBELL_ASSIGNMENT every doorbell index is bitshifted `<< 1` when passed to the gpu. So, to write doorbell on cpu`(uint64_t*)(bar2)[index/2] = val;`


## MEC

mec0 is me1 and so on (`ring->me = mec + 1;`).

For gfx110000
```
adev->gfx.mec.num_mec = 2;
adev->gfx.mec.num_pipe_per_mec = 4;
adev->gfx.mec.num_queue_per_pipe = 4;
```

## Blocks to init

[  399.579973] [drm] add ip block number 0 <soc21_common>
[  399.579978] [drm] add ip block number 1 <gmc_v11_0>
[  399.579981] [drm] add ip block number 2 <ih_v6_0>
[  399.579984] [drm] add ip block number 3 <psp>
[  399.579987] [drm] add ip block number 4 <smu>
[  399.579997] [drm] add ip block number 5 <gfx_v11_0>
[  399.579999] [drm] add ip block number 6 <sdma_v6_0>
[  399.580002] [drm] add ip block number 7 <mes_v11_0>

## MES

MES1 is MES KIQ, runs on me=3, ring=1. This is the first queue to run on gfx. Use it to add MES queue and use MES queue to add other queues.
Can pybass MES and map directly into queues (sched_policy=2 (non-HWS))
