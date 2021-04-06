//
// Created by Xin Sun on 2021-03-15.
//Given an array of integers arr, sort the array by performing a series of pancake flips.
//
//In one pancake flip we do the following steps:
//
//Choose an integer k where 1 <= k <= arr.length.
//Reverse the sub-array arr[0...k-1] (0-indexed).
//For example, if arr = [3,2,1,4] and we performed a pancake flip choosing k = 3, we reverse the sub-array [3,2,1], so arr = [1,2,3,4] after the pancake flip at k = 3.
//
//Return an array of the k-values corresponding to a sequence of pancake flips that sort arr. Any valid answer that sorts the array within 10 * arr.length flips will be judged as correct.
//Input: arr = [3,2,4,1]
//Output: [4,2,4,3]
//Explanation:
//We perform 4 pancake flips, with k values 4, 2, 4, and 3.
//Starting state: arr = [3, 2, 4, 1]
//After 1st flip (k = 4): arr = [1, 4, 2, 3]
//After 2nd flip (k = 2): arr = [4, 1, 2, 3]
//After 3rd flip (k = 4): arr = [3, 2, 1, 4]
//After 4th flip (k = 3): arr = [1, 2, 3, 4], which is sorted.
// [9,8,4,1.3,2,6,5,7]

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverse(vector<int> &arr, int n, vector<int> &ind) {
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            swap(arr[i], arr[j]);
            ind[arr[i]] = i;
            ind[arr[j]] = j;
        }

        return;
    }

    vector<int> pancakeSort(vector<int> &arr) {
        vector<int> ind(arr.size() + 1);
        vector<int> ret;
        for (int i = 0; i < arr.size(); i++) {
            //arr = [3, 2, 4, 1], ind[3] = 0, ind[2] = 1, ind[4] = 2, ind[1] = 3;
            ind[arr[i]] = i;
        }
        //arr.size() will be the maximum value in the array, in ind[] array.
        //it will be ind[i], but since it counted from 1, so it is ind[i] + 1;
        for (int i = arr.size(); i >= 1; i--) {
            //if(ind[i] == i -1) continue;
            if (ind[i] + 1 != 1){
                ret.push_back(ind[i] + 1);
                //reverse the highest value one to the beginning
                reverse(arr, ind[i] + 1, ind);
            }
            if(i != 1) {
                ret.push_back(i);
                //revers last, then last -1 to bring the highest one to the end
                reverse(arr, i, ind);
            }
        }

        return ret;
    }
};

int main() {
    Solution s;
    vector<int> v;
    //[9,8,4,1.3,2,6,5,7]
    v.push_back(9);
    v.push_back(8);
    v.push_back(4);
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);
    v.push_back(6);
    v.push_back(5);
    v.push_back(7);
    vector<int> ret = s.pancakeSort(v);
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i];
    }
    return 0;
}
