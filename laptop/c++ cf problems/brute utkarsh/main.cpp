#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Fast solution function (your original code converted into a function)
bool fastSolveCase(int n, int m, const string &s1, const string &s2) {
    ll cnt = 1;
    vector<ll> track;
    for (int i = 1; i < m; i++) {
        if (s2[i] != s2[i - 1]) {
            track.push_back(cnt);
            cnt = 1;
        } else {
            cnt++;
        }
    }
    track.push_back(cnt);
    ll p1 = 0;
    bool flag = true;
    ll curr = s2[0] - '0';
    vector<ll> ps(n + 1, 0);
    for (int i = 0; i < n; i++) {
        ps[i + 1] = ps[i] + (s1[i] - '0');
    }
    for (int i = 0; i < (int)track.size(); i++) {
        if (i == 0 && curr == 1) {
            if (ps[track[i]] - ps[0] < track[i]) {
                flag = false;
                break;
            }
            p1 = track[i];
        } else if (curr == 1) {
            while (p1 + track[i] <= n && ps[p1 + track[i]] - ps[p1] != track[i]) {
                p1++;
            }
            if (p1 + track[i] > n) {
                flag = false;
                break;
            }
            p1 += track[i];
        } else { // curr == 0
            ll temp = 0;
            while (p1 < n && temp < track[i]) {
                if (s1[p1] == '0') {
                    temp++;
                }
                p1++;
            }
            if (temp < track[i]) {
                flag = false;
                break;
            }
        }
        curr = 1 - curr;
    }
    if (curr == 0 && ps[n] - ps[n - track.back()] != track.back()) {
        flag = false;
    }
    return flag;
}

// Brute-force solution: recursively generate all outcomes.
void getAllOutcomes(const string &s, set<string> &outcomes, unordered_map<string, set<string>> &dp) {
    if(dp.count(s)) {
        outcomes.insert(dp[s].begin(), dp[s].end());
        return;
    }
    set<string> local;
    local.insert(s);
    if(s.size() >= 2) {
        for (int i = 0; i < (int)s.size() - 1; i++) {
            char newChar = (s[i] == '1' && s[i+1] == '1') ? '1' : '0';
            string next = s.substr(0, i) + string(1, newChar) + s.substr(i + 2);
            set<string> sub;
            getAllOutcomes(next, sub, dp);
            local.insert(sub.begin(), sub.end());
        }
    }
    dp[s] = local;
    outcomes.insert(local.begin(), local.end());
}

bool bruteSolveCase(int n, int m, const string &s1, const string &s2) {
    unordered_map<string, set<string>> dp;
    set<string> outcomes;
    getAllOutcomes(s1, outcomes, dp);
    return outcomes.count(s2) > 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(NULL));

    int T = 10000; // Number of random tests
    for (int test = 1; test <= T; test++){
        int n = rand() % 9 + 2;    // n in [2,10]
        int m = rand() % n + 1;    // m in [1, n]
        string s1, s2;
        for (int i = 0; i < n; i++){
            s1.push_back((rand() % 2) ? '1' : '0');
        }
        for (int i = 0; i < m; i++){
            s2.push_back((rand() % 2) ? '1' : '0');
        }
        bool fastAns = fastSolveCase(n, m, s1, s2);
        bool bruteAns = bruteSolveCase(n, m, s1, s2);
        if(fastAns != bruteAns){
            cout << "Mismatch found on test case " << test << "\n";
            cout << "n = " << n << ", m = " << m << "\n";
            cout << "s1 = " << s1 << "\n";
            cout << "s2 = " << s2 << "\n";
            cout << "fastSolveCase = " << (fastAns ? "yes" : "no") << "\n";
            cout << "bruteSolveCase = " << (bruteAns ? "yes" : "no") << "\n";
            return 0;
        }
    }
    cout << "All " << T << " tests passed.\n";
    return 0;
}
