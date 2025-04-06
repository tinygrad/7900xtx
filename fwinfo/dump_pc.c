#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

// clang -O2 dump_pc.c && sudo ./a.out
#define MI300X 1

#ifdef MI300X
  // mi300x
  #define GC_BASE_ADDR 0
  #define regCP_MEC1_INSTR_PNTR 0x21a8
  #define regCP_MEC2_INSTR_PNTR 0x21a9
  #define regGRBM_GFX_CNTL 0x2022
  #define regGRBM_GFX_INDEX 0x2a00
#else
  #define GC_BASE_ADDR 0xA000
  #define regCP_MEC_RS64_INSTR_PNTR  0x2908
  #define regCP_MEC_RS64_CNTL 0x2904
  #define regCP_GFX_RS64_INSTR_PNTR0 0x2a44
  #define regCP_GFX_RS64_INSTR_PNTR1 0x2a45
  #define regCP_MEC_RS64_INTERRUPT 0x2907

  #define regCP_MEC_ME1_UCODE_ADDR 0x581a
  #define regCP_MEC_ME1_UCODE_DATA 0x581b
  #define regCP_MEC_ME2_UCODE_ADDR 0x581c
  #define regCP_MEC_ME2_UCODE_DATA 0x581d
#endif

//#define regGRBM_GFX_CNTL 0x900

#define MEC_HALT 1<<30
#define MEC_STEP 1<<31

#define DUMP_COUNT 0x10000
int dumps[DUMP_COUNT];

#define MAX_ADDR 0x100000
int histogram[MAX_ADDR] = {0};

