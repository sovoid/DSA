#include <stdc++.h>
using namespace std;

class Solution {
    public:
        static void subarray_sum(vector<int> nums, int sum) {
            int current_sum = nums[0], start = 0, end;

            for (end = 1; end <= nums.size(); end++) {
                while(current_sum > sum && start < end-1) {
                    current_sum -= nums[start];
                    start++;
                }

                if(current_sum == sum) {
                    cout << "Sum found between indices " << start << " and " << end - 1 << "\n";
                    return;
                }

                if(end < nums.size()) {
                    current_sum += nums[end];
                }
            }

            cout << "No subarray found with given sum !"
                 << "\n";
        }
};

int main() {
    vector<int> nums = {1, 4, 0, 0, 3, 10, 5};
    int sum = 7;
    Solution::subarray_sum(nums, sum);
    return 0;
}