#include"header.h"
#include"decl.h"
struct QSET * create_scull (struct dev *ldev , int noq )
{
	int n , l;
	struct QSET *fqset;
	//	struct QSET *rqset;
	struct QSET *cqset;
#ifdef DEBUG
	printk(" creating SCULL\n");
#endif
	ldev -> qset = kmalloc(sizeof(struct QSET) , GFP_KERNEL);
	if(!ldev->qset)
	{
		printk(KERN_ERR "kmalloc failed");
		goto OUT;
	}	
	cqset = ldev->qset;
	printk("start   cqset %p\n",cqset );
	printk("noq  =  %d\n",noq);
	for(n=0; n < noq-1; n++)
	{
		cqset->data=(void **)kmalloc(sizeof(void *) * qset_size , GFP_KERNEL);
		for(l=0 ; l <  qset_size; l++)
		{
			cqset->data[l] = (void *)kmalloc((quantum_size) , GFP_KERNEL);
		}
		fqset = kmalloc(sizeof(struct QSET) , GFP_KERNEL);
	//	printk(KERN_INFO"-------------------------------------------------------------fqset %p\n",fqset );
		if(!fqset)
		{
			printk(KERN_ERR "kmalloc failed");
			goto OUT;
		}	
		cqset -> next =fqset;
		fqset -> next =NULL;
		cqset = cqset-> next;
	}
	printk("over   cqset %p\n",ldev -> qset );
	n=0;
	//while(1)
	//{
	//if(rqset-> next == NULL)
	//	break;
	//printk("%d\n",n++);

	return ldev->qset;
OUT:
	return NULL;
}
