/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/

class Solution {
public:
    int halfSearch(vector<int>& nums, int l, int r, int target)  {
        int m = 0;
        while(l <= r)  {
            m = (l + r) / 2;
            if (target == nums[m]) return m;
            if (target < nums[m])  {
                r = m - 1;
            }
            else l = m + 1;
        }
        if (target > nums[m]) return m + 1;    //[1,3] (-1)=> 0 [1,3] (2)=> 1 [1,3] (4)=> 2
        else return m;
     }
      int searchInsert(vector<int>& nums, int target) {
          int n = nums.size();
          if (n == 0) return 0;
          return halfSearch(nums, 0, n - 1, target);
    }
};