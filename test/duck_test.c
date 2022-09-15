#include "duck.h"

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

void duck_test_capture_constant()
{
    duck_define(o);
    duck_initialize(o);
    duck_set_send_fn(o, capture_42);

    value = 0;
    duck_send(o);
    assert(value == 42);
}

void duck_test_capture_data()
{
    duck_define(o);
    duck_set_data(o, (void *)123);

    value = 0;
    duck_send(o);
    assert(value == 123);
}

void duck_test_capture_argument()
{
    duck_define(o);
    duck_initialize(o);
    duck_set_send_fn(o, capture_first_arg_as_int);

    value = 0;
    duck_send(o, 13);
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

void duck_test_example_adder()
{
    duck_define(d);
    duck_initialize(d);
    duck_set_send_fn(d, adder);

    value = 0;
    duck_send(d, "inc");
    duck_send(d, "inc");
    assert(value == 2);
    duck_send(d, "dec");
    assert(value == 1);
}

void duck_test()
{
    duck_test_capture_constant();
    duck_test_capture_data();
    duck_test_capture_argument();
    duck_test_example_adder();
}