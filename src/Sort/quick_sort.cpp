#include <iostream>
#include <vector>
using namespace std;

void quick_sort(vector<int>& nums, int left, int right) {
    if (left >= right) return;
    int pivot = nums[left];
    int begin = left, end = right;
    while (left < right) {
        while (left < right && nums[right] >= pivot) {
            right--;
        }
        nums[left] = nums[right];
        while (left < right && nums[left] <= pivot) {
            left++;
        }
        nums[right] = nums[left];
    }
    nums[left] = pivot;
    quick_sort(nums, begin, left - 1);
    quick_sort(nums, left + 1, end);
}

int main() {
    vector<int> nums = {2, 14, 516, 64, 788, 4, 32, 45, 67};
    quick_sort(nums, 0, nums.size() - 1);
    for (auto x : nums) cout << x << " ";
    cout << endl;
    return 0;
}
