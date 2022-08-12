#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>
using std::copy;
using std::cout;
using std::endl;
using std::list;

template <typename Sequence>
void print(Sequence const &seq)
{
    for (const auto &i : seq)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};

    //使用迭代器
    list<int> lst1;
    copy(vec.cbegin(), vec.cend(), inserter(lst1, lst1.begin()));
    print(lst1);

    //使用 back_inserter
    list<int> lst2;
    copy(vec.cbegin(), vec.cend(), back_inserter(lst2));
    print(lst2);

    //使用 front_inserter
    list<int> lst3;
    copy(vec.cbegin(), vec.cend(), front_inserter(lst3));
    print(lst3);
}
