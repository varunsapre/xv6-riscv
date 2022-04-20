#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main (int argc, char *argv[])
{
    // int n = 0;
    // if (argc >= 2) n = atoi (argv[1]);

    int ret;
    printf("passing value to kernel -> %d\n", 1);
    ret = info(1);
    printf("return value: %d\n",ret);
    printf("----------\n");
    
    printf("passing value to kernel -> %d\n", 2);
    ret = info(2);
    printf("return value: %d\n",ret);
    printf("----------\n");

    printf("passing value to kernel -> %d\n", 3);
    ret = info(3);
    printf("return value: %d\n",ret);
    printf("----------\n");
    
    printf("passing value to kernel -> %d\n", 0);
    ret = info(0);
    printf("return value: %d\n",ret);
    printf("----------\n");
    
    exit(0);
}