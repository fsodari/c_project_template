#ifndef MYLIB_H
#define MYLIB_H

typedef struct mylib_struct * mylib;

mylib mylib_create(void);
void mylib_destroy(mylib self);

#endif
