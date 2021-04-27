//
// Created by sunxi on 2021-04-27.
//
#include <iostream>

using namespace std;

int a, b, l, ta, tb;
int main()
{
    cin >> a >> b >> l;
    double raw = (double) a / b;
    double now = 999999999;
    for (int i = 1; i <= l; i++){
        for (int j = 1; j <= l; j++){
            double t = (double) i / j;
            if(t >= raw && now - raw > t - raw){
                now = t;
                ta = i;
                tb = j;
            }
        }
    }
    cout << ta << " " << tb << endl;
    return 0;
}
