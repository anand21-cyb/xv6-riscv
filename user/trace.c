#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  if(argc < 3){
    fprintf(2, "Usage: trace mask command [args...]\n");
    exit(1);
  }

  int mask = atoi(argv[1]);   // convert string to int

  // Call our new system call to set the trace mask
  if(trace(mask) < 0){
    fprintf(2, "trace: syscall failed\n");
    exit(1);
  }

  // Replace current process with the command given
  exec(argv[2], &argv[2]);

  // If exec fails
  fprintf(2, "trace: exec %s failed\n", argv[2]);
  exit(1);
}
