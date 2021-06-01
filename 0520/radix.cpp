//
// Created by sunxi on 2021-05-21.
//

#include <iostream>

using namespace std;
#define low16(a) ((a) & 0xFFFF)
#define high16(a) (((a) & 0xFFFF0000) >> 16)
void radix_sort(int *arr, int n)
{
    int cnt[65536] = {0};
    int *tmp = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++) cnt[low16(arr[i])]++;
    for(int i = 1; i < 65536; i++) cnt[i] += cnt[i - 1];
    for(int i = n - 1; i >= 0; i--) tmp[--cnt[low16(arr[i])]] = arr[i];

    for(int i = 0; i < 65536; i++) cnt[i] = 0;

    for(int i = 0; i < n; i++) cnt[high16(tmp[i])]++;
    for(int i = 1; i < 65536; i++) cnt[i] += cnt[i - 1];
    for(int i = n - 1; i >= 0; i--) arr[--cnt[high16(tmp[i])]] = tmp[i];

}


int main() {
    int n = 10;
    int arr[10];
    for(int i = 0; i < 10; i++){
        cin >> arr[i];
    }
    radix_sort(arr, 10);
    for(int i = 0; i < 10; i++){
        if(i != 0) cout << " ";
        cout << arr[i];
    }
    cout << endl;

    return 0;
}