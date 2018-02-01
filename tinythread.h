/* Our own header for the programs that use threads.
   Include this file, instead of "tinyweb.h". */
   
#ifndef	__tinyweb_pthread_h
#define	__tinyweb_pthread_h

#include	"./tinyweb.h"

void	Pthread_create(pthread_t *, const pthread_attr_t *,
					   void * (*)(void *), void *);
void	Pthread_join(pthread_t, void **);

#endif	/* __tinyweb_pthread_h */
