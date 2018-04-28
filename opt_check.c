

#include "getopt.h"
#include "misc.h"

extern char *opt_errors[];
extern char *completed, *completed_param;
extern int opt_check_one(struct opt_entry *list, opt_flags flg, char *opt);

void opt_check(struct opt_entry *list, opt_flags flg, char **argv)
{
	char **opt;
	int res;

	if (*(opt = argv))
	while (*++opt) {
		if ((res = opt_check_one(list, flg, *opt))) {
//			if (john_main_process)
				fprintf(stderr, "%s: \"%s\"\n",
				        opt_errors[res], *opt);
//			error();
			error(__FILE__, __LINE__);
		}
		/* Alter **argv to reflect to full option names */
		else if (*opt[0] == '-') {
			int len = strlen(completed) + 2 + 1;
			if (completed_param)
				len += strlen(completed_param) + 1;
			*opt = (char *)mem_alloc_tiny(len, MEM_ALIGN_NONE);
			sprintf(*opt, "--%s%s%s", completed,
			        completed_param ? "=" : "",
			        completed_param ? completed_param : "");
		}
	}
}
