.PHONY: check-syntax

CC=gcc
EXTRA_CFLAGS=-g3 

obj-m := ftpfs.o
ftpfs-y :=  net.o operations.o super.o

PWD:= $(shell pwd)
KERNEL_SOURCES:= /lib/modules/$(shell uname -r)/build


all:
	$(MAKE) -C $(KERNEL_SOURCES) M=$(PWD) modules

mount:
#	sudo mount -t ftpfs n:a@127.0.0.1:tmp tmp
	mkdir -p /tmp/ftpfs-test-mountpoint
	sudo mount -t ftpfs ftp.cs.brown.edu /tmp/ftpfs-test-mountpoint

umount:
	sudo umount /tmp/ftpfs-test-mountpoint

clean:
	rm -rf *.o *.ko *.mod.c .*.cmd *.s modules.order Module.symvers .tmp*

check-syntax:
	gcc  -I $(KERNEL_SOURCES) -o nul -S $(CHK_SOURCES)
