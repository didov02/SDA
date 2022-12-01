#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

struct StrikeInformation
{
    int boatsBefore;
    int boatsAfter;

    StrikeInformation()
    {
        boatsAfter = 0;
        boatsBefore = 0;
    }
};

int main()
{
    int fields, boatsCount, boatSize, strikesCount, currentStrike;
    cin >> fields >> boatsCount >> boatSize;

    map<int, StrikeInformation> m;

    cin >> strikesCount;
    int fieldsBefore = 0;
    int fieldsAfter = 0;
    int currentBoatsCount = 0;

    for (int i = 1; i <= strikesCount; i++)
    {
        StrikeInformation strike;

        cin >> currentStrike;

        if (m.count(currentStrike) == 1)
            continue;

        auto lower = m.lower_bound(currentStrike);
        if (!m.empty())
            lower--;

        auto upper = m.upper_bound(currentStrike);

        if (lower != m.end())
        {
            StrikeInformation lowerStrike = (*lower).second;

            fieldsBefore = currentStrike - (*lower).first - 1;

            while (fieldsBefore >= boatSize)
            {
                currentBoatsCount++;
                fieldsBefore -= (boatSize + 1);
            }

            strike.boatsBefore = currentBoatsCount + lowerStrike.boatsBefore;
        }
        else
        {
            fieldsBefore = currentStrike - 1;

            while (fieldsBefore >= boatSize)
            {
                currentBoatsCount++;
                fieldsBefore -= (boatSize + 1);
            }

            strike.boatsBefore = currentBoatsCount;
        }
        currentBoatsCount = 0;

        if (upper != m.end())
        {
            StrikeInformation upperStrike = (*upper).second;

            fieldsAfter = (*upper).first - currentStrike - 1;

            while (fieldsAfter >= boatSize)
            {
                currentBoatsCount++;
                fieldsAfter -= (boatSize + 1);
            }

            strike.boatsAfter = currentBoatsCount + upperStrike.boatsAfter;
        }
        else
        {
            fieldsAfter = fields - currentStrike;

            while (fieldsAfter >= boatSize)
            {
                currentBoatsCount++;
                fieldsAfter -= (boatSize + 1);
            }

            strike.boatsAfter = currentBoatsCount;
        }
        currentBoatsCount = 0;

        if (strike.boatsAfter + strike.boatsBefore < boatsCount)
        {
            cout << i << '\n';
            return 0;
        }

        m[currentStrike] = strike;
    }

    cout << -1 << '\n';
}