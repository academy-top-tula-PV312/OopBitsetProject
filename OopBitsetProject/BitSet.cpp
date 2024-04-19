#include "BitSet.h"
#include <string>

BitSet::BitSet(std::string mask)
{
	value = 0;
	for (int i{}; i < mask.length(); i++)
		if (mask[mask.length() - i - 1] == '1')
			value |= (1 << i);
}

unsigned int BitSet::Count()
{
	unsigned int count{};
	for (int i{}; i < 32; i++)
		count += (bool)(value & (1 << i));
	return count;
}

unsigned int BitSet::Size()
{
	int i;
	for (i = 32; i > 0; i--)
		if ((bool)(value & (1 << (i - 1))))
			break;
	return i;
}

std::ostream& operator<<(std::ostream& out, const BitSet& bitset)
{
	bool is_zero = (bitset.value & (1 << 31)) == 0;
	for (int i{ 30 }; i >= 0; i--)
	{
		if ((bool)(bitset.value & (1 << i)))
			is_zero = false;
		if(!is_zero)
			out << (bool)(bitset.value & (1 << i));
	}
		
	return out;
}

unsigned int& BitSet::Value()
{
	return value;
}
