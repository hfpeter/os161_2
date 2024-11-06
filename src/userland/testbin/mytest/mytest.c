#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <err.h>
//#include </usr/include/math.h>
#include </usr/lib/gcc/x86_64-linux-gnu/9/include/float.h>
#include <signal.h>
//#include <src/kern/include/clock.h>
void test_f_exe(void);
void cpu_idle_f(int pid);
#define pid_t  int
int cpu_wake(unsigned int pid);
int cpu_wake(unsigned int pid)
{
	__asm__ volatile ( 
		"move $a0,%0\n"
		"li $v0, 67\n ; "
		"syscall\n ;"
		:
		:"r"(pid)
		:
);
return 0;
}  
void cpu_idle_f(int pid)
{
    __asm__ volatile (   // 
		//".data\n"
		//"path:   .asciiz   \"/testbin/hello\"\n"
		".text\n"
		"move $a0, %0\n"
    "li $v0, 66 ; "
    "syscall\n    ;   "
		://not any output
		:"r"(pid)//input follow one by one
		//:"t0", "t1"  // 告诉编译器这两个寄存器已经被使用
		);
}
#define cpu_idle \
		__asm__ volatile (                     \
		"li $v0, 66\n ; "                           \
		"syscall\n ;"                              \
		);         
#define __exit \
		__asm__ volatile (                     \
		"li $v0, 3 ; "   													 \
		"syscall;"                                 \
		"li $a0, 1\n"                              \
		"li $v0, 3\n ; "                           \
		"syscall\n ;"                              \
		);                                         \
		while(1){	};  
#define pid_exit \
		const char *ctmp1="before exit\n";         \
		write(fd[i],ctmp1, 13);	                   \
		__asm__ volatile (                     \
		"li $v0, 3 ; "   													 \
		"syscall;"                                 \
		"li $a0, 1\n"                              \
		"li $v0, 3\n ; "                           \
		"syscall\n ;"                              \
		);                                         \
		const char *ctmp2="after exit\n";		\
		write(fd[i],ctmp2, 13);				\
		while(1){	};  

#define sleep_macro \
ttm=(long int)(timer);    \
time(&timer);\
while(((long int)(timer)-ttm)<1)    \
{time(&timer);};                 
void random_burst(void);
void sched(void);
void t_exit_2(void);
void test_fork_5exe(void);
void test_execv(void);
void test_getcwd(void);
void asm_syscall(void);
void asm_syscall_wrt(void);
void time_w(void);
void test_fork_5child_wrt(void);
/*char  int_to_char(unsigned int intput);
char  int_to_char(unsigned int intput){
char c1[4];					
c1[0]=(char)(intput%10+0x30);
c1[1]=(char)((intput/10)%10+0x30);
c1[2]=(char)((intput/100)%10+0x30);
return c1;
}*/
# define timerclear(tvp)	((tvp)->tv_sec = (tvp)->tv_usec = 0)
#define ITIMER_REAL 0					
//void sleep(unsigned int time);
int get_cpu(int fd, int *buffer);
void test_wrt(void);
void 	test_fork2(void);
static void dowait(int nowait, int pid);
static int dofork(void);
static void check(void);
void test_getpid(void);
void test_dup2(void);
void test_lseek(void);
void test_fork(void);
void f_wrt(void);
void 	t_exit(void);
void t_timer(void);
struct itimerval tval;
static
pid_t
forkoff(void (*func)(void))
{
	pid_t pid = fork();
	switch (pid) {
		case -1:
									warn("fork");
									return -1;
		case 0:
									func();
									_exit(0);
		default: break;
	}
	return pid;
}

