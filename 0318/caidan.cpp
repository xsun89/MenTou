//
// Created by Xin Sun on 2021-03-23.
//
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <stack>
#include <vector>
#include <sstream>

using namespace std;
class Solution {
    public:
        vector<pair<string, int>> data;
        void loadData(){
            ifstream inFile;
            // open the file stream
            inFile.open("/Users/xsun/CLionProjects/MenTou/0318/0318.data");
            // check if opening a file failed
            if (inFile.fail()) {
                cerr << "Error opeing a file" << endl;
                inFile.close();
                exit(1);
            }
            string line;
            string op;
            int value;
            while (getline(inFile, line)) {
                istringstream iss(line);

                if (iss >> op){
                    if(op == "push" && iss >> value){
                        data.push_back(make_pair(op, value));
                        //cout << "op = " << op << " value = " << value << endl;
                    }else {
                        data.push_back(make_pair(op, -1000000));
                        //cout << op << endl;
                    }
                }else{
                    break;
                }
            }
            // close the file stream
            inFile.close();
        }
        long long getNumber(){
            int cnt = 1;
            stack<int> st;
            long long ans = 0;
            for (int i = 0; i < data.size(); i++){
                if(data[i].first == "push"){
                    st.push(data[i].second);
                }else{
                    ans += cnt * st.top();
                    st.pop();
                    cnt++;
                }
            }

            return ans;
        }
};
int main()
{
    Solution s;
    s.loadData();
    cout << s.getNumber() << endl;
    return 0;
}
