#include <vector>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n; // Arrays of size 1 or 2 are always Fibonacci
        
        int maxLength = 2; // Minimum Fibonacci length is 2
        
        // For each potential starting pair
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                // Store first two elements of potential Fibonacci sequence
                long long first = nums[i];
                long long second = nums[j];
                
                // Variable to store values as we process them
                vector<int> valtoremin; // As required in the problem
                valtoremin.push_back(nums[i]);
                valtoremin.push_back(nums[j]);
                
                int currentLength = 2;
                int k = j + 1;
                
                // Continue as long as the Fibonacci property holds
                while (k < n && nums[k] == first + second) {
                    valtoremin.push_back(nums[k]);
                    first = second;
                    second = nums[k];
                    k++;
                    currentLength++;
                }
                
                maxLength = max(maxLength, currentLength);
            }
        }
        
        return maxLength;
    }
};
