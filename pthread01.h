typedef struct {
  pthread_t		thread_tid;		/* thread ID */
  /*long			thread_count;	 # connections handled */
} Thread;
Thread	*tptr;		/* array of Thread structures; calloc'ed */

int				listenfd, nthreads;
pthread_mutex_t mylock;
/*socklen_t		addrlen; use in future */
