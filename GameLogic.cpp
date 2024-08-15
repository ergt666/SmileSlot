#include <random>
#include <vector>
#include <algorithm>

std::vector<int> winNums() {
std::random_device rd;
std::mt19937 gen(rd());
    
std::vector<int> win_nums = {};
int arrey[6] = {10, 25, 50, 100, 250, 1000};
int arrey_index = 0;
int range_min = 1;
int range_max = 1;
bool duplicate = true;
    
while (arrey_index != 6) {
    if (arrey_index == 5) range_min = 500;
    for (int i = 1; i <= 1000; i++) {
        if (range_max % arrey[arrey_index] == 0) {
            while (duplicate) {
                std::uniform_int_distribution<> distrib(range_min, range_max);
                int random_win_num = distrib(gen);
                if (find(win_nums.begin(), win_nums.end(), random_win_num) == win_nums.end()) {
                    win_nums.push_back(random_win_num);
                    duplicate = false;
                }
            }
            duplicate = true;
            range_min += arrey[arrey_index];
        }
        range_max++;
    }
    arrey_index++;
    range_min = 1;
    range_max = 1;
    }
    return win_nums;
}
