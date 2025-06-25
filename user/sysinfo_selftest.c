#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/sysinfo.h"

int main(void){
  struct sysinfo *s;
  s = (struct sysinfo *)malloc(sizeof(struct sysinfo));
  sysinfo(s);
  exit(0);
}
