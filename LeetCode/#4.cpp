// #4. Median Of Two Sorted Arrays

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Dam bao nums1 la mang ngan hon de giam do phuc tap
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int len1 = nums1.size();
        int len2 = nums2.size();
        int left = 0;            // bien trai cua binary search tren nums1
        int right = len1;        // bien phai cua binary search tren nums1

        // Binary search
        while (left <= right) {
            // part1: so phan tu lay tu nums1 de chia nua trai
            int part1 = (left + right) / 2;
            // part2: so phan tu lay tu nums2 de du nua trai cua mang gop
            int part2 = (len1 + len2 + 1) / 2 - part1;

            // Gia tri lon nhat ben trai part1
            int left1 = (part1 == 0) ? INT_MIN : nums1[part1 - 1];
            // Gia tri nho nhat ben phai part1
            int right1 = (part1 == len1) ? INT_MAX : nums1[part1];
            // Gia tri lon nhat ben trai part2
            int left2 = (part2 == 0) ? INT_MIN : nums2[part2 - 1];
            // Gia tri nho nhat ben phai part2
            int right2 = (part2 == len2) ? INT_MAX : nums2[part2];

            if (left1 <= right2 && left2 <= right1) {
                if ((len1 + len2) % 2 == 0) {
                    return (double(max(left1, left2) + min(right1, right2))) / 2;
                } 
                else {
                    return max(left1, left2);
                }
            } 
            // Neu left1 qua lon -> dich part1 sang trai (giam right)
            else if (left1 > right2) {
                right = part1 - 1;
            } 
            // Neu left2 qua lon -> dich part1 sang phai (tang left)
            else {
                left = part1 + 1;
            }
        }

        return 0; // Truong hop khong tim duoc
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    cout << sol.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}

