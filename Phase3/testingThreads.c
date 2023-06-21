#include "types.h"
#include "stat.h"
#include "user.h"

int x = 0;

void childCounter(){
    while(x < 20){
        x++;
        sleep(100);
    }
}

int
main(){

    // int id = fork();
    int id = thread_create(&childCounter, 0);

    if(id < 0){ //Failed
        printf(1, "Creating Child Failed!\n");

    } 

    while(x < 20){
        printf(1, "x = %d \n", x);
        sleep(100);
    }

    printf(1, "Waiting to be Done...\n");

    thread_join();

    printf(1, "Thread Done. x = %d\n", x);

    exit();
}
