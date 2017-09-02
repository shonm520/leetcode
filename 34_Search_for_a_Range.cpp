/*
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

class Solution {
public:
    int halfSearch(vector<int>& nums, int l, int r, int target)  {
        while(l <= r)  {
            int m = (l + r) / 2;
            if (target == nums[m]) return m;
            else if (target < nums[m]) r = m - 1;
            else l = m + 1;
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int ret = halfSearch(nums, 0, n - 1, target);
        if (ret == -1)  {
            vector<int> vtRes;
            vtRes.push_back(-1);
            vtRes.push_back(-1);
            return vtRes;
        }
        else  {
            int index = ret;
            vector<int> vtRes;
            while(index > 0)  {
                if (nums[--index] == target)  {
                    vtRes.insert(vtRes.begin(), index);   //注意这里一定是往最前插入,例如333找到了第[2]个3.前面2个也算[0,1,2]
                }
                else break;
            }
            vtRes.push_back(ret);
            index = ret;
            while(index < n - 1)  {
                if (nums[++index] == target)  {
                    vtRes.push_back(index);
                }
                else break;
            }
            if (vtRes.size() == 1)  {
                vtRes.push_back(ret);
            }
            else if (vtRes.size() > 2)  {
                vector<int> vtTemp;
                vtTemp.push_back(vtRes[0]);
                vtTemp.push_back(*vtRes.rbegin());
                return vtTemp;
            }
            return vtRes;
        }
    }
};