//
// Created by Xin Sun on 2021-04-23.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int ans11[10000][2], ans21[10000][2];
vector<string> data;

void loadData(vector<vector<long long>> &data)
{
    ifstream inFile;
    // open the file stream
    inFile.open("/Users/xsun/CLionProjects/Haizei/MenTou/0402/caidan.txt");
    // check if opening a file failed
    if (inFile.fail()) {
        cerr << "Error opeing a file" << endl;
        inFile.close();
        exit(1);
    }
    string line;
    long long value;
    int i = 0;
    while (getline(inFile, line)) {
        istringstream iss(line);
        if(data.size() == i){
            data.push_back(vector<long long>());
        }
        while(iss >> value){
            data[i].push_back(value);
        }
        i++;
    }
    inFile.close();
    return;
}
int main()
{


    return 0;
}