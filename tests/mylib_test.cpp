#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

#include <iostream>

extern "C"
{
#include "mylib/mylib.h"
}

TEST_GROUP(MYLIB)
{
    mylib dut;

    void setup()
    {
        dut = mylib_create();
    }

    void teardown()
    {
        mylib_destroy(dut);
    }
};

TEST(MYLIB, test1)
{
    FAIL("MYLIB fail");
}
