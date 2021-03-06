INSTALLDIR= modules
ifneq ($(KERNELRELEASE),)
	obj-m := drv.o
	drv-objs := init.o exit.o open_dev.o close_dev.o trim_dev.o write_dev.o create_scull.o 

else
	KERNDIR ?= /lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)

default:
	$(MAKE) -C $(KERNDIR) M=$(PWD) modules
	@rm -rf $(INSTALLDIR)
	@mkdir $(INSTALLDIR)
	@mv *.ko *.mod.c *.o .*.cmd $(INSTALLDIR)

clean:
	rm -rf $(INSTALLDIR)

endif

