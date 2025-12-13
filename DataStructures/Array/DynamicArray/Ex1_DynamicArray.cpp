#include <stdio.h>
#include <stdlib.h>

struct Number {
    float *items;
    size_t count;
    size_t capacity;
};

int main(void) {
    /* Initialize 
        xs {
            items = null
            count = 0 
            capacity = 0
        }
    */
    struct Number xs = {0};

    for (int x=0; x<10; ++x) {
        if (xs.count >= xs.capacity) {
            /* If the size exceed the current capacity, going to allocate more room. */
            if (xs.capacity == 0) {
                /* If the current capacity is 0, going to initialize it with 8. */
                xs.capacity = 8;
            } else {
                /* If the current capacity is not 0, increase the capacity by twice the current size. */
                xs.capacity *= 2;
            }

            /* Allocate new items with the new capacity. */
            xs.items = (float*)realloc(xs.items, xs.capacity*sizeof(*xs.items));
            printf("Update size of items to %d", xs.capacity);
        }

        /* Add new item into items, also increase counter. */
        xs.items[xs.count++] = x;
    }

    
    for (size_t i=0; i<xs.count; i++) {
        printf("%f ", xs.items[i]);
    }

    return 0;
}