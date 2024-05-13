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

BitSet& BitSet::Set()
{
	value = UINT_MAX;
	return *this;
}

BitSet& BitSet::Set(unsigned int position, bool value)
{
	uint32_t mask{ 1 << position };
	if (value)
		this->value |= mask;
	else
		this->value &= ~mask;

	return *this;
}

BitSet& BitSet::Reset()
{
	value = 0;
	return *this;
}

BitSet& BitSet::Reset(unsigned int position)
{
	return Set(position, false);
}

BitSet& BitSet::Flip()
{
	this->value = ~this->value;
	return *this;
}

BitSet& BitSet::Flip(unsigned int position)
{
	uint32_t mask{ 1 << position };
	if (value & mask)
		this->value &= ~mask;
	else
		this->value |= mask;
	return *this;
}

BitSet& BitSet::operator&=(const BitSet& other)
{
	this->value &= other.value;
	return *this;
}

BitSet& BitSet::operator|=(const BitSet& other)
{
	this->value |= other.value;
	return *this;
}

BitSet& BitSet::operator^=(const BitSet& other)
{
	this->value ^= other.value;
	return *this;
}

BitSet& BitSet::operator<<=(unsigned int position)
{
	this->value <<= position;
	return *this;
}

BitSet& BitSet::operator>>=(unsigned int position)
{
	this->value >>= position;
	return *this;
}

BitSet& BitSet::operator~()
{
	return Flip();
}

BitSet& operator&(const BitSet& bitset1, const BitSet& bitset2)
{
	BitSet result = BitSet(bitset1.value & bitset2.value);
	return result;
}

BitSet& operator|(const BitSet& bitset1, const BitSet& bitset2)
{
	BitSet result = BitSet(bitset1.value | bitset2.value);
	return result;
}

BitSet& operator^(const BitSet& bitset1, const BitSet& bitset2)
{
	BitSet result = BitSet(bitset1.value ^ bitset2.value);
	return result;
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

bool BitSet::operator[](unsigned int position)
{
	return (bool)(this->value & (1 << position));
}

unsigned int& BitSet::Value()
{
	return value;
}
