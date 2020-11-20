

#include <string.h>
#include "getoptlib.h"

extern char *completed, *completed_param;


char *opt_find(struct opt_entry *list, char *opt, struct opt_entry **entry)
{
	char *name, *param;
	size_t length;
	struct opt_entry *found;

	if (opt[0] == '-') {
		if (*(name = opt + 1) == '-') name++;
		if (!(param = strchr(name, '=')))
			param = strchr(name, ':');
		if (param) {
			char *c = strchr(name, ':');
			if (c && param > c)
				param = c;
			length = param - name;
			if (!*++param) param = NULL;
		} else
			length = strlen(name);

		found = NULL;
		do {
			if (length <= strlen(list->name))
			if (!strncmp(name, list->name, length)) {
				if (!found) {
					found = list;
					if (length == strlen(list->name))
						break;
				} else {
					*entry = NULL;
					return NULL;
				}
			}
		} while ((++list)->name);

		if ((*entry = found))
		{
			completed = found->name;
			completed_param = param;
			return param;
		}
		else
			return NULL;
	} else {
//		*entry = list;
//		return opt;
		return NULL;
	}
}
