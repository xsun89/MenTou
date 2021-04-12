//
// Created by Xin Sun on 2021-04-09.
//

#include <iostream>
using namespace std;

#define MAX_N 1000
int data[MAX_N + 5], cnt = 0;
int size(){ return cnt;}

void shift_up(int ind) {
    int parent = (ind - 1) >> 1;
    while(parent && data[ind] > data[parent]){
        swap(data[ind], data[parent]);
        ind = parent;
        parent = (ind - 1) >> 1;
    }

    return;
}

void shift_down(int ind) {

    int l = (ind << 1) + 1, r = (ind << 1) + 2;
    while(l <= cnt - 1){
        int ind_t = ind;
        if(data[l] > data[ind_t]) ind_t = l;
        if(r <= cnt -1 && data[r] > data[ind_t]) ind_t = r;
        if(ind == ind_t) break;
        swap(data[ind], data[ind_t]);
        ind = ind_t;
        l = (ind << 1) + 1;
        r = (ind << 1) + 2;
    }

    return;
}

int pop(){
    if(size() == 0) return -1;
    data[0] = data[cnt - 1];
    cnt--;
    shift_down(0);
    return 0;
}

int top(){
    if(size() == 0) return -1;
    return data[0];
}

int push(int x)
{
    if(cnt >= MAX_N) return -1;
    data[cnt++] = x;
    shift_up(cnt - 1);
    return 0;
}

void output()
{
    printf("[");
    for(int i = 0; i < cnt; i++){
        printf("%d ", data[i]);
    }
    printf("]\n");
}
int main()
{
    int op, val;
    while(cin >> op){
        switch(op){
            case 0:{
                cin >> val;
                printf("push %d to heap\n", val);
                push(val);
                output();
            } break;
            case 1: {
                printf("pop %d from heap\n", top());
                pop();
                output();
            } break;
        }
    }
}