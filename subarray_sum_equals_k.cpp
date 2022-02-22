#include <algorithm>
#include <iostream>
#include <vector>

int subarraySum(std::vector<int>& nums, int k) {
    if (!(nums.size() >= 1 && nums.size() <= 2e4 && k >= -1e7 && k <= 1e7)) {
        return 0;
    }
    
    for (size_t idx = 0; idx < nums.size(); ++idx) {
        if (nums[idx] < -1000 || nums[idx] > 1000 || nums[idx] < -1000 || nums[idx] > 1000) {
            return 0;
        }
    }
    
    int count = 0;
    // Iterate over each element in the array
    for (auto i = 0; i < nums.size(); ++i) {
        // Start summing over starting from this element
        int sum = 0;
        for (auto j = i; j < nums.size(); ++j) {
            sum += nums[j];
            if (sum == k) ++count;
        }
    }

    return count;
}

int main()
{
    size_t k = 2;
    /*
        3 + 1 + 2 = 6
        1 + 2 + 1 + 1 + 1 = 6
        2 + 1 + 1 + 1 + 1 = 6
    */
    std::vector<int> arr = { 1, 1, 1};
    
    int a = subarraySum(arr, k);
    std::cout << "\nfinal=" << a << std::endl;

    return 0;
}
