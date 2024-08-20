#include <iostream>
#include <string>
#include <vector>
#include <thread> 
#include <chrono>
#include <cstdlib> 
#include "GameLogic.h"
#include "Graphics.h"
#include <SFML/Audio.hpp>

void audioManagerMenu();
void audioManagerWin();
void audioManagerLose();
void audioManagerButton();

int main()
{
    bool start_game = true;
    std::string play_or_exit = "";
    int userWallet = 1000;

    startLogo();   
    menuPrize();
    while (start_game)
    {
        //add play menu music
        audioManagerMenu();
        // генеруємо виграшні номера
        std::vector<int> win_nums = winNums();
        /*for (const auto& n : win_nums)
        {
            std::cout << n << " ";
        }*/
        //add text "You Balance: " "$"; "Play press (1), Exit press (0) "
        std::cout << "\nYou Balance: " << userWallet << "$" << "\nPlay press (1), Exit press (0): ";
        std::cin >> play_or_exit;
        audioManagerButton();
        if (play_or_exit == "1") 
        {
            for (int i = 1; i <= 1000; i++)
            {
                system("clear");
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
                        audioManagerWin();
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
                        audioManagerWin();
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
                        audioManagerWin();
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
                        audioManagerWin();
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
                        audioManagerWin();
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
                        audioManagerWin();
                    }
                } 
                else
                {
                    std::string user_lose = userLose();
                    for (char s : user_lose)
                    {
                        std::cout << s;
                        std::cout.flush();
                        std::this_thread::sleep_for(std::chrono::milliseconds(25));
                    }
                    userWallet -= 1;
                    audioManagerLose();
                }
                std::cout << "\nYou Balance: " << userWallet << "$" << "\nPlay press (1), Exit press (0): ";
                std::cin >> play_or_exit;
                std::cout << std::endl;
                if (play_or_exit == "0") goto exit;
                audioManagerButton();  
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
void audioManagerMenu()
{
    static sf::Music music;
    if (!music.openFromFile("/home/ergt/Projects/SmileSlot/AcidJazzKevinMacLeod.mp3"))
    {
        std::cout << "Не вдалося відкрити перший файл!" << std::endl;
        return;
    }
    music.play();
}
void audioManagerWin()
{
    static sf::Music music;
    if (!music.openFromFile("/home/ergt/Projects/SmileSlot/coinwin.mp3"))
    {
        std::cout << "Не вдалося відкрити перший файл!" << std::endl;
        return;
    }
    music.play();
}
void audioManagerLose()
{
    static sf::Music music;
    if (!music.openFromFile("/home/ergt/Projects/SmileSlot/Ohmygah2.mp3"))
    {
        std::cout << "Не вдалося відкрити перший файл!" << std::endl;
        return;
    }
    music.play();
}
void audioManagerButton()
{
    static sf::Music music;
    if (!music.openFromFile("/home/ergt/Projects/SmileSlot/knopka.mp3"))
    {
        std::cout << "Не вдалося відкрити перший файл!" << std::endl;
        return;
    }
    music.play();
}