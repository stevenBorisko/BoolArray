#ifndef BOOLARRAY_H
#define BOOLARRAY_H

#include <stdlib.h>
#include <string.h>

// This is incase your c version is too old to have booleans
typedef enum { false, true } bool;

/*
--- BoolArray ---

array (char*)
	- Memory for the bools

Stores a list of boolean values.
	- Each individual bit the array is its own boolean.
	- Sacrifices a bit of speed for using as little as one eighth of the
	space.
*/
typedef struct {
	char* array;
} BoolArray;

/*
--- BA_init ---

count (size_t)
	- Number of boolean values this struct should hold.
init (bool)
	- Initial value to which all elements in the array will be initialized.

return (BoolArray)
	Initialized BoolArray

Creates a BoolArray and initializes each element to a specified value.
*/
BoolArray BA_init(size_t count, bool init);

/*
--- BA_destroy ---

ba (BoolArray*)
	- Array to destroy.

Frees the memory allocated in `BA_init`.
*/
void BA_destroy(BoolArray* ba);

/*
--- BA_set ---

ba (BoolArray*)
	- Array to manipulate.
index (size_t)
	- Index of the element to set to `val`.
val (bool)
	- Value to which the element in `ba` will be set.

Set an element in the BoolArray to a certain value.
*/
void BA_set(BoolArray* ba, size_t index, bool val);

/*
--- BA_get ---

ba (BoolArray*)
	- Array to inspect.
index (size_t)
	- Index of the element in the array to get.

return (bool)
	The element of `ba` at index `index`.

Get an element in the BoolArray.
*/
bool BA_get(BoolArray* ba, size_t index);

#endif
