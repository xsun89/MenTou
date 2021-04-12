//
// Created by Xin Sun on 2021-04-09.
//
#include <iostream>
#include <vector>

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
class Solution {
  vector<int> getLesastNumbers(vector<int> &arr, int k){
      if(k > arr.size()) return arr;
      vector<int> ans(k);
      for(int i = 0; i < k; i++){
          ans.push_back(arr[i]);
      }
      make_heap(ans.begin(), ans.end());
      for(int i = k; i < arr.size(); i++){
          if(ans[0] > arr[i]){
              ans[0] = arr[i];
              make_heap(ans.begin(), ans.end());
          }
      }

      return ans;

  }

  vector<int> getLesastNumbers2(vector<int> &arr, int k){
      Heap<int> h{less<int>()};
      for(auto x : arr){
          h.push(x);
          if(h.size() > k) h.pop();
      }

      return h;
  }
};

int main()
{
    return 0;
}
