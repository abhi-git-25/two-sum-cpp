#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> num_map; // num -> index

    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];

        if (num_map.find(complement) != num_map.end()) {
            return {num_map[complement], i};
        }

        num_map[nums[i]] = i;
    }

    // This should never be reached if there is exactly one solution
    return {};
}

// Example testing
int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(nums, target);

    cout << "Result: [" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}