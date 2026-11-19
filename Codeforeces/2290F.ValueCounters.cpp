
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n + 1);
        vector<int> p(n + 1);
        vector<int> ans(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        bool valid = true;

        for (int i = 1; i <= n; i++) {
            p[i] = a[i] + n + 1 - i;

            if (p[i] < 1 || p[i] > n || ans[p[i]] != 0) {
                valid = false;
                break;
            }

            ans[p[i]] = i;
        }

        if (!valid) {
            cout << -1 << '\n';
        } else {
            for (int i = 1; i <= n; i++) {
                cout << ans[i] << (i == n ? '\n' : ' ');
            }
        }
    }

    return 0;
}