/*
Given a string, find the length of the longest substring without repeating characters.
Examples:
Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.
Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include <string>
using std::string;

int max(int a, int b)  { if (a > b) return a; else return b; }

int lengthOfLongestSubstring(string s)   {         //窗口滑动，j先向前移动，遇到相同的i再向前移动 O(n)
	int n = s.length();
	char c[128] = { 0 };
	int ans = 0, i = 0, j = 0;
	while (i < n && j < n) {
		if (c[s[j]] == 0){
			c[s[j++]] = 1;
			ans = max(ans, j - i);
		}
		else {
			c[s[i++]] = 0;
		}
	}
	return ans;
}

int lengthOfLongestSubstring1(string s)   {          //遇到相同的就从相同的地方开始往后计算 O(n)
	int len = s.length();
	char c[128] = { 0 };
	int ans = 0;
	for (int j = 0, i = 0; j < len; j++) {
		i = max(c[s[j]], i);
		ans = max(ans, j - i + 1);
		c[s[j]] = j + 1;
	}
	return ans;
}


int lengthOfLongestSubstring2(string s) {           //时间复杂度O（n*n） 
	int len = s.length();
	char c[128] = { 0 };
	int longest = 0;
	for (int i = 0; i < len; i++)  {
		if (longest > len - i) break;
		int localLongest = 0;
		memset(c, 0, 128);
		int j = i;
		for (j = i; j < len; j++)  {
			if (c[s[j]] == 1)  {
				localLongest = j - i;
				break;
			}
			c[s[j]] = 1;
		}
		if (localLongest == 0)  {
			longest = len - i;
			break;
		}
		if (localLongest > longest)  {
			longest = localLongest;
		}
	}
	return longest;
}


int _tmain(int argc, _TCHAR* argv[])
{
	printf("n is %d", lengthOfLongestSubstring("abcabcbb"));
	return 0;
}

