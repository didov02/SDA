#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Breakfast
{
    size_t index;
    size_t timeToStart;
    size_t timeToBeDone;

    Breakfast(size_t index, size_t timeToStart, size_t timeToBeDone)
    {
        this->index = index;
        this->timeToStart = timeToStart;
        this->timeToBeDone = timeToBeDone;
    }
};

struct firstComparator
{
    bool operator()(const Breakfast& b1, const Breakfast& b2)
    {
        if (b1.timeToStart == b2.timeToStart)
        {
            return b1.timeToBeDone > b2.timeToBeDone;
        }

        return b1.timeToStart > b2.timeToStart;
    }
};

struct secondComparator
{
    bool operator()(const Breakfast& b1, const Breakfast& b2)
    {
        if (b1.timeToBeDone == b2.timeToBeDone)
        {
            return b1.index > b2.index;
        }

        return b1.timeToBeDone > b2.timeToBeDone;
    }
};

int main()
{
    size_t countOfBreakfast;
    cin >> countOfBreakfast;

    size_t startTime, doneForTime;

    priority_queue<Breakfast, vector<Breakfast>, firstComparator> q;

    for (size_t i = 0; i < countOfBreakfast; i++)
    {
        cin >> startTime >> doneForTime;

        Breakfast current(i, startTime, doneForTime);
        q.push(current);
    }

    size_t time = 0;
    priority_queue<Breakfast, vector<Breakfast>, secondComparator> miniQ;

    while (!(miniQ.empty() && q.empty()))
    {
        if (time == 0)
        {
            time += q.top().timeToBeDone + q.top().timeToStart;
            cout << q.top().index << " ";
            q.pop();
        }
        else
        {
            while (!q.empty())
            {
                if (q.top().timeToStart <= time)
                {
                    miniQ.push(q.top());
                    q.pop();
                }
                else
                {
                    break;
                }
            }

            if (!miniQ.empty())
            {
                time += miniQ.top().timeToBeDone;
                cout << miniQ.top().index << " ";
                miniQ.pop();
            }
            else
                time++;
        }
    }
}
