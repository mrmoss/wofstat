#include <iostream>
#include <sys/sysctl.h>
#include <sys/socket.h>

#define PF_LIST_INET	1

#ifdef INET6
	#define PF_LIST_INET6	2
#endif

int main()
{
	int name=-;
	size_t size=CTL_MAXNAME;
	std::cout<<"sysctlnametomib  "<<sysctlnametomib("net.inet.tcp.pcblist",&name,&size)<<std::endl;

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