## FW

Load with type: AMDGPU_FW_LOAD_PSP

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
`regGCVM_CONTEXT0_PAGE_TABLE_BASE_ADDR_LO32` = PT physical memory
`regGCVM_CONTEXT0_PAGE_TABLE_START_ADDR_LO32` = PT virt start?
`regGCVM_CONTEXT0_CNTL` = vm controls
    * Can enable interrupts...
    * The driver sets `ENABLE_CONTEXT=1, PAGE_TABLE_DEPTH=0, RETRY_PERMISSION_OR_INVALID_PAGE_FAULT=0`
    * The driver sets 512mb of pagetables.



