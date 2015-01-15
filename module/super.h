#include <linux/version.h>
#include "ftpfs.h"
#include "net.h"
#include "operations.h"

static ssize_t ftpfs_read_file(struct file *filp, char *buf, size_t count, loff_t *offset);
static ssize_t ftpfs_write_file(struct file *filp, const char *buf, size_t count, loff_t *offset);
#if LINUX_VERSION_CODE < KERNEL_VERSION(3,3,0)
static int ftpfs_create_file(struct inode *inode,struct dentry * dentry, int, struct nameidata *nameidata);
static int ftpfs_mkdir(struct inode *inode, struct dentry* dentry, int mode);
#else
static int ftpfs_create_file(struct inode *inode,struct dentry * dentry, umode_t mode, bool excl);
static int ftpfs_mkdir(struct inode *inode, struct dentry* dentry, umode_t mode);
#endif

static int ftpfs_rmdir(struct inode *inode, struct dentry* dentry);
static int ftpfs_rename(struct inode* inode_src, struct dentry* dentry_src,struct inode* inode_dst, struct dentry* dentry_dst );
static int ftpfs_unlink(struct inode* inode, struct dentry* dentry);