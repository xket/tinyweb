#ifndef __TinyWeb_H__
#define __TinyWeb_H__

#include <stdio.h> 		/*fprintf,stderr,printf */
#include <stdlib.h> 		/*exit,atoi,setenv */
#include <netinet/in.h> 	/*struct sockaddr_in,INADDR_,htons */
#include <sys/socket.h> 	/*socket,bind,accept,setsockopt */
#include <unistd.h> 		/*fork,close,execve,dup2,STDOUT_FILENO*/
#include <string.h> 		/*bzero,strerror*/
#include <strings.h>		/*strcasecmp*/
#include <errno.h>		/*error */
#include <pthread.h> 		/*pthread_mutex_lock/unlock*/
#include <signal.h> 		/*sigaction*/
#include <sys/wait.h>		/*waitpid*/
#include <sys/types.h>		/*pid_t,fork*/
#include <sys/stat.h>		/*stat,S_ISREG()*/
#include <fcntl.h>		/*open,O_RDONLY*/
#include <sys/mman.h>		/*mmap,munmap*/

/* Misc constants */
#define	MAXLINE	 8192  /* max text line length */
#define MAXBUF   8192  /* max I/O buffer size */
#define LISTENQ  1024  /* second argument to listen() */
   
/* Our own error-handling functions */
void unix_error(char *msg);
void posix_error(int code, char *msg);
			
/* Simplifies calls to bind(), connect(), and accept() */
typedef struct sockaddr SA;

typedef void Sigfunc(int);
Sigfunc *
signal(int signo, Sigfunc *func);

Sigfunc *
Signal(int signo, Sigfunc *func);

/* Persistent state for the robust I/O (Rio) package */
#define RIO_BUFSIZE 8192
typedef struct {
    int rio_fd;                /* descriptor for this internal buf */
    int rio_cnt;               /* unread bytes in internal buf */
    char *rio_bufptr;          /* next unread byte in internal buf */
    char rio_buf[RIO_BUFSIZE]; /* internal buffer */
} rio_t;

/* Rio (Robust I/O) package */
ssize_t rio_readn(int fd, void *usrbuf, size_t n);
ssize_t rio_writen(int fd, void *usrbuf, size_t n);
void rio_readinitb(rio_t *rp, int fd);
ssize_t	rio_readnb(rio_t *rp, void *usrbuf, size_t n);
ssize_t	rio_readlineb(rio_t *rp, void *usrbuf, size_t maxlen);

/* Wrappers for Rio package */
ssize_t Rio_readn(int fd, void *usrbuf, size_t n);
void Rio_writen(int fd, void *usrbuf, size_t n);
void Rio_readinitb(rio_t *rp, int fd);
ssize_t Rio_readnb(rio_t *rp, void *usrbuf, size_t n);
ssize_t Rio_readlineb(rio_t *rp, void *usrbuf, size_t maxlen);

/* Client/server helper functions */
int open_clientfd(char *hostname, int portno);
int open_listenfd(int portno);

/* Wrappers for client/server helper functions */
int Open_clientfd(char *hostname, int port);
int Open_listenfd(int port);

/* Unix I/O wrappers */
int Open(const char *pathname, int flags, mode_t mode);
void Close(int fd);
int Dup2(int fd1, int fd2);

int Accept(int s, struct sockaddr *addr, socklen_t *addrlen);

void	*Calloc(size_t, size_t);
void	*Malloc(size_t);

/* Memory mapping wrappers */
void *Mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset);
void Munmap(void *start, size_t length);

/* Process control wrappers */
pid_t Fork(void);
void Execve(const char *filename, char *const argv[], char *const envp[]);
extern char **environ; /* defined by libc */ 

#endif /* __TinyWeb_H__ */  
