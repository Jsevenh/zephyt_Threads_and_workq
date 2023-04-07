#ifndef THREADS_H

#define THREADS_H
#include"sys_deps.h"

#define STACK_SIZE 1024
#define STACKSIZE STACK_SIZE
#define THREAD0_PRIORITY 2 
#define THREAD1_PRIORITY 3
#define WORKQ_PRIORITY   4

// define work queue parameters
K_THREAD_STACK_DEFINE(workq_stack,512);
// queue to hold a list of un processed work
struct k_work_q offload_work_q;

struct work_info{
        struct k_work work;
        char name[25];
 }my_work;
// function declarations 
void blink_1();
void blink_2();
void offload_function(struct k_work *work_term);
void thread0(void);
void thread1(void);
void emulate_work();

#endif