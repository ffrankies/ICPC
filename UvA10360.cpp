//#include <unordered_map>
//#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct pairhash {
public:
  template <typename T, typename U>
  std::size_t operator()(const std::pair<T, U> &x) const
  {
    return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
  }
};

int main() {

    #ifndef ONLINE_JUDGE
        ifstream input;
        input.open("10360.txt");
    #else
        istream &input = cin;
    #endif

    int scenarios;
    input >> scenarios;

    for(int i = 0; i < scenarios; ++i) {

        int radius;
        input >> radius;

        int pop;
        input >> pop;

        //Position of rats, mapped to number of rats at position
        //typedef pair<int,int> Point;
        //unordered_map< Point, int, pairhash > pops;
        int grid[1024][1024] = {{0}};
        //fill(grid, grid + 1024*1024, 0);
        //vector< Point > pos;
        int frow = 0;
        int fcol = 0;
        int fsum = 0;

        for(int j = 0; j < pop; ++j) {

            //Building map of positions of rats
            int r, c, num;
            input >> r;
            input >> c;
            input >> num;

            int rstart = r - radius;
            if(rstart < 0)
                rstart = 0;
            int rend = r + radius;
            if(rend >= 1024)
                rend = 1023;
            int cstart = c - radius;
            if(cstart < 0)
                cstart = 0;
            int cend = c + radius;
            if(cend >= 1024)
                cend = 1023;

            for(int row = rstart; row <= rend; ++row) {

                for(int col = cstart; col <= cend; ++col) {

                    grid[row][col]+=num;

                }

            }

        }

        // for(int row = 0; row < 1024 - radius; ++row) {
        //
        //     for(int col = 0; col < 1024 - radius; ++col) {
        //
        //         int sum = 0;
        //
        //         for(auto &temp: pos) {
        //
        //             if(temp.first <= row + radius && temp.first >= row - radius &&
        //                temp.second <= col + radius && temp.second >= col - radius)
        //
        //                sum += pops[temp];
        //
        //         }
        //
        //         if( sum > fsum) {
        //
        //             frow = row;
        //             fcol = col;
        //             fsum = sum;
        //
        //         }
        //
        //     }
        //
        // }

        for(int row = 0; row < 1024; ++row) {

            for(int col = 0; col < 1024; ++col) {

                if(grid[row][col]>fsum) {

                        frow = row;
                        fcol = col;
                        fsum = grid[row][col];

                }

            }

        }

        cout << frow << " " << fcol << " " << fsum << endl;

    }

}
