#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// ---------------- Your Provided Solution ----------------
void solveSolution(istream &in, ostream &out) {
    int n, k;
    in >> n >> k;
    vector<int> a(n);
    vector<vector<int>> pos(n+1);
    for (int i = 0; i < n; i++){
        in >> a[i];
        // a[i] is between 1 and n (as per the problem)
        pos[a[i]].push_back(i);
    }

    vector<pair<int,int>> mnseg(n, {0, n-1});
    vector<pair<int,int>> mxseg(n, {0, n-1});
    stack<int> mnstack, mxstack;
    for (int i = n-1; i >= 0; i--){
        while (!mnstack.empty() && a[i] <= a[mnstack.top()]) {
            mnseg[mnstack.top()].first = i + 1;
            mnstack.pop();
        }
        while (!mxstack.empty() && a[i] >= a[mxstack.top()]) {
            mxseg[mxstack.top()].first = i + 1;
            mxstack.pop();
        }
        mnstack.push(i);
        mxstack.push(i);
    }
    while (!mnstack.empty()) mnstack.pop();
    while (!mxstack.empty()) mxstack.pop();
    for (int i = 0; i < n; i++){
        while (!mnstack.empty() && a[i] < a[mnstack.top()]) {
            mnseg[mnstack.top()].second = i - 1;
            mnstack.pop();
        }
        while (!mxstack.empty() && a[i] > a[mxstack.top()]) {
            mxseg[mxstack.top()].second = i - 1;
            mxstack.pop();
        }
        mnstack.push(i);
        mxstack.push(i);
    }

    vector<vector<int>> suff(n+1);
    for (int i = 0; i <= n; i++){
        int z = pos[i].size();
        if (z == 0) continue;
        suff[i].resize(z);
        suff[i][z-1] = n - 1 - mxseg[pos[i][z-1]].second;
        for (int j = z-2; j >= 0; j--){
            if (mxseg[pos[i][j]].second >= mxseg[pos[i][j+1]].first) {
                suff[i][j] = suff[i][j+1];
            } else {
                int res = mxseg[pos[i][j+1]].first - mxseg[pos[i][j]].second - 1;
                suff[i][j] = res + suff[i][j+1];
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++){
        int goal = k - a[i];
        if (goal < 0 || goal > n) continue;
        int stretch = mnseg[i].second;
        int lo = 0, hi = (int)pos[goal].size() - 1;
        bool good = false;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int cur = pos[goal][mid];
            if (cur <= i) {
                lo = mid + 1;
                continue;
            }
            if (mxseg[cur].first - 1 <= stretch) {
                good = true;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        if (!good || hi < 0) continue;
        int last = pos[goal][hi];
        auto it = upper_bound(pos[goal].begin(), pos[goal].end(), i);
        if (it == pos[goal].end()) continue;
        int p = it - pos[goal].begin();
        if (p >= (int)suff[goal].size() || hi >= (int)suff[goal].size()) continue;
        ll space = mxseg[last].second - (*it) + 1;
        ll loss = suff[goal][p] - suff[goal][hi];
        ll res = space - loss;
        ll fnal = (i - mnseg[i].first + 1) * res;
        ans += fnal;
    }
    out << ans << "\n";
}

// ---------------- Brute‑Force Implementation ----------------
ll solveBruteSingle(const vector<int>& a, int k) {
    int n = a.size();
    ll cnt = 0;
    // Check every subarray (of length at least 2) and every valid split.
    for (int L = 0; L < n; L++){
        for (int R = L+1; R < n; R++){
            for (int i = L; i < R; i++){
                int mn = INT_MAX, mx = INT_MIN;
                for (int j = L; j <= i; j++){
                    mn = min(mn, a[j]);
                }
                for (int j = i+1; j <= R; j++){
                    mx = max(mx, a[j]);
                }
                if (mn + mx == k) {
                    cnt++;
                    break; // count each subarray only once
                }
            }
        }
    }
    return cnt;
}

void solveBrute(istream &in, ostream &out) {
    int t;
    in >> t;
    while(t--){
        int n, k;
        in >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            in >> a[i];
        }
        ll ans = solveBruteSingle(a, k);
        out << ans << "\n";
    }
}

// ---------------- Stress Test Harness ----------------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // For random test generation
    mt19937 rng((unsigned)chrono::steady_clock::now().time_since_epoch().count());

    int stressTests = 10000;  // number of tests to run
    for (int test = 1; test <= stressTests; test++){
        // Use small n (between 2 and 8) for brute-force.
        int n = 2 + (rng() % 7); // n in [2, 8]
        // k must satisfy: n < k < 2*n. We'll choose k in [n+1, 2*n - 1].
        int k = n + 1 + (rng() % (n - 1));
        vector<int> a(n);
        // Generate array with values in [1, n]
        for (int i = 0; i < n; i++){
            a[i] = 1 + (rng() % n);
        }

        // Build the test case input.
        stringstream ss;
        ss << 1 << "\n";       // one test case
        ss << n << " " << k << "\n";
        for (int i = 0; i < n; i++){
            ss << a[i] << " ";
        }
        ss << "\n";

        // Run your solution.
        stringstream solOut, bruteOut;
        solveSolution(ss, solOut);

        // Reset the stream for the brute-force solution.
        ss.clear();
        ss.seekg(0, ios::beg);
        solveBrute(ss, bruteOut);

        string solStr = solOut.str();
        string bruteStr = bruteOut.str();
        if (solStr != bruteStr) {
            cout << "Test case #" << test << " failed!\n";
            cout << "Input:\n";
            cout << 1 << "\n";
            cout << n << " " << k << "\n";
            for (int i = 0; i < n; i++){
                cout << a[i] << " ";
            }
            cout << "\n";
            cout << "Your solution output: " << solStr;
            cout << "Brute-force output: " << bruteStr;
            return 0;
        }
    }
    cout << "All stress tests passed.\n";
    return 0;
}
