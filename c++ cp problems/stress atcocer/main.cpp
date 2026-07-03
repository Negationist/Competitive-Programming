/*  stress.cpp  ––  compares your fast solution with a tiny brute solver
    ---------------------------------------------------------------
    • fastSolve(...) :  your original algorithm (logic unchanged).
    • slowSolve(...) :  exhaustive checker for very small cases
      (N ≤ 8, values in {-1,0…3}).
    • main()         :  random generator + comparison loop.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/* ----------  YOUR ORIGINAL ALGORITHM  ---------- */
string fastSolve(const vector<ll>& A, const vector<ll>& B)
{
    int n = static_cast<int>(A.size());
    map<ll,ll> top, bottom;
    for (ll z : A) ++top[z];
    for (ll z : B) ++bottom[z];

    int need = n - (top[-1] + bottom[-1]);
    ll mx = -1;

    if (need <= 1) return "Yes";

    multiset<ll> cands;
    for (const auto& p : top) {
        if (p.second != bottom[p.first])
            mx = max(mx, p.first);
        ll mn = min(p.second, bottom[p.first]);
        for (ll i = 0; i < mn; ++i) cands.insert(p.first);
    }
    for (const auto& p : bottom)
        if (p.second != top[p.first])
            mx = max(mx, p.first);

    if (cands.empty()) return "No";

    int have = 1;
    ll hi = *cands.rbegin();
    cands.erase(prev(cands.end()));

    while (!cands.empty()) {
        ll nxt = *cands.rbegin();
        if (nxt + hi >= mx) {
            ++have;
            cands.erase(prev(cands.end()));
        } else break;
    }
    return (have >= need) ? "Yes" : "No";
}
/* ----------  END FAST SOLVER ---------- */


/* ----------  BRUTE-FORCE SOLVER FOR TINY CASES ---------- */
constexpr int MAXV = 3;                // brute enumerates only 0…3

bool feasibleWithSum(const vector<ll>& A, const vector<ll>& B, ll S)
{
    multiset<ll> poolA;
    int unkA = 0, unkB = 0;

    for (ll a : A)
        if (a == -1) ++unkA;
        else         poolA.insert(a);

    for (ll b : B)
    {
        if (b == -1) { ++unkB; continue; }

        ll need = S - b;
        if (need < 0) return false;

        auto it = poolA.find(need);
        if (it != poolA.end())  poolA.erase(it);
        else if (unkA)          --unkA;          // fabricate that value
        else                    return false;
    }

    /* pair remaining known As with unknown-B slots */
    for (ll a : poolA) {
        if (S - a < 0 || !unkB) return false;
        --unkB;
    }
    return true;                 // remaining slots can be filled arbitrarily
}

string slowSolve(const vector<ll>& A, const vector<ll>& B)
{
    ll fixed = -1;
    for (size_t i = 0; i < A.size(); ++i)
        if (A[i] != -1 && B[i] != -1) {
            ll cur = A[i] + B[i];
            if (fixed != -1 && cur != fixed) return "No";
            fixed = cur;
        }

    if (fixed != -1)
        return feasibleWithSum(A, B, fixed) ? "Yes" : "No";

    for (ll S = 0; S <= 2 * MAXV; ++S)
        if (feasibleWithSum(A, B, S)) return "Yes";
    return "No";
}
/* ----------  END BRUTE SOLVER ---------- */


/* ----------  RANDOM TEST-CASE GENERATOR (SMALL) ---------- */
pair<vector<ll>,vector<ll>> randomCase(std::mt19937& rng)
{
    std::uniform_int_distribution<int> nDist(2, 8);
    std::uniform_int_distribution<int> vDist(-1, MAXV);

    int n = nDist(rng);
    vector<ll> A(n), B(n);
    for (int i = 0; i < n; ++i) A[i] = vDist(rng);
    for (int i = 0; i < n; ++i) B[i] = vDist(rng);
    return {A, B};
}
/* ----------  END GENERATOR ---------- */


/* --------------------  DRIVER  -------------------- */
int main()
{
    std::mt19937 rng(static_cast<unsigned>(
        std::chrono::high_resolution_clock::now().time_since_epoch().count()));

    long long tests = 0;
    while (true) {
        auto [A, B] = randomCase(rng);

        string fast = fastSolve(A, B);
        string slow = slowSolve(A, B);

        if (fast != slow) {
            cout << "Mismatch after " << tests << " test(s)\n";
            cout << "N = " << A.size() << "\nA:";
            for (ll x : A) cout << ' ' << x;
            cout << "\nB:";
            for (ll x : B) cout << ' ' << x;
            cout << "\nfast = " << fast << "   slow = " << slow << '\n';
            return 0;
        }
        ++tests;
        if (tests % 100000 == 0)
            cerr << tests << " tests passed so far…\n";
    }
}
