//
// Frank Derry Wanye
//

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

#ifndef ONLINE_JUDGE
const string test_data = "ABCDEFG\n"
        "3\n"
        "E\n"
        "C\n"
        "D\n"
        "THELAZYDOG\n"
        "1\n"
        "D\n"
        "HIWORLD\n"
        "1\n"
        "O\n"
        "HIWORLD\n"
        "0\n"
        "ABCDEFGHIJKLMNOP\n"
        "5\n"
        "A\n"
        "E\n"
        "L\n"
        "I\n"
        "M\n"
        "A\n"
        "1\n"
        "A\n"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ\n"
        "26\n"
        "M\n"
        "N\n"
        "F\n"
        "T\n"
        "X\n"
        "W\n"
        "E\n"
        "G\n"
        "Z\n"
        "A\n"
        "L\n"
        "O\n"
        "K\n"
        "J\n"
        "I\n"
        "H\n"
        "P\n"
        "Q\n"
        "R\n"
        "S\n"
        "U\n"
        "Y\n"
        "B\n"
        "D\n"
        "V\n"
        "C\n"
        "STOP";
#endif

class Driveway {
private:

    //Number of cars that leave
    int operations;
    //The list of cars, in order in which they are in the driveway
    deque<char> cars;
    //The list of cars that leave, in order in which they leave
    queue<char> leaving;
    //The list of cars that make way for the leaving car
    queue<char> temp;
    deque<char> t;

public:
    string car_temp;

    void readData(istream& input) {
        input >> operations;
        //Builds a deque using the string car_temp
        for (int i = 0; i < car_temp.length(); ++i) {
            cars.push_back(car_temp[i]);
        }

        //Builds the queue of cars that leave from input
        for (int o = 0; o < operations; ++o) {
            char c;
            input >> ws >> c;
            leaving.push(c);
        }
    }

    //Old method that didn't work the first time
//
//    void solveIt() {
//        while(!leaving.empty()) {
//            //c is the car that's leaving
//            char c = leaving.front();
//            leaving.pop();
//            //find position of c in driveway
//            auto it = cars.begin();
//            for(auto i = cars.begin(); i < cars.end(); ++i)
//                if(*i == c)
//                    it = i;
//            //auto it = find(cars.front(), cars.back(), c);
//            int midpoint = cars.size();
//            if(midpoint % 2 == 0)
//                midpoint = midpoint/2 -1;
//            else
//                midpoint = midpoint/2;
//
//            //if it's in the right half of the driveway...
//            //Not checking for that, pop from both sides until find it
//            if (it > cars.begin() + midpoint) { //Make sure comparison works,
//                //try distance
//                //pushes cars that make space into temp list
//                while(cars.back()!=c) {
//                    temp.push(cars.back());
//                    cars.pop_back();
//                }
//                //removes the car that actually leaves
//                cars.pop_back();
//                //returns cars that made space to driveway
//                while(!temp.empty()) {
//                    cars.push_back(temp.front());
//                    temp.pop();
//                }
//            }
//                //if it's in the left half of the driveway...
//            else {
//                while(cars.front()!=c) {
//                    temp.push(cars.front());
//                    cars.pop_front();
//                }
//                //removes the car that actually leaves
//                cars.pop_front();
//                //returns cars that made space to driveway
//                while(!temp.empty()) {
//                    cars.push_front(temp.front());
//                    temp.pop();
//                }
//            }
//            printString(c,cars);
//        }
//        cars.clear();
//        cout << "\n";
//    }

    //New method that works, though it takes much longer
    void solveIt() {
        while(!leaving.empty()) {
            //c is the car that's leaving
            char c = leaving.front();
            leaving.pop();

            //stores first and last cars in driveway
            char front = cars.front(), back = cars.back();

            //pops first, then last car in driveway until finds c
            while(front != c && back != c) {
                t.push_front(front);
                t.push_back(back);
                cars.pop_front();
                cars.pop_back();
                front = cars.front();
                back = cars.back();
            }

            //left is a boolean variable that stores whether or not the cars
            //that make way for c are in the left half of the driveway
            bool left;

            if (front == c) {
                left = true;
                cars.pop_front();
            } else {
                left = false;
                cars.pop_back();
            }


            int size = t.size();

            //pushes previously popped cars back into driveway in correct order
            if(left == true) {
                for(int i = 1; i <= size; ++i) {
                    if(i <= size/2) {
                        cars.push_back(t.back());
                        t.pop_back();
                    }
                    else {
                        cars.push_front(t.back());
                        t.pop_back();
                    }
                }
            }
            else {
                for(int i = 1; i <= size; ++i) {
                    if(i <= size/2) {
                        cars.push_front(t.front());
                        t.pop_front();
                    }
                    else {
                        cars.push_back(t.front());
                        t.pop_front();
                    }
                }
            }
            printString(c,cars);
        }
        cars.clear();
        //cout << "\n";
    }

    void printString(char car, deque<char>& carsLeft) {
        cout << "After " << car << " leaves, the order is ";
        for(auto i = carsLeft.begin(); i != carsLeft.end(); ++i)
            cout << *i;
        cout << "." << "\n";
    }
};

int main() {
    Driveway driveway;

#ifndef ONLINE_JUDGE
    istringstream data (test_data);
#else
    istream& data = cin;
#endif
    data >> driveway.car_temp;
    driveway.car_temp = driveway.car_temp.substr(0,26);
    int n = 0;
    while(driveway.car_temp != "STOP") {
        driveway.readData(data);
        cout << "Dataset #" << (n + 1) << ":  The initial order is " <<
        driveway.car_temp << "." << "\n";
        driveway.solveIt();
        n++;
        data >> driveway.car_temp;
        driveway.car_temp = driveway.car_temp.substr(0,26);
        if(driveway.car_temp != "STOP")
            cout << "\n";
    }

    return 0;
}
