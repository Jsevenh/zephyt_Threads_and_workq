

#include"../include/threads.h"

//function to blink the first led on pin 25

void blink_1()
{
    while(1)
    {
        gpio_pin_toggle_dt(&led1);
        printk("led2 blinking");
        
        k_msleep(500);
    }
}
// function to blink the second led on pin 5
void blink_2()
{
    while(1)
    {
        gpio_pin_toggle_dt(&led2);
        printk("Led 1 blinking");
       
        k_msleep(500);
    }
}
void emulate_work()
{
	for(volatile int count_out = 0; count_out < 150000; count_out ++);
}

 void offload_function(struct k_work *work_term)
{
    emulate_work();
}


void thread0(void)
{   
    
    uint64_t time_stamp;
    int64_t delta_time;
    // initialize and start work queue
     
      //k_work_queue_start(&offload_work_q,workq_stack,K_KERNEL_STACK_SIZEOF(workq_stack),5,NULL);
      
     
    while (1) {
        time_stamp = k_uptime_get();
        // submit work to user defined work queue
        //k_work_submit_to_queue(&offload_work_q, &my_work.work);
            
        // submit work to the system queue
        k_work_submit(&my_work.work);
        delta_time = k_uptime_delta(&time_stamp);
        printk("thread0 yielding this round in %lld ms\n", delta_time);
        k_msleep(20);
    }
}


void thread1(void)
{
    uint64_t time_stamp;
    int64_t delta_time;
    while (1) {
        time_stamp = k_uptime_get();
        emulate_work();
        delta_time = k_uptime_delta(&time_stamp);
        printk("thread1 yielding this round in %lld ms\n", delta_time);
        k_msleep(20);
    }
}