
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int window = 0;
    int ans = 0;

    for (int i = n - 1; i >= 0; i--) {
        b[i] = (a[i] + window) % 2;

        ans ^= b[i];

        window ^= b[i];

        if (i + k < n) {
            window ^= b[i + k];
        }
    }

    cout << (ans ? "Alice" : "Bob") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}