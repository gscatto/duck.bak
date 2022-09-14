#ifndef GS_OBJECT_H
#define GS_OBJECT_H

#include <stdint.h>
#include <stdarg.h>

struct gs_object;
extern const unsigned long sizeof_gs_object;
typedef struct gs_object *gs_object_t;

#define gs_object_define(NAME)                \
    uint8_t NAME##as_bytes[sizeof_gs_object]; \
    gs_object_t NAME = (gs_object_t)NAME##as_bytes

typedef void (*gs_object_send_t)(void *, va_list);

void gs_object_initialize(gs_object_t, void *, gs_object_send_t);
void gs_object_invoke(gs_object_t, va_list);
void gs_object_send(gs_object_t, ...);

#endif