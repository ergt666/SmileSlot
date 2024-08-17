#include <algorithm>
#include <iostream>
#include <string>
#include <random>

using namespace std;

void startLogo() {
        cout << endl;
        cout << u8"(ノ￣▽￣)ノ (ʘ‿ʘ) (◕‿◕)ノ (⌐■_■)- (つ･･)つ ⊚ ◡ ⊚ ╰(°ㅂ° )╯ ＼(￣□￣)／ (ʘ‿ʘ)ノ"   << endl;
        cout << endl;
        cout << "                                   Smile Slot :)                        " << endl;
        cout << endl;
        cout << u8"(ノ￣▽￣)ノ (ʘ‿ʘ) (◕‿◕)ノ (⌐■_■)- (つ･･)つ ⊚ ◡ ⊚ ╰(°ㅂ° )╯ ＼(￣□￣)／ (ʘ‿ʘ)ノ"   << endl;
        cout << endl;
        cout << endl;
}

string userLose() 
{

    string user_lose;
    string wall = "||";
    vector<int> nums;

    random_device rd;
    mt19937 gen(rd());
    
    while (nums.size() != 3) 
    {
        uniform_int_distribution<> distrib(1, 6);
        int random_num = distrib(gen);
        
        auto it = adjacent_find(nums.begin(), nums.end());

        if (it == nums.end()) 
        {
            nums.push_back(random_num);
        }
    } 

    for (const auto& n : nums) 
    {
        switch (n) 
        {
        case 1: user_lose += "|| (ノ￣▽￣)ノ ||";break;
        case 2: user_lose += "|| ＼(￣□￣)／ ||"; break;
        case 3: user_lose += "||   ⊚ ◡ ⊚     ||"; break;
        case 4: user_lose += "||   (◕‿◕)ノ   ||"; break;
        case 5: user_lose += "|| ╰(°ㅂ° )╯   ||"; break;
        case 6: user_lose += "||   (⌐■_■)-   ||"; break;
        }
    }
    return user_lose;
}

string userWin(int i)
{
    string user_win;
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