#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> belowTwenty = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
                                  "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
                                  "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> thousands = {"", "Thousand", "Million", "Billion"};

    string numberToWords(int num) {
        if (num == 0) return "Zero";
        return helper(num);
    }

private:
    string helper(int num) {
        if (num < 20) {
            return belowTwenty[num];
        } else if (num < 100) {
            return tens[num / 10] + (num % 10 ? " " + helper(num % 10) : "");
        } else if (num < 1000) {
            return belowTwenty[num / 100] + " Hundred" + (num % 100 ? " " + helper(num % 100) : "");
        } else {
            for (int i = 3; i >= 0; --i) {
                int unit = pow(1000, i);
                if (num >= unit) {
                    return helper(num / unit) + " " + thousands[i] + (num % unit ? " " + helper(num % unit) : "");
                }
            }
        }
        return "";
    }
};