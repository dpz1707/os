#include <linux/init.h>
#include <linux/module.h>
#include <linux/jiffies.h>
#include <linux/ktime.h>
#include <linux/timekeeping.h>
MODULE_LICENSE("Dual BSD/GPL");  





unsigned long startJiffyTime;  // jiffies time
ktime_t startKtime;           // ktime time
int hello_init(void)
{
    // get time values at module insertion
    startJiffyTime = jiffies;  
    startKtime = ktime_get_boottime(); 

    int startJiffyTimeMs = (int) jiffies_to_msecs(startJiffyTime);
    int startKtimeMs = (int) (ktime_to_ns(startKtime) / 1000000); // could not think of easier way to get ms

    printk(KERN_ALERT "Hello, world\n");
    printk(KERN_ALERT "Jiffy start time: %d\n", startJiffyTimeMs);
    printk(KERN_ALERT "Ktime start time: %d\n", startKtimeMs);

    return 0;
}



void hello_exit(void)
{
    unsigned long endJiffyTime = jiffies;  
    ktime_t endKtime = ktime_get_boottime();  
    int elapsedJiffy = (int) jiffies_to_msecs(endJiffyTime - startJiffyTime);
    int elapsedKTime = (int) ((ktime_to_ns(endKtime) - ktime_to_ns(startKtime)) / 1000000); 


    printk(KERN_ALERT "Goodbye, cruel world\n");
    printk(KERN_ALERT "Jiffy elapsed time: %d\n", elapsedJiffy);
    printk(KERN_ALERT "KTime elapsed time: %d\n", elapsedKTime);
}


module_init(hello_init);
module_exit(hello_exit);
