#pragma once
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;


enum Denomination {
    GRN_500, GRN_200, GRN_100, GRN_50, GRN_20,
    GRN_10, GRN_5, GRN_2, GRN_1,
    COP_50, COP_25, COP_10, COP_5, COP_2, COP_1,
    DENOM_COUNT
};


class Money {
private:
    int counts[DENOM_COUNT] = { 0 };
public:
    //Constructors && destructors
    Money();
    Money(int _counts[DENOM_COUNT]);
    Money(const Money&);
    ~Money();

    //Getters
    static double get_value(Denomination d);

    //Main functions
    friend Money operator +(const Money& money, Denomination d);
    friend Money operator/(const Money& m, double divisor);
    friend Money operator/(const Money& lhs, const Money& rhs);
    friend bool operator==(const Money& a, const Money& b);
    friend bool operator<(const Money& a, const Money& b);

    double total() const;
    static Money from_amount(double amount);


    //Auxiliary functions
    operator string() const;

    friend ostream& operator <<(ostream&, const Money&);
    friend istream& operator >>(istream&, Money&);

    Money& operator ++();
    Money& operator --();
    Money operator ++(int);
    Money operator --(int);
};