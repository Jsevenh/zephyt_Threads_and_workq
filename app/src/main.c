// edited by Joseph Mbayi March 30 2023

// trial 1.0 to check on the zephyr multi threading capabilities

#include"../include/sys_deps.h"
#include"../include/threads.h"

 int main()
{
    // check if gpio devices are ready for use
    k_work_queue_init(&offload_work_q);
    if (!gpio_is_ready_dt(&led1))
    {
        printk("pin  %d is not ready name: %s", led1.pin, led1.port->name);
        return 1;
    }
    if (!gpio_is_ready_dt(&led2))
    {
        printk("pin %d is not ready name: %s", led2.pin, led2.port->name);
        return 1;
    }

    // configure gpio pins
    if (gpio_pin_configure_dt(&led1, GPIO_OUTPUT)!=0)
    {
        printk("gpio pin configuration failure");
      return 1;
    }
    if(gpio_pin_configure_dt(&led2,GPIO_OUTPUT)!=0){
        printk("gpio pin configuration failure");
    }
      strcpy(my_work.name, "Thread0 emulate_work()");
       k_work_init(&my_work.work,&offload_function);
    
        /*while(1){
             gpio_pin_toggle_dt(&led1);
             k_msleep(500);

        }*/
    
    return 0;
}

K_THREAD_DEFINE(blink_led1_id,STACK_SIZE,blink_1,NULL,NULL,NULL,2,0,0);
K_THREAD_DEFINE(blink_led2_id,STACK_SIZE,blink_2,NULL,NULL,NULL,4,0,0);

K_THREAD_DEFINE(thread0_id, STACKSIZE, thread0, NULL, NULL, NULL,
		THREAD0_PRIORITY, 0, 0);
        
K_THREAD_DEFINE(thread1_id, STACKSIZE, thread1, NULL, NULL, NULL,
		THREAD1_PRIORITY, 0, 0);