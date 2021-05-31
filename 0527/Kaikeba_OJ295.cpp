//
// Created by Xin Sun on 2021-05-28.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    int math, chinese, english, geography;
};

int n;
vector<Student> student(45);

int main() {
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        Student s;
        cin >> s.name >> s.math >> s.chinese >> s.english >> s.geography;
        student.push_back(s);
    }

    sort(student.begin(), student.end(), [](const Student& a, const Student& b){
        return (a.math + a.chinese + a.english + a.geography) > (b.math + b.chinese + b.english + b.geography);
    });

    for(int i = 0; i < 3; i++){
        cout << student[i].name << endl;
    }
    return 0;
}