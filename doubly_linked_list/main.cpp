#include <iostream>
#include "list.hpp"

int main()
{
    linked_list<int> ls;
    ls.push_back(10);
    ls.push_back(20);
    ls.push_back(555);
    ls.push_back(557);
    ls.push_front(550);
    ls.insert(0,0);
    ls.insert(2,500);
    ls.print();

    //linked_list<int> ls1 = ls;
    //ls1.print();

    /*ls.insert(0, 400);
    ls.insert(4, 500);
    ls.print();

    ls.insert(2, 600);
    ls.print();

    ls.insert(4, 700);
    ls.print();*/

    ls.remove_at(2);
    std::cout << "after free\n";
    ls.print();
}

