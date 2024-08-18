#include <algorithm>
#include <iostream>
#include <string>
#include <random>

using namespace std;

void startLogo() 
{
    cout << endl;
    cout << u8"(ノ￣▽￣)ノ (ʘ‿ʘ) (◕‿◕)ノ (⌐■_■)- (つ･･)つ ⊚ ◡ ⊚ ╰(°ㅂ° )╯ ＼(￣□￣)／ (ʘ‿ʘ)ノ"   << endl;
    cout << endl;
    cout << "                                   Smile Slot :)                        " << endl;
    cout << endl;
    cout << u8"(ノ￣▽￣)ノ (ʘ‿ʘ) (◕‿◕)ノ (⌐■_■)- (つ･･)つ ⊚ ◡ ⊚ ╰(°ㅂ° )╯ ＼(￣□￣)／ (ʘ‿ʘ)ノ"   << endl;
    cout << endl;
    cout << endl;
}

void menuPrize()
{
    cout << "3x   (◕‿◕)ノ   = 2$" << endl; 
    cout << "3x (ノ￣▽￣)ノ = 3$" << endl;
    cout << "3x ＼(￣□￣)／ = 7$" << endl;
    cout << "3x   (⌐■_■)-   = 20$" << endl;
    cout << "3x   ⊚ ◡ ⊚     = 50$" << endl;
    cout << "3x ╰(°ㅂ° )╯   = 100$" << endl;
}

string userLose() 
{
    string user_lose = "";   
    vector<int> nums = {};
    bool isX = true;

    random_device rd;
    mt19937 gen(rd());
    
    while (isX) 
    {
        uniform_int_distribution<> distrib(1, 6);
        int random_num = distrib(gen);
        
        nums.push_back(random_num);

        if (nums.size() == 3) 
        {                                                        //[&] читає значення з вектора
            bool all_equal = std::all_of(nums.begin(), nums.end(), [&](int num) { return num == nums[0]; });
            if (all_equal)
            {
                // якщо всі значення 1, 1, 1 тобто виграшні то перезапуск
                nums.clear();
            }
            else
            {
                isX = false;
            }
        }
    } 

    for (const auto& n : nums) 
    {
        user_lose += "||";
        switch (n) 
        {
            case 1: user_lose += " (ノ￣▽￣)ノ ";break;
            case 2: user_lose += " ＼(￣□￣)／ "; break;
            case 3: user_lose += "   ⊚ ◡ ⊚     "; break;
            case 4: user_lose += "   (◕‿◕)ノ   "; break;
            case 5: user_lose += " ╰(°ㅂ° )╯   "; break;
            case 6: user_lose += "   (⌐■_■)-   "; break;
        }
    }
    user_lose += "||";
    return user_lose;
}

string userWin(int i)
{
    string user_win = "";
    switch (i)
    {
        case 1: user_win += "||  (◕‿◕)ノ   ||  (◕‿◕)ノ    ||   (◕‿◕)ノ   ||\nYou win: 2$\n" ; break;
        case 2: user_win += "|| (ノ￣▽￣)ノ || (ノ￣▽￣)ノ || (ノ￣▽￣)ノ ||\nYou win: 3$\n" ; break;
        case 3: user_win += "|| ＼(￣□￣)／ || ＼(￣□￣)／ || ＼(￣□￣)／ ||\nYou win: 7$\n"; break;
        case 4: user_win += "||   (⌐■_■)-   ||   (⌐■_■)-   ||   (⌐■_■)-   ||\nYou win: 20\n"; break;
        case 5: user_win += "||   ⊚ ◡ ⊚     ||   ⊚ ◡ ⊚     ||   ⊚ ◡ ⊚     ||      \nYou win: 50$\n"; break;
        case 6: user_win += "|| ╰(°ㅂ° )╯   || ╰(°ㅂ° )╯   || ╰(°ㅂ° )╯   ||\nYou win: 100$\n"; break;
        default: break;
    }
    return user_win;
}