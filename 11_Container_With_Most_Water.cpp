/*Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.*/

class Solution {
public:

	int maxArea1(vector<int>& height) {
        int num = height.size();
        int max = 0;
        for (int i = 0; i < num; i++)  {   //O(n*n)
            for (int j = i + 1; j < num; j++)  {
                if (max < (j - i) * min(height[i], height[j]))  {
                    max = (j - i) * min(height[i], height[j]);
                }
            }
        }
        return max;
    }
    int maxArea(vector<int>& height) {  //两边夹击
        int num = height.size();
        int max = 0;
        int j = num - 1;
        for (int i = 0; i < j; )  {
            int localMax = min(height[i], height[j]) * (j - i);
            if (localMax > max)  {
                max = localMax;
            }
            if (height[i] > height[j])  {
                j--;
            }
            else   {
                i++;
            }
        }
        return max;
    }
};