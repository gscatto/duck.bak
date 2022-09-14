#include "gs_object.h"

#include <assert.h>

int captured;

void capture_42(void *data, va_list args)
{
    captured = 42;
}

void capture_data(void *data, va_list args)
{
    captured = (int)data;
}

void capture_first_arg_as_int(void *data, va_list args)
{
    captured = va_arg(args, int);
}

void gs_object_test_capture_constant()
{
    gs_object_define(o);
    gs_object_initialize(o, 0, capture_42);

    captured = 0;
    gs_object_send(o);
    assert(captured == 42);
}

void gs_object_test_capture_data()
{
    gs_object_define(o);
    gs_object_initialize(o, (void *)123, capture_data);

    captured = 0;
    gs_object_send(o);
    assert(captured == 123);
}

void gs_object_test_capture_argument()
{
    gs_object_define(o);
    gs_object_initialize(o, (void *)123, capture_first_arg_as_int);

    captured = 0;
    gs_object_send(o, 13);
    assert(captured == 13);
}

void gs_object_test()
{
    gs_object_test_capture_constant();
    gs_object_test_capture_data();
    gs_object_test_capture_argument();
}