#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

class fraction {
private:
    int numerator;
    int denominator;

public:
    fraction(int n, int d) {
        numerator = n;
        denominator = d;
        simplify();
    }

    void add(fraction f) {
        numerator = numerator * f.denominator + f.numerator * denominator;
        denominator *= f.denominator;
        simplify();
    }

    void mult(fraction f) {
        numerator *= f.numerator;
        denominator *= f.denominator;
        simplify();
    }

    void div(fraction f) {
        numerator *= f.denominator;
        denominator *= f.numerator;
        simplify();
    }

    void simplify() {
        int common = gcd(numerator, denominator);
        numerator /= common;
        denominator /= common;

        if (denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }
    }

    void display() {
        cout << numerator << " / " << denominator;
    }
};

int main() {
    string operation;
    char f;
    int a, b, c, d;

    while (cin >> a >> f >> b >> operation >> c >> f >> d) {
        fraction f1(a, b);
        fraction f2(c, d);

        if (operation == "+") {
            f1.add(f2);
        } else if (operation == "*") {
            f1.mult(f2);
        } else if (operation == "div") {
            f1.div(f2);
        }

        f1.display();
        cout << endl;
    }

    return 0;
}
