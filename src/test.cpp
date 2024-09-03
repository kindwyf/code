#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums{1, 4, 3, 4, 4};
    int idx = nums[0], count = 1;
    for (int i = 1; i < (int)nums.size(); ++i) {
        if (nums[i] == idx) {
            count++;
        } else {
            count--;
        }
        if (count == 0) {
            idx = nums[i];
        }
    }
    cout << idx << endl;
    return 0;
}