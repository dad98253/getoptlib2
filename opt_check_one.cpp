


#include "getoptlib.h"

extern char *opt_find(struct opt_entry *list, char *opt, struct opt_entry **entry);

int opt_check_one(struct opt_entry *list, opt_flags flg, char *opt)
{
	struct opt_entry *entry;

	opt_find(list, opt, &entry);
	if (!entry) return OPT_ERROR_UNKNOWN;

	if ((flg & entry->req_set) != entry->req_set || (flg & entry->req_clr))
		return OPT_ERROR_COMB;

	return OPT_ERROR_NONE;
}
