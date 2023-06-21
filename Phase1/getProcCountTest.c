#include "types.h"
#include "stat.h"
#include "user.h"

int main(void){
    int res = getProcCount();
    printf(1, "%d Processes are Executing.\n" ,res);
    
    printf(1, "Successful\n");
    exit();
}
