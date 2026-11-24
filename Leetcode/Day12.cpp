#include <algorithm>
#include <numeric>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int ans = 0;

        // Upper bound for lcm(1..10) * gcd(1..10) is 2520 * 10 = 25200.
        // Once prod exceeds this max possible lcm * gcd, no longer subarray starting at i can match.
        const long long maxTarget = 25200LL;

        for (int i = 0; i < n; ++i) {
            long long prod = 1;
            long long g = 0;
            long long l = 1;

            for (int j = i; j < n; ++j) {
                long long x = nums[j];
                if (prod > maxTarget / x) {
                    break;
                }
                prod *= x;
                g = (g == 0) ? x : std::gcd(g, x);
                l = std::lcm(l, x);

                if (prod == l * g) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};