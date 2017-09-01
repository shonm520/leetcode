/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

class Solution {
public:
    int halfSearch(vector<int>& nums, int l, int r, int target)  {
        while(l <= r)  {    //注意边界问题,调试了很久
            int m = (l + r) / 2;
            if (target == nums[m]) return m;
            else if (target < nums[m]) r = m - 1;    
            else  l = m + 1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;
        if (n == 1) {
            if(target == nums[0])  return 0;
            else return -1;
        }
        int l = 0;
        int r = n;
        int m = 0;
        while(l < r)  {
            m = (l + r) / 2;
            if (nums[l]  < nums[m])  {
                l = m;
            }
            else  {
                r = m;
            }
        }
        int start = m + 1;  //得到拐点,没有拐点则是数组长度
        if (target > nums[start - 1]) return -1;
        else  {
            if (target >= nums[0])  {
                return halfSearch(nums, 0, start - 1,target);
            }
            else  {
                return halfSearch(nums, start, n - 1,target);
            }
        }
        
        
    }
};