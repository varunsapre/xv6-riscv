#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main (int argc, char *argv[])
{
    int n = 0;
    if (argc >= 2) n = atoi (argv[1]);

    int ret;
    ret = info(n);
    printf("return value: %d\n",ret);
    printf("----------\n");
    if (ret == -1) 
    {
        exit(-1);
    }

    exit(1);
}