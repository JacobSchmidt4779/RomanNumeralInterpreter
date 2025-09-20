#include <string>
#include <iostream>
#include <map>
#include <functional>
#include <random>
#include <array>
#include <chrono>
#include <fstream>

using namespace std;

const string roman[] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
const int num[] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
//map<char, int> romanToInt = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

string romanConvert(int* n) {

    //string roman[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    //int num[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

    string result = "";
    int i = (sizeof(num)/sizeof(num[0])) - 1;



    while (*n > 0) {
        int temp = *n / num[i];
        while (temp > 0) {
            result += roman[i];
            --temp;
        }

        *n = *n % num[i];

        --i;
    }

    return result;
}

//int integerConvert(string roman) {
//    bool dec_not_avail = true;
//    int curr_digit = 0;
//    int res = 0;
//
//    for (int i = roman.size() - 1; i > -1; --i) {
//        if (auto search = romanToInt.find(roman.at(i)); search != romanToInt.end()) {
//            int curr_val = search->second;
//            if (curr_val >= curr_digit) {
//                dec_not_avail = curr_val == curr_digit;
//                curr_digit = curr_val;
//            }
//            else if (!dec_not_avail && ((curr_val * 10 != curr_digit) != (curr_val * 5 != curr_digit)))  {
//                curr_val = -curr_val;
//            }
//            else {
//                return -1;
//            }
//            res += curr_val;
//        }
//    }
//    return res;
//}

int main() {
    vector<int> nums;
    fstream numbers("rand_ints.txt");
    if (!numbers.is_open()) {
        return 1;
    }

    fstream results;
    results.open("results.txt", ios_base::app);
    if (!results.is_open()) {
        return 1;
    }

    string temp;
    while (getline(numbers, temp)) {
        nums.push_back(stoi(temp));
    }
    numbers.close();

    auto start = chrono::high_resolution_clock::now();
    auto stop = chrono::high_resolution_clock::now();
    //chrono::microseconds duration;
    chrono::microseconds total_duration(0);

    start = chrono::high_resolution_clock::now();
    for (int j = 0; j < 10000; ++j) {
        
        for (int i = 0; i < nums.size(); ++i) {
            romanConvert(&nums[i]);
        }
        
        /*duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        cout << duration << "\n";
        total_duration += duration;*/
    }
    stop = chrono::high_resolution_clock::now();
    total_duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    total_duration /= 10000;
    string res_msg = "Pass by ptr    | Average duration: " + to_string(total_duration.count()) + "us\n";
    results << res_msg;
    results.close();
    cout << res_msg;

    return 0;

    //cout << "Enter a number to be converted\n";
    //int num;
    //cin >> num;
    //if (num < 1 || num > 3999) {
    //    cout << "invalid number\n";
    //}
    //else {
    //    cout << romanConvert(num) + "\n";
    //}
    //return 0;
}
