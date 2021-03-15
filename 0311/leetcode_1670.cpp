//
// Created by Xin Sun on 2021-03-15.
//
#include <iostream>
#include <queue>
using namespace std;
class Node {
public:
    Node(int x) : __d(x){}

private:
    int __d;
    Node *pre, *next;

};

class _queue {
public:
    _queue();
private:
    Node *head, *tail;
};

int main()
{
    queue<int> a;
    int c = a.size();
    return 0;
}
