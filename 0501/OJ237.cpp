//
// Created by Xin Sun on 2021-05-06.
//
#include <iostream>

using namespace std;
int n, ans[15], mask[15], nums[105];

void p(){
    for(int i = 1; i <= n; i++){
        if(i != 1){
            cout << " ";
        }
        cout << ans[i];
    }
    cout << endl;
    return;
}
void func(int s){
    if(s == n + 1){
        p();
        return;
    }
    for(int i = 1; i <= n; i++){
        if(mask[i] == 0) {
            ans[s] = i;
            mask[i] = 1;
            func(s + 1);
            mask[i] = 0;
        }
    }
}
void p2(){
    for(int i = 1; i <= n; i++){
        if(i != 1){
            cout << " ";
        }
        cout << nums[i];
    }
    cout << endl;
}

void func2(int idx){
    if(idx == n){
        p2();
        return;
    }
    for(int i = idx; i <= n; i++){
        swap(nums[idx], nums[i]);
        func2(idx + 1);
        swap(nums[idx], nums[i]);
    }
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        nums[i] = i;
    }
    //func(1);
    func2(1);
    return 0;
}