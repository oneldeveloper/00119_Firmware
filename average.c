#include "average.h"

int average(int16_t *samples, uint8_t count)
{
    if (count == 0)
        return 0;
    if (count == 1)
        return *samples;    
    uint32_t accumulator = *samples++;
    uint8_t index;
    for (index = 1; index < count; index ++)
    {
        accumulator += *samples++;
        accumulator /= 2;
    } 
    return (int16_t)accumulator;
}
