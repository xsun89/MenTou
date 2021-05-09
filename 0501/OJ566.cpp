//
// Created by Xin Sun on 2021-05-04.
//
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Node {
    string name;
    vector<string> data;
};
int n, m, cnt;
Node p[5005];

int main() {
    cin >> n >> m;
    unordered_map<string, int> mp;
    for (int i = 0; i < m; i++) {
        string a, b;
        cin >> a >> b;
        if (mp.count(a)) {
            p[mp[a]].data.push_back(b);
        } else {
            cnt++;
            mp[a] = cnt;
            p[mp[a]].name = a;
            p[mp[a]].data.push_back(b);
        }
    }
    for (int i = 1; i <= n ; i++) {
        cout << p[i].name << " ";
        for (int j = 0; j < p[i].data.size(); j++) {
            if (j != 0) {
                cout << " ";
            }
            cout << p[i].data[j];
        }
        cout << endl;
    }
    return 0;
}