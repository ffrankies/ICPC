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
        "E 1 1\n"
        "W 1 1\n"
        "2\n"
        "4\n"
        "E 1 1\n"
        "W 2 1\n"
        "5\n"
        "4\n"
        "E 2 2\n"
        "W 3 1\n"
        "5\n"
        "0\n";
#endif

class GameData {
private:

    pair<int,int> tom;
    pair<int,int> jerry;
    int t_speed;
    int j_speed;
    char t_dir;
    char j_dir;
    int t_turn;
    int j_turn;
    int hour;
    int turns;

public:
    int size;
    int *grid;
    /*
     * Builds a map of each player and the words they used, a map of each
     * word and how many times it has been used, and a vector containing the
     * player names in the order in which they appear
     */
    void readData(istream& input) {
        // int temp[size][size];
        // grid = *temp;
        tom = make_pair(0,0);
        jerry = make_pair(size-1,size-1);
        input >> t_dir;
        input >> t_speed;
        input >> t_turn;
        input >> j_dir;
        input >> j_speed;
        input >> j_turn;
        input >> turns;
        hour = 0;
    }

    void solveIt() {
        while (hour < turns) {

            move();//Moves the two rabbits
            hour++;
            if(tom.first == jerry.first && tom.second == jerry.second)
                exchange();//Exchanges directions if in same cell
            else
                turn();//Turns tom & jerry if it's the right turn
        }
        cout << tom.first + 1 << " " << tom.second + 1 << endl;
        cout << jerry.first + 1 << " " << jerry.second + 1 << endl;
    }

    void turn() {
        //turns both to the left if it's their turn
        if(hour > 0 && hour % t_turn == 0)
            turn_left(t_dir);
        if(hour > 0 && hour % j_turn == 0)
            turn_left(j_dir);
    }

    void move() {
        //Moves Tom
        if(t_dir == 'N') {
            tom.first -= t_speed;
            if(tom.first < 0) {
                tom.first *= -1;
                t_dir = 'S';
            }
        } else if(t_dir == 'W') {
            tom.second -= t_speed;
            if(tom.second < 0) {
                tom.second *= -1;
                t_dir = 'E';
            }
        } else if(t_dir == 'S') {
            tom.first += t_speed;
            if(tom.first >= size) {
                tom.first = (size - 1) - (tom.first - size + 1);
                t_dir = 'N';
            }
        } else if(t_dir == 'E') {
            tom.second += t_speed;
            if(tom.second >= size) {
                tom.second = (size - 1) - (tom.second - size + 1);
                t_dir = 'W';
            }
        }
        //Moves Jerry
        if(j_dir == 'N') {
            jerry.first -= j_speed;
            if(jerry.first < 0) {
                jerry.first *= -1;
                j_dir = 'S';
            }
        } else if(j_dir == 'W') {
            jerry.second -= j_speed;
            if(jerry.second < 0) {
                jerry.second *= -1;
                j_dir = 'E';
            }
        } else if(j_dir == 'S') {
            jerry.first += j_speed;
            if(jerry.first >= size) {
                jerry.first = (size - 1) - (jerry.first - size + 1);
                j_dir = 'N';
            }
        } else if(j_dir == 'E') {
            jerry.second += j_speed;
            if(jerry.second >= size) {
                jerry.second = (size - 1) - (jerry.second - size + 1);
                j_dir = 'W';
            }
        }
    }

    void exchange() {
        char t = t_dir;
        t_dir = j_dir;
        j_dir = t;
    }

    void turn_left(char &c) {
        if(c == 'N')
            c = 'W';
        else if(c == 'W')
            c = 'S';
        else if(c == 'S')
            c = 'E';
        else if(c == 'E')
            c = 'N';
        else
            cout << "Wrong input" << endl;
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
    data >> game.size;

    while(game.size != 0) {
        game.readData(data);
        game.solveIt();
        data >> game.size;
    //    delete[] game.grid;
    }

    return 0;
}
