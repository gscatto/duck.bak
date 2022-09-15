#ifndef DUCK_H
#define DUCK_H

#include <stdint.h>
#include <stdarg.h>

struct duck;
extern const unsigned long sizeof_duck;
typedef struct duck *duck_t;

#define duck_define(NAME)                \
    uint8_t NAME##as_bytes[sizeof_duck]; \
    duck_t NAME = (duck_t)NAME##as_bytes

typedef void (*duck_send_t)(void *, va_list);

void duck_initialize(duck_t);
void duck_set_data(duck_t, void *);
void duck_set_send_fn(duck_t, duck_send_t);
void duck_invoke(duck_t, va_list);
void duck_send(duck_t, ...);

#endif