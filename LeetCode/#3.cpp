// 3.longest-substring-without-repeating-characters (tim chuoi con dai nhat)
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {	
	public:
	    int lengthOfLongestSubstring1(string s) {
	        int left = 0;
	        int maxLength = 0;
	        unordered_set<char> charSet; // charSet = {a, b, c, ...}
	
	        for (int right = 0; right < s.length(); right++) {
	            while (charSet.count(s[right])) {
	                charSet.erase(s[left]);
	                left++;
	            }
	            charSet.insert(s[right]);
	            maxLength = max(maxLength, right - left + 1);
	        }
	
	        return maxLength;
	    }
	    
	    int lengthOfLongestSubstring2(string s) {
	    	int left = 0;
	    	int maxLength = 0;
	    	unordered_map<char, int> lastSeen; // Luu vi tri cuoi cua ky tu
	    	for (int right = 0; right < s.length(); right++) {
            char c = s[right];
            // Neu ky tu da xuat hien va nam trong cua so hien tai
            if (lastSeen.find(c) != lastSeen.end() && lastSeen[c] >= left) {
                // Nhay trai den ngay sau vi tri trung
                left = lastSeen[c] + 1;
            }
            // Cap nhat vi tri cuoi caa ky tu nay
            lastSeen[c] = right;
            maxLength = max(maxLength, right - left + 1);
			}
			return maxLength;
		}
	};

int main() {
	Solution sol;
	string a = "abcadbcd";
	string b = "fthfgjghdf";
	
	cout << sol.lengthOfLongestSubstring1(a) << endl;
	cout << sol.lengthOfLongestSubstring1(b) << endl;
	cout << "---------------------------" << endl;
	cout << sol.lengthOfLongestSubstring2(a) << endl;
	cout << sol.lengthOfLongestSubstring2(b) << endl;
	
	return 0;
}
