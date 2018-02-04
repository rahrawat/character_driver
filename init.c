#include"header.h"
#include"decl.h"
#include"fileop.h"
dev_t temp , temp2;
int nod , error , l;
struct dev *device;
//const struct file_operations fopsi;
module_param( nod , int , S_IRUGO);
	int majorno , dev_size , data_size , qset_size , quantum_size;

static int __init hello(void)
{
	dev_size = DEV_SIZE;
	data_size = DATA_SIZE;
	qset_size = QSET_SIZE;
	quantum_size = QUANTUM_SIZE;
	printk( KERN_INFO "hello linux -from rahul\n");
	printk( KERN_INFO "nod = %d\n",nod);

	error = alloc_chrdev_region( &temp ,0 , nod , DEVICE);
	if(error < 0)
		printk(KERN_ERR "alloc_crrdev_region /n");
	majorno = MAJOR(temp);
#ifdef DEBUG
	printk( KERN_INFO "MAJOR NO IS--%d\n",majorno);
#endif

	device = kmalloc(sizeof(struct dev)*nod , GFP_KERNEL);

	memset(device , '\0' , sizeof(struct dev)*nod);

	for(l=0 ; l < nod; l++)
	{
		device[l].dev_size = dev_size;
		device[l].data_size = data_size;
		device[l].qset_size = qset_size;
		device[l].quantum_size = quantum_size;
		temp2 = MKDEV(majorno , l );
		(device[l]. c_dev).owner= THIS_MODULE;
		(device[l]. c_dev).ops = &fopsi;
		cdev_init(&(device[l].c_dev) , &fopsi);
		cdev_add(&(device[l].c_dev),temp2 , nod );
		printk( KERN_INFO "%d \n" , MINOR(device[l].c_dev.dev ));
	}

	return 0;

}


module_init(hello);