void f_wrt(void)
{
	int fd,rv;
	fd = open("test.txt", O_WRONLY);
	if (fd<0) { 
		err(1, "%s: open for wrt", 1);
	}
const	char *cbuffer="pid wrt: pls continue dont cpmln..";
	for (int i = 0; i < 4; i++) {
		  rv=write(fd, &cbuffer[i], 40);
				if (rv<0) {
					err(1, "%s: write", 1);
				}		
	}
		rv = close(fd);
}
void test_fork(void)
{
	forkoff(f_wrt);
	while(1){}	
}
void test_lseek(void)
{
	static char readbuf[20];
	int fd=0, rv=0;;
	fd = open("test.txt", O_RDWR);
	if (fd<0) { 
		err(1, "%s: open for wrt", 1);
	}
	int f1=lseek(fd,4,SEEK_CUR);
	printf("Pointer is at %d position\n",f1);
	if (f1<0) err(f1, "%s: lseek error", NULL);
	rv = read(fd, readbuf, 20);		
	rv = write(fd, readbuf, 20);
	if (rv<0) {
	err(1, "%s: read", 0);
	}	
	rv = close(fd);
	return;//while(1){}	
}
void test_dup2(void)
{
	int number1=3, number2=4, sum;
	const	char *cbuffer="redirect to standard output, call printf then the file is wrote instead of printting on shell.  ";	
	int output_fds = open("./output.txt", O_WRONLY);
	dup2(output_fds, STDOUT_FILENO);
	sum = number1 + number2;
	printf("%d + %d = %d\n", number1, number2, sum);
	printf("%s",cbuffer);
	close(output_fds);		
	return ; //while(1);	
	//scanf("%d %d", &number1, &number2);
	//write(),
  /*int number1=0, number2=0, sum;
  int input_fds = open("input.txt", O_RDONLY);
   //int fd4 = open("input.txt", O_RDONLY);
  if(dup2(input_fds, 1) < 0) {
    printf("Unable to duplicate file descriptor.");
  }
		char ch;
   number1=read(STDIN_FILENO, &ch, 1);
   err(number1, "%s: read1 error", NULL);	
   number2=read(STDIN_FILENO, &ch, 1);
   err(number2, "%s: read2 error", NULL);		
  //putchar();
  sum = number1 + number2;
 
  printf("%d + %d = %d\n", number1, number2, sum);
 while(1);
  return ;
	//static char readbuf[20];
	int fd=0;
	fd = open("test.txt", O_RDONLY);
	if (fd<0) { 
		err(1, "%s: open for wrt", 1);
	}
	int errn=dup2(fd,1);//redirect to 1, means standard ouput(stdout)  
	if (errn<0) err(errn, "%s: dup2 error", NULL);
	//stdin, stdout, stderr, in integers they are 0,1,2.
	close(fd);	
	while(1){}	*/
}
static int dofork(void)
{int pid;
	pid = fork();
	if (pid < 0) {
		warn("fork");
	}
	return pid;}
static volatile int  mypid;
static void check(void)
{	int i;
	mypid = getpid();
	/* Make sure each fork has its own address space. */
	for (i=0; i<800; i++) {
		volatile int seenpid;
		seenpid = mypid;
		if (seenpid != getpid()) {
			errx(1, "pid mismatch (%d, should be %d) "
			     "- your vm is broken!", 
			     seenpid, getpid());
		}
		printf("child pid is  %d\n", getpid());
	}
}
static void dowait(int nowait, int pid)
{ 	int x;
	if (pid<0) {
		/* fork in question failed; just return */
		return;
	}
	if (pid==0) {
		/* in the fork in question we were the child; exit */
		exit(0);
	}
	if (!nowait) {
		if (waitpid(pid, &x, 0)<0) {
			warn("waitpid");
		}
		else if (WIFSIGNALED(x)) {
			warnx("pid %d: signal %d", pid, WTERMSIG(x));
		}
		else if (WEXITSTATUS(x) != 0) {
			warnx("pid %d: exit %d", pid, WEXITSTATUS(x));
		}
	}
}
static volatile int  pid;
void test_getpid(void)
{	int pid0, pid1, pid2, pid3;
	pid0 = dofork();
	putchar('0');
	check();
	pid1 = dofork();
	putchar('1');
	check();
	pid2 = dofork();
	putchar('2');
	check();
	pid3 = dofork();
	putchar('3');
	check();

	dowait(0, pid3);
	dowait(0, pid2);
	dowait(0, pid1);
	dowait(0, pid0);
	while(1);
    //int pid;
    /*pid = fork();
    if (pid == 0)
    {
			printf("child pid is  %d\n", getpid());
    }	
		int pid2=fork();
		if (pid2==0)
		printf("child2 pid is  %d\n", getpid());
		while(1);*/
}
/*void sleep(unsigned int time)
{
for(;time>0;time--){
unsigned int tt2=0;
for(;tt2<65530;tt2++){};	
};

}*/
void test_execv(void)
{
char str1[] = " child.c";
char str2[] = " \nHello from ";
char str3[] = " process 2 ";
		const char *path="/testbin/hello";
    char *ptrArray[4];
    ptrArray[0] = str1;
    ptrArray[1] = str2;
    ptrArray[2] = str3;
    ptrArray[3]  =(char *)0;//str4;
		//execv("/testbin/hello",ptrArray);
		//execv(path,ptrArray);
    __asm__ volatile (   // 
		//".data\n"
		//"path:   .asciiz   \"/testbin/hello\"\n"
		".text\n"
		"move $a0, %0\n"
		"move $a1, %1\n;" 
		"li $v0, 2 ; "
		"syscall\n    ;   "
		://not any output
		:"r"(path),"r"(ptrArray)//input follow previous one
		//:"t0", "t1"  // 告诉编译器这两个寄存器已经被使用
		);
		{
			printf(" execv error\n");   
		}
		while(1){}
		execv(path,ptrArray);
		while(1){}
}

