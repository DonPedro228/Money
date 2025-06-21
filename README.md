💰 Ukrainian Currency Handling with the Money Class

This C++ class provides a structured way to represent and manipulate monetary amounts using Ukrainian currency denominations. It supports various operations such as addition, division, comparison, and conversion between monetary amounts and their string representations.
📦 Project Overview

The Money class models Ukrainian currency using the following denominations:
Banknotes (in UAH):

    500 UAH

    200 UAH

    100 UAH

    50 UAH

    20 UAH

    10 UAH

    5 UAH

    2 UAH

    1 UAH

Coins (in UAH):

    0.50 UAH

    0.25 UAH

    0.10 UAH

    0.05 UAH

    0.02 UAH

    0.01 UAH

The class provides methods to:

    Add denominations to a monetary amount.

    Divide a monetary amount by another amount or a scalar.

    Compare two monetary amounts for equality or relative size.

    Convert a monetary amount to a string representation.

    Parse a string to create a monetary amount.

🛠️ Usage Instructions
1. Include the Header File

#include "Money.h"

2. Create a Money Object

Money wallet;

3. Input Monetary Amount

cin >> wallet;

4. Output Monetary Amount

cout << wallet;

5. Perform Operations

Money updatedWallet = wallet + GRN_500; // Add one 500 UAH banknote
Money halvedWallet = wallet / 2.0;      // Divide amount by 2
bool isEqual = (wallet == updatedWallet); // Check if amounts are equal

💡 Example Code

#include "Money.h"
#include <iostream>
using namespace std;

int main() {
    Money wallet1, wallet2;

    cout << "Enter the first wallet amount:\n";
    cin >> wallet1;
    cout << "First wallet: " << wallet1 << "\n";

    cout << "Enter the second wallet amount:\n";
    cin >> wallet2;
    cout << "Second wallet: " << wallet2 << "\n";

    Money ratio = wallet1 / wallet2;
    cout << "wallet1 / wallet2 = " << ratio << "\n";

    cout << "wallet1 == wallet2? " << boolalpha << (wallet1 == wallet2) << "\n";
    cout << "wallet1 < wallet2? " << boolalpha << (wallet1 < wallet2) << "\n";

    double divisor;
    cout << "Enter divisor (double): ";
    cin >> divisor;
    Money result = wallet1 / divisor;
    cout << "wallet1 / " << divisor << " = " << result << "\n";

    return 0;
}

🔧 Class Methods Overview

    Constructors & Destructor

        Money(): Default constructor.

        Money(int counts[DENOM_COUNT]): Initializes with specific counts for each denomination.

        Money(const Money&): Copy constructor.

        ~Money(): Destructor.

    Static Methods

        static double get_value(Denomination d): Returns the value of a given denomination.

    Operator Overloads

        operator +(const Money& money, Denomination d): Adds one unit of a denomination to the monetary amount.

        operator /(const Money& m, double divisor): Divides the monetary amount by a scalar.

        operator /(const Money& lhs, const Money& rhs): Divides one monetary amount by another.

        operator ==(const Money& a, const Money& b): Checks if two monetary amounts are equal.

        operator <(const Money& a, const Money& b): Checks if one monetary amount is less than another.

    Conversion Methods

        double total() const: Returns the total monetary value.

        static Money from_amount(double amount): Creates a Money object from a decimal amount.

        operator string() const: Converts the monetary amount to a string representation.

    Stream Operators

        friend ostream& operator <<(ostream&, const Money&): Outputs the monetary amount.

        friend istream& operator >>(istream&, Money&): Inputs the monetary amount.

    Increment/Decrement Operators

        Money& operator ++(): Pre-increment.

        Money operator ++(int): Post-increment.

        Money& operator --(): Pre-decrement.

        Money operator --(int): Post-decrement.

✅ Example Output

Enter the first wallet amount:
Input count for 500 grn: 2
Input count for 200 grn: 1
Input count for 100 grn: 0
Input count for 50 grn: 1
Input count for 20 grn: 0
Input count for 10 grn: 2
Input count for 5 grn: 0
Input count for 2 grn: 1
Input count for 1 grn: 0
Input count for 50 cop: 0
Input count for 25 cop: 0
Input count for 10 cop: 1
Input count for 5 cop: 0
Input count for 2 cop: 0
Input count for 1 cop: 0
First wallet: 720.10 grn

Enter the second wallet amount:
Input count for 500 grn: 1
Input count for 200 grn: 0
Input count for 100 grn: 1
Input count for 50 grn: 0
Input count for 20 grn: 0
Input count for 10 grn: 1
Input count for 5 grn: 0
Input count for 2 grn: 0
Input count for 1 grn: 0
Input count for 50 cop: 0
Input count for 25 cop: 0
Input count for 10 cop: 1
Input count for 5 cop: 0
Input count for 2 cop: 0
Input count for 1 cop: 0
Second wallet: 600.10 grn

wallet1 / wallet2 = 1.20000 grn
wallet1 == wallet2? false
wallet1 < wallet2? false

Enter divisor (double): 2
wallet1 / 2 = 360.05 grn



THIS IS BASIC PET PROJECT FOR STUDING OPERATOR OVERLOAD🧑‍💻
