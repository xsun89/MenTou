//
// Created by Xin Sun on 2021-03-15.
//Given two strings a and b, return true if you can swap two letters in a so the result is equal to b, otherwise, return false.
//
//Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at a[i] and b[j]. For example, swapping at indices 0 and 2 in "abcd" results in "cbad".
#include <iostream>
using namespace std;

class Solution{
public:
    bool hasDuplicates(string a){
        int cnt[24] = {0};
        for(int i = 0; a[i]; i++){
            cnt[a[i] - 'a']++;
            if(cnt[a[i] - 'a'] > 1){
                return true;
            }
        }

        return false;
    }
    bool buddyStrings(string a, string b) {
        if(a == b) {
            return hasDuplicates(a);
        }
        if(a.size() != b.size()) return false;
        int p1 = 0, p2 = 0, q1 = 0, q2 = 0, cnt = 0;
        for(int i = 0; a[i]; i++){
            if(a[i] == b[i]) {
                continue;
            }
            if(a[i] != b[i]){
                cnt++;
                if(cnt == 1){
                    p1 = i;
                    q1 = i;
                }
                if(cnt == 2){
                    p2 = i;
                    q2 = i;
                }
                if(cnt > 2){
                    return false;
                }
            }

        }
        if(a[p1] == b[q2] && a[p2] == b[q1]){
            return true;
        }
        return false;
    }
};
int main()
{
    //"aaaaaaabc"
    //"aaaaaaacb"
    Solution s;
    cout << s.buddyStrings("aaaaaaabc", "aaaaaaacb") << endl;
    return 0;
}
