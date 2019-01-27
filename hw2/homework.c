/* 
 * file:        homework.c
 * description: Skeleton code for CS 5600 Homework 2
 *
 * Peter Desnoyers, Northeastern CCIS, 2011
 * $Id: homework.c 530 2012-01-31 19:55:02Z pjd $
 */

#include <stdio.h>
#include <stdlib.h>
#include "hw2.h"

void print_barber_sleep(){
    printf("DEBUG: %f barber goes to sleep\n", timestamp());
}

void print_barber_wakes_up(){
    printf("DEBUG: %f barber wakes up\n", timestamp());
}

void print_customer_enters_shop(int customer){
    printf("DEBUG: %f customer %d enters shop\n", timestamp(), customer);
}

void print_customer_starts_haircut(int customer){
    printf("DEBUG: %f customer %d starts haircut\n", timestamp(), customer);
}

void print_customer_leaves_shop(int customer){
    printf("DEBUG: %f customer %d leaves shop\n", timestamp(), customer);
}

/********** YOUR CODE STARTS HERE ******************/

/*
 * Here's how you can initialize global mutex and cond variables
 */
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t C = PTHREAD_COND_INITIALIZER;

/* the barber method
 */
void barber(void)
{
    pthread_mutex_lock(&m);
    while (1) {
        /* your code here */
    }
    pthread_mutex_unlock(&m);
}

/* the customer method
 */
void customer(int customer_num)
{
    pthread_mutex_lock(&m);
    /* your code here */
    pthread_mutex_unlock(&m);
}

/* Threads which call these methods. Note that the pthread create
 * function allows you to pass a single void* pointer value to each
 * thread you create; we actually pass an integer (the customer number)
 * as that argument instead, using a "cast" to pretend it's a pointer.
 */

/* the customer thread function - create 10 threads, each of which calls
 * this function with its customer number 0..9
 */
void *customer_thread(void *context) 
{
    int customer_num = (int)context; 

    /* your code goes here */
    
    return 0;
}

/*  barber thread
 */
void *barber_thread(void *context)
{
    barber(); /* never returns */
    return 0;
}

void q2(void)
{
    /* to create a thread:
        pthread_t t; 
        pthread_create(&t, NULL, function, argument);
    */

    /* your code goes here */
    
}

/* For question 3 you need to measure the following statistics:
 *
 * 1. fraction of  customer visits result in turning away due to a full shop 
 *    (calculate this one yourself - count total customers, those turned away)
 * 2. average time spent in the shop (including haircut) by a customer 
 *     *** who does not find a full shop ***. (timer)
 * 3. average number of customers in the shop (counter)
 * 4. fraction of time someone is sitting in the barber's chair (counter)
 *
 * The stat_* functions (counter, timer) are described in the PDF. 
 */

void q3(void)
{
    /* your code goes here */
}
