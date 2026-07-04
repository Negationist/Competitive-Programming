#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Gate {
    char op;
    int a;
};

struct TestCase {
    int n;
    vector<Gate> left, right;
};

// This simulates your submitted solution exactly.
ll simulate_user(const TestCase &tc) {
    int n = tc.n;
    ll l = 1, r = 1, extra = 0;
    for (int i = 0; i < n; i++) {
        char x1 = tc.left[i].op, x2 = tc.right[i].op;
        int y1 = tc.left[i].a, y2 = tc.right[i].a;
        if (x1 == 'x' && x2 == 'x') {
            if(y1>y2){
                l+=extra;
                extra = 0;
            } else if(y2>y1){
                r+=extra;
                extra = 0;
            } else{
                int sum = l+r+extra;
                sum*=(y1-1);
                extra+=(sum);
                continue;
            }
        } else if (x1 == 'x') {
            l += extra;
            extra = 0;
        } else if (x2 == 'x') {
            r += extra;
            extra = 0;
        } else {
            extra += (y1 + y2);
            continue;
        }
        if (x1 == 'x')
            extra += (l * (y1 - 1));
        else
            extra += y1;
        if (x2 == 'x')
            extra += (r * (y2 - 1));
        else
            extra += y2;
    }
    return l + r + extra;
}

// Brute force simulation using the correct interpretation:
// In each pair, the bonus from each gate is computed using the lane count
// at the start of the pair. The bonus cannot "feed" into a multiplication bonus.
ll bruteRec(int idx, int n, ll L, ll R, const vector<Gate>& leftOps, const vector<Gate>& rightOps) {
    if (idx == n)
        return L + R;
    // Compute bonuses based solely on the current (base) lane counts.
    ll bonusL = (leftOps[idx].op == '+' ? leftOps[idx].a : (leftOps[idx].a - 1) * L);
    ll bonusR = (rightOps[idx].op == '+' ? rightOps[idx].a : (rightOps[idx].a - 1) * R);
    ll best = 0;
    // Four ways to assign the two bonuses:
    best = max(best, bruteRec(idx + 1, n, L + bonusL + bonusR, R, leftOps, rightOps));
    best = max(best, bruteRec(idx + 1, n, L + bonusL, R + bonusR, leftOps, rightOps));
    best = max(best, bruteRec(idx + 1, n, L + bonusR, R + bonusL, leftOps, rightOps));
    best = max(best, bruteRec(idx + 1, n, L, R + bonusL + bonusR, leftOps, rightOps));
    return best;
}

ll simulate_brute(const TestCase &tc) {
    return bruteRec(0, tc.n, 1, 1, tc.left, tc.right);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    mt19937 rng((unsigned)chrono::steady_clock::now().time_since_epoch().count());
    // Keep n small for brute force.
    uniform_int_distribution<int> distN(1, 4);
    uniform_int_distribution<int> distOp(0, 1);       // 0: '+', 1: 'x'
    uniform_int_distribution<int> distPlus(1, 10);    // addition value
    uniform_int_distribution<int> distMul(2, 3);      // multiplication factor (2 or 3)

    int testCount = 0;
    while (true) {
        testCount++;
        TestCase tc;
        tc.n = distN(rng);
        tc.left.resize(tc.n);
        tc.right.resize(tc.n);
        for (int i = 0; i < tc.n; i++) {
            if (distOp(rng) == 0) {
                tc.left[i].op = '+';
                tc.left[i].a = distPlus(rng);
            } else {
                tc.left[i].op = 'x';
                tc.left[i].a = distMul(rng);
            }
            if (distOp(rng) == 0) {
                tc.right[i].op = '+';
                tc.right[i].a = distPlus(rng);
            } else {
                tc.right[i].op = 'x';
                tc.right[i].a = distMul(rng);
            }
        }

        ll userRes = simulate_user(tc);
        ll bruteRes = simulate_brute(tc);
        if (userRes != bruteRes) {
            cout << "Discrepancy found on test #" << testCount << "\n";
            cout << "n = " << tc.n << "\n";
            for (int i = 0; i < tc.n; i++) {
                cout << tc.left[i].op << " " << tc.left[i].a << " "
                     << tc.right[i].op << " " << tc.right[i].a << "\n";
            }
            cout << "User solution result: " << userRes << "\n";
            cout << "Brute force result: " << bruteRes << "\n";
            break;
        }
        if (testCount % 10000 == 0)
            cout << testCount << " tests passed.\n";
    }
    return 0;
}
