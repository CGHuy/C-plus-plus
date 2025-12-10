// #5. Longest Palindromic Substring

#include <iostream>

using namespace std;

class Solution {
public:
	string longestPalindrome (string s) {
		int n = s.size();
		if (n == 0) return "";
		
		int start = 0, maxLen = 1;
		
		auto expand = [&](int left, int right) {
			while (left >=0 && right < n && s[left] == s[right]) {
				left--;
				right++;
			}
			return right - left - 1;
		};
		
		for (int i = 0; i < n; i++) {
			int len1 = expand(i,i); 
			int len2 = expand(i, i+1);
			int len = max(len1, len2);
			if (len > maxLen) {
				maxLen = len;
				start = i - (len - 1)/2;
			}
		}
		return s.substr(start, maxLen);
	}
};

int main() {
	Solution sol;
	string s1 = "tdfgabcbatgdf";
	string s2 = "dfgdfasffsaaa";
	cout << sol.longestPalindrome(s1) << endl;
	cout << sol.longestPalindrome(s2);
	return 0;
}
