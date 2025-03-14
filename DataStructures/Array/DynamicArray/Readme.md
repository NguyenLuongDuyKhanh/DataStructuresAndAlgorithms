# Other names:
array list, growable array, resizable array, mutable array

One limitation of arrays is that they're fixed size, meaning you need to specify the number of elements your array will hold ahead of time.

A dynamic array expands as you add more elements. So you don't need to determine the size ahead of time.
When you allocate a dynamic array, your dynamic array implementation makes an underlying fixed-size array. The starting size depends on the implementation—let's say our implementation uses 10 indices. Now say we append 4 items to our dynamic array. At this point, our dynamic array has a length of 4. But the underlying array has a length of 10.

We'd say this dynamic array's size is 4 and its capacity is 10. The dynamic array stores an endIndex to keep track of where the dynamic array ends and the extra capacity begins.

What if we try to append an item but our array's capacity is already full?

To make room, dynamic arrays automatically make a new, bigger underlying array. Usually twice as big.

Why not just extend the existing array? Because that memory might already be taken by another program.

Each item has to be individually copied into the new array.