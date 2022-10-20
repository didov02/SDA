#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

void countingSort(std::string& films)
{
    char* copyFilms = new char[films.size()];

    int count[256]{};

    for (int i = 0; i < films.size(); ++i)
        count[films[i]] += 1;

    for (int i = 1; i <= 255; ++i)
        count[i] += count[i - 1];

    for (int i = 0; i <films.size(); ++i)
    {
        copyFilms[count[films[i]] - 1] = films[i];
        count[films[i]] -= 1;
    }

    for (int i = 0; i<films.size(); ++i)
        films[i] = copyFilms[i];

    delete[] copyFilms;
}

int getIndex(char symbol, std::string films)
{
    for (int i = 0; i < films.size(); i++)
    {
        if (films[i] == symbol)
            return i;
    }

    return 0;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string films;
    std::cin >> films;

    std::string filmsOrdered = films;
    countingSort(filmsOrdered);
    auto symbolsToPrint = std::vector<char>();

    for (int i = 0; i < filmsOrdered.size(); i++)
    {
        if (i==0)
        {
            if (filmsOrdered[i] != filmsOrdered[i + 1])
            {
                symbolsToPrint.push_back(filmsOrdered[i]);
            }
        }
        else if (i == filmsOrdered.size() - 1)
        {
            if (filmsOrdered[i] != filmsOrdered[i - 1])
            {
                symbolsToPrint.push_back(filmsOrdered[i]);
            }
        }
        else
        {
            if (filmsOrdered[i] != filmsOrdered[i + 1] && filmsOrdered[i] != filmsOrdered[i - 1])
            {
                symbolsToPrint.push_back(filmsOrdered[i]);
            }
        }
    }

    auto printIndex = std::vector<int>();
    for (int i = 0; i < symbolsToPrint.size(); i++)
    {
        printIndex.push_back(getIndex(symbolsToPrint[i], films));
    }

    std::sort(printIndex.begin(), printIndex.end());

    for (int film : printIndex)
    {
        printf("%d ", film);
    }
}