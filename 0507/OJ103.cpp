//
// Created by Xin Sun on 2021-05-13.
//
#include <iostream>
#include <unordered_map>

using namespace std;

string data[105];
int n;
void quickSort(pair<string, string> *arr, int l, int r){
    if(l >= r) return;
    int x = l;
    int y = r;
    pair<string, string> base = arr[x];

    while (x < y) {
        while (x < y && arr[y].second >= base.second) y--;
        if (x < y) arr[x++] = arr[y];
        while (x < y && arr[x].second <= base.second) x++;
        if (x < y) arr[y--] = arr[x];
    }
    arr[x] = base;

    quickSort(arr, l, x - 1);
    quickSort(arr, x + 1, r);

    return;
}
int main() {
    cin >> n;
    pair<string, string> p[n];
    for(int i = 0; i < n; i++){
        cin >> data[i];
        string date = data[i].substr(6, 8);
        cout << data[i] << "   " << date << endl;
        p[i] = make_pair(data[i], date);
    }
    quickSort(p, 0, n - 1);

    for(int i = 0; i < n; i++){
        cout << p[i].first << endl;
    }
    return 0;
}
