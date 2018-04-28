#include <stdlib.h>

void real_error(char *file, int line)
{
#ifndef _JOHN_MISC_NO_LOG
	log_event("Terminating on error, %s:%d", file, line);
	log_done();
#endif

	exit(1);
}
