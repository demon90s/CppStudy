#include "utility.h"

void SetBit(unsigned long *flag, size_t bit)
{
	*flag |= 1UL << bit;
}

void ClearBit(unsigned long *flag, size_t bit)
{
	*flag &= ~(1UL << bit);
}

bool IsBitSet(const unsigned long *flag, size_t bit)
{
	return *flag & (1UL << bit);
}
