#include <iostream>
#include <string>
#include <vector>
#include <thread> 
#include <chrono>
#include <cstdlib> 
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
        for (const auto& n : win_nums)
        {
            std::cout << n << " ";
        }
        //add text "You Balance: " "$"; "Play press (1), Exit press (0) "
        std::cout << "p or x: " << std::endl;
        std::cin >> play_or_exit;
        //add start play music 
        if (play_or_exit == "1") 
        {
            for (int i = 1; i <= 1000; i++)
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
                        for (char s : win)
                        {
                            std::cout << s;
                            std::cout.flush();
                            std::this_thread::sleep_for(std::chrono::milliseconds(25));
                        }
                        userWallet += 2;
                    }
                    if (index >= 100 && index <= 139)
                    {
                        int win_two = 2;
                        std::string win = userWin(win_two);
                        for (char s : win)
                        {
                            std::cout << s;
                            std::cout.flush();
                            std::this_thread::sleep_for(std::chrono::milliseconds(25));
                        }
                        userWallet += 3;
                    }
                    if (index >= 140 && index <= 159)
                    {
                        int win_three = 3;
                        std::string win = userWin(win_three);
                        for (char s : win)
                        {
                            std::cout << s;
                            std::cout.flush();
                            std::this_thread::sleep_for(std::chrono::milliseconds(25));
                        }
                        userWallet += 7;
                    }
                    if (index >= 160 && index <= 169)
                    {
                        int win_four = 4;
                        std::string win = userWin(win_four);
                        for (char s : win)
                        {
                            std::cout << s;
                            std::cout.flush();
                            std::this_thread::sleep_for(std::chrono::milliseconds(25));
                        }
                        userWallet += 20;
                    }
                    if (index >= 170 && index <= 173)
                    {
                        int win_five = 5;
                        std::string win = userWin(win_five);
                        for (char s : win)
                        {
                            std::cout << s;
                            std::cout.flush();
                            std::this_thread::sleep_for(std::chrono::milliseconds(25));
                        }
                        userWallet += 50;
                    }
                    if (index == 174)
                    {
                        int win_six = 6;
                        std::string win = userWin(win_six);
                        for (char s : win)
                        {
                            std::cout << s;
                            std::cout.flush();
                            std::this_thread::sleep_for(std::chrono::milliseconds(25));
                        }
                        userWallet += 100;
                    }
                } 
                else
                {
                    std::string user_lose = userLose();
                    std::cout << user_lose << std::endl;
                }
                std::cout << "\nYou Balance: " << userWallet << "$" << "\nPlay press (1), Exit press (0): ";
                std::cin >> play_or_exit;
                std::cout << std::endl;
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
