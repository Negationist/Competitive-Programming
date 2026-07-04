#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 998244353ll

void rem(map<int, int>& m, int elem) {
    auto cres = m.find(elem);
    cres->second--;
    if (cres->second == 0) {
        m.erase(elem);
    }
}

void ins(map<int, int>& m, int u) {
    auto cres = m.find(u);
    if (cres == m.end()) {
        m.insert({u, 1});
    } else {
        cres->second++;
    }
}

void run() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> nums(n);
    ll numsum = 0;
    for (int i=0; i<n; i++) {
        int u;
        cin >> u;
        nums[i] = u;
        numsum += u;
    }

    vector<int> magic(m);
    for (int i=0; i<m; i++) {
        int u;
        cin >> u;
        magic[i] = u;
    }

    vector<vector<int>> magics(m+1);
    magics[1] = magic;

    set<int> seenmagics;
    for (int i : magic) {
        seenmagics.insert(i);
    }
    for (int i=2; i<=m; i++) {
        for (int j : magics[i-1]) {
            for (int kp : magic) {
                int l = j & kp;
                if (seenmagics.find(l) == seenmagics.end()) {
                    seenmagics.insert(l);
                    magics[i].push_back(l);
                }
            }
        }
    }

    vector<int> reductions;

    for (int num : nums) {
        int prevbest = num;
        for (int fold=1; fold<=m; fold++) {
            int best = prevbest;
            for (int mask : magics[fold]) {
                int num2 = num & mask;
                if (num2 < best) {
                    best = num2;
                }
            }
            reductions.push_back(prevbest - best);
            prevbest = best;
        }
    }

    sort(reductions.begin(), reductions.end());

    int rl = reductions.size()-1;
    ll tot = numsum;
    for (int o=0; o<k; o++) {
        tot -= reductions[rl-o];
    }

    cout << tot << "\n";

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    ll n;
    cin >> n;

    for (ll i=0; i < n; i++) {
        run();
    }
}
