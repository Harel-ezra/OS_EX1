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
    //process one
    // child
    pid_t pid = fork();
    if (pid == 0)
    {
        //process tow
        // grand child
        pid_t pid1 = fork();
        if (pid1 == 0)
        {
            print("grand child");
            
        }
        else
        {
            print("child");
        }
    }
    else
    {
        print("parent");
    }
    return 0;
}