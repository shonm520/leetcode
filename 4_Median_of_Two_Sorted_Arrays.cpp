/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int m = (n1 + n2 + 1) / 2;
        int index = 0;
        int a = 0, b = 0;
        int temp = 0;
        int lastTemp = 0;
        for (int i = 0; i < (n1 + n2); i++)  {
            if (a < n1 && b < n2)  {
                if (nums1[a] < nums2[b])  {
                    temp = nums1[a++];
                }
                else  {
                    temp = nums2[b++];
                }
            }
            else if (a == n1)  {    //1数组完毕
                temp = nums2[b++];
            }
            else  {
                temp = nums1[a++];
            }
            index++;
            if (index == m && (n1 + n2) % 2 == 1)  {   //奇数个正好是中间那个
                return temp;
            }
            if (index == (m + 1) && (n1 + n2) % 2 == 0)  {
                return (lastTemp + temp) * 1.0 / 2;
            }
            lastTemp = temp;
        }
    }
};