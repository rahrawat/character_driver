#include"header.h"
#include"decl.h"
//#include"fileop.h"
struct QSET *lqset;
ssize_t write_dev(struct file *filep, const char __user *buff, size_t count, loff_t *loff)
{
	struct dev *ldev;
	int not ,noq, q;
	ldev = NULL;
#ifdef DEBUG
	printk(KERN_INFO "BEGIN:  %s \n",__func__);
#endif
	noq = count /(qset_size * quantum_size);
	if(count %(qset_size * quantum_size))
	{
		noq++;
	}
	ldev = filep -> private_data;
	if(!ldev)
		goto OUT;

	lqset = create_scull(ldev , noq);
	printk ("in %s address is %p \n",__func__,lqset);
	printk("in %s address is %p \n",__func__,ldev -> qset);
	for( q = 0 ;q < noq; q++)
	{
		for()	
		not = copy_from_user(*(lqset->data) , buff , (qset_size * quantum_size) );	
		printk("%d\n",not );
		
		if( ( lqset = lqset->next) == NULL)
			break;
	}

#ifdef DEBUG
	printk(KERN_INFO "end:  %s \n",__func__);
#endif
	return 0;
OUT:
#ifdef DEBUG
	printk(KERN_INFO "error:  end:  %s \n",__func__);
#endif
	return -1;
}

