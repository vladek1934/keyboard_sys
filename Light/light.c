
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/ioctl.h>
#include <linux/workqueue.h>
#include <linux/interrupt.h>
#include <asm/io.h>

typedef unsigned char byte;
struct color
{
    byte R;
    byte G;
    byte B;
};

void *HANDLER_KEY;

irqreturn_t irq_handler(int irq, void *dev_id)
{
    /*
* This variables are static because they need to be
* accessible (through pointers) to the bottom half routine.
*/

    static unsigned char scancode;
    unsigned char status;

    /*
* Read keyboard status
*/
    status = inb(0x64);
    scancode = inb(0x60);

    struct color newcolor;

    switch (scancode)
    {
    case 0x02:
        printk(KERN_INFO "! You pressed 1 and selected the left part, no color ...\n");
        region = 1;
        newcolor->red = 0;
        newcolor->green = 0;
        newcolor->blue = 255;
        break;
    case 0x03:
        printk(KERN_INFO "! You pressed 2 and selected the left part, red color ...\n");
        region = 1;
        newcolor->red = 255;
        newcolor->green = 0;
        newcolor->blue = 0;
        break;
    case 0x04:
        printk(KERN_INFO "! You pressed 3 and selected the left part, green color ...\n");
        region = 1;
        newcolor->red = 0;
        newcolor->green = 255;
        newcolor->blue = 0;
        break;
    case 0x05:
        printk(KERN_INFO "! You pressed 4 and selected the left part, blue color ...\n");
        region = 1;
        newcolor->red = 0;
        newcolor->green = 0;
        newcolor->blue = 255;
        break;
    case 0x06:
        printk(KERN_INFO "! You pressed 5 and selected the middle part, no color ...\n");
        region = 1;
        newcolor->red = 0;
        newcolor->green = 0;
        newcolor->blue = 255;
        break;
    case 0x07:
        printk(KERN_INFO "! You pressed 6 and selected the middle part, red color ...\n");
        region = 1;
        newcolor->red = 255;
        newcolor->green = 0;
        newcolor->blue = 0;
        break;
    case 0x08:
        printk(KERN_INFO "! You pressed 7 and selected the middle part, green color ...\n");
        region = 1;
        newcolor->red = 0;
        newcolor->green = 255;
        newcolor->blue = 0;
        break;
    case 0x09:
        printk(KERN_INFO "! You pressed 8 and selected the middle part, blue color ...\n");
        region = 1;
        newcolor->red = 0;
        newcolor->green = 0;
        newcolor->blue = 255;
        break;
    case 0x0A:
        printk(KERN_INFO "! You pressed 9 and selected the right part, no color ...\n");
        region = 1;
        newcolor->red = 0;
        newcolor->green = 0;
        newcolor->blue = 255;
        break;
    case 0x0B:
        printk(KERN_INFO "! You pressed 0 and selected the right part, red color ...\n");
        region = 1;
        newcolor->red = 255;
        newcolor->green = 0;
        newcolor->blue = 0;
        break;
    case 0x0C:
        printk(KERN_INFO "! You pressed - and selected the right part, green color ...\n");
        region = 1;
        newcolor->red = 0;
        newcolor->green = 255;
        newcolor->blue = 0;
        break;
    case 0x0D:
        printk(KERN_INFO "! You pressed = and selected the right part, blue color ...\n");
        region = 1;
        newcolor->red = 0;
        newcolor->green = 0;
        newcolor->blue = 255;
        break;
    default:
        break;
    }


    byte buffer[8];
    buffer[0] = 1;
    buffer[1] = 2;
    buffer[2] = 64;
    buffer[3] = part;
    buffer[4] = newcolor.R;
    buffer[5] = newcolor.G;
    buffer[6] = newcolor.B;

    int device_handle = open(path, O_RDWR);
    ioctl(device_handle, HIDIOCSFEATURE(8), buffer);

    return IRQ_HANDLED;
}

/*
* Initialize the module - register the IRQ handler
*/
static int __init irq_ex_init(void)
{
    HANDLER_KEY = (void *)(irq_handler);
    /* Free interrupt*/
    free_irq(1, NULL);
    /*
    * Request IRQ 1, the keyboard IRQ, to go to our irq_handler.
    */
    return request_irq(1, (irq_handler_t)irq_handler, IRQF_SHARED, "test_keyboard_irq_handler", HANDLER_KEY);
}

static void __exit irq_ex_exit(void)
{
    printk(KERN_INFO "! Module is unload... \n");
    free_irq(1, HANDLER_KEY);
}

module_init(irq_ex_init);
module_exit(irq_ex_exit);