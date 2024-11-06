#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <err.h>
//#include <fcntl.h>
#include <signal.h>
int get_cpu(int fd, int *buffer);

int main(int argc, char *argv[])
{ volatile int num1=0xff;
  int fd;
  fd = open(argv[0], O_WRONLY);
	if (fd<0) { 
		printf("erro open for wrt");//不能printf 否则loadelf找不到魔术数字
	}  
  const char *cbuffer=" write from image is ";
  dup2(fd, STDOUT_FILENO);
  while(1)
  {
  printf("arg %s",argv[0]);
  printf("%s",cbuffer);
  int num=0;
    printf(" cpu is: ");
    get_cpu(0, &num);
    num=num;
    printf("%d",num);
      printf("\n");
  }
  (void)num1;
  close(fd);	
  //}
return argc;
}
int get_cpu(int fd, int *buffer)
{
	__asm__ volatile ( 
		"move $a0,%0\n"
		"move $a1,%1\n"
		"li $v0, 309\n ; "
		"syscall\n ;"
		:"=r"(*buffer)
		:"r"(fd),"r"(*buffer)
		:
);
return 0;
}
