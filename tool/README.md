FTPMOUNT - FTP File System mounting utility
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Installation Notes
~~~~~~~~~~~~~~~~~~
Build the binary:
    make
    
Install it:
    sudo make install


Usage
~~~~~
The ftpfs module should be loaded (`insmod ftpfs.ko`).

It accepts the following syntax:

    ftpmount [user_name[:password]@]host_name[:host_port][/root_dir] mount_directory [-o]

If there is a user_name but no password, it will prompt for one.
The '-o' flag forces ownership on all files. You want to use this with SERV-U & other dumb servers.

Unmounting is done the usual way:

    umount mount_directory
    

Author
~~~~~~
Florin Malita <mali@users.sourceforge.net>

