#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
    int pid;
    pid=getpid();
    printf("Current Process ID is :: %d\n\n",pid);
    printf("\n[Forking Child Process...]\n\n");
    pid=fork();
    if(pid<0)
    {
        printf("\nProcess Can not be created");
    }
    else
    {
        if(pid==0)
        {
            printf("Child Process is sleeping..........\n\n\n\n");
            sleep(5);
            printf("\n\nOrphan Child's Process ID :: %d",getpid());
        }
        else
        {
            printf("\n\n\n\nParent Process Completed.....\n\n\n\n\n");
        }
    }
}