#define wrt_fd0_float_bit d=a*exp;\
exp=exp*10;\
wrt=((int)d)%10+0x30;\
write(fd[0],&wrt, 1)
void sched(void)
{
	int fd[10];
	time_t timer;
	time(&timer);
	long int ttm;
	pid_t pid;

		pid = fork();
		if (pid == 0) {
				fd[1] = open("p2.txt", O_WRONLY);
					volatile unsigned long m=0 ;
						m=0;
						for(;m<6550;m++){
	/*volatile int b=0;
	syscall( (int *)((int)&b));*/
						volatile int num1=0xff;
						get_cpu(0,(int *)((int)&num1));
						printf("cpu %d",num1);
						char wrt2=num1+0x30;
						write(fd[1],&wrt2, 1);
						//getpid();
						}
				__exit;
		} 

		pid = fork();
		if (pid == 0) {
			fd[0] = open("p1.txt", O_WRONLY);
			volatile unsigned long m1=0 ;
			m1=0;
			for(;m1<6550;m1++){
				volatile int num2=0xff;
				get_cpu(0,(int *)((int)&num2));
				//printf("cpu %d",num);
			char wrt2=num2+0x30;
			write(fd[0],&wrt2, 1);
			//getpid();
			}
			__exit;
		}
		pid = fork();
		if (pid == 0) {
			fd[2] = open("p3.txt", O_WRONLY);
			volatile unsigned long m3=0 ;
			m3=0;
			for(;m3<6550;m3++){
				volatile int num3=0xff;
				get_cpu(0,(int *)((int)&num3));
				//printf("cpu %d",num);
			char wrt2=num3+0x30;
			write(fd[2],&wrt2, 1);
			//getpid();
			}
			__exit;
		}
		pid = fork();
		if (pid == 0) {
			fd[3] = open("p4.txt", O_WRONLY);
			volatile unsigned long m4=0 ;
			m4=0;
			for(;m4<6550;m4++){
			//printf("cur pid %d",getpid());
				volatile int num4=0xff;
				get_cpu(0,(int *)((int)&num4));
			char wrt2=num4+0x30;
			write(fd[3],&wrt2, 1);
			//getpid();
			}

			__exit;
		}
						//{
							//printf("?????");
							//printf("   lllllllllllllllllllllllllll  %ld\n",m);
//-----------------------------------
        /*"li $2, 1;"         // 将1加载到寄存器$2
        "li $3, 2;"         // 将2加载到寄存器$3
        "add $2, $2, $3;"   // 将$2和$3相加，结果存储在$2中
        "move %0, $2;"      // 将$2的值存储到result变量中
        : "=r" (result)     // 输出操作数：result
        :                   // 输入操作数（这里没有输入）
        : "$2", "$3"        // clobbered寄存器：告诉编译器我们使用了$2和$3寄存器*/

//-----------------------------------
							//if(m==500)
							
						//}
						/*float a=0,b=0,c=13;
						unsigned long  d=0;
						a=b/c;
						unsigned long exp=10;
						char wrt;
						//for(unsigned int prc=1;prc<=5;prc++){
						wrt_fd0_float_bit;
					 //}
						wrt_fd0_float_bit;
						wrt_fd0_float_bit;
						wrt_fd0_float_bit;
						wrt_fd0_float_bit;
						wrt_fd0_float_bit;
						wrt_fd0_float_bit;
						wrt_fd0_float_bit;
						wrt_fd0_float_bit;
						wrt_fd0_float_bit;
						wrt_fd0_float_bit;
						wrt_fd0_float_bit;*/
						//__exit;
				//sleep_macro;
				//__exit;
		//waitpid(4, NULL, 0);
	
	
		sleep_macro;

		__exit;
		sleep_macro;
	while(1);
}
void random_burst(void){
	int seed=0;
	srandom(seed);

	time_t timer;
	time(&timer);
	long int ttm;
	pid_t pid;
	//pid_t child_pids[10];	
	int fd[10];
	fd[0] = open("p1.txt", O_WRONLY);
	fd[1] = open("p2.txt", O_WRONLY);
	fd[2] = open("p3.txt", O_WRONLY);
	fd[3] = open("p4.txt", O_WRONLY);
	fd[4] = open("p5.txt", O_WRONLY);
	fd[5] = open("p6.txt", O_WRONLY);
	fd[6] = open("p7.txt", O_WRONLY);
	fd[7] = open("p8.txt", O_WRONLY);
	fd[8] = open("p9.txt", O_WRONLY);
	fd[9] = open("p10.txt", O_WRONLY);
volatile int i=0;
	for (; i < 10; i++) {
		pid = fork();
		if (pid == 0) {
			while(1){
				sleep_macro;
				volatile int num1=0;
				get_cpu(0,(int *)((int)&num1));
				char wrt2=num1+0x30;
				write(fd[getpid()-3],&wrt2, 1);
				seed=random();	
				printf("seed, %d\n",seed);
			}
		}
			while(1){
				sleep_macro;
				seed=random();	
				printf("seed, %d\n",seed);
			}
		}
}

			//sleep_macro;
					//printf("    ch%d pid %d\n",i, getpid());		
			/*char c1;		
			int ppid=getpid();
			c1=(char)((ppid/100)%10+0x30);
			write(fd[i],&c1, 1);			
			c1=(char)((ppid/10)%10+0x30);
			write(fd[i],&c1, 1);					
			c1=(char)(ppid%10+0x30);
			write(fd[i],&c1, 1);*/
			//write(fd[i],"\n", 2);	
			//	printf("    ch%d pid %s\n",i, pid_c);	
				//exit(1);//
				/*float a=0.02,b=0.09,c=0;
				c=a*b;
				if(c<1)
				{
					const char *charaa="k0000000000000000";
				write(fd[i],charaa, 18);
				}*/
							//sleep_macro;
					//printf("    ch%d pid %d\n",i, getpid());		
			/*char c1;		
			int ppid=getpid();
			c1=(char)((ppid/100)%10+0x30);
			write(fd[i],&c1, 1);			
			c1=(char)((ppid/10)%10+0x30);
			write(fd[i],&c1, 1);					
			c1=(char)(ppid%10+0x30);
			write(fd[i],&c1, 1);*/
			//write(fd[i],"\n", 2);	
			//	printf("    ch%d pid %s\n",i, pid_c);	
				//exit(1);//
				/*float a=0.02,b=0.09,c=0;
				c=a*b;
				if(c<1)
				{
					const char *charaa="k0000000000000000";
				write(fd[i],charaa, 18);
				}*/
						/*for(;cnt<20;cnt++)//
						//while(1)
						{
						get_cpu(0,(int *)((int)&num1));
						char wrt2=num1+0x30;
						write(fd[i],&wrt2, 1);
						//sleep_macro;
						//for(;time_mem<500;time_mem++);
						}*/
						//printf("idl cpu is %d\n",num1);
						//__exit;						
						//cpu_idle;
						//cpu_idle_f(getpid());
