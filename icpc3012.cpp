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
    double turns;
    int curr;
    double sum;
    double avg;
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
        int a,b,c,my_gcd;
        a = sum/turns;

        if(double(a) == avg)
            if(a < 0)
                cout << "- " << abs(a) << endl;
            else
                cout << a << endl;
        else {
            b = abs(sum - (turns * a));
            my_gcd = gcd(b,turns);
            b = b / my_gcd;
            c = turns / my_gcd;

            int digb = digits(b);
            int digc = digits(c);

            if(a == 0)
                if(avg < 0) {
                    cout << "  " << string(digc-digb,' ') << b << endl;
                    cout << "- " << string(digc,'-') << endl;
                    cout << "  " << c << endl;
                }
                else {
                    cout << string(digc-digb,' ') << b << endl;
                    cout << string(digc,'-') << endl;
                    cout << c << endl;
                }
            else {
                if(a < 0) {
                    cout << "  " << string(digits(abs(a)),' ') << string(digc-digb,' ') << b << endl;
                    cout << "- " << abs(a) << string(digc,'-') << endl;
                    cout << "  " << string(digits(abs(a)),' ') << c << endl;
                }
                else {
                    cout << string(digits(abs(a)),' ') << string(digc-digb,' ') << b << endl;
                    cout << a << string(digc,'-') << endl;
                    cout << string(digits(abs(a)),' ') << c << endl;
                }
            }
        }

        sum = 0;
        avg = 0;
    }

    void readData(istream& input) {
        cout << "Case " << _case << ":" << endl;
        for(int i = 0; i < turns; ++i) {
            input >> curr;
            sum += curr;
        }
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
