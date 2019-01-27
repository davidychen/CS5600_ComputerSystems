/*
 * file:        qthread.c
 * description: assignment - simple emulation of POSIX threads
 * class:       CS 5600, Spring 2018
 */

/* a bunch of includes which will be useful */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <sys/time.h>
#include <fcntl.h>
#include <sys/select.h>
#include <errno.h>
#include "qthread.h"

struct qthread{
    /* your code here */
};

/* prototypes for stack.c and switch.s
 * see source files for additional details
 */
extern void switch_to(void **location_for_old_sp, void *new_value);
extern void *setup_stack(int *stack, void *func, void *arg1, void *arg2);

/* qthread_start, qthread_create - see video for difference.
 * (function passed to qthread_create is allowed to return)
 */
qthread_t qthread_start(void (*f)(void*, void*), void *arg1, void *arg2){
    /* your code here */
    return NULL;
}

qthread_t qthread_create(void* (*f)(void*), void *arg1){
    /* your code here */
    return NULL;
}


/* see the video for description */
void schedule(void *save_location){
    /* your code here */
}

/* qthread_run - run until the last thread exits
 */
void qthread_run(void){
    /* your code here */
}

/* qthread_yield - yield to the next runnable thread.
 */
void qthread_yield(void){
}

/* qthread_exit, qthread_join - exit argument is returned by
 * qthread_join. Note that join blocks if thread hasn't exited yet,
 * and may crash if thread doesn't exist.
 */
void qthread_exit(void *val){
    /* your code here */
}

void *qthread_join(qthread_t thread){
    /* your code here */
}

/* qthread_mutex_init/lock/unlock
 */
void qthread_mutex_init(qthread_mutex_t *mutex){
    /* your code here */
}

void qthread_mutex_lock(qthread_mutex_t *mutex){
    /* your code here */
}

void qthread_mutex_unlock(qthread_mutex_t *mutex){
    /* your code here */
}

/* qthread_cond_init/wait/signal/broadcast
 */
void qthread_cond_init(qthread_cond_t *cond){
    /* your code here */
}

void qthread_cond_wait(qthread_cond_t *cond, qthread_mutex_t *mutex){
    /* your code here */
}

void qthread_cond_signal(qthread_cond_t *cond){
    /* your code here */
}

void qthread_cond_broadcast(qthread_cond_t *cond){
    /* your code here */
}

/* POSIX replacement API. These are all the functions (well, the ones
 * used by the sample application) that might block.
 *
 * If there are no runnable threads, your scheduler needs to block
 * waiting for one of these blocking functions to return. You should
 * probably do this using the select() system call, indicating all the
 * file descriptors that threads are blocked on, and with a timeout
 * for the earliest thread waiting in qthread_usleep()
 */

/* You'll need to tell time in order to implement qthread_usleep.
 * Here's an easy way to do it. 
 */
static unsigned get_usecs(void){
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec*1000000 + tv.tv_usec;
}

/* qthread_usleep - yield to next runnable thread, making arrangements
 * to be put back on the active list after 'usecs' timeout. 
 */
void qthread_usleep(long int usecs){
    /* your code here */
}

/* make sure that the file descriptor is in non-blocking mode, try to
 * read from it, if you get -1 / EAGAIN then add it to the list of
 * file descriptors to go in the big scheduling 'select()' and switch
 * to another thread.
 */
ssize_t qthread_io(ssize_t (*op)(int, void*, size_t), int fd, void *buf, size_t len){
    /* set non-blocking mode every time. If we added some more
     * wrappers we could set non-blocking mode from the beginning, but
     * this is a lot simpler (if less efficient). Do this for _write
     * and _accept, too.
     */
    int val, tmp = fcntl(fd, F_GETFL, 0);
    fcntl(fd, F_SETFL, tmp | O_NONBLOCK);

    /* your code here */
}

ssize_t qthread_read(int fd, void *buf, size_t len){
    /* your code here */
    return 0;
}

ssize_t qthread_recv(int sockfd, void *buf, size_t len, int flags){
    return qthread_read(sockfd, buf, len);
}

/* like read - make sure the descriptor is in non-blocking mode, check
 * if if there's anything there - if so, return it, otherwise save fd
 * and switch to another thread. Note that accept() counts as a 'read'
 * for the select call.
 */
int qthread_accept(int fd, struct sockaddr *addr, socklen_t *addrlen){
    /* your code here */
    return 0;
}

/* Like read, again. Note that this is an output, rather than an input
 * - it can block if the network is slow, although it's not likely to
 * in most of our testing.
 */
ssize_t qthread_write(int fd, void *buf, size_t len){
    /* your code here */
}

ssize_t qthread_send(int fd, void *buf, size_t len, int flags){
    return qthread_write(fd, buf, len);
}
