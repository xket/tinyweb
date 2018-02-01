/* include prethreaded_server.c */
#include	"./tinyweb.h"
#include	"./pthread01.h"

/*strerror:not thread-safe;*/

pthread_mutex_t	mlock = PTHREAD_MUTEX_INITIALIZER;

		 
int
main(int argc, char **argv)
{
	int	connfd, port;
	void	sig_chld(int), thread_make(int);
	
    if (argc != 3) {
	   fprintf(stderr, "usage: %s <port><#threads>\n", argv[0]);
	   exit(1);
    }
    port = atoi(argv[1]);
	
    listenfd = Open_listenfd(port);
	nthreads = atoi(argv[argc-1]);
	tptr = Calloc(nthreads, sizeof(Thread));
	
	/*SIGCHLD handler function*/
	Signal(SIGCHLD, sig_chld);
	
	/*make threads,process request*/
	for (i = 0; i < nthreads; i++)
		thread_make(i);			/* only main thread returns */
	
	for ( ; ; )
		pause();	/* everything done by threads */
}
/* end  */

void
sig_chld(int signo)
{
	pid_t pid;
	int   stat;
	while(pid = waitpid(-1,&stat,WNOHANG)>0)    /*non-blocking,return 0*/
		printf("child %d terminated\n",pid);       /*not async-signal safe ,just for check*/
	return;
}
