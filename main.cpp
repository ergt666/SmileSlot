#include <iostream>
#include <vector>
#include "GameLogic.h"
#include "Graphics.h"

int main()
{
    startLogo();

    std::vector<int> win_nums = winNums();
    
    for (const auto& n : win_nums) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    std::cout << win_nums.size() << std::endl;

    std::string user_lose = userLose();
    std::cout << user_lose << std::endl;
    

    return 0;
}
