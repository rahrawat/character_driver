#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/fs.h>
#include<linux/slab.h>
#include<linux/cdev.h>
#include<linux/moduleparam.h>
#include<linux/uaccess.h>

MODULE_LICENSE("GPL");

#ifndef DEVICE
#define DEVICE "R_DRIVER"
#endif

#ifndef DEBUG
#define DEBUG
#endif

#ifndef DEV_SIZE
#define DEV_SIZE 1024
#endif

#ifndef DATA_SIZE
#define DATA_SIZE 0
#endif

#ifndef QSET_SIZE
#define QSET_SIZE 3
#endif

#ifndef QUANTUM_SIZE
#define QUANTUM_SIZE 8
#endif





