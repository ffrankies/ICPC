//
// Frank Derry Wanye
//

#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

class Data {
private:

public:
    int turns;
    int curr;
    int sum;
    int avg;
    int _case;

    int gcd(int a, int b) {
        while(b != 0) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    int digits(int i) {
        int count = 0;
        while(i != 0) {
            i = i / 10;
            count++;
        }
        return count;
    }

    void solve() {
        //right now sum = numberator and turns is denominator
        int a,b,c,my_gcd;
        //a = sum/turns;

        my_gcd = abs(gcd(sum,turns));
        sum = sum/my_gcd;
        turns = turns/my_gcd;

        //cout << "sum: " << sum << " turns: " << turns << " avg: " << avg << " gcd: " << my_gcd << endl;

        if(turns == 1)
            if(sum < 0)
                cout << "- " << abs(sum) << endl;
            else
                cout << sum << endl;
        else {
            a = sum/turns;
            b = abs(sum) % turns;
            c = turns;

            // b = abs(sum - (turns * a));
            // my_gcd = gcd(b,turns);
            // b = b / my_gcd;
            // c = turns / my_gcd;

            int digb = digits(b);
            int digc = digits(c);

            if(a == 0)
                if(avg < 0) {
                    cout << setw(2+digc) << b << endl;
                    cout << "- " << string(digc,'-') << endl;
                    cout << "  " << c << endl;
                }
                else {
                    cout << setw(digc) << b << endl;
                    cout << string(digc,'-') << endl;
                    cout << c << endl;
                }
            else {
                if(a < 0) {
                    cout << setw(digits(abs(a))+digc+2) << b << endl;
                    cout << "- " << abs(a) << string(digc,'-') << endl;
                    cout << setw(digits(abs(a))+digc+2) << c << endl;
                }
                else {
                    cout << setw(digits(abs(a))+digc) << b << endl;
                    cout << a << string(digc,'-') << endl;
                    cout << setw(digits(abs(a))+digc) << c << endl;
                }
            }
        }

        sum = 0;
        avg = 0;
    }

    void readData(istream& input) {
        cout << "Case " << _case << ":" << endl;

        sum = 0;
        //turns = 0;
        //cout << "original sum: " << sum << endl;

        for(int i = 0; i < turns; ++i) {
            input >> curr;
            sum += curr;
            //cout << sum << " after adding " << curr << endl;
        }

        //cout << "Sum: " << sum << " turns: " << turns << endl;
        avg = sum/turns;
    }
};

int main() {
    Data data;
    //ata.turns = 1; //default
#ifndef ONLINE_JUDGE
    ifstream numbers;
    numbers.open("toavg.txt");
#else
    istream& numbers = cin;
#endif
    numbers >> data.turns;
    data._case = 1;
    while(data.turns != 0) {
        data.readData(numbers);
        data.solve();
        numbers >> data.turns;
        data._case++;
    }
    return 0;
}
