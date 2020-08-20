#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>

/* Try to open shared library
 * Command line syntax:
 *
 * $ my_test /usr/lib/x86_64-linux-gnu/libm.so.6
 *
 */
int main(int argc, char **argv) {
    if (argc != 2) {
        printf( "Bad arguments!\n" );
        exit(1);
    }
    char *lib_path = argv[1];
    double (*cosine)(double);
    char *error;

    void *handle = dlopen (lib_path, RTLD_LAZY);
    if (!handle) {
        fputs (dlerror(), stderr);
        exit(1);
    }

    printf( "Success!\n" );
    //cosine = dlsym(handle, "cos");
    //if ((error = dlerror()) != NULL)  {
    //    fputs(error, stderr);
    //    exit(1);
    //}
    //printf ("%f\n", (*cosine)(2.0));
    dlclose(handle);
}
