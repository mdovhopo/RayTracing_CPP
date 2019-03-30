#include <thread>
#include <iostream>


void aux(int &a, int &b)
{
    ++a;
    ++b;
}


int main()
{
    int a;
    std::cin >> a;
    std::thread thr(aux, std::ref(a), std::ref(a));
    thr.join();
    std::cout << a;
    return 0;
}