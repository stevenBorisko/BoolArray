#include "BoolArray.h"

BoolArray BA_init(size_t count, bool init) {
	BoolArray ret;
	size_t arrSize;
	arrSize = (count >> 3) + !!(count & 7);
	ret.array = malloc(arrSize);
	memset(ret.array,-(char)init,arrSize);
	return ret;
}

void BA_destroy(BoolArray* ba) {
	free(ba->array);
}

void BA_set(BoolArray* ba, size_t index, bool val) {
	size_t outer, inner;
	char temp;
	outer = index >> 3;
	inner = index & 7;

	temp = ((char)(-1) << inner) >> inner;
	temp &= ba->array[outer];

	ba->array[outer] = (((ba->array[outer] >> (inner + 1)) << 1) | val) << inner;
	ba->array[outer] |= temp;
}

bool BA_get(BoolArray* ba, size_t index) {
	return !!(ba->array[index >> 3] & ((char)1 << (char)(index & 7)));
}
