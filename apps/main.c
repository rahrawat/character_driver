#include"header.h"
int open_device();
int close_device( int );
int write_device( int );
int main()
{
	int choice, fd=0;
	while(1)
	{
		printf("---------------MAIN MENU----------------------\n");
		printf("1. open\n");
		printf("2. write\n");
		printf("3. close\n");

		printf("0.exit\n");
		printf("enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				fd=open_device();
				printf("fd = %d\n",fd);
				break;
			case 2:
				write_device(fd);
				break;
			case 3:
				close_device(fd);
				break;
			case 0:
				exit(0);
				break;
			default:
				printf("wrong choice\n");
		}
	}
	return 0;
}


int open_device()
{
	int fd;
	fd = open("node", O_WRONLY);
	printf("fd = %d\n",fd);
	if( fd < 0 )
	{
		perror("open\n");
		return fd;
	}
	return fd;
}


int close_device(int fd)
{
	close(fd);
}


int write_device(int fd)
{
	int count ,l ;
	char arr[]="RAHUL  -------------------------------------------------------------------------------------------```";
	l = strlen(arr);
	count = write(fd , arr , l);
	perror("write\n");
	printf("%d\t bits written\n" ,count );

}
