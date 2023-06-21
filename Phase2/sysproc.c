#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "sysinfo.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int
sys_getProcTick(void)
{
  int pid;
  if(argint(0, &pid) < 0)
    return -1;

  return getProcTick(pid);
}

int
sys_sysinfo(void)
{
  struct sysinfo *info;
  const int secPerTick = 10;     // each tick is 10 ms
  const uint bytePerPS = 4096;      // eack PageSize is 4096 (= 212) bytes long (4KB)
  // xv6 uses 32-bit virtual addresses, resulting in a virtual address space of 4GB.
  unsigned long freeram;

  if(argptr(0, (void*)&info, sizeof(*info)) < 0)// argaddr
    return -1;

  info->uptime = (long)(ticks * secPerTick);
  freeram = (unsigned long)(cal_freeram() * bytePerPS);
  info->totalram =  freeram + get_usedram();
  info->freeram = freeram;
  info->procs = cal_procs();

  return 0;
}