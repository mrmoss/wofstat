#include <iostream>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sys/socket.h>
#include <unistd.h>
#include <pwd.h>
#include <kvm.h>
#include <sys/param.h>
#include <sys/sysctl.h>
#include <sys/user.h>

#define PF_LIST_INET	1

#ifdef INET6
	#define PF_LIST_INET6	2
#endif

int main()
{
	int mib[4];
	size_t len=4;
	kinfo_proc kp;

	std::cout<<sysctlnametomib("kern.proc.pid",mib,&len)<<std::endl;

	for(int ii=0;ii<100;++ii)
	{
		mib[3]=ii;
		len=sizeof(kp);
		if(sysctl(mib,4,&kp,&len,NULL,0)==-1)
			std::cout<<"["<<ii<<"]\tfail"<<std::endl;

		std::cout<<"["<<ii<<"]\tsuccess"<<std::endl;
	}

	return 0;
}

/*void get_sockets(const char *mib)
{
	void *v;
	size_t sz;
	int rc, n, name[CTL_MAXNAME];
	u_int namelen;

	sz = CTL_MAXNAME;
	rc = sysctlnametomib(mib, &name[0], &sz);
	if (rc == -1) {
		if (errno == ENOENT)
			return;
		err(1, "sysctlnametomib: %s", mib);
	}
	namelen = sz;

	name[namelen++] = PF_INET;
	name[namelen++] = 0;		// XXX all pids
	name[namelen++] = 10000
	name[namelen++] = INT_MAX;	// all of them

	sysctl_sucker(&name[0], namelen, &v, &sz);
	n = sz / 10000;
	socket_add_hash(v, n);
}
*/
