#include "gs_object.h"

#include <assert.h>
#include <string.h>

int value;

void capture_42(void *data, va_list args)
{
    value = 42;
}

void capture_data(void *data, va_list args)
{
    value = (int)data;
}

void capture_first_arg_as_int(void *data, va_list args)
{
    value = va_arg(args, int);
}

void gs_object_test_capture_constant()
{
    gs_object_define(o);
    gs_object_initialize(o, 0, capture_42);

    value = 0;
    gs_object_send(o);
    assert(value == 42);
}

void gs_object_test_capture_data()
{
    gs_object_define(o);
    gs_object_initialize(o, (void *)123, capture_data);

    value = 0;
    gs_object_send(o);
    assert(value == 123);
}

void gs_object_test_capture_argument()
{
    gs_object_define(o);
    gs_object_initialize(o, (void *)123, capture_first_arg_as_int);

    value = 0;
    gs_object_send(o, 13);
    assert(value == 13);
}

void adder(void *data, va_list args)
{
    const char * method = va_arg(args, const char *);
    if (strcmp(method, "inc") == 0)
        value++;
    else if (strcmp(method, "dec") == 0)
        value--;
}

void gs_object_test_example_adder()
{
    gs_object_define(o);
    gs_object_initialize(o, 0, adder);

    value = 0;
    gs_object_send(o, "inc");
    gs_object_send(o, "inc");
    assert(value == 2);
    gs_object_send(o, "dec");
    assert(value == 1);
}

void gs_object_test()
{
    gs_object_test_capture_constant();
    gs_object_test_capture_data();
    gs_object_test_capture_argument();
    gs_object_test_example_adder();
}