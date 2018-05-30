

#ifndef BSD
#include <malloc.h>
#else	// BSD
#include <stdlib.h>
#endif	// BSD
#ifdef WINDOZE
#include <windows.h>
#endif


int posix_memalign(void **memptr, size_t alignment, size_t size) {

//	if ( ( *memptr = (void *)_aligned_malloc(size, alignment) ) == NULL ) {
	if ( ( *memptr = malloc(size) ) == NULL ) {
		return(1);
	}
 
	return (0);
}
