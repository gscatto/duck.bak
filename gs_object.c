#include "gs_object.h"

struct gs_object
{
    void * data;
    gs_object_send_t send;
};

const unsigned long sizeof_gs_object = sizeof(struct gs_object);

void gs_object_initialize(gs_object_t self, void * data, gs_object_send_t send)
{
    self->data = data;
    self->send = send;
}

void gs_object_invoke(gs_object_t self, va_list args) {
    self->send(self->data, args);
}

void gs_object_send(gs_object_t self, ...) {
    va_list args;
    va_start(args, self);
    gs_object_invoke(self, args);
    va_end(args);
}