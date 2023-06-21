#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"

int
main(int argc,char **argv)
{
    int pid1, pid2, res;
    
    pid1 = fork();
    

    if(pid1 > 0){
        pid2 = fork();

        if(pid2 == 0){
            res = getProcTick(pid1);
            if(res >= 0)
                printf(1, "%d Ticks have passed from when process (pid=%d) was created.\n", res, pid1); 
            else
                printf(1, "Error! Process not found.\n");
            
        } else 
            wait();
        
        wait();

    } else {
        sleep(50);
        printf(1, "Process is done.\n");
    }

    exit();
}