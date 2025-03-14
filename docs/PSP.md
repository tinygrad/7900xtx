# Platform Security Processor

The PSP does bringup of the rest of the system. See `psp_cmd_submit_buf` for RPC.

```C
/* TEE Gfx Command IDs for the ring buffer interface. */
enum psp_gfx_cmd_id
{
    GFX_CMD_ID_LOAD_TA            = 0x00000001,   /* load TA */
    GFX_CMD_ID_UNLOAD_TA          = 0x00000002,   /* unload TA */
    GFX_CMD_ID_INVOKE_CMD         = 0x00000003,   /* send command to TA */
    GFX_CMD_ID_LOAD_ASD           = 0x00000004,   /* load ASD Driver */
    GFX_CMD_ID_SETUP_TMR          = 0x00000005,   /* setup TMR region */
    GFX_CMD_ID_LOAD_IP_FW         = 0x00000006,   /* load HW IP FW */
    GFX_CMD_ID_DESTROY_TMR        = 0x00000007,   /* destroy TMR region */
    GFX_CMD_ID_SAVE_RESTORE       = 0x00000008,   /* save/restore HW IP FW */
    GFX_CMD_ID_SETUP_VMR          = 0x00000009,   /* setup VMR region */
    GFX_CMD_ID_DESTROY_VMR        = 0x0000000A,   /* destroy VMR region */
    GFX_CMD_ID_PROG_REG           = 0x0000000B,   /* program regs */
    GFX_CMD_ID_GET_FW_ATTESTATION = 0x0000000F,   /* Query GPUVA of the Fw Attestation DB */
    /* IDs upto 0x1F are reserved for older programs (Raven, Vega 10/12/20) */
    GFX_CMD_ID_LOAD_TOC           = 0x00000020,   /* Load TOC and obtain TMR size */
    GFX_CMD_ID_AUTOLOAD_RLC       = 0x00000021,   /* Indicates all graphics fw loaded, start RLC autoload */
    GFX_CMD_ID_BOOT_CFG           = 0x00000022,   /* Boot Config */
    GFX_CMD_ID_SRIOV_SPATIAL_PART = 0x00000027,   /* Configure spatial partitioning mode */
};
```

## Secure Operating System

This is the main code for the PSP. It's an ARM binary, amdgpu/psp_13_0_0_sos.bin

It's loaded with `psp_v13_0_bootloader_load_sos`. The bootloader commands are here.

```C
enum psp_bootloader_cmd {
	PSP_BL__LOAD_SYSDRV		= 0x10000,
	PSP_BL__LOAD_SOSDRV		= 0x20000,
	PSP_BL__LOAD_KEY_DATABASE	= 0x80000,
	PSP_BL__LOAD_SOCDRV             = 0xB0000,
	PSP_BL__LOAD_DBGDRV             = 0xC0000,
	PSP_BL__LOAD_INTFDRV		= 0xD0000,
	PSP_BL__LOAD_RASDRV		    = 0xE0000,
	PSP_BL__DRAM_LONG_TRAIN		= 0x100000,
	PSP_BL__DRAM_SHORT_TRAIN	= 0x200000,
	PSP_BL__LOAD_TOS_SPL_TABLE	= 0x10000000,
};
```

TODO: how do we dump the bootloader and what arch is it?

The SOS is handed in from memory allocated with `amdgpu_bo_create_kernel` in `AMDGPU_GEM_DOMAIN_GTT`

The bootloader appears to copy it in to the GPU, if you change it early it crashes.

- regMP0_SMN_C2PMSG_81 = sol_reg (is sos alive, this is polled after load)
- regMP0_SMN_C2PMSG_36 = address
- regMP0_SMN_C2PMSG_35 = psp_bootloader_cmd

## Trusted Application

The "applications" that run in the PSP

- HDCP = High-bandwidth Digital Content Protection
- DTM = Dynamic Thermal Management?
- RAS = Reliability, Availability, and Serviceability?

```
kafka@q:/lib/firmware/amdgpu$ strings psp_13_0_0_ta.bin | grep Application
AMD HDCP Application
AMD DTM Application
AMD RAS Application
```

## Inside the SOS

The `psp_13_0_0_sos.bin` file contains several parts.

```
am.PSP_FW_TYPE_PSP_SYS_DRV, 0x100-0x26890, 0x26790
am.PSP_FW_TYPE_PSP_SOS, 0x26890-0x3ec10, 0x18380
4, 0x3ec10-0x3f510, 0x900
am.PSP_FW_TYPE_PSP_KDB, 0x3f510-0x40c10, 0x1700
5, 0x40c10-0x40eb0, 0x2a0
6, 0x40eb0-0x41810, 0x960
```

or for psp_13_0_7_sos.bin with hash 9db47a0c224501f74a9dc28818f8b0fb230aec48

```
am.PSP_FW_TYPE_PSP_SYS_DRV, 0x100-0x22890, 0x22790
am.PSP_FW_TYPE_PSP_SOS, 0x22890-0x3ac00, 0x18370
4, 0x3ac00-0x3b500, 0x900
am.PSP_FW_TYPE_PSP_KDB, 0x3b500-0x3c810, 0x1310
5, 0x3c810-0x3cab0, 0x2a0
```

The SOS parses the GFX commands, used to load second stage firmware

```
GFX_CMD_ID_LOAD_TA = 1
GFX_CMD_ID_UNLOAD_TA = 2
GFX_CMD_ID_INVOKE_CMD = 3
GFX_CMD_ID_LOAD_ASD = 4
GFX_CMD_ID_SETUP_TMR = 5
GFX_CMD_ID_LOAD_IP_FW = 6
GFX_CMD_ID_DESTROY_TMR = 7
GFX_CMD_ID_SAVE_RESTORE = 8
GFX_CMD_ID_SETUP_VMR = 9
GFX_CMD_ID_DESTROY_VMR = 10
GFX_CMD_ID_PROG_REG = 11
GFX_CMD_ID_GET_FW_ATTESTATION = 15
GFX_CMD_ID_LOAD_TOC = 32
GFX_CMD_ID_AUTOLOAD_RLC = 33
GFX_CMD_ID_BOOT_CFG = 34
GFX_CMD_ID_SRIOV_SPATIAL_PART = 39
```

The SOS itself is pretty much just a stub, making "syscalls" with interrupt 0xf2 into the SYS_DRV. From the SOS firmware @ 0x1466c

```
LOAD_IP_FW = 6 -> 0x1007
DESTROY_TMR = 7 -> 0x101e
SAVE_RESTORE = 8 -> 0x1024
SETUP_VMR = 9 -> 0x1045
DESTROY_VMR = 10 -> 0x1046
```

Then there's a syscall parser @ 0x1aa10 in the SYS_DRV




