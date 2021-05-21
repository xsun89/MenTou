//
// Created by Xin Sun on 2021-05-13.
//

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> data;
int n;
void quickSort(vector<int> &arr, int l, int r){
    if(l >= r) return;
    int x = l;
    int y = r;
    int base = arr[x];

    while (x < y) {
        while (x < y && arr[y] >= base) y--;
        if (x < y) arr[x++] = arr[y];
        while (x < y && arr[x] <= base) x++;
        if (x < y) arr[y--] = arr[x];
    }
    arr[x] = base;

    quickSort(arr, l, x - 1);
    quickSort(arr, x + 1, r);

    return;
}
int main() {
    cin >> n;
    int tmp;
    unordered_map<int, int> mp(n);
    for(int i = 0, j = 0; i < n; i++){
        cin >> tmp;
        mp[tmp] += 1;
        if(mp[tmp] > 1){
            continue;
        }
        data.push_back(tmp);
    }
    quickSort(data, 0, data.size() - 1);

    for(int i = 0; i < data.size(); i++){
        cout << data[i] << endl;
    }
    return 0;
}