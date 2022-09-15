#include "duck.h"

struct duck
{
    void * data;
    duck_send_t send;
};

const unsigned long sizeof_duck = sizeof(struct duck);

void duck_initialize(duck_t self, void * data, duck_send_t send)
{
    self->data = data;
    self->send = send;
}

void duck_invoke(duck_t self, va_list args) {
    self->send(self->data, args);
}

void duck_send(duck_t self, ...) {
    va_list args;
    va_start(args, self);
    duck_invoke(self, args);
    va_end(args);
}