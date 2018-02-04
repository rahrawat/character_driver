extern dev_t temp;
//extern struct cdev c_dev;
extern int nod, majorno , minorno , device_size , data_size , qset_size , quantum_size;
struct QSET
{
	struct QSET *next;
	void **data;
};
struct dev {
	struct cdev c_dev;
	struct QSET *qset;
	int dev_size;
	int data_size;
	int qset_size;
	int quantum_size;
};
extern struct dev *device;
//extern struct inode i_node;
//extern struct file *file1;
ssize_t write_dev(struct file *, const char __user *, size_t, loff_t *);
int open_dev(struct inode * , struct file *);
int close_dev(struct inode * , struct file *);
int trim_dev(struct dev *);
struct QSET * create_scull(struct dev * , int );



