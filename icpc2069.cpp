//
// Created by Frank Derry Wanye
//

#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>

using namespace std;

#ifndef ONLINE_JUDGE
const string test_data = "4\n"
        "John dire direct direction\n"
        "Jane direkt\n"
        "Joan direction\n"
        "Janet vondire direction\n"
        "3\n"
        "john great admired politician poorer loss\n"
        "jehn great admired politician poorer loss\n"
        "Kim great loss poorer\n"
        "8\n"
        "peter moral choice\n"
        "paul moral choice\n"
        "james moral choice\n"
        "hello moral\n"
        "abc moral choice\n"
        "bcd moral choice\n"
        "cde moral choice\n"
        "efg moral choice\n"
        "0\n";
#endif

struct MyCompare {
    bool operator() (const pair<string,int> &left, const pair<string,int>
    &right) const {
        return left.second < right.second;
    }
};

class GameData {
private:

    unordered_map<string,set<string>> player_words;
    map<string,int> words;
    map<string,float> points;
    vector<string> order;
    float max_score = -1;
    int round = 1;

public:
    int num_players;

    /*
     * Builds a map of each player and the words they used, a map of each
     * word and how many times it has been used, and a vector containing the
     * player names in the order in which they appear
     */
    void readData(istream& input) {
        string line;
        //input >> line;
        for (int i = 0; i < num_players; ++i) {
            getline(input, line);
            if(line == "")
                getline(input,line);
            istringstream player(line);
            string name;
            player >> name;
            player_words[name];
            string word;
            while (player >> word) {
                player_words[name].insert(word);
                words[word]++;
            }
            order.push_back(name);
        }
    }

    void solveIt() {
        //Builds a map of each player and the score they earned, keeping track
        //of the maximum score as the map is built
        for(auto it = player_words.begin(); it != player_words.end(); ++it) {
            auto temp = *it;
            double score = 0.00;
            for(auto word: temp.second) {
                double add = ((double)word.size()/(double)words[word]);
                score += add;
            }
            if(score > max_score)
                max_score = score;
            points[temp.first] = score;
        }
        cout << "Round " << round << "\n";
        int num = 0;
        //Goes through the vector of names, and if that player has the
        //maximum score, prints it out
        for(auto it2 = order.begin(); it2 != order.end(); ++it2) {
            string n = *it2;
            if(points[n] == max_score) {
                if(num > 0)
                    cout << " ";
                cout << n;
                num = num+1;
            }
        }
        cout << "\n";
        round++;

        //Resets all global variables
        player_words.clear();
        words.clear();
        points.clear();
        order.clear();
        max_score = -1;
    }
};

int main() {
    GameData game;

#ifndef ONLINE_JUDGE
    istringstream data (test_data);
#else
    istream& data = cin;
#endif
    //int num_players;
    data >> game.num_players;

    while(game.num_players != 0) {
        game.readData(data);
        game.solveIt();
        data >> game.num_players;
    }

    return 0;
}
