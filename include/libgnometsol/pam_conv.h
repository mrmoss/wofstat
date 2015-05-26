

#ifndef GNOMETSOL_PAM_CONV_H
#define GNOMETSOL_PAM_CONV_H

#include <glib.h>
#include <security/pam_appl.h>

G_BEGIN_DECLS

/* Not defined in pam headers */
#define GNOME_TSOL_PAM_CANCEL	-1
#define GNOME_TSOL_PAM_SUCCESS	PAM_SUCCESS
#define GNOME_TSOL_PAM_CONV_ERR	PAM_CONV_ERR

/* Structure for appdata passed to conversation function */
typedef	struct conv_info {
	gboolean debug;				/* For debug tracing */
	gboolean sysmodal;			/* Makes the dialog system modal for volatile operations like workspace role su */
	char *prog_name;			/* For syslog and audit purposes */
	char *echoonmsg;			/* Extra message to display to user during PAM_PROMPT_ECHO_ON */
	char *echooffmsg;			/* Extra message to display to user during PAM_PROMPT_ECHO_OFF */
	GdkScreen *screen;  	 /* screen on which to display the dialog */
} conv_info_t;

int
gnometsol_pam_conv(int num_msg, struct pam_message **msg,
           struct pam_response **resp, void *info);

G_END_DECLS

#endif /* GNOMETSOL_PAM_CONV_H */
