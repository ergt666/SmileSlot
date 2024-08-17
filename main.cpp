#include <iostream>
#include <vector>
#include "GameLogic.h"
#include "Graphics.h"

int main()
{
    bool start_game = true;
    std::string play_or_exit = "";
    int userWallet = 1000;

    startLogo();   
    
    while (start_game)
    {
        //add play menu music
        // генеруємо виграшні номера
        std::vector<int> win_nums = winNums();
        //add text "You Balance: " "$"; "Play press (1), Exit press (0) "
        std::cout << "p or x: " << std::endl;
        std::cin >> play_or_exit;
        //add start play music 
        if (play_or_exit == "1") 
        {
            for (int i = 0; i < 1000; i++)
            {
                userWallet -= 1;
                auto it = std::find(win_nums.begin(), win_nums.end(), i);
                if (it != win_nums.end())
                {
                    int index = std::distance(win_nums.begin(), it);
                    if (index <= 99)
                    {
                        int win_one = 1;
                        std::string win = userWin(win_one);
                        std::cout << win;
                    }
                    if (index >= 100 && index <= 139)
                    {
                        std::cout << "you win 3$";
                    }
                } 
                else
                {
                    std::string user_lose = userLose();
                    std::cout << user_lose << std::endl;
                }
                std::cout << "p or x: " << std::endl;
                std::cin >> play_or_exit;
                if (play_or_exit == "0") goto exit;  
            } 
        }
        else
        {
            break;
        }

    }
    exit:
    return 0;
}
