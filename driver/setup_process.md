## FW

Load with type: AMDGPU_FW_LOAD_PSP

### PSP
First thing that loads is PSP. 7900xtx uses `psp13_0_0`. Loads `sOS`, `TA`. Both sos and ta contains several fw blobs.
Can send requests to sOS with ring (ring entry: `psp_gfx_rb_frame`, commands: `psp_gfx_cmd_resp`).

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