void test_fork_5child_wrt(void){
	int seed=0;
	srandom(seed);	
	time_t timer;
	time(&timer);
	long int ttm;
	pid_t pid;
	pid_t child_pids[10];	
	 unsigned int i=0;
	const char *files[] = {
			"p1.txt",
			"p2.txt",
			"p3.txt",
			"p4.txt",
			"p5.txt",
			"p6.txt"
	};
	int fd[10];
	 pid_t ppid=getpid();
	const char **ptr0 = files; // 指向包含字符串的数组的指针
	for (; i <6; i++) {
		if(ppid==getpid())
		child_pids[i] = fork();
		if (child_pids[i] == 0) {
			fd[i]=open(ptr0[i], O_WRONLY);
			const char *cbuffer="for loop index is ";
			size_t length = strlen(cbuffer);
			write(fd[i], cbuffer, length);
			volatile char i2=i+0x30;
			char i3=i2;
			write(fd[i], &i3, 1);
			write(fd[i], " ", 1);
			write(fd[i], " ", 1);
			write(fd[i], " ", 1);
			write(fd[i], " ", 1);
			close(fd[i]);
			__exit;

		} else if (child_pids[i] > 0) {
		
			} else {
					printf("fork failed");
				}
	}
	for(int j=0;j<6;j++){
	waitpid(child_pids[i],NULL,0);	
	}
	//return;//
	while(1){}
pid = fork();
if (pid == 0) 
	while(1){}{
						for(int i=0; i<5;i++)
						{
						volatile unsigned long time_mem=0;
						for(;time_mem<200;time_mem++);
						cpu_idle_f(child_pids[i]);
						}
}//else while(1){}
pid = fork();
if (pid == 0) {
	while(1){}
	{
//sleep_macro;//不能用定时器为什么?CPU被锁住?
		volatile unsigned long time_mem=0;
		for(time_mem=0;time_mem<2000;time_mem++);
	};
}
	while(1){
	};sleep_macro;	
		printf("pid array1 is %d\n", child_pids[0]);	

}
void test_f_exe(void){
	char file1[] = "p1.txt";
	char file2[] = "p2.txt";
	char file3[] = "p3.txt";
	char file4[] = "p4.txt";
	char file5[] = "p5.txt";
	char file6[] = "p6.txt";
	char *files[] = {file1,file2,file3,file4,file5,file6
	};
	char **ptr0 = files; // 指向包含字符串的数组的指针
	pid_t child_pids;	
		child_pids = fork();	
		if (child_pids == 0) 
		{
		char *arguments[4]={};
		 arguments[0]=ptr0[0];
		 arguments[1]=NULL;
		 arguments[2]=NULL;
		 arguments[3]=NULL;
		  //const char programPath0[] = "/testbin/wrt1";//C lib path no *	
		const char programPath0[] = "/testbin/wrt1";//C lib path no *	
		execv(programPath0, arguments);
		} else if (child_pids > 0) {
				
		} else {
		printf("fork failed");
		}		  
}
void test_fork_5exe(void){
	int seed=0;
	srandom(seed);	
//struct timespec current_time;
	//clock_gettime(&current_time);
	time_t timer;
	time(&timer);
	long int ttm;
	pid_t pid=0;
	pid_t child_pids[10];	
	//char str1[] = " child.c";
	//volatile char *ptr0[4];
	unsigned int i=0;
	  char file1[] = "p1.txt";
	  char file2[] = "p2.txt";
	  char file3[] = "p3.txt";
	  char file4[] = "p4.txt";
	  char file5[] = "p5.txt";
	  char file6[] = "p6.txt";
	  char *files[] = {file1,file2,file3,file4,file5,file6
			};
	 char **ptr0 = files; // 指向包含字符串的数组的指针
	 pid_t ppid=getpid();
	for (; i <5; i++) 
	{
		if(ppid==getpid())
		child_pids[i] = fork();
		if (child_pids[i] == 0) 
		{		
		char *arguments[4]={};
		 arguments[0]=ptr0[i];
		 arguments[1]=NULL;
		 arguments[2]=NULL;
		 arguments[3]=NULL;
		  //const char programPath0[] = "/testbin/wrt1";//C lib path no *	
		const char programPath0[] = "/testbin/wrt1";//C lib path no *	
		execv(programPath0, arguments);
		} else if (child_pids[i] > 0) {

		} else {
		printf("fork failed");
		}
			
	}

	//return;
	/*	volatile unsigned long time_mem=0;
		for(;time_mem<(unsigned)(500000);time_mem++);*/
	//sleep_macro;
	while(1);	

		pid = fork();
		if (pid == 0) 
		{
		char *arguments[4]={};
		 arguments[0]=ptr0[1];
		 arguments[1]=NULL;
		 arguments[2]=NULL;
		 arguments[3]=NULL;
		  //const char programPath0[] = "/testbin/wrt1";//C lib path no *	
		const char programPath0[] = "/testbin/wrt1";//C lib path no *	
		execv(programPath0, arguments);
		} else if (pid > 0) {
				child_pids[i] = pid;
			} else {
					printf("fork failed");
				}	
	while(1){}
pid = fork();
if (pid == 0) 
	while(1){}{
						for(int i=0; i<5;i++)
						{
						volatile unsigned long time_mem=0;
						for(;time_mem<200;time_mem++);
						cpu_idle_f(child_pids[i]);
						}
}//else while(1){}
pid = fork();
if (pid == 0) {
	while(1){}
	{
//sleep_macro;//不能用定时器为什么?CPU被锁住?
		volatile unsigned long time_mem=0;
		for(time_mem=0;time_mem<2000;time_mem++);
		for(time_mem=0;time_mem<2000;time_mem++);
		for(time_mem=0;time_mem<2000;time_mem++);
		for(time_mem=0;time_mem<2000;time_mem++);
		for(time_mem=0;time_mem<2000;time_mem++);
		for(time_mem=0;time_mem<2000;time_mem++);
		for(time_mem=0;time_mem<2000;time_mem++);
	};
}
	while(1){

	};sleep_macro;	
		printf("pid array1 is %d\n", child_pids[0]);	
		printf("pid array2 is %d\n", child_pids[1]);	
		printf("pid array3 is %d\n", child_pids[2]);	
		printf("pid array4 is %d\n", child_pids[3]);	
		printf("pid array5 is %d\n", child_pids[4]);	

}
void 	test_fork2(void){
	time_t timer;
	time(&timer);
	printf(" TIMEaa %ld\n",(long int)(timer));   
	time_t current_time;
	current_time = time(NULL);
	printf(" TIME %ld\n",(long int)(current_time/3600));
	int sum=0;
	int pid;
	pid=fork();
	long int ttm=(long int)(timer);
	long int ttm2=(long int)(timer);
    if (pid == 0)
    {
				int fd=0;
				fd = open("test.txt", O_WRONLY);
				if (fd<0) { 
					err(1, "%s: open for wrt", 1);
				}
			while(1){//printf(" child pid is %d\n",getpid());
			sum=sum+5;
			const	char *cbufferc="child wrt.\n";
			write(fd, cbufferc, 11);
			time(&timer);
			ttm=(long int)(timer);
			while(((long int)(timer)-ttm)<2)
			{time(&timer);};
			}
    }else 
		if(pid>0){
			int fd2 = open("test2.txt", O_WRONLY);
			if (fd2<0) { err(1, "%s: open for wrt", 1);}	
			while(1){//printf(" parent pid is %d\n",getpid());
			sum=sum+1;
			const	char *cbuffer="parent wrt.\n";
			write(fd2, cbuffer, 12);						
			time(&timer);
			ttm2=(long int)(timer);
			while(((long int)(timer)-ttm2)<2){time(&timer);				};
			}
		}
		
}
/*void 	test_fork2(void){
	time_t timer;
	time(&timer);
	printf(" TIMEaa %ld\n",(long int)(timer));   
	time_t current_time;
	current_time = time(NULL);
	printf(" TIME %ld\n",(long int)(current_time/3600));
	int sum=0;
	int pid;
	pid=fork();
	long int ttm=(long int)(timer);
	long int ttm2=(long int)(timer);
    if (pid == 0)
    {
				int fd=0;
				fd = open("test.txt", O_WRONLY);
				if (fd<0) { 
					err(1, "%s: open for wrt", 1);
				}
			while(1){//printf(" child pid is %d\n",getpid());
			sum=sum+5;
			const	char *cbufferc="child wrt.\n";
						write(fd, cbufferc, 11);
			time(&timer);
			ttm=(long int)(timer);
			while(((long int)(timer)-ttm)<2)
			{time(&timer);};
			}
    }else 
		if(pid>0){
			int fd2 = open("test2.txt", O_WRONLY);
			if (fd2<0) { err(1, "%s: open for wrt", 1);}	
			while(1){//printf(" parent pid is %d\n",getpid());
			sum=sum+1;
			const	char *cbuffer="parent wrt.\n";
			write(fd2, cbuffer, 12);						
			time(&timer);
			ttm2=(long int)(timer);
			while(((long int)(timer)-ttm2)<2){time(&timer);				};
			}
		}		
}*/
void test_wrt(void)
{
	int fd,rv;
	fd = open("test.txt", O_WRONLY);
	if (fd<0) { 
		err(1, "%s: open for wrt", 1);
	}
const	char *cbuffer="wrt: pls continue dont cpmln..";
	for (int i = 0; i < 4; i++) {
		  rv=write(fd, &cbuffer[i], 40);
				if (rv<0) {
					err(1, "%s: write", 1);
				}		
	}
		rv = close(fd);	

}
static int timing = 0;
void time_w(void){
	 	time_t startsecs, endsecs;
	unsigned long startnsecs, endnsecs;		
		if (timing) {
		__time(&startsecs, &startnsecs);
	}

		if (timing) {
		__time(&endsecs, &endnsecs);
		if (endnsecs < startnsecs) {
			endnsecs += 1000000000;
			endsecs--;
		}
		endnsecs -= startnsecs;
		endsecs -= startsecs;
		warnx("subprocess time: %lu.%09lu seconds",
		      (unsigned long) endsecs, (unsigned long) endnsecs);
	}
}
void asm_syscall(void)
{
	//const char* message= "Hello, OS/161!\n";
    __asm__ volatile (   // # 设置系统调用号（4对应于_write系统调用）
    "li $v0, 1 ; "// 设置系统调用号（1对应于_write系统调用）
    "li $a0, 1 ;  "//设置参数：文件描述符为1（标准输出），字符串地址为message，长度为14
    "la $a1, 0x31  ; "//要写的东西
    "li $a2, 1  ;  "//写字符串长度
    "syscall    ;   "
    "li $v0, 10    ; "
    "syscall       ; "
	);
	while(1){};	
}
void asm_syscall_wrt(void){
    int result;
    // 内嵌汇编语言块开始
    __asm__ volatile (
        "li $2, 1;"         // 将1加载到寄存器$2
        "li $3, 2;"         // 将2加载到寄存器$3
        "add $2, $2, $3;"   // 将$2和$3相加，结果存储在$2中
        "move %0, $2;"      // 将$2的值存储到result变量中
        : "=r" (result)     // 输出操作数：result
        :                   // 输入操作数（这里没有输入）
        : "$2", "$3"        // clobbered寄存器：告诉编译器我们使用了$2和$3寄存器
    );
		//write();

    // 内嵌汇编语言块结束
    printf("Result: %d\n", result);
while(1){}
}
void test_getcwd(void){
  char cwd[255];///home/os161user/os161/root/test.txt
  #if 0
  if (chdir("/testbin") != 0)  ///home/os161user/os161/src/userland/testbin/mytest
   {
		 printf("change cwd error \n");
	 }
  else 
	{
    if (getcwd(cwd, sizeof(cwd)) == NULL)
     {
				 printf("get cwd error \n");
		 }
    else
		getcwd(cwd, sizeof(cwd));
		printf("current working directory is: %s\n", cwd);
  }
  #endif
	time_t timer;
	time(&timer);
	long int ttm;  		
		sleep_macro;
		//sleep_macro;
		//sleep_macro;
		//sleep_macro; 

	if (chdir("mydisk:") != 0)  ///home/os161user/os161/src/userland/testbin/mytest
	{
	printf("change cwd error \n");
	//return;
	}	
		getcwd(cwd, sizeof(cwd));
		printf("current working directory is: %s\n", cwd);
		return;
		#if 0
	time_t timer;
	time(&timer);
	long int ttm;  		
		sleep_macro;
		sleep_macro;
		sleep_macro;
		sleep_macro;
		#endif
	//while(1){};
}
#define pid_num 5
void t_exit(void){
	#ifdef random_t
	unsigned int prime_num=65521;
	unsigned int ram_sum=65519;
	#endif
	int fd[5];
	fd[0] = open("p1.txt", O_WRONLY);
	fd[1] = open("p2.txt", O_WRONLY);
	fd[2] = open("p3.txt", O_WRONLY);
	fd[3] = open("p4.txt", O_WRONLY);
	fd[4] = open("p5.txt", O_WRONLY);
	//close(fd[0]);
	pid_t child_pids[pid_num];
	for(int i=0;i<pid_num;i++)
	{child_pids[i]=0;}
	int status;
	for (int i = 0; i < pid_num; i++) {
		pid_t pid = fork();
		if (pid == 0) {
			#ifdef random_t
				int random=ram_sum%7;
				ram_sum=prime_num+65519;
				printf("random num is %d\n",random);
				if(random==getpid())
				{
				__asm__ volatile (   // # 
				#ifdef argasm
				"li $v0, 3 ; "// 设置系统调用号（3 is sys_exit）
				"syscall;"
				#else
				"li $a0, 1\n"
				"li $v0, 3\n ; "
				"syscall\n ;"
				#endif
				);					
				}
				#endif
				const char *ctmp1="before exit\n";
				write(fd[i],ctmp1, 13);	
				#define sysexit			
				#ifdef sysexit
				//pid_t child_pid = getpid();
				//printf("   child pid %d\n", child_pid);
				//exit(1);
				//while(1){	};
				//#define argasm
				__asm__ volatile (   // # 
				#ifdef argasm
				"li $v0, 3 ; "// 设置系统调用号（3 is sys_exit）
				"syscall;"
				#else
				"li $a0, 1\n"
				"li $v0, 3\n ; "
				"syscall\n ;"
				#endif
				);
				//exit(1);
				//printf("after exit");		
				#endif
				const char *ctmp2="after exit\n";		
				write(fd[i],ctmp2, 13);					
				while(1){	};
		} else if (pid > 0) {
			child_pids[i] = pid;
		} else {
			printf("fork failed");
			//exit(1);
		}
	}
	//while(1){};
	// Parent process
		//printf("before waitpid\n");		

	for(int i=0;i<pid_num;i++)
	{//pid_t random_child_pid = child_pids[i];
		//printf("Sending SIGUSR1 signal to child process with PID %d\n", child_pids[i]);
		waitpid(child_pids[i], &status, 0);
		//active_children--;
	}
		//printf("after wwwwwwwwwwwwwwwwwwwwwww\n");		
		while(1);
	return;
}
                 
