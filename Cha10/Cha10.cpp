#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void elimdups(std::vector<std::string> &vs)
{
    std::sort(vs.begin(), vs.end());
    auto new_end = std::unique(vs.begin(), vs.end());
    vs.erase(new_end, vs.end());
}

void biggies(std::vector<std::string> &vs, std::size_t sz)
{
    using std::string;

    elimdups(vs);

    //按大小排序，但相同大小保持字母顺序。
    std::stable_sort(vs.begin(), vs.end(), [](string const &lhs, string const &rhs)
                     { return lhs.size() < rhs.size(); });

    // 获取第一个 size() >= sz 的迭代器
    auto wc = std::find_if(vs.begin(), vs.end(), [sz](string const &s)
                           { return s.size() >= sz; });

    //打印
    std::for_each(wc, vs.end(), [](const string &s)
                  { std::cout << s << " "; });
}

int main()
{
    std::vector<std::string> v{
        "1234", "1234", "1234", "hi~", "alan", "alan", "cp"};

    std::cout << "Test:";
    biggies(v, 3);
    std::cout << std::endl;
    return 0;
}