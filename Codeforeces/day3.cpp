#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n < 4) {
        cout << -1 << "\n";
        return;
    }
    if (n % 2 == 0) {
        for (int i = n; i >= 1; i--) {
            cout << i << (i == 1 ? "" : " ");
        }
        cout << "\n";
    } else {
        cout << "4 5 3 1 2";
        for (int i = 6; i <= n; i++) {
            cout << " " << i;
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}