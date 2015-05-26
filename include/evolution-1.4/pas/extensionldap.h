#define NULL 0
#define LDAP_OPT_SUCCESS        0
#define LDAP_OPT_ERROR          (-1)
#define LDAP_EXOP_START_TLS     "1.3.6.1.4.1.1466.20037"
#define LDAP_OPT_X_TLS_HARD             1
#define LDAP_OPT_X_TLS                          0x6000
#define LDAP_CONST       const

#define LDAP_SCHEMA_STRUCTURAL                    1

#define TK_NOENDQUOTE	-2
#define TK_OUTOFMEM	-1
#define TK_EOS		0
#define TK_UNEXPCHAR	1
#define TK_BAREWORD	2
#define TK_QDSTRING	3
#define TK_LEFTPAREN	4
#define TK_RIGHTPAREN	5
#define TK_DOLLAR	6
#define TK_QDESCR	TK_QDSTRING

#define AC_MEMCPY( d, s, n ) (SAFEMEMCPY((d),(s),(n)))
#define LDAP_DIGIT(c)             ((c) >= '0' && (c) <= '9')
#define LDAP_SPACE(c)             ((c) == ' ' || (c) == '\t' || (c) == '\n')

#define LDAP_RANGE(n,x,y)       (((x) <= (n)) && ((n) <= (y)))
#define LDAP_NAME_ERROR(n)      LDAP_RANGE((n),0x20,0x24)

#include <ldap.h>
#include <lber.h>
#include <string.h>

#include "ldap_cdefs.h"

struct lber_options {
        short lbo_valid;
        unsigned short          lbo_options;
        int                     lbo_debug;
        long            lbo_meminuse;
};


LBER_F( void )
ber_memvfree LDAP_P((
        void** vector ));

LDAP_F( int )
ldap_start_tls_s LDAP_P((
	LDAP *ld,
	LDAPControl **serverctrls,
	LDAPControl **clientctrls ));

