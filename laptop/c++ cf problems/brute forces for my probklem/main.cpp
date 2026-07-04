#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << "\n"
#define each(a, x) for(auto &&a : x)

unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
mt19937_64 rng(seed);

uniform_int_distribution<int> dist1(1, 9);
uniform_int_distribution<int> dist2(0, 9);
uniform_int_distribution<int> dist_n(1, 8);

// Global container for precomputed move sequences (for n=1..8)
vector<vector<vector<int>>> precomputedSeq(9);

void genSequences(int n, vector<int>& cur, vector<bool>& used, vector<vector<int>> &res) {
    res.push_back(cur);
    for (int i = 0; i < n; i++){
        if (!used[i]){
            used[i] = true;
            cur.push_back(i);
            genSequences(n, cur, used, res);
            cur.pop_back();
            used[i] = false;
        }
    }
}

// Given a state and a move, apply the move and list outcome states with probabilities.
inline void applyMove(int state, int move, int n, long double p, array<pair<int,long double>,4>& out, int &outCount) {
    int base = state | (1 << move);
    int left = -1, right = -1;
    for (int j = move - 1; j >= 0; j--){
        if (base & (1 << j)){
            left = j; break;
        }
    }
    for (int j = move + 1; j < n; j++){
        if (base & (1 << j)){
            right = j; break;
        }
    }
    outCount = 0;
    if(left == -1 && right == -1){
        out[outCount++] = {base, 1.0L};
    }
    else if(left == -1 && right != -1){
        int st1 = base & ~(1 << right);
        out[outCount++] = {st1, p};
        out[outCount++] = {base, 1.0L - p};
    }
    else if(left != -1 && right == -1){
        int st1 = base & ~(1 << left);
        out[outCount++] = {st1, p};
        out[outCount++] = {base, 1.0L - p};
    }
    else {
        int st_both = base; st_both &= ~(1 << left); st_both &= ~(1 << right);
        int st_left = base; st_left &= ~(1 << left);
        int st_right = base; st_right &= ~(1 << right);
        out[outCount++] = {st_both, p * p};
        out[outCount++] = {st_left, p * (1.0L - p)};
        out[outCount++] = {st_right, (1.0L - p) * p};
        out[outCount++] = {base, (1.0L - p) * (1.0L - p)};
    }
}

// Simulate the given sequence of moves from a uniformly random starting state with exactly k bits on.
long double simulateSequence(int n, int k, long double p, const vector<int>& seq) {
    int totalStates = 1 << n;
    vector<long double> dp(totalStates, 0.0L);
    vector<int> initStates;
    for (int s = 0; s < totalStates; s++){
        if(__builtin_popcount(s) == k)
            initStates.push_back(s);
    }
    long double initProb = 1.0L / initStates.size();
    for (int s : initStates)
        dp[s] = initProb;

    for (int move : seq) {
        vector<long double> newdp(totalStates, 0.0L);
        for (int s = 0; s < totalStates; s++){
            long double prob = dp[s];
            if(prob == 0) continue;
            array<pair<int,long double>,4> outcomes;
            int count;
            applyMove(s, move, n, p, outcomes, count);
            for (int i = 0; i < count; i++){
                int ns = outcomes[i].first;
                long double pbranch = outcomes[i].second;
                newdp[ns] += prob * pbranch;
            }
        }
        dp = newdp;
    }

    long double expected = 0.0L;
    for (int s = 0; s < totalStates; s++){
        if(dp[s] == 0) continue;
        int val = 0;
        for (int i = 0; i < n; i++){
            if(s & (1 << i))
                val += (1LL << i);
        }
        expected += dp[s] * val;
    }
    return expected;
}

// Pick test-case values using the original distributions, brute-force over move sequences, and output the best.
void solve(){
    int n,k,d1,d2;
    long double p;
    cin >> n; //n = dist_n(rng);
    uniform_int_distribution<int> dist_k(1, n);
    cin >> k; //k = dist_k(rng);
    //d1 = dist1(rng);
    //d2 = dist2(rng);
    //p = (d1 * 10 + d2) / 100.0L;
    vector<vector<int>> &candidates = precomputedSeq[n];
    cin >> p;
    long double bestVal = -1.0L;
    vector<int> bestSeq;
    for (auto &seq : candidates){
        long double cur = simulateSequence(n, k, p, seq);
        if(cur > bestVal + 1e-12){
            bestVal = cur;
            bestSeq = seq;
        }
    }
    cout << "n: " << n << ". k: " << k << ". p: " << p << "\n";
    cout << fixed << setprecision(10) << bestVal << "\n";
    cout << bestSeq.size();
    for (int m : bestSeq)
        cout << " " << m;
    cout << "\n";
}

signed main(){
    for (int n = 1; n <= 8; n++){
        vector<vector<int>> seqs;
        vector<int> cur;
        vector<bool> used(n, false);
        genSequences(n, cur, used, seqs);
        precomputedSeq[n] = seqs;
    }
    int t = 10;
    while(t--){
        solve();
    }
    return 0;
}
