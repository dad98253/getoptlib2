

#include "getopt.h"
#include "memory.h"
#include "list.h"


int opt_process_param(char *param, char *format, void *buffer)
{
	if (format[0] == OPT_FMT_STR_ALLOC[0]) {
		*(char **)buffer = str_alloc_copy(param);
		return 0;
	} else
	if (format[0] == OPT_FMT_ADD_LIST[0]) {
		list_add(*(struct list_main **)buffer, param);
		return 0;
	} else
	if (format[0] == OPT_FMT_ADD_LIST_MULTI[0]) {
		list_add_multi(*(struct list_main **)buffer, param);
		return 0;
	} else
		return sscanf(param, format, buffer) != 1;
}