int main() {
  int fd = open("/sys/kernel/debug/dri/1/amdgpu_regs2", O_RDWR);
  int val;
  int dump;
  int gap;
  int ret;
  int bak;

  ret = pread(fd, &bak, 4, (GC_BASE_ADDR + regGRBM_GFX_CNTL)*4);
  printf("pread dump:%x ret:%d\n", bak, ret);

  int pfd = open("/sys/bus/pci/devices/0000:05:00.0/resource5", O_RDWR);
  printf("opened pfd %d\n", pfd);
  if (pfd < 0) return -1;
  #define SZ 1024*1024
  volatile unsigned int *a = (unsigned int*)mmap(0, SZ, PROT_READ, MAP_PRIVATE, pfd, 0);
  printf("mapped %p\n", a);

  dump = (0 << 8) | (0 << 4) | (1 << 2) | 0;
  ret = pwrite(fd, &dump, 4, (GC_BASE_ADDR + regGRBM_GFX_CNTL)*4);

  /*for (int i = 0; i < 100; i++) {
    ret = pread(fd, &dump, 4, (GC_BASE_ADDR + regCP_MEC1_INSTR_PNTR)*4);
    if (ret != 4) break;
    printf("address:0x%x\n", 4*dump);
  }*/

  printf("dump start\n");
  for (int i = 0; i < DUMP_COUNT; i++) {
    dumps[i] = a[GC_BASE_ADDR + regCP_MEC1_INSTR_PNTR];
  }
  printf("dump end\n");


  ret = pwrite(fd, &bak, 4, (GC_BASE_ADDR + regGRBM_GFX_CNTL)*4);
  printf("restored\n");

  //pread(fd, &dump, 4, (GC_BASE_ADDR + regGRBM_GFX_CNTL)*4);
  //printf("%x\n", dump);
  for (int i = 0; i < DUMP_COUNT; i++) {
    histogram[dumps[i]]++;
  }
  for (int i = 0; i < MAX_ADDR; i++) {
    if (histogram[i] != 0) printf("%8x : %d\n", i*4, histogram[i]);
  }

  return 0;


  /*
  regGRBM_GFX_CNTL 0 0x22 4 0 0
        PIPEID 0 1
        MEID 2 3
        VMID 4 7
        QUEUEID 8 10
  */

  int meid = 0;

  /*for (int meid = 0; meid < 4; meid++) {
    dump = (0 << 8) | (0 << 4) | (meid << 2) | 1;
    ret = pwrite(fd, &dump, 4, (GC_BASE_ADDR + regGRBM_GFX_CNTL)*4);
    printf("pwrite dump:%x ret:%d\n", dump, ret);

    ret = pread(fd, &dump, 4, (GC_BASE_ADDR + regCP_MEC1_INSTR_PNTR)*4);
    if (ret != 4) { printf("READ FAILED"); return -1; }
    printf("addr1 0x%x\n", dump*4);

    ret = pread(fd, &dump, 4, (GC_BASE_ADDR + regCP_MEC2_INSTR_PNTR)*4);
    if (ret != 4) { printf("READ FAILED"); return -1; }
    printf("addr2 0x%x\n", dump*4);
  }*/

  //dump = 1;
  dump = (0 << 8) | (0 << 4) | (meid << 2) | 1;
  ret = pwrite(fd, &dump, 4, (GC_BASE_ADDR + regGRBM_GFX_CNTL)*4);
  printf("pwrite dump:%x ret:%d\n", dump, ret);


  /*while (1) {
    ret = pread(fd, &dump, 4, (GC_BASE_ADDR + regCP_MEC2_INSTR_PNTR)*4);
    if (ret != 4) {
      printf("READ FAILED");
      return -1;
    }
    if (dump != 0x4fb) {
      printf("addr 0x%x\n", dump*4);
    }
  }
  return 0;*/

  //int pfd = open("/sys/bus/pci/devices/0000:07:00.0/resource0", O_RDWR);
  // 0x85fc000000
  //#define SZ 32LL*1024*1024*1024
  //#define SZ 256*1024*1024
  /*#define SZ 1024*1024
  volatile unsigned int *a = (unsigned int*)mmap(0, SZ, PROT_READ, MAP_PRIVATE, pfd, 0);
  printf("mapped %p\n", a);*/


  printf("dump start\n");
  for (int i = 0; i < DUMP_COUNT; i++) {
    dumps[i] = a[GC_BASE_ADDR + regCP_MEC1_INSTR_PNTR];
  }
  printf("dump end\n");

  /*dump = 0;
  pwrite(fd, &dump, 4, (GC_BASE_ADDR + regCP_MEC_ME1_UCODE_ADDR)*4);
  for (int i = 0; i < 0x80; i++) {
    ret = pread(fd, &dump, 4, (GC_BASE_ADDR + regCP_MEC_ME1_UCODE_DATA)*4);
    printf("%x: %x\n", i, dump);
  }*/
  //exit(0);


  /*for (int i = 0; i < DUMP_COUNT; i++) {
    //dumps[i] = a[GC_BASE_ADDR + regCP_MEC_RS64_INTERRUPT];
    dumps[i] = a[GC_BASE_ADDR + regCP_MEC_RS64_INSTR_PNTR];
    //pread(fd, &dumps[i], 4, (GC_BASE_ADDR + regCP_MEC_RS64_INSTR_PNTR)*4);
  }*/

  for (int i = 0; i < DUMP_COUNT; i++) {
    histogram[dumps[i]]++;
  }
  for (int i = 0; i < MAX_ADDR; i++) {
    if (histogram[i] != 0) printf("%8x : %d\n", i*4, histogram[i]);
  }
  //printf("%x\n", a[GC_BASE_ADDR + regCP_MEC_RS64_INSTR_PNTR]);
  //for (long i=0xff400000/4; i < 0xff401000/4; i++) {
  //for (long i=0; i < SZ/4; i+=0x400) {
  /*for (long i=0; i < SZ/4; i++) {
    unsigned int rd = a[i];
    if (rd != 0xbebebebe && rd != 0xffffffff) printf("access %lx = %x\n", i*4, rd);
  }*/
  return 0;

  //pread(fd, &dump, 4, (GC_BASE_ADDR + regGRBM_GFX_CNTL)*4);
  //printf("%x\n", dump);

  // dump
  /*val = 0x100000;
  pwrite(fd, &val, 4, (GC_BASE_ADDR + regCP_MEC_ME1_UCODE_ADDR)*4);

  for (int i = 0; i < 0x1000; i++) {
    pread(fd, &val, 4, (GC_BASE_ADDR + regCP_MEC_ME1_UCODE_DATA)*4);
    printf("%4X: %8X\n", i, val);
  }

  exit(0);*/

  // halting crashes the GPU


  /*val = MEC_HALT;
  pwrite(fd, &val, 4, (GC_BASE_ADDR + regCP_MEC_RS64_CNTL)*4);

  // 10 steps
  for (int i = 0; i < 10; i++) {
    pread(fd, &val, 4, (GC_BASE_ADDR + regCP_MEC_RS64_INSTR_PNTR)*4);
    //printf("regCP_MEC_RS64_INSTR_PNTR : %x\n", val);
  }

  // unhalt
  val = 0;
  pwrite(fd, &val, 4, (GC_BASE_ADDR + regCP_MEC_RS64_CNTL)*4);

  pread(fd, &val, 4, (GC_BASE_ADDR + regCP_MEC_RS64_CNTL)*4);
  printf("regCP_MEC_RS64_CNTL : %x\n", val);

  exit(0);*/


  // mmap doesn't work :(
  /*int* gpu = (int *)mmap(0, 0x1000, PROT_READ, MAP_SHARED, fd, GC_BASE_ADDR*4);
  if (gpu == MAP_FAILED) {
    printf("MAP FAILED\n");
    return -1;
  }*/
  //pread(fd, &dump, 4, (GC_BASE_ADDR + regCP_GFX_RS64_INSTR_PNTR0)*4);
  //pread(fd, &dump, 4, (GC_BASE_ADDR + regCP_GFX_RS64_INSTR_PNTR1)*4);
  //pread(fd, &dump, 4, (GC_BASE_ADDR + tmp)*4);
  //if (dumps[i] != 0x9123) i++;

  /*for (int i = 0; i < DUMP_COUNT; i++) {
    pread(fd, &dump, 4, (GC_BASE_ADDR + regCP_MEC_RS64_INSTR_PNTR)*4);
    dumps[i] = dump;
    histogram[dump]++;
  }*/

  for (int i = 0; i < MAX_ADDR; i++) {
    if (histogram[i] != 0) printf("%8x : %d\n", i*4, histogram[i]);
  }

  gap = 0;
  for (int i = 0; i < DUMP_COUNT; i++) {
    if (dumps[i]*4 != 0x24794) {
      if (gap) {
        printf("(%d skipped)\n", gap);
        gap = 0;
      }
      printf("0x%8X\n", dumps[i]*4);
    } else gap++;
  }
  return 0;
}
