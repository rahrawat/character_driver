#include"header.h"
#include"decl.h"
static void __exit end(void)
{	int l;
	printk( KERN_INFO"Goodbye linux\n");
	for( l=0 ; l < nod ;l++)
	{
		cdev_del(&(device[l].c_dev));

	}
	kfree(device);
	unregister_chrdev_region( temp , nod);
}
module_exit(end);
