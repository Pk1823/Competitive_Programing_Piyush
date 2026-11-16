
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1000000007LL;

ll modpow(ll a, ll b) {
    ll res = 1;

    while (b) {
        if (b & 1) {
            res = res * a % MOD;
        }

        a = a * a % MOD;
        b >>= 1;
    }

    return res;
}

vector<ll> fact, ifact;

void precomp_fact(int n) {
    fact.resize(n + 1);
    ifact.resize(n + 1);

    fact[0] = 1;

    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    ifact[n] = modpow(fact[n], MOD - 2);

    for (int i = n; i >= 1; i--) {
        ifact[i - 1] = ifact[i] * i % MOD;
    }
}

ll choose(int n, int r) {
    if (r < 0 || r > n) return 0;

    return fact[n] * ifact[r] % MOD
           * ifact[n - r] % MOD;
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<ll> a(n);

    for (auto &x : a) {
        cin >> x;
    }

    precomp_fact(n);

    vector<ll> pref(n);

    for (int i = 0; i < n; i++) {
        pref[i] = a[i] - a[n - 1 - i];
    }

    vector<int> zero(n, 0);

    map<ll, vector<int>> pos;

    for (int i = 0; i < n - 1; i++) {

        if (pref[i] == 0) {
            zero[i + 1]++;
        }

        zero[i + 1] += zero[i];

        pref[i + 1] += pref[i];

        pos[pref[i]].push_back(i);
    }

    while (q--) {

        int i, v;
        cin >> i >> v;

        int l = --i;
        int r = n - 1 - i;

        if (l > r) {
            swap(l, r);
            v = -v;
        }

        // Original zero prefix sums outside [l, r)
        int x = zero[n - 1] - zero[r] + zero[l];

        // Prefix sums inside [l, r) that become zero
        auto it = pos.find(-1LL * v);

        if (it != pos.end()) {

            x += lower_bound(
                it->second.begin(),
                it->second.end(),
                r
            ) - lower_bound(
                it->second.begin(),
                it->second.end(),
                l
            );
        }

        cout << choose(x, m - 1) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}