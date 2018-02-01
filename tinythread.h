/* Our own header for the programs that use threads.
   Include this file, instead of "tinyweb.h". */
   
#ifndef	__tinyweb_pthread_h
#define	__tinyweb_pthread_h

#include	"./tinyweb.h"

void Pthread_create(pthread_t *, const pthread_attr_t *,
					   void * (*)(void *), void *);
void Pthread_mutex_lock(pthread_mutex_t *mptr);
void Pthread_mutex_unlock(pthread_mutex_t *mptr);

#endif	/* __tinyweb_pthread_h */
