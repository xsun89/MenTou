//
// Created by Xin Sun on 2021-04-09.
//
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>


using namespace std;

template <typename T>
class Heap : public vector<T>{
public:
    template<typename Func_T>
    Heap(Func_T cmp): cmp(cmp){}
    void push(const T&a){
        this->push_back(a);
        push_heap(this->begin(), this->end(), cmp);
        return;
    }
    void pop(){
        pop_heap(this->begin(), this->end(), cmp);
        this->pop_back();
        return;
    }

    T &top(){
        return this->at(0);
    }
private:
    function<bool(T, T)> cmp;
};

int main()
{
    Heap<int> h1{less<int>()};
    Heap<int> h2{greater<int>()};
    h1.push(3); h1.push(2); h1.push(4); h1.push(1);
    h2.push(3); h2.push(2); h2.push(4); h2.push(1);

    while(h1.size()){
        cout << h1.top() << " ";
        h1.pop();
    }
    cout << endl;
    while(h2.size()){
        cout << h2.top() << " ";
        h2.pop();
    }
    cout << endl;
    return 0;
}