

#include <malloc.h>
#include <windows.h>


int posix_memalign(void **memptr, size_t alignment, size_t size) {

//	if ( ( *memptr = (void *)_aligned_malloc(size, alignment) ) == NULL ) {
	if ( ( *memptr = malloc(size) ) == NULL ) {
		return(1);
	}
 
	return (0);
}