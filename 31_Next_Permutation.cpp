/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

class Solution {
public:
    void swap(int& a, int& b)  {
        int t = a;
        a = b;
        b = t;
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n == 2)  {
            swap(nums[0], nums[1]);
        }
        else if(n > 2)  {
            if (nums[n - 2] < nums[n - 1])  {
                swap(nums[n -2], nums[n -1]);
            }
            else  {                
                int i = 0;
                for (i = n - 1; i > 0; i--)  {
                    if (nums[i - 1] < nums[i])  {    //找到大的 2 65431  找到6,为i
                        break;
                    }
                }
                int j = 0;
                if (i > 0)  {
                    for(j = i ; j < n - 1; j++)  {
                        if (nums[j] > nums[i - 1] && nums[j + 1] <= nums[i - 1])  {  //反过来从65431找刚刚比2大的为3，交换365421
                            break;
                        }
                    }
                    swap(nums[j], nums[i - 1]);
                }
                j = n - 1;
                while(i < j)  {  //后面的65421反转12456
                    swap(nums[i++], nums[j--]);
                } 
            }
            
        }
        
    }
};