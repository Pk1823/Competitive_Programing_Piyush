// // A



// A. Youmu Konpaku and the Duel
// time limit per test1 second
// memory limit per test256 megabytes
// Youmu Konpaku is dueling a youkai. The youkai has x
//  health, and Youmu's attack power is 1
// .

// In one move Youmu does one of the following:

// Charge: gain one stack. Each stack increases her attack power by 1
// .
// Attack: deal damage equal to her current attack power to the youkai, then the number of stacks decreases by 1
//  (if she has any).
// The youkai is defeated once its health becomes 0
//  or less. Find the minimum number of moves Youmu needs.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t
//  (1≤t≤100
// ). The description of the test cases follows.

// Each of the next t
//  lines contains a single integer x
//  (1≤x≤104
// ) — the health of the youkai.

// Output
// For each test case, output a single integer — the minimum number of moves.

// Example
// InputCopy
// 6
// 1
// 2
// 3
// 4
// 10
// 10000
// OutputCopy
// 1
// 2
// 3
// 4
// 7
// 244
// Note
// In the first test case, one attack is enough: it deals 1
//  damage.

// In the second test case, Youmu charges once (her attack power becomes 2
// ) and attacks once, so 2
//  moves are enough. Note that attacking twice also takes 2
//  moves.

// In the fifth test case, Youmu charges 4
//  times and attacks 3
//  times: the attacks deal 5
// , 4
// , and 3
//  damage, 12
//  in total, so it takes 7
//  moves. With 6
//  moves she can deal at most 9
//  damage, so the answer is 7
//  .


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static long long max_damage_in_moves(int m) {
    long long best = 0;
    for (int a = 1; a <= m; ++a) {
        int c = m - a;
        long long dmg = 0;
        if (a <= c + 1) {
            // Attacks deal (c + 1) + c + ... + (c - a + 2)
            dmg = 1LL * a * (2 * c - a + 3) / 2;
        } else {
            // First (c + 1) attacks use stacks: (c + 1) + ... + 1, rest deal 1 each
            dmg = 1LL * (c + 1) * (c + 2) / 2 + (a - c - 1);
        }
        best = max(best, dmg);
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAX_X = 10000;
    vector<int> ans(MAX_X + 1, 0);

    int m = 1;
    long long prev_max = 0;
    for (int x = 1; x <= MAX_X; ++x) {
        while (prev_max < x) {
            prev_max = max(prev_max, max_damage_in_moves(m));
            if (prev_max < x) {
                ++m;
            }
        }
        ans[x] = m;
    }

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int x;
        cin >> x;
        cout << ans[x] << '\n';
    }

    return 0;
}