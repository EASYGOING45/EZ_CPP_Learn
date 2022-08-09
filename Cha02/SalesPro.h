/*
 *C++ Primer 5Th Learning Note
 */

//通过预编译指令防止重复包含
#ifndef SALESPRO_H
#define SALESPRO_H

#include <iostream>
#include <string>

//定义Sale类
class Sales_item
{
    //定义一堆友元函数 运算符重载
    friend std::istream &operator>>(std::istream &, Sales_item &);
    friend std::ostream &operator<<(std::ostream &, const Sales_item &);
    friend bool operator<(const Sales_item &, const Sales_item &);
    friend bool operator==(const Sales_item &, const Sales_item &);

public:
    Sales_item() = default;
    Sales_item(const std::string &book) : bookNo(book) {}
    Sales_item(std::istream &is) { is >> *this; }

public:
    Sales_item &operator+=(const Sales_item &);

    std::string isbn() const { return bookNo; }
    double avg_price() const;

private:
    std::string bookNo;
    unsigned units_sold = 0; //销售量
    double revenue = 0.0;    //收入
};

inline bool compareIsbn(const Sales_item &lhs, const Sales_item &rhs)
{
    return lhs.isbn() == rhs.isbn();
}

// 非成员二元运算符：必须为每个操作数声明一个参数
Sales_item operator+(const Sales_item &, const Sales_item &);

inline bool operator==(const Sales_item &lhs, const Sales_item &rhs)
{
    return lhs.units_sold == rhs.units_sold && lhs.isbn() == rhs.isbn() && lhs.revenue == rhs.revenue;
}

inline bool operator!=(const Sales_item &lhs, const Sales_item &rhs)
{
    return !(lhs == rhs);
}

// 假设两个对象都引用同一个 ISBN
Sales_item &Sales_item::operator+=(const Sales_item &rhs)
{
    this->units_sold += rhs.units_sold;
    this->revenue += rhs.revenue;
    return *this;
}

Sales_item operator+(const Sales_item &lhs, const Sales_item &rhs)
{
    Sales_item ret(lhs); //拷贝构造
    ret += rhs;
    return ret;
}

std::istream &operator>>(std::istream &in, Sales_item &s)
{
    double price;
    in >> s.bookNo >> s.units_sold >> price;
    if (in)
    {
        s.revenue = s.units_sold * price;
    }
    else
    {
        s = Sales_item(); // 输入失败：将对象重置为默认状态
    }
    return in;
}

std::ostream &operator<<(std::ostream &out, const Sales_item &s)
{
    out << s.isbn() << " " << s.units_sold << " " << s.revenue << " " << s.avg_price();
    return out;
}

double Sales_item::avg_price() const
{
    //计算平均销售价格
    if (units_sold)
    {
        return revenue / units_sold;
    }
    else
    {
        return 0;
    }
}
#endif