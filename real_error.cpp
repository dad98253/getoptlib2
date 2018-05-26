#include <stdlib.h>
#include <syslog.h>

void real_error(char *file, int line)
{
#ifndef _JOHN_MISC_NO_LOG
	 openlog("getoptlib2", LOG_PID|LOG_CONS|LOG_NDELAY|LOG_NOWAIT, LOG_USER);
	 syslog(LOG_INFO, "Terminating on error, %s:%d", file, line);
	 closelog();
//	log_event("Terminating on error, %s:%d", file, line);
//	log_done();
#endif

	exit(1);
}