/*printf(" TIME ssss %ld\n",(long int)(timer)); \*/		
/*printf(" TIME eeeee %ld\n",(long int)(timer)); */

void t_exit_2(void){
	time_t timer;
	time(&timer);
	long int ttm;
	int fd[5];
	//sleep_macro
	fd[0] = open("p1.txt", O_WRONLY);
	fd[1] = open("p2.txt", O_WRONLY);
	fd[2] = open("p3.txt", O_WRONLY);
	fd[3] = open("p4.txt", O_WRONLY);
	fd[4] = open("p5.txt", O_WRONLY);
	pid_t child_pids[pid_num];
	for(int i=0;i<pid_num;i++)
	{child_pids[i]=0;}
		int status;
		pid_t pid[pid_num];
		pid[0]= fork();
		if (pid[0] > 0) {
		child_pids[0] = pid[0];
				while(1);
		}
		 pid[1]= fork();
		if (pid[1] > 0) {
		child_pids[1] = pid[1];
				//while(1);
		}
		if (pid[1] == 0){
		//sleep_macro
		//sleep_macro
		int i;
		i = 0;
    pid_exit//其实不需要exit直接在内核强制替换旧的Pid内存
		//也就是说fork系统调用需要调用exit系统调用
		sleep_macro
		sleep_macro
		}
		 pid[2]= fork();
		if (pid[2] == 0){
			//while(1);
		}
		if (pid[2] > 0) {
		child_pids[2] = pid[2];
		//while(1);
		}
		sleep_macro
		sleep_macro
		sleep_macro
		printf("before 00000000000000000\n");		
		waitpid(pid[0], &status, 0);
		sleep_macro
		printf("after 0000000000000000\n");		
		sleep_macro
		sleep_macro
		sleep_macro

		pid[0]= fork();
		if (pid[0] > 0) {
		child_pids[0] = pid[0];
		//while(1);
		}
		pid[1]= fork();
		if (pid[1] > 0) {
		child_pids[1] = pid[1];
		//while(1);
		}
		if (pid[0] == 0) {
		//sleep_macro
		int i;
		i = 0;
    pid_exit
		sleep_macro
		}

/*
		pid[1]= fork();
		if (pid[1] > 0) {
		child_pids[1] = pid[0];
		}
		i = 1;
		if (pid[1] == 0) {
    pid_exit
		sleep_macro
		}
*/
		sleep_macro
		sleep_macro
		sleep_macro

	//	printf("before waitpid\n");		
	for(int i=0;i<pid_num;i++)
	{
		waitpid(child_pids[i], &status, 0);
	}
	//sleep_macro
//	printf("maybe multiple parent here id is %d \n\n",getpid());		
//	sleep_macro
	sleep_macro
	sleep_macro

		//printf("after wwwwwwwwwwwwwwwwwwwwwww\n");		
		while(1){
		sleep_macro
		//printf("enddddddddddddddddd\n");	
		}
	return;
}
void t_timer(void)
{
//const char *arg1="hello";
char arg1=0;
char arg2=1;
char arg3=2;
    __asm__ volatile (   
		/*".text\n"
    "li $v0, 3\n ; "
    "syscall\n;"*/
		"move $a0,%0\n"
		"move $a1,%1\n"
		"move $a2,%2\n"
		"li $v0, 113\n ; "
		"syscall\n ;"
		:"=r"(arg3)
		:"r"(arg1),"r"(arg2)//input follow previuos one
		:
		);
		printf("%c %c %c ",arg1,arg2,arg3);
	while(1);
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
}          //本地打开下面连接改设置
int main()///C:/Users/HP/AppData/Roaming/Code - Insiders/User/settings.json
{///home/os161user/os161/src/userland/testbin/mytest/mytest.c
	timerclear(& tval.it_interval);	
	timerclear(& tval.it_value);
	tval.it_value.tv_sec = 10;	/* 10 second timeout */	
	//random_burst();
	//t_timer();
	//t_exit_2();
	//t_exit();
	//sched();
	//return 0;
	//__exit;
	//test_fork_5exe();
	//test_fork_5child_wrt();
	//test_execv();
	//test_f_exe();
	test_getcwd();
	//test_fork();
	//test_fork2();
	//test_lseek();
	//test_dup2();
	//test_getpid();
	//test_wrt();
//asm_syscall();
//asm_syscall_wrt();
	return 0;
	static char writebuf[40] = "Twiddle dee dee, Twiddle dum dum.......\n";
	static char readbuf[20];
	int fd=0, rv;
	fd = open("test.txt", O_RDWR);
	if (fd<0) { 
		err(1, "%s: open for wrt", 1);
	}
//const	char *cbuffer="pls continue dont complain";
//int length=strlen(readbuf);
rv = read(fd, readbuf, 20);		
rv = write(fd, readbuf, 20);
if (rv<0) {
err(1, "%s: write", 1);
}		
	
int f1=lseek(fd,-7,SEEK_CUR);
printf("Pointer is at %d position\n",f1);
		rv = read(fd, readbuf, 20);		
		rv=write(fd, readbuf, 20);


				if (rv<0) {
					err(1, "%s: read", 0);
				}
		  /*rv=write(fd, &cbuffer[0], length);
				if (rv<0) {
					err(1, "%s: write", 1);
				}*/				
		rv = close(fd);
		while(1){}	
	if (rv<0) {
		err(1, "%s: close (2nd time)",0);
	}
	fd = open("test.txt", 0);
	if (fd<0) { 
		err(1, "%s: open for read", 0);
	}
for(int cnt=0;cnt<=7;cnt++){
				rv = read(fd, readbuf, 40);
				if (rv<0) {
					err(1, "%s: read", 0);
				}
	}
	rv = close(fd);
	if (rv<0) {
		err(1, "%s: close (2nd time)",0);
	}
	forkoff(f_wrt);
/*
		for (i = 0; i < SECTOR_SIZE + 1; i++) {
		cbuffer[i] = READCHAR;
	}
*/

	rv = close(fd);

	if (rv<0) {
		err(1, "%s: close (2nd time)",0);
	}
	/* ensure null termination */
	readbuf[40] = 0;

	if (strcmp(readbuf, writebuf)) {
		errx(1, "Buffer data mismatch!");
	}


	printf("Passed filetest.\n");
	return 0;
}

