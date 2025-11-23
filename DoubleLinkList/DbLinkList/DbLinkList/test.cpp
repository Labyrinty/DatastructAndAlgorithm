#include <iostream>
#include "DbLinkList.h"

template<class Iterator>	//在指定范围内输出元素
void display(Iterator first, Iterator last)
{
    for (; first != last; ++first)
       std:: cout << *first << ' ';
    std::cout << std::endl;
}

int main() {
    DoubleLinkList<int> L;
    for (int i = 0; i < 10; i++)
    {
        L.Insert(L.Begin(), i + 100);
    }
    display(L.Begin(), L.End());
    L.Erase(L.Begin());
    display(L.Begin(), L.End());
    DoubleLinkList<int> L2;
    L2 = L;
    display(L2.Begin(), L2.End());
    for (int i = 0; i < 20; i++)
    {
        L2.Insert(L2.Begin(), i * 2);
    }
    display(L2.Begin(), L2.End());
    L.Erase(L2.Begin());
    display(L2.Begin(), L2.End());

    const DoubleLinkList<int> L3(L2);
    display(L2.Begin(), L2.End());

    return 0;
}