#include "types.h"
#include "stat.h"
#include "user.h"

int main(void){
    int res = getReadCount();
    printf(1, "Read System Call was Called %d Times.\n", res);
    
    printf(1, "Successful\n");
    exit();
}
