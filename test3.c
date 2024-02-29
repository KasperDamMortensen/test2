#include "linux/kernel.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "arch/x86/include/generated/uapi/asm/unistd_64.h"

int main(int argc, char** argv) {
  char *in = "This is a stupid message.";
  char msg[50];
  int msglen;

  /* Send a message containing 'in' */
  syscall(__NR_dm510_msgbox_put,in,strlen(in)+1);

  /* Read a message */
  msglen = syscall(__NR_dm510_msgbox_get, msg, 50);
  printf("%s\n",msg);
  return 0;
}
