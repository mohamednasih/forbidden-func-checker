#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <curses.h>
#include <term.h>
#include <fcntl.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
FILE *stderr = (void *)0;
FILE *stdint = (void *)0;
FILE *stdout = (void *)0;
#undef errno
long errno;
#include <errno.h>


int * __errno_location(void) {
	return (NULL);
}

void add_history(const char *line) {
    (void)line;
}

/* standard libc functions */
int printf(const char *format, ...) {
    (void)format;
    return 0;
}

void *malloc(size_t size) {
    (void)size;
    return NULL;
}

void free(void *ptr) {
    (void)ptr;
    /* No return in void function */
}

ssize_t write(int fd, const void *buf, size_t count) {
    (void)fd;
    (void)buf;
    (void)count;
    return 0;
}

/* file operations */
int access(const char *pathname, int mode) {
    (void)pathname;
    (void)mode;
    return 0;
}

int open(const char *pathname, int flags, ...) {
    (void)pathname;
    (void)flags;
    return 0;
}

ssize_t read(int fd, void *buf, size_t count) {
    (void)fd;
    (void)buf;
    (void)count;
    return 0;
}

int close(int fd) {
    (void)fd;
    return 0;
}

int unlink(const char *pathname) {
    (void)pathname;
    return 0;
}

/* process control */
pid_t fork(void) {
    return 0;
}

pid_t wait(int *wstatus) {
    (void)wstatus;
    return 0;
}

pid_t waitpid(pid_t pid, int *wstatus, int options) {
    (void)pid;
    (void)wstatus;
    (void)options;
    return 0;
}

pid_t wait3(int *wstatus, int options, struct rusage *rusage) {
    (void)wstatus;
    (void)options;
    (void)rusage;
    return 0;
}

pid_t wait4(pid_t pid, int *wstatus, int options, struct rusage *rusage) {
    (void)pid;
    (void)wstatus;
    (void)options;
    (void)rusage;
    return 0;
}

/* signal handling */
void (*signal(int sig, void (*func)(int)))(int) {
    (void)sig;
    (void)func;
    return NULL;
}

int sigaction(int sig, const struct sigaction *act, struct sigaction *oldact) {
    (void)sig;
    (void)act;
    (void)oldact;
    return 0;
}

int sigemptyset(sigset_t *set) {
    (void)set;
    return 0;
}

int sigaddset(sigset_t *set, int signum) {
    (void)set;
    (void)signum;
    return 0;
}

int kill(pid_t pid, int sig) {
    (void)pid;
    (void)sig;
    return 0;
}

_Noreturn void exit(int status) {
    (void)status;
    while(1) {} // Infinite loop to satisfy noreturn requirement
}

/* directory operations */
DIR *opendir(const char *name) {
    (void)name;
    return NULL;
}

struct dirent *readdir(DIR *dirp) {
    (void)dirp;
    return NULL;
}

int closedir(DIR *dirp) {
    (void)dirp;
    return 0;
}

/* filesystem operations */
char *getcwd(char *buf, size_t size) {
    (void)buf;
    (void)size;
    return NULL;
}

int chdir(const char *path) {
    (void)path;
    return 0;
}

int stat(const char *pathname, struct stat *statbuf) {
    (void)pathname;
    (void)statbuf;
    return 0;
}

int lstat(const char *pathname, struct stat *statbuf) {
    (void)pathname;
    (void)statbuf;
    return 0;
}

int fstat(int fd, struct stat *statbuf) {
    (void)fd;
    (void)statbuf;
    return 0;
}

/* execution */
int execve(const char *pathname, char *const argv[], char *const envp[]) {
    (void)pathname;
    (void)argv;
    (void)envp;
    return -1;
}

/* file descriptor operations */
int dup(int oldfd) {
    (void)oldfd;
    return 0;
}

int dup2(int oldfd, int newfd) {
    (void)oldfd;
    (void)newfd;
    return 0;
}

int pipe(int pipefd[2]) {
    (void)pipefd;
    return 0;
}

/* error handling */
char *strerror(int errnum) {
    (void)errnum;
    return NULL;
}

void perror(const char *s) {
    (void)s;
    /* No return in void function */
}

/* terminal operations */
int isatty(int fd) {
    (void)fd;
    return 0;
}

char *ttyname(int fd) {
    (void)fd;
    return NULL;
}

int ttyslot(void) {
    return 0;
}

int ioctl(int fd, unsigned long request, ...) {
    (void)fd;
    (void)request;
    return 0;
}

/* environment */
char *getenv(const char *name) {
    (void)name;
    return NULL;
}

/* termios */
int tcsetattr(int fd, int optional_actions, const struct termios *termios_p) {
    (void)fd;
    (void)optional_actions;
    (void)termios_p;
    return 0;
}

int tcgetattr(int fd, struct termios *termios_p) {
    (void)fd;
    (void)termios_p;
    return 0;
}

/* terminfo */
int tgetent(char *bp, const char *name) {
    (void)bp;
    (void)name;
    return 0;
}

int tgetflag(const char *id) {
    (void)id;
    return 0;
}

int tgetnum(const char *id) {
    (void)id;
    return 0;
}

char *tgetstr(const char *id, char **area) {
    (void)id;
    (void)area;
    return NULL;
}

char *tgoto(const char *cap, int col, int row) {
    (void)cap;
    (void)col;
    (void)row;
    return NULL;
}

int tputs(const char *str, int affcnt, int (*putfunc)(int)) {
    (void)str;
    (void)affcnt;
    (void)putfunc;
    return 0;
}
