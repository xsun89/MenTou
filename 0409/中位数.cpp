//
// Created by Xin Sun on 2021-04-12.
//
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
class Heap : public vector<T> {
public:
    template<typename Func_T>
    Heap(Func_T cmp): cmp(cmp) {}

    void push(const T &a) {
        this->push_back(a);
        push_heap(this->begin(), this->end(), cmp);
        return;
    }

    void pop() {
        pop_heap(this->begin(), this->end(), cmp);
        this->pop_back();
        return;
    }

    T &top() {
        return this->at(0);
    }

private:
    function<bool(T, T)> cmp;
};

class MedianFinder {
private:
    Heap<int> h1;
    Heap<int> h2;
public:
    /** initialize your data structure here. */
    MedianFinder() : h1{less<int>()}, h2{greater<int>()}{

    }

    void addNum(int num) {
        if(h1.size() == 0 || num <= h1.top()) {
            h1.push(num);
        }else{
            h2.push(num);
        }
        if(h2.size() > h1.size()){
            h1.push(h2.top());
            h2.pop();
        }
        if (h1.size() == h2.size() + 2) {
            h2.push(h1.top());
            h1.pop();
        }
    }

    double findMedian() {
        int size = h1.size() + h2.size();
        if (size % 2 == 1) {
            return 1.0 * h1.top();
        }
        return (h1.top() + h2.top()) / 2.0;
    }
};

int main(){
    return 0;
}