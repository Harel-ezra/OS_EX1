#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <dlfcn.h>

void (*print_hello)();

bool init_lib()
{
    void *lib = dlopen("./libHello.so", RTLD_LAZY);
    if (NULL == lib)
    {
        return false;
    }
    print_hello = (void (*)())dlsym(lib, "print_hello_ariel");
    if (NULL == print_hello)
    {
        return false;
    }
    return true;
}

int main()
{
    if (init_lib())
    {
        print_hello();
    }
    else
    {
        printf("cant loded lib\n");
    }
    return 0;
}