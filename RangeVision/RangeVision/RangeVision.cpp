// RangeVision.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

int main()
{
    int N = 50;

    std::vector<int> p_vec;

    if (N > 1) { p_vec.push_back(2); }
    for (int i = 3; i < N; i += 2)
    {
        bool is_simple = true;
        for (int p : p_vec)
        {
            if (p * p > i) { break; } // p > sqrt(i)

            if (i % p == 0)
            {
                is_simple = false;
                break;
            }
        }

        if (is_simple) { p_vec.push_back(i); }
    }

    for (int num : p_vec) { std::cout << num << " "; }   
}

//int main()
//{
//    int N = 50;
//
//    std::vector<int> p_vec;
//
//    if (N > 1) { std::cout << 2 << " "; }
//    for (int i = 3; i < N; i += 2)
//    {
//        bool is_simple = true;
//        for (int j = 3; j <= std::sqrt(i); j += 2)
//        {
//            if (i % j == 0)
//            {
//                is_simple = false;
//                break;
//            }
//        }
//
//        if (is_simple) { p_vec.push_back(i); }
//    }
//
//    for (int num : p_vec) { std::cout << num << " "; }
//}
