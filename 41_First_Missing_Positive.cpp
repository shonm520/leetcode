class Solution {
public:
    int firstMissingPositive(vector<int>& nums)   //好像是N(o2)又好像不是
    {
        int n = nums.size();
        for(int i = 0; i < n; ++ i)
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);
        
        for(int i = 0; i < n; ++ i)
            if(nums[i] != i + 1)
                return i + 1;
        
        return n + 1;
    }
	
	int firstMissingPositive2(vector<int>& nums) {  //空间是O(n)
        int n = nums.size();
        int min = 0;
        for (int i = 0; i < n; i++)  {
            if (nums[i] > 0)  {
                if (min == 0) min = nums[i];
                if (nums[i] < min)  {
                    min = nums[i];
                }
            }
        }
        if (min != 1) return 1;
        int* pInt  = new int[n + 1];
        memset(pInt, 0, (n + 1) * 4);
        for (int i = 0; i < n; i++)  {
            if (nums[i] > 0)  {
                if (nums[i] - min >= n) continue;
                pInt[nums[i]- min] = 1;
            }
        }
        for (int i = 0; i < n + 1; i++)  {
            if (pInt[i] == 0)  {
                return i + min;
            }
        }
        return 1;
    }
};
