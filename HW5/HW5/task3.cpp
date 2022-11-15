#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

void func(list<int>& positive, list<int>& negative, list<int>& answer)
{
    while (positive.size() != 0 && negative.size() != 0)
    {
        int positiveElement = abs(positive.back());
        int negativeElement = abs(negative.front());

        if (positiveElement == negativeElement)
        {
            positive.pop_back();
            negative.pop_front();
        }
        else if (positiveElement > negativeElement)
        {
            negative.pop_front();
        }
        else if (negativeElement > positiveElement)
        {
            positive.pop_back();
        }
    }

    while (negative.size() != 0)
    {
        int negativeElement = negative.front();
        answer.push_back(negativeElement);
        negative.pop_front();
    }
}

int main()
{
    int N;
    cin >> N;

    list<int> list;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        list.push_back(num);
    }

    std::list<int> positive;
    std::list<int> negative;
    std::list<int> answer;

    bool firstElements = true;
    int previousElement = 0;

    while (list.size() != 0)
    {
        int currentElement = list.front();
        if (currentElement < 0 && firstElements)
        {
            answer.push_back(currentElement);
            list.pop_front();
        }
        else if (currentElement > 0)
        {
            if (previousElement < 0 && !firstElements)
            {
                func(positive, negative, answer);
            }

            positive.push_back(currentElement);
            list.pop_front();

            if (firstElements)
                firstElements = false;
        }
        else if (currentElement < 0)
        {
            negative.push_back(currentElement);
            list.pop_front();

            if (list.size() == 0)
            {
                func(positive, negative, answer);
            }
        }

        previousElement = currentElement;
    }

    while (positive.size() != 0)
    {
        int positiveElement = positive.front();
        answer.push_back(positiveElement);
        positive.pop_front();
    }

    while (negative.size() != 0)
    {
        int negativeElement = negative.front();
        answer.push_back(negativeElement);
        negative.pop_front();
    }

    if (answer.size() == 0)
        std::cout << '\n';
    else
    {
        while (answer.size() != 0)
        {
            int num = answer.front();
            std::cout << num << " ";
            answer.pop_front();
        }
    }
}