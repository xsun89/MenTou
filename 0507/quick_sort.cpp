//
// Created by Xin Sun on 2021-05-08.
//
#include <iostream>

using namespace std;

void quickSort(int *arr, int l, int r) {
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
    int arr[10] = {2, 3, 1, 0, 4, 5, 9, 6, 8, 7};
    quickSort(arr, 0, 9);
    for(int i = 0; i < 10; i++){
        if(i != 0) cout << " ";
        cout << arr[i];
    }
    cout << endl;
    return 0;
}
