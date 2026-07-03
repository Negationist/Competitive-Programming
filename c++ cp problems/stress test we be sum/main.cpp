#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <random>
#include <chrono>
#include <algorithm>
#include <climits>
using namespace std;
using ll = long long;

// ---------------- Your Provided Solution ----------------
void solveSolution(istream &in, ostream &out) {
    int n, k;
    in >> n >> k;
    vector<int> a(n);
    // pos[x] will store all indices i where a[i] == x.
    vector<vector<int>> pos(n + 1);
    for (int i = 0; i < n; i++){
        in >> a[i];
        // Problem guarantees 1 ≤ a[i] ≤ n.
        pos[a[i]].push_back(i);
    }

    vector<pair<int,int>> mnseg(n, {0, n - 1});
    vector<pair<int,int>> mxseg(n, {0, n - 1});
    stack<int> mnstack, mxstack;

    // Compute the "first" values of mnseg and mxseg.
    for (int i = n - 1; i >= 0; i--){
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

    // Compute the "second" values of mnseg and mxseg.
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

    // Precompute suff arrays for each possible value.
    vector<vector<int>> suff(n + 1);
    for (int i = 0; i <= n; i++){
        int z = pos[i].size();
        if (z == 0) continue;
        suff[i].resize(z);
        suff[i][z - 1] = n - 1 - mxseg[pos[i][z - 1]].second;
        for (int j = z - 2; j >= 0; j--){
            if (mxseg[pos[i][j]].second >= mxseg[pos[i][j + 1]].first)
                suff[i][j] = suff[i][j + 1];
            else {
                int res = mxseg[pos[i][j + 1]].first - mxseg[pos[i][j]].second - 1;
                suff[i][j] = res + suff[i][j + 1];
            }
        }
    }

    ll ans = 0;
    // Process each index as a potential left end.
    for (int i = 0; i < n; i++){
        int goal = k - a[i];
        if (goal < 0 || goal > n) continue;
        if (pos[goal].empty()) continue;
        int stretch = mnseg[i].second;
        int lo = 0, hi = (int) pos[goal].size() - 1;
        bool good = false;
        // Binary search on pos[goal].
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
        if (p >= (int) suff[goal].size() || hi >= (int) suff[goal].size())
            continue;
        ll space = mxseg[last].second - (*it) + 1;
        ll loss = suff[goal][p] - suff[goal][hi];
        ll res = space - loss;
        ll fnal = (i - mnseg[i].first + 1LL) * res;
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
        for (int R = L + 1; R < n; R++){
            for (int i = L; i < R; i++){
                int mn = INT_MAX, mx = INT_MIN;
                for (int j = L; j <= i; j++){
                    mn = min(mn, a[j]);
                }
                for (int j = i + 1; j <= R; j++){
                    mx = max(mx, a[j]);
                }
                if (mn + mx == k) {
                    cnt++;
                    break; // Count each subarray once.
                }
            }
        }
    }
    return cnt;
}

void solveBrute(istream &in, ostream &out) {
    int t;
    in >> t;
    while (t--) {
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
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int stressTests = 10000; // Number of test cases to run.
    mt19937 rng((unsigned) chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distN(2, 8); // n between 2 and 8.

    for (int test = 1; test <= stressTests; test++){
        int n = distN(rng);
        // Choose k in [n+1, 2*n-1] to satisfy n < k < 2*n.
        uniform_int_distribution<int> distK(n + 1, 2 * n - 1);
        int k = distK(rng);
        vector<int> a(n);
        uniform_int_distribution<int> distA(1, n);
        for (int i = 0; i < n; i++){
            a[i] = distA(rng);
        }

        // Build the test case input.
        stringstream ss;
        ss << 1 << "\n" << n << " " << k << "\n";
        for (int i = 0; i < n; i++){
            ss << a[i] << " ";
        }
        ss << "\n";
        string input = ss.str();

        // Run your solution.
        istringstream iss(input);
        ostringstream solOut;
        solveSolution(iss, solOut);

        // Run the brute-force solution.
        istringstream iss2(input);
        ostringstream bruteOut;
        solveBrute(iss2, bruteOut);

        if (solOut.str() != bruteOut.str()){
            cout << "Test case #" << test << " failed!\n";
            cout << "Input:\n" << input;
            cout << "Your solution output: " << solOut.str();
            cout << "Brute-force output: " << bruteOut.str();
            return 0;
        }
    }
    cout << "All stress tests passed.\n";
    return 0;
}
