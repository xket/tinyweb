/*
 * pthreads wrapper functions.
 */
 
#include	"./tinythread.h"

void Pthread_create(pthread_t *tidp, pthread_attr_t *attrp, 
		    void * (*routine)(void *), void *argp) 
{
    int rc;

    if ((rc = pthread_create(tidp, attrp, routine, argp)) != 0)
		  posix_error(rc, "Pthread_create error");
}

void Pthread_mutex_lock(pthread_mutex_t *mptr)  
{  
    int n = pthread_mutex_lock(mptr);  
    if ( n == 0 )  
        return;    
    unix_error("pthread_mutex_lock error");  
}  

void Pthread_mutex_unlock(pthread_mutex_t *mptr)  
{  
    int n = pthread_mutex_unlock(mptr);  
    if ( n == 0 )  
        return;   
    unix_error("pthread_mutex_unlock error");  
}  
