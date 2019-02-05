#include "mylib/mylib.h"
#include <stdlib.h>

struct mylib_struct
{
    int placeholder;
};

mylib mylib_create(void)
{
    mylib self = malloc(sizeof(*self));

    if (self) {
        self->placeholder = 0;
    }

    return self;
}

void mylib_destroy(mylib self)
{
    free(self);
}
