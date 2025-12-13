#include <stdio.h>
#include <stdlib.h>

struct Number {
    float *items;
    size_t count;
    size_t capacity;
};

#define da_append(xs, x) \
    if (xs.count >= xs.capacity) { \
        if (xs.capacity == 0) { \
            xs.capacity = 8; \
        } else { \
            xs.capacity *= 2; \
        } \
        xs.items = (float*)realloc(xs.items, xs.capacity*sizeof(*xs.items)); \
        printf("Update size of items to %d", xs.capacity); \
    } \
    xs.items[xs.count++] = x; \

int main(void) {
    struct Number xs = {0};

    for (int x=0; x<10; ++x) {
        da_append(xs, x)
    }

    
    for (size_t i=0; i<xs.count; i++) {
        printf("%f ", xs.items[i]);
    }

    return 0;
}