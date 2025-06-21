#include "Money.h"
#include <iostream>

Money::Money() {
    for (int i = 0; i < DENOM_COUNT; ++i) {
        counts[i] = 0;
    }
}

Money::Money(int _counts[DENOM_COUNT]) {
    for (int i = 0; i < DENOM_COUNT; ++i) {
        counts[i] = _counts[i];
    }
}

Money::Money(const Money& other) {
    for (int i = 0; i < DENOM_COUNT; ++i) {
        counts[i] = other.counts[i];
    }
}

Money::~Money() {}

double Money::get_value(Denomination d) {
    switch (d) {
    case GRN_500: return 500.0;
    case GRN_200: return 200.0;
    case GRN_100: return 100.0;
    case GRN_50:  return 50.0;
    case GRN_20:  return 20.0;
    case GRN_10:  return 10.0;
    case GRN_5:   return 5.0;
    case GRN_2:   return 2.0;
    case GRN_1:   return 1.0;
    case COP_50:  return 0.50;
    case COP_25:  return 0.25;
    case COP_10:  return 0.10;
    case COP_5:   return 0.05;
    case COP_2:   return 0.02;
    case COP_1:   return 0.01;
    default: return 0.0;
    }
}

//Main methods
Money operator+(const Money& money, Denomination d) {
    Money result = money;
    result.counts[d] += 1;
    return result;
}

double Money::total() const {
    double sum = 0.0;
    for (int i = 0; i < DENOM_COUNT; ++i) {
        sum += counts[i] * get_value(static_cast<Denomination>(i));
    }

    return sum;
}

Money Money::from_amount(double amount) {
    Money result;
    double remaining = round(amount * 100) / 100.0;

    for (int i = 0; i < DENOM_COUNT; ++i) {
        Denomination d = static_cast<Denomination>(i);
        double value = get_value(d);
        int count = static_cast<int>(remaining / value);
        result.counts[i] = count;
        remaining -= count * value;
        remaining = round(remaining * 100.0) / 100.0;
    }
    return result;
}

Money operator/(const Money& lhs, const Money& rhs) {
    double totalLhs = lhs.total();
    double totalRhs = rhs.total();

    if (std::fabs(totalRhs) < 1e-6) {
        std::cerr << "???????: ??????? ?? ????!" << std::endl;
        return Money();
    }

    double ratio = totalLhs / totalRhs;
    return Money::from_amount(ratio);
}

Money operator/(const Money& m, double divisor) {
    if (divisor == 0.0) {
        cerr << "Error: division by zero!" << endl;
        return Money();
    }
    double result = m.total() / divisor;
    return Money::from_amount(result);
}

bool operator==(const Money& a, const Money& b) {
    return fabs(a.total() - b.total()) < 1e-6;
}

bool operator<(const Money& a, const Money& b) {
    return a.total() + 1e-6 < b.total();
}


Money::operator string() const {
    stringstream sout;
    double total_amount = total();
    int hryvnia = static_cast<int>(total_amount);
    int kopiyky = static_cast<int>(round((total_amount - hryvnia) * 100));

    sout << hryvnia << "," << setw(2) << setfill('0') << kopiyky << " grn" << endl;
    
    return sout.str();
}

ostream& operator <<(ostream& out, const Money& m) {
    out << string(m) << endl;
    return out;
}

istream& operator >>(istream& in, Money& m) {
    const char* names[DENOM_COUNT] = {
    "500 grn", "200 grn", "100 grn", "50 grn", "20 grn",
    "10 grn", "5 grn", "2 grn", "1 grn",
    "50 cop", "25 cop", "10 cop", "5 cop", "2 cop", "1 cop"
    };

    for (int i = 0; i < DENOM_COUNT; ++i) {
        cout << "Input count: " << names[i] << ": ";
        in >> m.counts[i];

        if (m.counts[i] < 0) {
            cout << "Count can not be minus!" << endl;
            m.counts[i] = 0;
        }
    }

    return in;
}


//Increment-decrement
Money& Money::operator++() {
    for (int i = 0; i < DENOM_COUNT; ++i) {
        ++counts[i];
    }
    return *this;
}

Money Money::operator++(int) {
    Money temp = *this;
    ++(*this);
    return temp;
}

Money& Money::operator--() {
    for (int i = 0; i < DENOM_COUNT; ++i) {
        if (counts[i] > 0) {
            --counts[i];
        }
    }
    return *this;
}

Money Money::operator--(int) {
    Money temp = *this;
    --(*this);
    return temp;
}
