#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define N 998244353

bool possible(vector<int>& a, int total, int cost) {
    int blockedsum = 0;
    int currsum = 0; // sum from front to i inclusive
    int currfront = -1;

    vector<int> mib(a.size());
    deque<int> cands;
    cands.push_back(-1);
    int could = 1e14+1;
    for (int i=0; i<a.size(); i++) {
        while (currsum > cost) {
            currfront++;
            currsum -= a[currfront];
        }
        while (cands.front() < currfront) {
            cands.pop_front();
        }

        if (cands.front() == -1) {
            mib[i] = a[i];
        } else {
            mib[i] = a[i] + mib[cands.front()];
        }

        while (!cands.empty() && mib[cands.back()] > mib[i]) {
            cands.pop_back();
        }
        cands.push_back(i);

        currsum += a[i];

        total -= a[i];
        if (total <= cost) {
            if (mib[i] <= cost) {
                return true;
            }
        }
    }
    return false;
}

void run() {
    int n;
    cin >> n;
    vector<int> a(n);
    int total = 0;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        total += a[i];
    }

    // possible(a, total, 5);
    int left = 0; // always impossible
    int right = 1e14+1; // always possible
    while (right-left > 1) {
        int mid = (left+right)/2;
        if (possible(a, total, mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    cout << right << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        run();
    }
}
