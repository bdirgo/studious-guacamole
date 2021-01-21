#include <stdlib.h>
#include "stack.h"

void stackNew(stack *s) 
{
    s->logicalLength = 0;
    s->allocLength = 4;
    s->elems = malloc(4 * sizeof(int));
    assert(s->elems != NULL);
}