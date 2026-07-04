#include <bits/stdc++.h>
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << "\n"
#define each(a, x) for(auto &&a : x)

using namespace std;

struct tuple_hash {
    template <typename T1, typename T2, typename T3>
    size_t operator()(const tuple<T1, T2, T3>& t) const {
        auto [a, b, c] = t;
        return hash<T1>()(a) ^ (hash<T2>()(b) << 1) ^ (hash<T3>()(c) << 2);
    }
};

struct dsu{
    vector<int> parent, cnt;
    dsu(int n) : parent(n), cnt(n, 1) { iota(parent.begin(), parent.end(), 0); }
    int _find(int i) { return (i == parent[i]) ? i : (parent[i] = _find(parent[i])); }
    bool unite(int a, int b) {
        int x = _find(a), y = _find(b);
        if (x == y) return false;
        if (cnt[x] < cnt[y]) swap(x, y);
        parent[y] = x;
        cnt[x] += cnt[y];
        return true;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    dsu tree(n);
    unordered_map<int, unordered_set<tuple<int, int, int>, tuple_hash>> edges;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        auto &l = edges[tree._find(a)];
        auto &r = edges[tree._find(b)];
        if (!tree.unite(a, b)) {
            edges[tree._find(a)].insert({i, a, b});
        } else {
            if (l.size() < r.size()) swap(l, r);
            l.insert(r.begin(), r.end());
            r.clear();
            edges[tree._find(a)] = move(l);
        }
    }

    unordered_set<int> components, useful;
    for (int i = 0; i < n; i++) {
        int tag = tree._find(i);
        components.insert(tag);
        if (!edges[tag].empty()) useful.insert(tag);
    }

    vector<tuple<int, int, int>> ans;
    while (components.size() > 1) {
        int cur = *useful.begin(), to = -1;
        for (int x : components) {
            if (x != cur) {
                to = x;
                break;
            }
        }
        useful.erase(cur);
        useful.erase(to);
        components.erase(cur);
        components.erase(to);

        tuple<int, int, int> curedge = *edges[cur].begin();
        ans.pb({get<0>(curedge), get<1>(curedge), to});
        edges[cur].erase(curedge);

        auto &l = edges[cur];
        auto &r = edges[to];
        if (l.size() < r.size()) swap(l, r);
        l.insert(r.begin(), r.end());
        r.clear();

        tree.unite(cur, to);
        int last = tree._find(cur);
        if (edges[last].size() != l.size()) edges[last] = move(l);
        components.insert(last);
        if (!edges[last].empty()) useful.insert(last);
    }

    cout << ans.size() << "\n";
    for (auto [a, b, c] : ans) cout << a + 1 << " " << b + 1 << " " << c + 1 << "\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
