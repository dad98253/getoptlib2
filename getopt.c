/*
 * This file is part of John the Ripper password cracker,
 * Copyright (c) 1996-2000,2003 by Solar Designer
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted.
 *
 * There's ABSOLUTELY NO WARRANTY, express or implied.
 */

#include <stdio.h>
#include <string.h>

//#include "misc.h"
//#include "memory.h"
//                       #include "list.h"
#include "getopt.h"
//#include "john.h"
//#include "memdbg.h"


#define FLG_ZERO			0x0

char *opt_errors[] = {
	NULL,	// No error 
	"Unknown option",
	"Option requires a parameter",
	"Invalid option parameter",
	"Extra parameter for option",
	"Invalid options combination or duplicate option"
};

char *completed, *completed_param;

int optind;


// initialize getoptlib... 

void getopt () {

	return;
}