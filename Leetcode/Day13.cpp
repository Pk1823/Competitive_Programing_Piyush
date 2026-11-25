#include <vector>
#include <unordered_map>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

// class Solution {
// public:
//     int smallestUniqueSubarray(vector<int>& nums) {
//         int n = static_cast<int>(nums.size());
//         const long long MOD1 = 1000000007LL;
//         const long long MOD2 = 1000000009LL;
//         const long long BASE1 = 131313LL;
//         const long long BASE2 = 1000003LL;

//         vector<long long> pow1(n + 1, 1), pow2(n + 1, 1);
//         for (int i = 1; i <= n; ++i) {
//             pow1[i] = (pow1[i - 1] * BASE1) % MOD1;
//             pow2[i] = (pow2[i - 1] * BASE2) % MOD2;
//         }

//         auto hasUniqueOfLength = [&](int len) -> bool {
//             long long h1 = 0, h2 = 0;
//             for (int i = 0; i < len; ++i) {
//                 h1 = (h1 * BASE1 + nums[i]) % MOD1;
//                 h2 = (h2 * BASE2 + nums[i]) % MOD2;
//             }

//             unordered_map<unsigned long long, int> freq;
//             freq.reserve(n - len + 1);

//             auto pack = [](long long a, long long b) -> unsigned long long {
//                 return (static_cast<unsigned long long>(a) << 32) | static_cast<unsigned long long>(b);
//             };

//             freq[pack(h1, h2)]++;

//             for (int i = len; i < n; ++i) {
//                 long long outVal = nums[i - len];
//                 h1 = (h1 - (outVal * pow1[len - 1]) % MOD1 + MOD1) % MOD1;
//                 h1 = (h1 * BASE1 + nums[i]) % MOD1;

//                 h2 = (h2 - (outVal * pow2[len - 1]) % MOD2 + MOD2) % MOD2;
//                 h2 = (h2 * BASE2 + nums[i]) % MOD2;

//                 freq[pack(h1, h2)]++;
//             }

//             for (const auto& [_, cnt] : freq) {
//                 if (cnt == 1) return true;
//             }
//             return false;
//         };

//         int low = 1, high = n, ans = n;
//         while (low <= high) {
//             int mid = low + (high - low) / 2;
//             if (hasUniqueOfLength(mid)) {
//                 ans = mid;
//                 high = mid - 1;
//             } else {
//                 low = mid + 1;
//             }
//         }
//         return ans;
//     }
// };