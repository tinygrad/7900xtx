import numpy as np
from tinygrad import Device
from tinygrad.helpers import flat_mv
from tinygrad.runtime.ops_hip import HIPDevice, HIPAllocator, HIPProgram
N = 1

device = HIPDevice()
hipallocator = HIPAllocator(device)
a = hipallocator.alloc(32)

prog_str = f"""
typedef long unsigned int size_t;
extern "C" __attribute__((device)) __attribute__((const)) size_t __ockl_get_group_id(unsigned int);
extern "C" __attribute__((global))void test(float *a) {{
  int gid = __ockl_get_group_id(0);
  int loop_len = (gid==0) ? 1000000 : 100;

  int gidmod = gid%8;
  float inp = a[gidmod];
  for (int i = 0; i < loop_len; i++) {{
    inp = inp * i;
  }}
  a[gidmod] = (inp+1);
}}
"""

print(prog_str)
lib = device.compiler.compile(prog_str)
prog = HIPProgram(device, "test", lib)

na = np.empty(8, np.float32)

wait = True
while 1:
  tm = prog(a, global_size=(8*100,1,1), local_size=(1,1,1), wait=wait)
  if wait:
    hipallocator._copyout(flat_mv(na.data),a)
    print(f"tm {tm*1e6:7.2f} us, launch", na)