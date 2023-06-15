#include <iostream>

using namespace std;

void
d2bUsingMod(int number) {
    int remainder = 0;
    int quotient = 0;

    int bits[1000000];
    int bitIndex = 0;
    int printIndex = 0;

    
    quotient = number;

    while (quotient > 0) {
        remainder = quotient % 2;
        bits[bitIndex++] = remainder;
        quotient = (quotient - remainder) / 2;
    }

    for (printIndex = bitIndex - 1; printIndex >= 0; printIndex--) {
        cout << bits[printIndex];
    }
    cout << endl;
}

void
d2bUsingBitOp(int number) {
    int value;

    int bits[1000000];
    int bitIndex = 0;
    int printIndex = 0;
    int bit = -1;

    value = number;
    while (value > 0) {
        bits[bitIndex] = value & 1;
        bitIndex++;
        value = value >> 1;
    }

    for (printIndex = bitIndex - 1; printIndex >= 0; printIndex--) {
        cout << bits[printIndex];
    }
    cout << endl;
}

int
main(int argc, char** argv) {
    int number = 0;

    cout << "Number: ";
    cin >> number;
    cout << "You type: " << number << endl;

    // d2bUsingMod(number);
    d2bUsingBitOp(number);

    return 0;
}
