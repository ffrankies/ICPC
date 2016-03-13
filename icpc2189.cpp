//
// Frank Derry Wanye
//

#include <iostream>
#include <sstream>
#include <iomanip>
#include <math.h>
#include <fstream>

using namespace std;

#ifndef ONLINE_JUDGE
const string test_data = "3\n"
        "01711322396\n"
        "01711322397\n"
        "01711322398\n"
        "7\n"
        "01187239192\n"
        "01711322396\n"
        "01711322397\n"
        "01711322398\n"
        "01711322399\n"
        "01711322400\n"
        "01711389821\n"
        "0\n";
#endif

class Data {
private:
    long curr;
    long next;

public:
    long turns;
    string number;
    string nextnumber;

    string getSuffix(int diff) {
        long temp = curr + diff;
        string t1 = to_string(curr);
        string t2 = to_string(temp);
        int pos = 0;
        while(t1[pos] == t2[pos])
            pos++;
        return t2.substr(pos,t2.length());
    }

    void readData(istream& input) {
        input >> number;
        long diff = 0;
        curr = stol(number);
        for (int i = 0; i < turns; ++i) {
            if(i != turns - 1) {
                input >> nextnumber;
                next = stol(nextnumber);
            }
            if(next - curr == diff + 1)
                diff++;
            else {
                if(diff == 0)
                    cout << number << endl;
                else {
                    cout << number << "-" << getSuffix(diff) << endl;
                }
                diff = 0;
                number = nextnumber;
                curr = stol(number);
            }
        }
        input >> turns;
    }
};

int main() {
    Data data;
    data.turns = 1; //default
#ifndef ONLINE_JUDGE
    ifstream numbers;
    numbers.open("nrs.txt");
#else
    istream& numbers = cin;
#endif
    numbers >> data.turns;
    int c = 1;
    while(data.turns != 0) {
        cout << "Case " << c << ":" << endl;
        data.readData(numbers);
        cout << endl;
        c++;
    }
    return 0;
}
