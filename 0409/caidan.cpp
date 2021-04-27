//
// Created by Xin Sun on 2021-04-13.
//
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <queue>

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
public:
    void loadData(vector<int> &data)
    {
        ifstream inFile;
        // open the file stream
        inFile.open("/Users/xsun/Study/MenTou/0409/caidan.txt");
        // check if opening a file failed
        if (inFile.fail()) {
            cerr << "Error opeing a file" << endl;
            inFile.close();
            exit(1);
        }
        string line;
        int value;
        int i = 0;
        while (getline(inFile, line)) {
            istringstream iss(line);
            while(iss >> value){
                data.push_back(value);
            }
            i++;
        }
        inFile.close();
        return;
    }
    void lastStoneWeight(vector<int>& stones) {
        priority_queue<int> h{less<int>()};
        for(auto x : stones){
            h.push(x);
        }
        while (h.size() >= 6) {
            int y = h.top();
            h.pop();
            int x = h.top();
            h.pop();
            if((x - y) == 0)
            {
                continue;
            }
            h.push(y - x);

        }
        string str;
        vector<int> ans;

        for(int i = h.size() -1 ; i >= 0; i--){
            ans.push_back(h.top());
            cout << h.top() << endl;
            h.pop();
        }
        for(int i = ans.size() -1 ; i >= 0; i--){
            str += to_string(ans[i]); ;
        }
        cout << str << endl;
    }
};

int main()
{
    Solution s;
    vector<int> data;
    s.loadData(data);
    s.lastStoneWeight(data);

    return 0;
}
