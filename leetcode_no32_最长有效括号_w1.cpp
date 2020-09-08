/*------------------------------------------------------------------|
给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长|
度。																|
																	|
示例 1:																|
																	|
输入: "(()"															|
输出: 2																|
解释: 最长有效括号子串为 "()"										|
示例 2:																|
																	|
输入: ")()())"														|
输出: 4																|
解释: 最长有效括号子串为 "()()"										|
																	|
来源：力扣（LeetCode）												|
链接：https://leetcode-cn.com/problems/longest-valid-parentheses	|
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	正反向查找法
*	正着来一遍反向又来一遍
*	执行用时：4 ms, 在所有 C++ 提交中击败了94.13%的用户
*	内存消耗：6.8 MB, 在所有 C++ 提交中击败了98.87%的用户
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

int longestValidParentheses(string s) 
{
	int len = s.size();
	int res = 0;
	if (len < 2)
	{
		return res;
	}
	int left = 0;
	int right = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		if (s[i] == '(')
		{
			left++;
		}
		if (s[i] == ')')
		{
			right++;
		}
		if (left == right)
		{
			res = max(res, 2 * left);
		}
		if (left > right)
		{
			left = 0;
			right = 0;
		}
	}
	if (res == len)
	{
		return res;
	}
	left = 0;
	right = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '(')
		{
			left++;
		}
		if (s[i] == ')')
		{
			right++;
		}
		if (left == right)
		{
			res = max(res, 2 * left);
		}
		if (left < right)
		{
			left = 0;
			right = 0;
		}
	}
	return res;
}

int main()
{
	string s = "()(()";
}
	