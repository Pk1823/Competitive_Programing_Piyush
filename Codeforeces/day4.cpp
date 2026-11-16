#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

struct DSU {
    int n;
    vector<int> parent;
    vector<int> comp_size;
    vector<vector<int>> members;

    DSU(int n) : n(n), parent(n + 1), comp_size(n + 1, 1), members(n + 1) {
        iota(parent.begin(), parent.end(), 0);
        for (int i = 1; i <= n; i++) {
            members[i] = {i};
        }
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    // Resets a list of vertices back to singletons (used on explosion)
    void explode(const vector<int>& vertices, int& total_molecules) {
        for (int v : vertices) {
            parent[v] = v;
            comp_size[v] = 1;
            members[v] = {v};
        }
        total_molecules += (int)vertices.size() - 1;
    }
};

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DSU dsu(n);
    int total_molecules = n;

    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;

        int root_u = dsu.find(u);
        int root_v = dsu.find(v);

        if (root_u != root_v) {
            // Small-to-large merging
            if (dsu.members[root_u].size() < dsu.members[root_v].size()) {
                swap(root_u, root_v);
            }

            // Check if any reactive pair spans between the two components
            bool explodes = false;
            for (int x : dsu.members[root_v]) {
                for (int y : adj[x]) {
                    if (dsu.find(y) == root_u) {
                        explodes = true;
                        break;
                    }
                }
                if (explodes) break;
            }

            if (explodes) {
                // Combine both components temporarily to collect all affected vertices, then explode
                vector<int> affected;
                affected.insert(affected.end(), dsu.members[root_u].begin(), dsu.members[root_u].end());
                affected.insert(affected.end(), dsu.members[root_v].begin(), dsu.members[root_v].end());
                dsu.explode(affected, total_molecules);
            } else {
                // Successful merge
                for (int x : dsu.members[root_v]) {
                    dsu.parent[x] = root_u;
                    dsu.members[root_u].push_back(x);
                }
                dsu.comp_size[root_u] += dsu.comp_size[root_v];
                dsu.members[root_v].clear();
                total_molecules--;
            }
        }

        cout << total_molecules << "\n";
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