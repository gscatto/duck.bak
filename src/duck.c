#include "duck.h"

struct duck
{
    void *data;
    duck_send_t send;
};

const unsigned long sizeof_duck = sizeof(struct duck);

void * duck_default_send_fn(duck_t self, va_list args) {

}

void duck_initialize(duck_t self)
{
    self->data = 0;
    self->send = duck_default_send_fn;
}

void duck_set_data(duck_t self, void *it)
{
    self->data = it;
}

void duck_set_send_fn(duck_t self, duck_send_t it)
{
    self->send = it;
}

void duck_invoke(duck_t self, va_list args)
{
    self->send(self->data, args);
}

void duck_send(duck_t self, ...)
{
    va_list args;
    va_start(args, self);
    duck_invoke(self, args);
    va_end(args);
}