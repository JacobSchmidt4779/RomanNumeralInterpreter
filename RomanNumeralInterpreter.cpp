#include "RomanNumeralInterpreter.h"
#include <string>
#include <iostream>
using namespace std;

string romanConvert(int n) {

    string roman[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int num[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

    string result = "";
    int i = (sizeof(num)/sizeof(num[0])) - 1;



    while (n > 0) {
        int temp = n / num[i];
        while (temp > 0) {
            result += roman[i];
            temp--;
        }

        n = n % num[i];

        i--;
    }

    return result;
}

int main() {
    cout << "Enter a number to be converted\n";
    int num;
    cin >> num;
    if (num < 1 || num > 3999) {
        cout << "invalid number\n";
    }
    else {
        cout << romanConvert(num) + "\n";
    }
    return 0;
}
