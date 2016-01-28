#include <iostream>
#include <string>
#include <stdint.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

//mode_t   st_mode;          /* File mode (see mknod(2)) */
//ino_t    st_ino;           /* Inode number */
//dev_t    st_dev;           /* ID of device containing */
                                 /* a directory entry for this file */
//dev_t    st_rdev;          /* ID of device */
                                 /* This entry is defined only for */
                                 /* char special or block special files */
//nlink_t  st_nlink;         /* Number of links */
//uid_t    st_uid;           /* User ID of the file's owner */
//gid_t    st_gid;           /* Group ID of the file's group */
//off_t    st_size;          /* File size in bytes */
//time_t   st_atime;         /* Time of last access */
//time_t   st_mtime;         /* Time of last data modification */
//time_t   st_ctime;         /* Time of last file status change */
                                 /* Times measured in seconds since */
                                 /* 00:00:00 UTC, Jan. 1, 1970 */
//long     st_blksize;       /* Preferred I/O block size */
//blkcnt_t st_blocks;        /* Number of 512 byte blocks allocated*/
//char     st_fstype[_ST_FSTYPSZ];

int main()
{
	struct stat buffer;

	if(stat("/proc/1009/fd/5",&buffer)==-1)
	{
		std::cout<<"Error opening."<<std::endl;
		return 1;
	}

	std::cout<<(buffer.st_mode==S_IFSOCK)<<std::endl;

	return 0;
}
