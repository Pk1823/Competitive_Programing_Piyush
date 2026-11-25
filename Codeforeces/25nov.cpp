// ============================================================================
// Problem: B - Diverse String
// ============================================================================
// Core Idea:
//   Let a binary string of length n have z zeros and o = n - z ones.
//   Performing "set s[l..r] = 1" once can flip any contiguous subsegment of the
//   z zero-positions (including empty = no change) -> 1 + z*(z + 1)/2 outcomes.
//   Performing "set s[l..r] = 0" once can flip any contiguous subsegment of the
//   o one-positions (including empty = no change) -> 1 + o*(o + 1)/2 outcomes.
//   Only the original string itself is counted twice, so:
//     diversity(z) = 1 + z*(z + 1)/2 + (n - z)*(n - z + 1)/2
//
// Convexity & Toggles:
//   - Initial zero count = z0.
//   - With at most k toggles, final zero count z can lie in:
//       [low_z, high_z] = [max(0, z0 - k), min(n, z0 + k)]
//   - diversity(z) is convex in z (2nd derivative > 0), so its maximum on
//     [low_z, high_z] is always at one of the endpoints: low_z or high_z.
//
// Complexity:
//   - Time:  O(n) per test case, O(sum of n) total across all test cases.
//   - Space: O(n) for string s, O(1) extra space.
// ============================================================================

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Computes diversity for length n with z zeros and (n - z) ones.
long long calc_diversity(long long n, long long z) {
    long long o = n - z;
    return 1LL + (z * (z + 1)) / 2LL + (o * (o + 1)) / 2LL;
}

// Solves a single test case.
void solve() {
    long long n, k;
    string s;
    cin >> n >> k >> s;

    // Count initial zeros and find achievable zero-count bounds after <= k toggles.
    long long z0 = count(s.begin(), s.end(), '0');
    long long low_z = max(0LL, z0 - k);
    long long high_z = min(n, z0 + k);

    // Maximum of a convex function on a closed interval lies at an endpoint.
    cout << max(calc_diversity(n, low_z), calc_diversity(n, high_z)) << '\n';
}

int main() {
    // Fast I/O for competitive programming.
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}