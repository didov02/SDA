//#include <cmath>
//#include <cstdio>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//#include <set>
//#include <list>
//using namespace std;
//
//
//int main()
//{
//    set<long long int> s;
//    list<long long int> l;
//
//    long long int Q, N, currentNum, max, count;
//    cin >> Q;
//
//    for (long long int i = 0; i < Q; i++)
//    {
//        cin >> N;
//        count = 0;
//        max = -1;
//
//        s.clear();
//        l.clear();
//
//        for (long long int j = 0; j < N; j++)
//        {
//            cin >> currentNum;
//
//            if (s.count(currentNum) == 0)
//            {
//                l.push_back(currentNum);
//                s.insert(currentNum);
//                count++;
//            }
//            else
//            {
//                if (max < count)
//                    max = count;
//
//                while (true)
//                {
//                    if (l.front() == currentNum)
//                    {
//                        s.erase(l.front());
//                        l.pop_front();
//                        count--;
//                        break;
//                    }
//
//                    s.erase(l.front());
//                    l.pop_front();
//                    count--;
//                }
//
//                l.push_back(currentNum);
//                s.insert(currentNum);
//                count++;
//            }
//        }
//
//        if (max < count)
//            max = count;
//
//        std::cout << max << '\n';
//    }
//
//}