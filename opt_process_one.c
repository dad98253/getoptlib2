
#include <stdio.h>
#include "getopt.h"

extern char *completed, *completed_param;
extern char *opt_find(struct opt_entry *list, char *opt, struct opt_entry **entry);
extern int opt_process_param(char *param, char *format, void *buffer);

#define FLG_ZERO			0x0

int opt_process_one(struct opt_entry *list, opt_flags *flg, char *opt)
{
	char *param;
	struct opt_entry *entry;

	completed = NULL;

	param = opt_find(list, opt, &entry);
	if (!entry) return OPT_ERROR_UNKNOWN;

	if (*flg & entry->flg_set & entry->flg_clr) return OPT_ERROR_COMB;

	*flg &= ~entry->flg_clr;
	*flg |= entry->flg_set;

	if (entry->format) {
		if (!param) {
			if (entry->req_clr & OPT_REQ_PARAM)
				return OPT_ERROR_PARAM_REQ;
		} else
		if (opt_process_param(param, entry->format, entry->param))
			return OPT_ERROR_PARAM_INV;

		/* Dupe checking without an option flag */
		if (param && entry->flg_set == FLG_ZERO &&
		    entry->req_clr & OPT_REQ_PARAM && entry->param_set++)
			return OPT_ERROR_COMB;
	} else
	if (param) return OPT_ERROR_PARAM_EXT;

	return OPT_ERROR_NONE;
}
