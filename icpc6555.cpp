//
// Created by Frank Derry Wanye
//

#include <iostream>
#include <sstream>
#include <map>
#include <regex>

using namespace std;

#ifndef ONLINE_JUDGE
const string test_data = "7\n"
        "ECNA Programming Contest 2013\n"
        "This is the easy problem!\n"
        "HDALKJFEL\n"
        "AAAAAAAAAAA\n"
        "\n"
        "POOS\n"
        "ZXYWE\n"
        "BBBBBBBBBBBBBBBBBBBDDDDDDDDDDDDDDDDRRRRRRRTTTTVVYYYA\n"
        "New code line here\n"
        "Try solving this one.324\n"
        "Z\n"
        "DO\n"
        "ECNA Programming Contest 2013\n"
        "AAAAAAAAAAAAAAAAAAAAAAAAAAA\n";

#endif

class GameData {
private:

    map<char,int[2]> positions;
    char grid[5][5];
    string alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
    string code = "";
    string line = "";

public:

    void readData(istream& input) {
        string c;
        string l;
        regex r ("^A-Za-z");

        //Get line of code
        getline(input, c);
       // if(c == "")
          //  getline(input,c);
        for(int i = 0; i < c.size(); ++i) {
            if(isalpha(c[i])) {
                if(code.find(toupper(c[i])) == string::npos)
                    code += toupper(c[i]);
            }
        }

        //Adds other letters to complete code
        for(int i = 0; i < alphabet.size(); ++i) {
            if(code.find(alphabet[i]) == string::npos)
                code += alphabet[i];
        }

        //Builds grid
        istringstream str(code);
        for(int i = 0; i < 5; ++i)
            for(int j = 0; j < 5; ++j) {
                char ch;
                str >> ch;
                grid[i][j] = ch;
                positions[ch][0] = i;
                positions[ch][1] = j;
            }


        //Get line of text
        getline(input, l);
        string li;
      //  if(l == "")
      //      getline(input,l);

        //Remove non-alpha characters from line of text, stores result as li
        for(int i = 0; i < l.size(); ++i) {
            if(isalpha(l[i]))
                li += toupper(l[i]);
        }

        //Build correct line from li, with correct insertions from alphabet
        line += li[0];
        int ins = 0;
        for(int pos = 1; pos < li.size(); ++pos) {
            if(line.size() % 2 == 1 && li[pos]==line[line.size()-1]) {
                if(alphabet[ins]==line[line.size()-1]) {
                    ins++;
                    ins = ins%25;
                }
                line += alphabet[ins];
                line += li[pos];
                ins++;
                ins = ins%25;

            }
            else
                line += li[pos];
        }

        //Add character at end if size isn't even
        if(line.size() % 2 != 0) {
            if (alphabet[ins] == line[line.size() - 1]) {
                ins++;
                ins = ins % 25;
            }
            line += alphabet[ins];
        }


    }

    void solveIt(int t_case) {
        //if(t_case > 0)
            //cout << "\n";
        cout << "Case " << t_case+1 << ": ";

        //takes 2 characters at a time, encodes them and prints them out
        for(int i = 0; i < line.size(); i += 2) {
            string temp = line.substr(i,2);
            int r1,c1,r2,c2;
            r1 = positions[temp[0]][0];
            c1 = positions[temp[0]][1];
            r2 = positions[temp[1]][0];
            c2 = positions[temp[1]][1];
            if (r1 == r2) {
                c1++;
                c1 = c1 % 5;
                c2++;
                c2 = c2 % 5;
                cout << grid[r1][c1];
                cout << grid[r2][c2];
            }
            else if(c1 == c2) {
                r1++;
                r1 = r1 % 5;
                r2++;
                r2 = r2 % 5;
                cout << grid[r1][c1];
                cout << grid[r2][c2];
            }
            else {
                cout << grid[r1][c2];
                cout << grid[r2][c1];
            }
        }

        cout << endl;
        //clears global variables
        positions.clear();
        code.clear();
        line.clear();
    }
};

int main() {
    GameData game;

#ifndef ONLINE_JUDGE
    istringstream data (test_data);
#else
    istream& data = cin;
#endif
    int test_cases;

    //I used getline so that next getline automatically reads the next
    //line of instructions - this way the program can respond to an empty
    //string of encrypting code
    string t;
    //data >> test_cases;
    getline(data,t);
    stringstream ss (t);
    ss >> test_cases;

    for(int i = 0; i < test_cases; ++i) {
        game.readData(data);
        game.solveIt(i);
    }

    return 0;
}
