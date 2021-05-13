//
// Created by Xin Sun on 2021-05-10.
//
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        int l = head->val, r = head->val;
        double mid;
        ListNode *p = head, *q, *h1 = nullptr, *h2 = nullptr;
        while(p) l = min(p->val, l), r = max(p->val, r), p =p->next;
        if(l == r) return head;
        mid = (l + r) / 2.0;
        p = head;
        while(p)
        {
            q = p->next;
            if(p->val <= mid){
                p->next = h1;
                h1 = p;
            }else{
                p->next = h2;
                h2 = p;
            }
            p = q;
        }
        h1 = sortList(h1);
        h2 = sortList(h2);

        p = h1;
        while(p->next){
            p = p->next;
        }
        p->next = h2;
        return h1;
    }
};