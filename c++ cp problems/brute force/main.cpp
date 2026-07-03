#include <iostream>

int popcount(unsigned int x) {
    x = x - ((x >> 1) & 0x55555555); // Subtract pairs of bits
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333); // Sum groups of 2 bits
    x = (x + (x >> 4)) & 0x0F0F0F0F; // Sum groups of 4 bits
    x = x + (x >> 8); // Sum groups of 8 bits
    x = x + (x >> 16); // Sum groups of 16 bits
    return x & 0x3F; // Mask to get the final result
}

int main() {
    unsigned int n; // 29 in binary is 11101 -> has 4 bits set
    std::cin >> n;
    std::cout << "Bit count: " << popcount(n) << std::endl;
    return 0;
}
