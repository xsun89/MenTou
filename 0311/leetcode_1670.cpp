//
// Created by Xin Sun on 2021-03-15.
//
#include <iostream>
using namespace std;
class Node {
public:
    int __d;
    Node *pre, *next;
    Node(int x = 0, Node *next = nullptr, Node *pre = nullptr) : __d(x), pre(pre), next(next){}
    void insert_pre(Node *p){
        p->pre = this->pre;
        p->next = this;
        if(this->pre) this->pre->next = p;
        this->pre = p;
        return;
    }
    void insert_next(Node *p)
    {
        p->pre = this;
        p->next = this->next;
        if(this->next) this->next->pre = p;
        this->next = p;

        return;
    }
    void delete_pre()
    {
        if(this->pre == nullptr) return;
        Node *p = this->pre;
        if(p) this->pre = p->pre;
        if(p->pre) p->pre->next = this;
        delete p;
        return;
    }
    void delete_next()
    {
        if(this->next == nullptr) return;
        Node *p = this->next;
        if(p) this->next = p->next;
        if(p->next) p->next->pre = this;

        delete p;

        return;
    }



};

class Queue {
public:
    Queue() : cnt(0){
        head.next = &tail;
        tail.pre = &head;
        head.pre = nullptr;
        tail.next = nullptr;
    }

    void push_back(int val){
        tail.insert_pre(new Node(val));
        cnt += 1;
        return;
    }
    void push_front(int val){
        head.insert_next(new Node(val));
        cnt += 1;
    }
    int pop_back(){
        if(isEmpty()) return -1;
        int ret = tail.pre->__d;
        tail.delete_pre();
        cnt--;
        return ret;
    }
    int pop_front(){
        if(isEmpty()) return -1;
        int ret = head.next->__d;
        head.delete_next();
        cnt--;
        return ret;
    }

    int front(){
        return head.next->__d;
    }

    int back(){
        return tail.pre->__d;
    }
    bool isEmpty()
    {
        return head.next == &tail;
    }
    int size(){
        return cnt;
    }
private:
    Node head, tail;
    int cnt;
};

class FrontMiddleBackQueue {
public:
    Queue q1, q2;
    FrontMiddleBackQueue() {

    }

    void pushFront(int val) {
        q1.push_front(val);
        update();
        return;
    }

    void pushMiddle(int val) {
        if(q1.size() > q2.size()){
            q2.push_front(q1.back());
            q1.pop_back();
        }

        q1.push_back(val);
        return;
    }

    void pushBack(int val) {
        q2.push_back(val);
        update();
        return;
    }

    int popFront() {
        if(isEmpty()) return -1;
        int ret = q1.front();
        q1.pop_front();
        update();
        return ret;
    }

    int popMiddle() {
        if(isEmpty()) return -1;
        int ret = q1.back();
        q1.pop_back();
        update();
        return ret;
    }

    int popBack() {
        if(isEmpty()) return -1;
        int ret;
        if(q2.isEmpty()){
            ret = q1.back();
            q1.pop_back();
        }else{
            ret = q2.back();
            q2.pop_back();
        }
        update();

        return ret;
    }

    bool isEmpty(){
        return q1.size() == 0;
    }
    void update(){
        if(q1.size() < q2.size()){
            q1.push_back(q2.front());
            q2.pop_front();
        }
        if(q1.size() == q2.size() + 2){
            q2.push_front(q1.back());
            q1.pop_back();
        }

        return;
    }
};

int main()
{
    FrontMiddleBackQueue q;
    q.pushFront(1);
    q.pushBack(2);
    q.pushMiddle(3);  // [1, 3, 2]
    q.pushMiddle(4);  // [1, 4, 3, 2]
    q.popFront();     // return 1 -> [4, 3, 2]
    q.popMiddle();    // return 3 -> [4, 2]
    q.popMiddle();    // return 4 -> [2]
    q.popBack();      // return 2 -> []
    q.popFront();     // return -1 -> [] (The queue is empty)

    return 0;
}
