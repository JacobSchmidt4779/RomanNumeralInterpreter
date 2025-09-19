#include "RomanNumeralInterpreter.h"
#include <string>
#include <iostream>
#include <map>
#include <functional>
using namespace std;

const string roman[] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
const int num[] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
map<char, int> romanToInt = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

string romanConvert(int n) {

    /*string roman[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int num[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};*/

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

int integerConvert(string roman) {
    int curr_digit = 0;
    int res = 0;

    for (int i = roman.size() - 1; i > -1; --i) {
        if (auto search = romanToInt.find(roman.at(i)); search != romanToInt.end()) {
            int curr_val = search->second;
            if (curr_val >= curr_digit) {
                curr_digit = curr_val;
            }
            else {
                curr_val = -curr_val;
            }
            res += curr_val;
        }
    }
    return res;
}

int main() {
    int res = integerConvert("MMCDLXXXVII");
    cout << res << "\n";
    return 0;
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
