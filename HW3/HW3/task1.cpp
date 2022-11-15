#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void getBonbons(unsigned long long myFriend, unsigned long long start, unsigned long long end, unsigned long long friendsCount, unsigned long long bonbons)
{
    unsigned long long firstMid = start + (end - start) / 3;
    unsigned long long secondMid = start + 2 * ((end - start) / 3);

    if (myFriend > firstMid && myFriend <= secondMid)
    {
        printf("%llu\n", bonbons);
    }
    else if (myFriend <= firstMid)
    {
        bonbons++;
        if (secondMid - firstMid == 1)
            printf("%llu\n", bonbons);
        else
            getBonbons(myFriend, start, firstMid, friendsCount / 3, bonbons);
    }
    else if (myFriend > secondMid)
    {
        bonbons++;
        if (secondMid - firstMid == 1)
            printf("%llu\n", bonbons);
        else
            getBonbons(myFriend, secondMid, end, friendsCount / 3, bonbons);
    }
}

int main() {
    unsigned long long power, count;
    std::cin >> power >> count;

    unsigned long long friendsCount = pow(3, power);

    auto friendsInvited = std::vector<unsigned long long>(count);
    for (unsigned long long i = 0; i < count; i++)
    {
        std::cin >> friendsInvited[i];
    }

    unsigned long long bonbons = 1;

    for (unsigned long long i = 0; i < count; i++)
    {
        unsigned long long currentFriend = friendsInvited[i];

        getBonbons(currentFriend, 0, friendsCount, friendsCount, bonbons);
    }

    return 0;
}
