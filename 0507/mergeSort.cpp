//
// Created by Xin Sun on 2021-05-14.
//
#include <iostream>

using namespace std;

void mergeSort(int *arr, int l, int r){
    if(l >= r) return;
    int mid = (l + r) >> 1;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);

    int *tmp = new int[r - l + 1];
    int pl = l;
    int pr = mid + 1;
    int k = 0;
    while(pl <= mid || pr <= r){
        if((pr > r) || (pl <= mid && arr[pl] <= arr[pr])){
            tmp[k++] = arr[pl++];
        }else{
            tmp[k++] = arr[pr++];
        }
    }
    for(int i = l; i <= r; i++){
        arr[i] = tmp[i - l];
    }
    delete [] tmp;

    return;
}

int main()
{
    int n;
    int arr[100];
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    mergeSort(arr, 0, n -1);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}