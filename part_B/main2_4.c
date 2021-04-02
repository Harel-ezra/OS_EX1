#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void print(const char *text)
{
    for (int i = 0; i < 20; i++)
    {
        printf("hello from %s\n", text);
        usleep(1000000);
    }
}

int main()
{
    pid_t pid = fork();
    if (pid == 0)
    {
        = char * args1[2] = {"./main2_1", NULL};
        execvp(args1[0], args1);

        char *args2[2] = {"./main2_2", NULL};
        execvp(args2[0], args2);

        char *args3[2] = {"./main2_3", NULL};
        execvp(args3[0], args3);
    }
    else
    {
        print("parent");
    }
    return 0;
}