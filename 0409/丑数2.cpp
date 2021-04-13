//
// Created by Xin Sun on 2021-04-12.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
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
    Heap<long long> h{greater<long long>()};
    set<long long> s;
    vector<long long> nums = {5, 3, 2};
    int nthUglyNumber(int n) {
        long long t = 0;
        h.push(1);
        s.insert(1);
        while(n--){
            t = h.top();
            h.pop();
            for(auto x : nums){
                if(s.find(t * x) != s.end()){
                    continue;
                }
                h.push(t * x);
                s.insert(t * x);
            }
        }
        return t;
    }
};

int main() {

    Solution s;
    int ans = s.nthUglyNumber(2);
    cout << ans << endl;

    return 0;
}