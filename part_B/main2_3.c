#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <syslog.h>

int main()
{
    pid_t pid = fork();
    if (pid == 0)
    {
        chdir("/");

        setsid();
        printf("start deamon\n");

        close(stdout);
        close(stdin);
        close(stderr);

        openlog("myDeamon", LOG_PID, LOG_DAEMON);
        syslog(LOG_NOTICE, "daemon started");
        usleep(3000000);
        syslog(LOG_NOTICE, "work..");
        usleep(3000000);
        syslog(LOG_NOTICE, "finishd");
    }
    else
    {
        printf("daemon PID %d\n", pid);
    }
    return 0;
}