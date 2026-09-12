/* main_dyn.c - loads libutil.so at run time via the dl functions */
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(void)
{
    void *handle;
    void (*p_util_file)(void);
    int  (*p_util_power)(int, int);
    unsigned int (*p_gcd)(unsigned int, unsigned int);
    char *err;

    handle = dlopen("./libutil.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "dlopen error: %s\n", dlerror());
        return 1;
    }

    dlerror();  /* clear any existing error */

    p_util_file  = (void (*)(void)) dlsym(handle, "util_file");
    p_util_power = (int (*)(int, int)) dlsym(handle, "util_power");
    p_gcd        = (unsigned int (*)(unsigned int, unsigned int)) dlsym(handle, "gcd");
    err = dlerror();
    if (err) {
        fprintf(stderr, "dlsym error: %s\n", err);
        dlclose(handle);
        return 1;
    }

    printf("Loaded libutil.so dynamically:\n");
    p_util_file();
    printf("util_power(2, 10) = %d\n", p_util_power(2, 10));
    printf("gcd(48, 36)       = %u\n", p_gcd(48, 36));

    dlclose(handle);
    return 0;
}
