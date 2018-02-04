 const struct file_operations fopsi={
 	open	:  open_dev,
 	release	: close_dev,
	write   : write_dev
 
 };

