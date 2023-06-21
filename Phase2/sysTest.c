#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "sysinfo.h"

void
tostring(char str[], unsigned long num)
{
  int len = 0, rem;
  unsigned long n = num;

  while (n != 0){
      len++;
      n /= 10;
  }

  for (int i = 0; i < len; i++){
      rem = (int)(num % 10);
      num = num / 10;
      str[len - (i + 1)] = rem + '0';
  }

  str[len] = '\0';
}

int
main(int argc,char **argv)
{
  int res;
  struct sysinfo info;

  res = sysinfo(&info);
  
  if(res < 0){
    printf(1, "Error! system information test failed.\n");
  } else {

      char str1[25], str2[32], str3[32], str4[10];
    
      tostring(str1, (unsigned long)info.uptime);
      tostring(str2, info.totalram);
      tostring(str3, info.freeram);
      tostring(str4, (unsigned long)info.procs);

      printf(1, "System Information:\n");
      printf(1, "uptime =   %s\n", str1);
      printf(1, "totalram = %s\n", str2);
      printf(1, "freeram =  %s\n", str3);
      printf(1, "procs =    %s\n", str4);
  }
  
  exit();
}