
#include <stdarg.h>
#include <stdio.h>
#include <stdarg.h>
#include "misc.h"


void real_pexit(char *file, int line, char *format, ...)
{
        va_list args;

#if !defined(_JOHN_MISC_NO_LOG)
#if HAVE_MPI
        if (mpi_p > 1)
                fprintf(stderr, "%u@%s: ", mpi_id + 1, mpi_name);
#endif
#if HAVE_MPI && OS_FORK
        else
#endif
#if OS_FORK
        if (options.fork)
                fprintf(stderr, "%u: ", options.node_min);
#endif
#endif

        va_start(args, format);
        vfprintf(stderr, format, args);
        va_end(args);

//        fprintf(stderr, ": %s\n", strerror(errno));
        fprintf(stderr, ": %s\n", "oops... error !");

        real_error(file, line);
}
