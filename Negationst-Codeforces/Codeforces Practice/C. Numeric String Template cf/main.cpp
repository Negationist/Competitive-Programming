#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    FOR(i, n) {
        cin >> arr[i];
    }

    int tc;
    cin >> tc;

    while (tc--) {
        unordered_map<char, int> charToInt;
        unordered_set<int> usedInts;
        bool good = true;
        string x;
        cin >> x;
        if (x.size() != n) {
            cout << "NO" << endl;
            continue;
        }
        FOR(i, n) {
            if (charToInt.find(x[i]) == charToInt.end()) {
                if (usedInts.find(arr[i]) != usedInts.end()) {
                    good = false;
                    break;
                }
                charToInt[x[i]] = arr[i];
                usedInts.insert(arr[i]);
            } else {
                if (charToInt[x[i]] != arr[i]) {
                    good = false;
                    break;
                }
            }
        }

        if (good) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
