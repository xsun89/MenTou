//
// Created by Xin Sun on 2021-03-19.
//
#include <iostream>
#include <stack>
using namespace std;
class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        s2.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        transfer();
        int ret = -1;
        if(!s1.empty()) {
            ret = s1.top();
            s1.pop();
        }

        return ret;
    }

    /** Get the front element. */
    int peek() {
        transfer();
        return s1.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        if(s1.empty() && s2.empty())
        {
            return true;
        }else{
            return false;
        }
    }
    void transfer(){
        if(!s1.empty()) return;
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }

        return;
    }
};
int main()
{
    MyQueue q;
    q.push(1);
    q.push(2);
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    return 0;
}