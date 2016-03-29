#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

int main() {
    int cases;

    #ifndef ONLINE_JUDGE
        ifstream input;
        input.open("482.txt");
    #else
        istream &input = cin;
    #endif

    input >> cases;
    string s;
    getline(input, s);

    for(int i = 0; i < cases; ++i) {
        vector<int> pos;
        vector<string> nrs;
        vector<string> output;
        string pos_str, nrs_str, skip;

        getline(input,skip);
        getline(input,pos_str);
        getline(input,nrs_str);
    //    cout << "skip: " << skip << endl;
    //    cout << "pos: " << pos_str << endl;
    //    cout << "nrs: " << nrs_str << endl;

        istringstream positions (pos_str);
        istringstream numbers (nrs_str);

        int t1;
        string t2;
        while(positions >> t1) {
            pos.push_back(t1-1);
            numbers >> t2;
            nrs.push_back(t2);
            output.push_back("");
        }

        for(int j = 0; j < pos.size(); ++j) {
            int temp = pos[j];
            output[temp] = nrs[j];
            //cout << nrs[temp] << endl;
        }

        for(int k = 0; k < output.size(); ++k) {
            cout << output[k];
            //if(k != output.size() - 1)
                cout << endl;
        }

        if(i != cases - 1)
            cout << endl;

    }
}
