typedef unsigned long int size_t;
typedef long int ssize_t;

/*
 *	Wrappers for the asm syscalls
 * */

void* syscall(size_t number);
void* syscall1(size_t number, void* arg1);
void* syscall2(size_t number, void* arg1, void* arg2);
void* syscall3(size_t number, void* arg1, void* arg2, void* arg3);
void* syscall4(size_t number, void* arg1, void* arg2, void* arg3, void* arg4);
void* syscall5(size_t number, void* arg1, void* arg2, void* arg3, void* arg4, void* arg5);

/*
 *	Utilities
 * */

ssize_t write(int fd, void* data, size_t nbytes) {
	return (ssize_t) syscall3(
			1,
			(void*) (ssize_t) fd,
			(void*) data,
			(void*) nbytes
		);
}

#define O_RDONLY 	0
#define O_WRONLY 	1
#define O_RDWR   	2
#define O_CREAT  	100
#define O_APPEND	2000
// #define O_ASYNC
#define O_CLOEXEC	2000000
#define O_DIRECT	40000
#define O_DIRECTORY	200000
// #define O_DSYNC
#define O_EXCL		200
#define O_LARGEFILE	100000
#define O_NOATIME	1000000
#define O_NOCTTY	400
#define O_NOFOLLOW	400000
#define O_NONBLOCK	4000
#define O_NDELAY 	O_NONBLOCK
// #define O_PATH
#define O_SYNC		10000
// #define O_TMPFILE
#define O_TRUNC		1000

#define S_IRWXU 700
#define S_IRUSR 400
#define S_IWUSR 200
#define S_IXUSR 100
#define S_IRWXG 70
#define S_IRGRP 40
#define S_IWGRP 20
#define S_IXGRP 10
#define S_IRWXO 7
#define S_IROTH 4
#define S_IWOTH 2
#define S_IXOTH 1

ssize_t open(char* filename, int flags, int mode) {
	if (!mode) mode = S_IROTH | S_IWOTH | S_IRGRP | S_IWGRP | S_IRUSR | S_IWUSR;
	return (ssize_t) syscall3(
			2,
			(void*) filename,
			(void*) flags,
			(void*) mode
		);
}

ssize_t read(ssize_t fd, char* buf, size_t count) {
	return (ssize_t) syscall3(
			0,
			(void*) fd,
			(void*) buf,
			(void*) count
		);
}

ssize_t close(ssize_t fd) {
	return (ssize_t) syscall1(3, (void*) fd);
}

size_t strlen(char* str) {
	char* p;
	for (p = str; *p; ++p);
	return p - str;
}

size_t puts(char* str) {
	return write(1, str, strlen(str));
}

