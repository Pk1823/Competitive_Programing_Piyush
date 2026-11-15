#include <vector>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long odd_count = 0, even_count = 1;
        long long current_sum = 0;
        long long total_subarrays = 0;
        long long MOD = 1e9 + 7;

        for (int num : arr) {
            current_sum += num;
            
            if (current_sum % 2 != 0) {
                total_subarrays = (total_subarrays + even_count) % MOD;
                odd_count++;
            } else {
                total_subarrays = (total_subarrays + odd_count) % MOD;
                even_count++;
            }
        }

        return total_subarrays;
    }
};