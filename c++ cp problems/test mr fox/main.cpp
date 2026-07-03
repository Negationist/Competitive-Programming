#include <bits/stdc++.h>
using namespace std;

// ---------- Fast (provided) solution implementation ----------

// This function simulates the provided solution.
// It reads the test case from the input string and returns a vector of answers.
vector<long long> fast_solution(const string &input_str) {
    istringstream iss(input_str);
    int n, L, q;
    iss >> n >> L >> q;
    vector<long long> a(n);
    for (int i = 0; i < n; i++){
        iss >> a[i];
    }
    auto eps = -1e-12L;
    auto check = [&](int z, int p, int w) -> long long {
        long double x = L - ( (long double)L * p / w ); // x = L - L*p/w
        long double u = (long double)L / a[z];            // u = L / a[z]
        int lo = 0, hi = z;
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            long double distance = (a[z] - a[mid]) * u;
            if(distance - x < eps){
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return (long long)(z - lo + 1);
    };
    vector<long long> ans;
    while(q--){
        int p, w;
        iss >> p >> w;
        ans.push_back(check(n-1, p, w));
    }
    return ans;
}

// ---------- Brute force (correct) solution implementation ----------
//
// For each player i the conditions for being caught (by a chosen U) are:
//   (L*P)/(w*A[i]) < U < L/(A[i])
// Hence for each query (with given P and w) the answer is the maximum
// number of intervals (one per player) that overlap – i.e. the maximum
// count of players that would be caught for some U.

vector<long long> brute_solution(const string &input_str) {
    istringstream iss(input_str);
    int n, L, Q;
    iss >> n >> L >> Q;
    vector<long long> A(n);
    for (int i = 0; i < n; i++){
        iss >> A[i];
    }
    vector<long long> ans;
    for (int qi = 0; qi < Q; qi++){
        int P, W;
        iss >> P >> W;
        vector<pair<long double,long double>> intervals;
        vector<long double> endpoints;
        // For each player i, the interval is ( L*P/(W*A[i]) , L/(A[i]) )
        for (int i = 0; i < n; i++){
            long double left = ( (long double)L * P ) / (W * (long double)A[i]);
            long double right = (long double)L / (long double)A[i];
            intervals.push_back({left, right});
            endpoints.push_back(left);
            endpoints.push_back(right);
        }
        sort(endpoints.begin(), endpoints.end());
        // Remove duplicate endpoints (using a tolerance)
        vector<long double> uniq;
        for (long double v : endpoints) {
            if(uniq.empty() || fabsl(v - uniq.back()) > 1e-12L)
                uniq.push_back(v);
        }

        int best = 0;
        // Try candidate U values in the “gaps” between endpoints.
        // (Since the caught–count function is piecewise constant between endpoints.)
        if(!uniq.empty()){
            {
                long double candidate = uniq[0] + 1e-9L;
                int cnt = 0;
                for (int i = 0; i < n; i++){
                    if(candidate - intervals[i].first > 1e-12L && intervals[i].second - candidate > 1e-12L)
                        cnt++;
                }
                best = max(best, cnt);
            }
            for (size_t i = 0; i + 1 < uniq.size(); i++){
                if(uniq[i+1] - uniq[i] > 1e-12L) {
                    long double candidate = (uniq[i] + uniq[i+1]) / 2.0L;
                    int cnt = 0;
                    for (int j = 0; j < n; j++){
                        if(candidate - intervals[j].first > 1e-12L && intervals[j].second - candidate > 1e-12L)
                            cnt++;
                    }
                    best = max(best, cnt);
                }
            }
        }
        ans.push_back(best);
    }
    return ans;
}

// ---------- Test case generator ----------
//
// This generator produces random test cases that obey the constraints.
// (For stress testing we choose small N and Q so that the brute force method is fast.)
// The paces A are generated as an arithmetic progression (which meets the conditions).
string generate_test_case() {
    static mt19937 rng((unsigned)chrono::steady_clock::now().time_since_epoch().count());
    // Choose N and Q in [1, 10]
    int N = uniform_int_distribution<int>(1, 10)(rng);
    int Q = uniform_int_distribution<int>(1, 10)(rng);
    // Generate an arithmetic progression for A: choose a start and difference.
    int start = uniform_int_distribution<int>(1, 10)(rng);
    int d = uniform_int_distribution<int>(1, 10)(rng);
    vector<int> A(N);
    for (int i = 0; i < N; i++){
        A[i] = start + i * d;
    }
    // Choose L so that L >= A[N-1]. Let L be in [A[N-1], A[N-1] + 50]
    int L = A[N-1] + uniform_int_distribution<int>(0, 50)(rng);
    // Build the test case string in the required format.
    ostringstream oss;
    oss << N << " " << L << " " << Q << "\n";
    for (int i = 0; i < N; i++){
        oss << A[i] << (i + 1 == N ? "\n" : " ");
    }
    // For each query, choose integers P and W (with 1 ≤ P < W ≤ 10^9).
    // Here we choose P in [1, 10] and W in [P+1, P+10].
    for (int i = 0; i < Q; i++){
        int P = uniform_int_distribution<int>(1, 10)(rng);
        int W = uniform_int_distribution<int>(P+1, P+10)(rng);
        oss << P << " " << W << "\n";
    }
    return oss.str();
}

// ---------- Main stress-test loop ----------

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCount = 0;
    while (true) {
        testCount++;
        string test_input = generate_test_case();

        vector<long long> fast_ans = fast_solution(test_input);
        vector<long long> brute_ans = brute_solution(test_input);

        if (fast_ans != brute_ans) {
            cout << "Discrepancy found on test case #" << testCount << ":\n";
            cout << "============================================\n";
            cout << "Test case input:\n" << test_input << "\n";
            cout << "Fast (provided) solution output:\n";
            for(auto &x : fast_ans)
                cout << x << "\n";
            cout << "Brute force (correct) output:\n";
            for(auto &x : brute_ans)
                cout << x << "\n";
            cout << "============================================\n";
            break;
        }

        if(testCount % 1000 == 0){
            cout << testCount << " test cases passed so far...\n";
        }
    }

    return 0;
}
