#include"header.h"
#include"decl.h"
//#include"fileop.h"

int open_dev(struct inode *i_node, struct file *file_f )
{
	struct dev *l_dev;
	printk(KERN_INFO " hello this is %s running\n",__func__);
	l_dev = device;


	l_dev = container_of( i_node->i_cdev , struct dev , c_dev );
	if(l_dev == NULL)
	{
		printk(KERN_ERR " container_of failed \n" );
		goto out;
	}
	file_f->private_data = l_dev;
	if((file_f->f_flags & O_ACCMODE)==O_WRONLY)
	{
		trim_dev(l_dev);
	}

	return 0;
out:
	printk(KERN_ERR "------ error------ \n" );

	return -1;
}

