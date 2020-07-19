#include <stdc++.h>
using namespace std;

class Solution {
    public:
        static void move_zeroes(vector<int>& nums) {
            int i = 0, j = 0, n = nums.size();
            while(j < n) {
                if(nums[j] != 0) {
                    nums[i++] = nums[j++];
                } else {
                    j++;
                }
            }
            while(i<n) {
                nums[i] = 0;
                i++;
            }
        }
};

int main() {
    vector<int>
        nums = {0, 1, 0, 3, 12};
    Solution::move_zeroes(nums);
    for(auto el: nums) {
        cout << el << " ";
    }
    return 0;
}