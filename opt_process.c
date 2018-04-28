

#include "getopt.h"
#include "misc.h"

extern int opt_process_one(struct opt_entry *list, opt_flags *flg, char *opt);
extern char *opt_errors[];


void opt_process(struct opt_entry *list, opt_flags *flg, char **argv)
{
	struct opt_entry *lp;
	char **opt;
	int res;

	/* Clear Jumbo dupe-check in case we're resuming */
	if ((lp = list))
	while (lp->name)
		lp++->param_set = 0;

	if (*(opt = argv))
	while (*++opt)
	if ((res = opt_process_one(list, flg, *opt))) {
//		if (john_main_process)
			fprintf(stderr, "%s: \"%s\"\n", opt_errors[res], *opt);
//		error();
		error(__FILE__, __LINE__);
	}
}
