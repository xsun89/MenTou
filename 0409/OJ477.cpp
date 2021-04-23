//
// Created by Xin Sun on 2021-04-19.
//
#include <iostream>
#include <string>

using namespace std;
bool isValid(char c){
    if(c == 'A' || c == 'O' || c == 'E' || c == 'I' || c == 'U'){
        return true;
    } else{
        return false;
    }
}
int main()
{
    string s;
    cin >> s;


    int ans = 0;
    int k = 0;
    while(isValid(s[k]) != true){
        k++;
    }
    int pre = k;
    int next = k;
    for(int i = k + 1; i < s.size(); i++){
        if(isValid(s[i])){
            next = i;
            ans = max(ans, next - pre);
            pre = i;
        }
    }

    cout << ans << endl;
    return 0;
}
