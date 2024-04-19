#pragma once
#include <iostream>

class BitSet
{
	unsigned int value;
public:
	BitSet() : value{} {};
	BitSet(unsigned int value) : value{ value } {};
	BitSet(std::string mask);

	unsigned int Count();
	unsigned int Size();

	BitSet& Set();
	BitSet& Set(unsigned int position, bool value = true);
	BitSet& Reset();
	BitSet& Reset(unsigned int position);
	BitSet& Flip();
	BitSet& Flip(unsigned int position);

	BitSet& operator&=(const BitSet& other);
	BitSet& operator|=(const BitSet& other);
	BitSet& operator^=(const BitSet& other);

	BitSet& operator<<=(unsigned int position);
	BitSet& operator>>=(unsigned int position);

	BitSet& operator~();
	
	friend BitSet& operator&=(const BitSet& bitset1, const BitSet& bitset2);
	friend BitSet& operator|=(const BitSet& bitset1, const BitSet& bitset2);
	friend BitSet& operator^=(const BitSet& bitset1, const BitSet& bitset2);

	friend std::ostream& operator<<(std::ostream& out, const BitSet& bitset);

	bool& operator[](unsigned int position);

	unsigned int& Value();
};

