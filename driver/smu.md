[2445476.090869] amdgpu: Unknown symbol amddrm_gem_ttm_vmap (err -2)
[2445476.094767] amdgpu: Unknown symbol amddrm_gem_ttm_vunmap (err -2)
[2445476.098126] amdgpu: Unknown symbol amddrm_gem_ttm_mmap (err -2)
[2445477.117148] workqueue: vmstat_update hogged CPU for >10000us 4 times, consider switching to WQ_UNBOUND
[2445477.118787] workqueue: vmstat_update hogged CPU for >10000us 8 times, consider switching to WQ_UNBOUND
[2445479.264543] [drm] amdgpu kernel modesetting enabled.
[2445479.264549] [drm] amdgpu version: 6.8.5
[2445479.264552] [drm] OS DRM version: 6.8.0
[2445479.264920] amdgpu: Virtual CRAT table created for CPU
[2445479.264946] amdgpu: Topology: Add CPU node
[2445479.271841] [drm] initializing kernel modesetting (IP DISCOVERY 0x1002:0x744C 0x1EAE:0x7901 0xC8).
[2445479.271866] [drm] register mmio base: 0xC5500000
[2445479.271868] [drm] register mmio size: 1048576
[2445480.399852] [drm] add ip block number 0 <soc21_common>
[2445480.399861] [drm] add ip block number 1 <gmc_v11_0>
[2445480.399868] [drm] add ip block number 2 <ih_v6_0>
[2445480.399873] [drm] add ip block number 3 <psp>
[2445480.399878] [drm] add ip block number 4 <smu>
[2445480.399884] [drm] add ip block number 5 <gfx_v11_0>
[2445480.399889] [drm] add ip block number 6 <sdma_v6_0>
[2445480.399895] [drm] add ip block number 7 <mes_v11_0>
[2445480.399950] amdgpu 0000:c3:00.0: amdgpu: Fetched VBIOS from VFCT
[2445480.399959] amdgpu: ATOM BIOS: 113-31XFSHBS1-L02
[2445480.402254] amdgpu 0000:c3:00.0: amdgpu: CP RS64 enable
[2445480.405491] amdgpu 0000:c3:00.0: amdgpu: Trusted Memory Zone (TMZ) feature not supported
[2445480.405513] amdgpu 0000:c3:00.0: amdgpu: MODE1 reset
[2445480.405521] amdgpu 0000:c3:00.0: amdgpu: GPU mode1 reset
[2445480.405631] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetSmuVersion(1) with param 0x00000000
[2445480.405659] amdgpu 0000:c3:00.0: amdgpu: GPU smu mode1 reset
[2445480.405668] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message Mode1Reset(170) with param 0x00000000
[2445480.914760] amdgpu 0000:c3:00.0: amdgpu: MEM ECC is not presented.
[2445480.914771] amdgpu 0000:c3:00.0: amdgpu: SRAM ECC is not presented.
[2445480.914795] [drm] vm size is 262144 GB, 4 levels, block size is 9-bit, fragment size is 9-bit
[2445480.914816] amdgpu 0000:c3:00.0: amdgpu: VRAM: 24560M 0x0000008000000000 - 0x00000085FEFFFFFF (24560M used)
[2445480.914825] amdgpu 0000:c3:00.0: amdgpu: GART: 512M 0x00007FFF00000000 - 0x00007FFF1FFFFFFF
[2445480.914857] [drm] Detected VRAM RAM=24560M, BAR=32768M
[2445480.914863] [drm] RAM width 384bits GDDR6
[2445480.915261] [drm] amdgpu: 24560M of VRAM memory ready
[2445480.915268] [drm] amdgpu: 64330M of GTT memory ready.
[2445480.915328] [drm] GART: num cpu pages 131072, num gpu pages 131072
[2445480.915367] amdgpu 0000:c3:00.0: amdgpu: MMHUB: Enable GART
[2445480.915383] amdgpu 0000:c3:00.0: amdgpu: MMMC_VM_MX_L1_TLB_CNTL: 0x00001859
[2445480.915391] amdgpu 0000:c3:00.0: amdgpu: MMVM_L2_CNTL: 0x00080E01
[2445480.915399] amdgpu 0000:c3:00.0: amdgpu: MMVM_L2_CNTL2: 0x00000003
[2445480.915405] amdgpu 0000:c3:00.0: amdgpu: MMVM_L2_CNTL3: 0x80130009
[2445480.915411] amdgpu 0000:c3:00.0: amdgpu: MMVM_L2_CNTL4: 0x00000001
[2445480.915417] amdgpu 0000:c3:00.0: amdgpu: MMVM_L2_CNTL5: 0x00003FE0
[2445480.915445] [drm] PCIE GART of 512M enabled (table at 0x00000085FEB00000).
[2445480.919193] amdgpu 0000:c3:00.0: amdgpu: PSP is starting...
[2445480.919205] amdgpu 0000:c3:00.0: amdgpu: psp_v13_0_bootloader_load_component 524288
[2445480.920023] amdgpu 0000:c3:00.0: amdgpu: psp_v13_0_bootloader_load_component 268435456
[2445480.920142] amdgpu 0000:c3:00.0: amdgpu: psp_v13_0_bootloader_load_component 65536
[2445480.990157] amdgpu 0000:c3:00.0: amdgpu: reserve 0x1300000 from 0x85fc000000 for PSP TMR
[2445481.115935] amdgpu 0000:c3:00.0: amdgpu: RAP: optional rap ta ucode is not available
[2445481.115943] amdgpu 0000:c3:00.0: amdgpu: SECUREDISPLAY: securedisplay ta ucode is not available
[2445481.115949] amdgpu 0000:c3:00.0: amdgpu: SMU is initializing...
[2445481.115957] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetDriverIfVersion(2) with param 0x00000000
[2445481.116026] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetSmuVersion(1) with param 0x00000000
[2445481.116046] amdgpu 0000:c3:00.0: amdgpu: smu driver if version = 0x0000003d, smu fw if version = 0x00000040, smu fw program = 0, smu fw version = 0x004e7e00 (78.126.0)
[2445481.116055] amdgpu 0000:c3:00.0: amdgpu: SMU driver if version not matched
[2445481.116061] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message SetDriverDramAddrHigh(16) with param 0x00000085
[2445481.116080] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message SetDriverDramAddrLow(17) with param 0xFEAF8000
[2445481.116099] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message SetToolsDramAddrHigh(18) with param 0x00000085
[2445481.116119] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message SetToolsDramAddrLow(19) with param 0xFEAC0000
[2445481.116139] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message TransferTableSmu2Dram(20) with param 0x00000001
[2445481.119640] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message RunDcBtc(97) with param 0x00000000
[2445481.119663] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message EnableAllSmuFeatures(5) with param 0x00000000
[2445481.254170] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.254191] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.254208] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.254225] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.254242] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.254319] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.254339] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message PowerUpVcn(87) with param 0x00000000
[2445481.255331] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message PowerUpVcn(87) with param 0x00010000
[2445481.256592] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message PowerUpJpeg(89) with param 0x00000000
[2445481.257186] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.257205] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.257223] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.257240] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.257338] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetDpmFreqByIndex(38) with param 0x000100FF
[2445481.257358] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.257374] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.257391] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetDpmFreqByIndex(38) with param 0x000100FF
[2445481.257410] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.257427] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.257443] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetDpmFreqByIndex(38) with param 0x00010000
[2445481.257462] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.257479] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.257496] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetDpmFreqByIndex(38) with param 0x00010001
[2445481.257837] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.257864] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.257884] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.257903] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.257920] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetDpmFreqByIndex(38) with param 0x000000FF
[2445481.258770] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.258791] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.258808] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetDpmFreqByIndex(38) with param 0x000000FF
[2445481.258827] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.258846] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.258863] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetDpmFreqByIndex(38) with param 0x00000000
[2445481.258883] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.258899] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.258916] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetDpmFreqByIndex(38) with param 0x00000001
[2445481.258935] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.258954] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.258971] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.258987] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.259093] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetDpmFreqByIndex(38) with param 0x000200FF
[2445481.259114] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.259131] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.259148] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetDpmFreqByIndex(38) with param 0x000200FF
[2445481.259166] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.259183] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.259200] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetDpmFreqByIndex(38) with param 0x00020000
[2445481.259219] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.259235] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.259333] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetDpmFreqByIndex(38) with param 0x00020001
[2445481.259354] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.259373] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.259390] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetDpmFreqByIndex(38) with param 0x00020002
[2445481.259409] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.259425] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.259442] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetDpmFreqByIndex(38) with param 0x00020003
[2445481.259461] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.259478] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.259494] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.259833] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.259854] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetDpmFreqByIndex(38) with param 0x000300FF
[2445481.259873] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.259890] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.259907] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetDpmFreqByIndex(38) with param 0x000300FF
[2445481.259926] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.259943] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.259960] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetDpmFreqByIndex(38) with param 0x00030000
[2445481.259979] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.259996] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.260447] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetDpmFreqByIndex(38) with param 0x00030001
[2445481.260469] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.260486] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.260594] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetDpmFreqByIndex(38) with param 0x00030002
[2445481.260615] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.260633] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.260651] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetDpmFreqByIndex(38) with param 0x00030003
[2445481.260671] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.260688] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.260706] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetDpmFreqByIndex(38) with param 0x00030004
[2445481.260727] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.260744] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.260840] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetDpmFreqByIndex(38) with param 0x00030005
[2445481.260861] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.260879] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.260897] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetDpmFreqByIndex(38) with param 0x00030006
[2445481.260916] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.260933] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.260950] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetDpmFreqByIndex(38) with param 0x00030007
[2445481.260969] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.260986] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.261417] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.261443] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.261463] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetDpmFreqByIndex(38) with param 0x000500FF
[2445481.262090] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.262110] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.262127] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetDpmFreqByIndex(38) with param 0x000500FF
[2445481.262146] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.262163] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.262180] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetDpmFreqByIndex(38) with param 0x00050000
[2445481.262200] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.262216] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.262233] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetDpmFreqByIndex(38) with param 0x00050001
[2445481.262351] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.262370] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.262387] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.262403] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.262420] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetDpmFreqByIndex(38) with param 0x000400FF
[2445481.262439] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.262456] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.262473] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetDpmFreqByIndex(38) with param 0x000400FF
[2445481.262492] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.262590] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.262609] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetDpmFreqByIndex(38) with param 0x00040000
[2445481.262629] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.262647] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.262665] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetDpmFreqByIndex(38) with param 0x00040001
[2445481.262685] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.262702] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.262721] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetDpmFreqByIndex(38) with param 0x000B00FF
[2445481.262741] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetDpmFreqByIndex(38) with param 0x000B00FF
[2445481.263179] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetDpmFreqByIndex(38) with param 0x000B0000
[2445481.263201] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetDpmFreqByIndex(38) with param 0x000B0001
[2445481.263221] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message PowerDownJpeg(90) with param 0x00000000
[2445481.263381] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message PowerDownVcn(88) with param 0x00000000
[2445481.263930] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message PowerDownVcn(88) with param 0x00010000
[2445481.264232] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message OverridePcieParameters(46) with param 0x00000001
[2445481.264482] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message OverridePcieParameters(46) with param 0x00010103
[2445481.266711] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message OverridePcieParameters(46) with param 0x00020306
[2445481.268870] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.268890] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.268907] amdgpu 0000:c3:00.0: amdgpu: SMU is initialized successfully!
[2445481.400982] amdgpu: HMM registered 24560MB device memory
[2445481.403432] kfd kfd: amdgpu: Allocated 3969056 bytes on gart
[2445481.403464] kfd kfd: amdgpu: Total number of KFD nodes to be created: 1
[2445481.403559] amdgpu: Virtual CRAT table created for GPU
[2445481.404054] amdgpu: Topology: Add dGPU node [0x744c:0x1002]
[2445481.404058] kfd kfd: amdgpu: added device 1002:744c
[2445481.404078] amdgpu 0000:c3:00.0: amdgpu: SE 6, SH per SE 2, CU per SH 8, active_cu_number 96
[2445481.404086] amdgpu 0000:c3:00.0: amdgpu: ring gfx_0.0.0 uses VM inv eng 0 on hub 0
[2445481.404090] amdgpu 0000:c3:00.0: amdgpu: ring comp_1.0.0 uses VM inv eng 1 on hub 0
[2445481.404093] amdgpu 0000:c3:00.0: amdgpu: ring comp_1.1.0 uses VM inv eng 4 on hub 0
[2445481.404096] amdgpu 0000:c3:00.0: amdgpu: ring comp_1.2.0 uses VM inv eng 6 on hub 0
[2445481.404100] amdgpu 0000:c3:00.0: amdgpu: ring comp_1.3.0 uses VM inv eng 7 on hub 0
[2445481.404103] amdgpu 0000:c3:00.0: amdgpu: ring comp_1.0.1 uses VM inv eng 8 on hub 0
[2445481.404106] amdgpu 0000:c3:00.0: amdgpu: ring comp_1.1.1 uses VM inv eng 9 on hub 0
[2445481.404108] amdgpu 0000:c3:00.0: amdgpu: ring comp_1.2.1 uses VM inv eng 10 on hub 0
[2445481.404112] amdgpu 0000:c3:00.0: amdgpu: ring comp_1.3.1 uses VM inv eng 11 on hub 0
[2445481.404115] amdgpu 0000:c3:00.0: amdgpu: ring sdma0 uses VM inv eng 12 on hub 0
[2445481.404118] amdgpu 0000:c3:00.0: amdgpu: ring sdma1 uses VM inv eng 13 on hub 0
[2445481.404121] amdgpu 0000:c3:00.0: amdgpu: ring mes_kiq_3.1.0 uses VM inv eng 14 on hub 0
[2445481.404346] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message TransferTableSmu2Dram(20) with param 0x00000008
[2445481.404934] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.404955] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.404971] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetPptLimit(77) with param 0x00000000
[2445481.404988] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message TransferTableSmu2Dram(20) with param 0x00000005
[2445481.405789] [drm] ring gfx_32768.1.1 was added
[2445481.406101] [drm] ring compute_32768.2.2 was added
[2445481.406373] [drm] ring sdma_32768.3.3 was added
[2445481.406474] [drm] ring gfx_32768.1.1 ib test pass
[2445481.406575] [drm] ring compute_32768.2.2 ib test pass
[2445481.406621] [drm] ring sdma_32768.3.3 ib test pass
[2445481.407732] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message TransferTableSmu2Dram(20) with param 0x00000005
[2445481.408782] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.409227] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.409246] amdgpu 0000:c3:00.0: amdgpu: Using BACO for runtime pm
[2445481.409436] [drm] Initialized amdgpu 3.58.0 20150101 for 0000:c3:00.0 on minor 1
[2445481.410009] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesHigh(13) with param 0x00000000
[2445481.410158] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message GetEnabledSmuFeaturesLow(12) with param 0x00000000
[2445481.433030] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message TransferTableSmu2Dram(20) with param 0x00000005
[2445481.483029] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message TransferTableSmu2Dram(20) with param 0x00000005
[2445481.514607] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message AllowGfxOff(75) with param 0x00000000
[2445481.533085] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message TransferTableSmu2Dram(20) with param 0x00000005
[2445481.583142] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message TransferTableSmu2Dram(20) with param 0x00000005
[2445481.633204] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message TransferTableSmu2Dram(20) with param 0x00000005
[2445481.683271] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message TransferTableSmu2Dram(20) with param 0x00000005
[2445481.733401] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message TransferTableSmu2Dram(20) with param 0x00000005
[2445481.783444] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message TransferTableSmu2Dram(20) with param 0x00000005
[2445481.833504] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message TransferTableSmu2Dram(20) with param 0x00000005
[2445481.883569] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message TransferTableSmu2Dram(20) with param 0x00000005
[2445481.933879] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message TransferTableSmu2Dram(20) with param 0x00000005
[2445481.983701] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message TransferTableSmu2Dram(20) with param 0x00000005
[2445482.033765] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message TransferTableSmu2Dram(20) with param 0x00000005
[2445482.083833] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message TransferTableSmu2Dram(20) with param 0x00000005
[2445482.133897] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message TransferTableSmu2Dram(20) with param 0x00000005
[2445482.183965] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message TransferTableSmu2Dram(20) with param 0x00000005
[2445482.234029] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message TransferTableSmu2Dram(20) with param 0x00000005
[2445482.284097] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message TransferTableSmu2Dram(20) with param 0x00000005
[2445482.334160] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message TransferTableSmu2Dram(20) with param 0x00000005
[2445482.384228] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message TransferTableSmu2Dram(20) with param 0x00000005
[2445482.434293] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message TransferTableSmu2Dram(20) with param 0x00000005
[2445482.484362] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message TransferTableSmu2Dram(20) with param 0x00000005
[2445482.534425] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message TransferTableSmu2Dram(20) with param 0x00000005
[2445482.584491] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message TransferTableSmu2Dram(20) with param 0x00000005
[2445482.634555] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message TransferTableSmu2Dram(20) with param 0x00000005
[2445482.684637] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message TransferTableSmu2Dram(20) with param 0x00000005
[2445482.734686] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message TransferTableSmu2Dram(20) with param 0x00000005
[2445482.784755] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message TransferTableSmu2Dram(20) with param 0x00000005
[2445482.834822] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message TransferTableSmu2Dram(20) with param 0x00000005
[2445482.884889] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message TransferTableSmu2Dram(20) with param 0x00000005
[2445482.934954] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message TransferTableSmu2Dram(20) with param 0x00000005
[2445482.985052] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message TransferTableSmu2Dram(20) with param 0x00000005
[2445483.035090] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message TransferTableSmu2Dram(20) with param 0x00000005
[2445483.085158] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message TransferTableSmu2Dram(20) with param 0x00000005
[2445483.135223] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message TransferTableSmu2Dram(20) with param 0x00000005
[2445483.185322] amdgpu 0000:c3:00.0: amdgpu: Sending SMU message TransferTableSmu2Dram(20) with param 0x00000005