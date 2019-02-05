#include "mylib/mylib.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    mylib obj = mylib_create();
    mylib_destroy(obj);
    printf("Project Name Main Exe!\n");

    return 0;
}
