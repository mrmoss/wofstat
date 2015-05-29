#include <iostream>
#include <sys/types.h>
#include <sys/param.h>
#include <sys/sysctl.h>
#include <sys/socket.h>
#include <sys/socketvar.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <net/route.h>
#include <netinet/in_systm.h>
#include <netinet/ip.h>
#include <netinet/in_pcb.h>
#include <netinet/tcp_fsm.h>
#include <arpa/inet.h>
#include <bitstring.h>
#include <ctype.h>
#include <err.h>
#include <errno.h>
#include <netdb.h>
#include <pwd.h>
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/tcp.h>
#include <netinet/tcp_timer.h>
#include <netinet/tcpip.h>
#include <netinet/tcp_var.h>

#define PF_LIST_INET	1

#ifdef INET6
	#define PF_LIST_INET6	2
#endif

void sysctl_sucker(int *name, u_int namelen, void **vp, size_t *szp);
void get_sockets(const char *mib);

int main()
{
	get_sockets("net.inet6.tcp6.pcblist");
	get_sockets("net.inet6.udp6.pcblist");
	return 0;
}

void sysctl_sucker(int *name, u_int namelen, void **vp, size_t *szp)
{
	int rc;
	void *v;
	size_t sz;

	/* printf("name %p, namelen %u\n", name, namelen); */

	v = NULL;
	sz = 0;
	do {
		rc = sysctl(&name[0], namelen, v, &sz, NULL, 0);
		if (rc == -1 && errno != ENOMEM)
			err(1, "sysctl");
		if (rc == -1 && v != NULL) {
			free(v);
			v = NULL;
		}
		if (v == NULL) {
			v = malloc(sz);
			rc = -1;
		}
		if (v == NULL)
			err(1, "malloc");
	} while (rc == -1);

	*vp = v;
	*szp = sz;
	/* printf("got %zu at %p\n", sz, v); */
}

void get_sockets(const char *mib)
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
	name[namelen++] = sizeof(struct kinfo_pcb);
	name[namelen++] = INT_MAX;	// all of them

	sysctl_sucker(&name[0], namelen, &v, &sz);
	n = sz / sizeof(struct kinfo_pcb);
	socket_add_hash(v, n);
}
