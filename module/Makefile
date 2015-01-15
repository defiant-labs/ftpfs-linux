.PHONY: check-syntax

CXX=g++
CC=gcc

EXTRA_CFLAGS=-g3 


obj-m := ftpfs.o

ftpfs-y :=  net.o operations.o super.o

PWD:= $(shell pwd)
KERNEL_SOURCES:= /lib/modules/$(shell uname -r)/build



default:
	$(MAKE) -C $(KERNEL_SOURCES) M=$(PWD) modules

ins: default 
	sudo insmod ftpfs.ko
	sudo mount -t ftpfs n:a@127.0.0.1:tmp tmp
rm:
	sudo umount tmp
	sudo rmmod ftpfs
clean:
	rm -f *.o *.ko *.mod.c .*o.cmd *.s modules.order   Module.symvers

check-syntax:
	gcc  -I $(KERNEL_SOURCES) -o nul -S $(CHK_SOURCES)
