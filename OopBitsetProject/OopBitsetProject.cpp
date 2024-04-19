#include <iostream>
#include "BitSet.h"

int main()
{
    BitSet b1("1001101100101");

    std::cout << b1 << " " << b1.Size() << "\n";
}
