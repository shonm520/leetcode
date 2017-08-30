#include <stdlib.h>
#include <stdio.h>
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target)  {
        int n = num.size();
        if (n <= 2) {
            return num;
        }  
        vector<int> ret;
        for (int i = 0; i < n ; i++)  {
            for (int j = i + 1; j < n ; j++)  {
                if (num[i] + num[j] == target)  {
                    ret.push_back(i);
                    ret.push_back(j);
                    return ret;
                }
            }
        }
        return ret;
    }
};

int main()  {
    vector<int> arrNum;
    arrNum.push_back(2);
    arrNum.push_back(4);
    arrNum.push_back(3);
    arrNum.push_back(8);
    arrNum.push_back(1);
    arrNum.push_back(5);
    int target = 9;
    Solution sl;
    vector<int> ret = sl.twoSum(arrNum, target);
    for (int i = 0; i < ret.size(); i++ )  {
        printf("%d ",ret[i]);
    }
    return 0;
}