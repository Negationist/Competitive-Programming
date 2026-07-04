#include <bits/stdc++.h>
#include <chrono>
#include <random>
using namespace std;

unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
mt19937_64 rng(seed);
long long mn = 1, mx = 1LL << 30;
uniform_int_distribution<long long> dist(mn, mx);

int palindrome(string s) {
    int n = s.size();
    if(n == 0) return 0;

    // Random base and fixed modulus.
    long long A = dist(rng);
    int B = 1000000007;

    // Precompute powers of A modulo B.
    vector<long long> p(n);
    p[0] = 1;
    for (int i = 1; i < n; i++) {
        p[i] = (p[i - 1] * A) % B;
    }

    // Compute prefix hash for the original string.
    vector<long long> h(n);
    h[0] = s[0];
    for (int i = 1; i < n; i++) {
        h[i] = (h[i - 1] * A + s[i]) % B;
    }

    // Create a reversed copy of s and compute its prefix hash.
    string rs = s;
    reverse(rs.begin(), rs.end());
    vector<long long> h2(n);
    h2[0] = rs[0];
    for (int i = 1; i < n; i++) {
        h2[i] = (h2[i - 1] * A + rs[i]) % B;
    }

    // Helper lambda to compute hash for substring [i, j] using a prefix hash array.
    auto getHash = [&](const vector<long long>& H, int i, int j) -> int {
        long long result = H[j] - (i ? (H[i - 1] * p[j - i + 1]) % B : 0);
        result %= B;
        if(result < 0) result += B;
        return (int) result;
    };

    // For substring s[i...j], its reverse is rs[n-1-j...n-1-i].
    auto getRevHash = [&](int i, int j) -> int {
        int L = n - 1 - j;
        int R = n - 1 - i;
        return getHash(h2, L, R);
    };

    // Check if s[i...j] is a palindrome by comparing its hash with the hash of its reverse.
    auto isPalindrome = [&](int i, int j) -> bool {
        return getHash(h, i, j) == getRevHash(i, j);
    };

    // Use a vector of sets to collect unique palindromes (grouped by length).
    long long ans = 0;
    vector<set<int>> hashes(n + 1);
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            if (isPalindrome(i, j)) {
                int len = j - i + 1;
                hashes[len].insert(getHash(h, i, j));
            }
        }
    }

    for (int len = 1; len <= n; len++){
        ans += hashes[len].size();
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);
    int result = palindrome(s);
    cout << result << "\n";
    return 0;
}
