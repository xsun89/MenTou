//
// Created by Xin Sun on 2021-03-15.
//At a lemonade stand, each lemonade costs $5.
//
//Customers are standing in a queue to buy from you, and order one at a time (in the order specified by bills).
//
//Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill.  You must provide the correct change to each customer, so that the net transaction is that the customer pays $5.
//
//Note that you don't have any change in hand at first.
//
//Return true if and only if you can provide every customer with correct change.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int b5 = 0, b10 = 0, b20 = 0;
        int i = 0;
        while(i < bills.size()) {
            if (bills[i] == 5) b5++;
            if (bills[i] == 10) {
                if (b5 == 0) {
                    return false;
                } else {
                    b10++;
                    b5--;
                }
            }
            if (bills[i] == 20) {
                if (b10 > 0 && b5 > 0) {
                    b20++;
                    b10--;
                    b5--;
                } else if (b10 > 0 && b5 == 0) {
                    return false;
                } else if (b10 == 0 && b5 > 2) {
                    b5 -= 3;
                    b20++;
                } else {
                    return false;
                }
            }
            i++;
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<int> v;
    //[5,5,5,10,20]
    v.push_back(5);
    v.push_back(5);
    v.push_back(5);
    v.push_back(10);
    v.push_back(20);
    bool ret = s.lemonadeChange(v);
    cout << ret << endl;
    return 0;
}

