#include <iostream>
#include <fstream>
#include <bitset>

using namespace std;

// bitset<32> increment (bitset<32> &b) {
//     int pos = 0;
//     while(b[pos] != 0 && pos != 31) {
//         b.flip(pos);
//         pos++;
//     }
//     b.flip(pos);
// }

int main() {

    #ifndef ONLINE_JUDGE
        ifstream input;
        input.open("594.txt");
    #else
        istream &input = cin;
    #endif

    int value;

    while(input >> value) {

        //cout << "value: " << value << endl;

        bitset<32> b1(value);
        bitset<32> b2(value);

        int pos = 24;
        for(int i = 0; i < 8; ++i) {
            b2[pos] = b1[i];
            pos++;
        }
        pos = 16;
        for(int i = 8; i < 16; ++i) {
            b2[pos] = b1[i];
            pos++;
        }
        pos = 8;
        for(int i = 16; i < 24; ++i) {
            b2[pos] = b1[i];
            pos++;
        }
        pos = 0;
        for(int i = 24; i < 32; ++i) {
            b2[pos] = b1[i];
            pos++;
        }

        cout << (int)b1.to_ulong() << " converts to " << (int)b2.to_ulong() << endl;
        //try shift right and copy rightmost byte
        //use to_string
        //flip and add 1 if need to do two's complement

    }

}
