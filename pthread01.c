#include	"./tinyweb.h"
#include	"./pthread01.h"

void
thread_make(int i)
{
	void	*thread_main(void *);

	Pthread_create(&tptr[i].thread_tid, NULL, &thread_main, (void *) i);
	return;		/* main thread returns */
}

void *
thread_main(void *arg)
{
	int				connfd;
	void			request_process(int);
	
	printf("thread %d starting\n", (int) arg); /* ? potential problem,not thread  safe*/
	for ( ; ; ) {
    	Pthread_mutex_lock(&mlock);
		connfd = Accept(listenfd, (SA*)NULL, NULL);
		Pthread_mutex_unlock(&mlock);
		//tptr[(int) arg].thread_count++;   using in future
		request_process(connfd);		/* process request */
		Close(connfd);
	}
}
