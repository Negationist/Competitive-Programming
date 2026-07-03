#include <bits/stdc++.h>
using namespace std;

// Shortcut definitions (as in your code)
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using u128 = unsigned __int128;
const int inf = 1LL << 60;

// ----- Your Original Solve() Function -----
void solve(){
    string x;
    unsigned long long b;
    cin >> x >> b;
    int n = x.size();
    if(x[0]=='0'){
        cout << "0\n";
        return;
    }
    vector<vi> dp(n, vi(20, inf));
    vector<vi> mn(n, vi(20, inf));
    for(int i = n - 1; i >= 0; i--){
        u128 tot = 0;
        for(int j = 0; j < 20 && i + j < n; j++){
            // if the starting digit of the segment is '0', skip it.
            if(x[i]=='0'){
                continue;
            }
            tot = tot * 10 + (x[i + j] - '0');
            if(tot > b){
                continue;
            }
            if(i + j == n - 1){
                dp[i][j] = 0;
            } else{
                u128 otot = 0;
                int len = -1;
                // Note: if there are many digits (especially if they are zeros)
                // len might become large. Our DP table is only 20 columns wide.
                while(otot < tot && (i + j + 1 + len) < n){
                    ++len;
                    otot = otot * 10 + (x[i + j + 1 + len] - '0');
                }
                if(otot >= tot){
                    // If len is >= 20 then this state will remain inf.
                    dp[i][j] = 1 + mn[i + j + 1][len];
                }
            }
        }
        mn[i][19] = dp[i][19];
        for(int j = 18; j >= 0; j--){
            mn[i][j] = min(mn[i][j+1], dp[i][j]);
        }
    }
    if(mn[0][0] != inf){
        cout << mn[0][0] << "\n";
    } else{
        cout << "NO WAY\n";
    }
}

// ----- Helper to Run a Single Test Case -----
// This function redirects cin/cout using string streams so that we can
// simulate input and capture the output from solve().
string runTestCase(const string &input) {
    auto oldCinBuf = cin.rdbuf();
    auto oldCoutBuf = cout.rdbuf();

    stringstream iss(input);
    ostringstream oss;
    cin.rdbuf(iss.rdbuf());
    cout.rdbuf(oss.rdbuf());

    solve();

    cin.rdbuf(oldCinBuf);
    cout.rdbuf(oldCoutBuf);

    return oss.str();
}

// ----- Stress Test Harness in main() -----
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // --- Random Test Cases ---
    int T = 100; // Number of random tests (adjust as needed)
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

    cout << "=== Random Test Cases ===\n";
    for (int t = 1; t <= T; t++) {
        // Choose a random length for x between 50 and 500 (feel free to adjust)
        int n = uniform_int_distribution<int>(50, 500)(rng);

        // Build a random number string x with n digits; ensure the first digit is nonzero.
        string x;
        x.resize(n);
        x[0] = char('1' + uniform_int_distribution<int>(0, 8)(rng)); // '1'-'9'
        for (int i = 1; i < n; i++){
            x[i] = char('0' + uniform_int_distribution<int>(0, 9)(rng));
        }

        // Generate b: choose a random digit count l in [1, min(n,20)]
        int l = uniform_int_distribution<int>(1, min(n, (int)20))(rng);
        unsigned long long max_b = 1;
        for (int i = 0; i < l; i++){
            max_b *= 10;
        }
        max_b -= 1;
        unsigned long long b = uniform_int_distribution<unsigned long long>(1, max_b)(rng);

        // Prepare the test case input (x and b separated by newline)
        string input = x + "\n" + to_string(b) + "\n";

        // Measure execution time
        auto start = chrono::steady_clock::now();
        string output = runTestCase(input);
        auto end = chrono::steady_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();

        // Display summary for this test case
        cout << "Test Case " << t << ":\n";
        cout << "  n = " << n << ", b = " << b << "\n";
        cout << "  x (first 50 digits): "
             << x.substr(0, min((int)x.size(), 50LL)) << (x.size() > 50 ? "..." : "") << "\n";
        cout << "  Output: " << output;
        cout << "  Time: " << duration << " microseconds\n";
        cout << "----------------------------------------\n";
    }

    // --- Special (Hand-Crafted) Worst-Case Test Cases ---
    cout << "\n=== Special Edge Test Cases ===\n";
    vector<pair<string, unsigned long long>> specialTests;

    // Example 1: x = "1" followed by many zeros, forcing many iterations of the inner loop.
    {
        int n = 100; // e.g. 100-digit number
        string x = "1" + string(n - 1, '0');
        unsigned long long b = 1; // Very small b
        specialTests.push_back({x, b});
    }
    // Example 2: x = repeating '1's
    {
        int n = 100;
        string x(n, '1');
        // b chosen near the upper limit (with 20 digits)
        unsigned long long b = 18446744073709551615ULL;
        specialTests.push_back({x, b});
    }

    for (int i = 0; i < specialTests.size(); i++) {
        auto &test = specialTests[i];
        string input = test.first + "\n" + to_string(test.second) + "\n";

        auto start = chrono::steady_clock::now();
        string output = runTestCase(input);
        auto end = chrono::steady_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();

        cout << "Special Test Case " << i + 1 << ":\n";
        cout << "  n = " << test.first.size() << ", b = " << test.second << "\n";
        cout << "  x (first 50 digits): "
             << test.first.substr(0, min((int)test.first.size(), 50LL))
             << (test.first.size() > 50 ? "..." : "") << "\n";
        cout << "  Output: " << output;
        cout << "  Time: " << duration << " microseconds\n";
        cout << "========================================\n";
    }

    return 0;
}
