#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

struct Student
{
    std::string name;
    int points;

    void print() const
    {
        //printf("%s %d\n", name.c_str(), points);
        std::cout << name << " " << points << '\n';
    }
};

void merge(Student* array, int left, int mid, int right) {
    int subArrayOneLength = mid - left + 1;
    int subArrayTwoLength = right - mid;

    Student* leftArray = new Student[subArrayOneLength];
    Student* rightArray = new Student[subArrayTwoLength];

    for (int i = 0; i < subArrayOneLength; i++) {
        leftArray[i] = array[left + i];
    }

    for (int j = 0; j < subArrayTwoLength; j++) {
        rightArray[j] = array[mid + 1 + j];
    }

    int indexOfSubArrayOne = 0;
    int indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while (indexOfSubArrayOne < subArrayOneLength && indexOfSubArrayTwo < subArrayTwoLength) {
        if (leftArray[indexOfSubArrayOne].points > rightArray[indexOfSubArrayTwo].points) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else if (leftArray[indexOfSubArrayOne].points == rightArray[indexOfSubArrayTwo].points)
        {
            if (leftArray[indexOfSubArrayOne].name <= rightArray[indexOfSubArrayTwo].name)
            {
                array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            }
            else
            {
                array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }

        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOneLength) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < subArrayTwoLength) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void sortStudents(Student*& students, int begin, int end)
{
    if (begin >= end) {
        return;
    }

    int mid = begin + (end - begin) / 2;
    sortStudents(students, begin, mid);
    sortStudents(students, mid + 1, end);
    merge(students, begin, mid, end);
}

bool alreadyPrinted(std::vector<std::string> printedNames, Student student)
{
    for (int i = 0; i < printedNames.size(); i++)
    {
        if (printedNames[i] == student.name)
        {
            return true;
        }
    }

    return false;
}

void printStudents(Student* students, int size)
{
    auto names = std::vector<std::string>(size);
    int counter = 0;

    for (int i = 0; i < size; i++)
    {
        int maxIndx = 0;
        int maxPoints = -1;

        for (int j = 0; j < size; j++)
        {
            if (students[j].points > maxPoints)
            {
                if (!alreadyPrinted(names, students[j]))
                {
                    maxPoints = students[j].points;
                    maxIndx = j;
                }
            }
        }

        students[maxIndx].print();
        names[counter++] = students[maxIndx].name;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;

    Student* students = new Student[N];

    for (int i = 0; i < N; i++)
    {
        std::string currentName;
        std::cin >> currentName;

        students[i].name = currentName;
    }

    for (int i = 0; i < N; i++)
    {
        int currentPoints;
        std::cin >> currentPoints;

        students[i].points = currentPoints;
    }

    sortStudents(students, 0, N - 1);

    for (int i = 0; i < N; i++)
    {
        students[i].print();
    }

    return 0;
}