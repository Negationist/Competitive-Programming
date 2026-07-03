#include <bits/stdc++.h>
using namespace std;

// ======================================================
// Your solution code, wrapped as a function solveCandidate()
// so we can call it from the test driver.
// ======================================================
void solveCandidate(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // This array is partially initialized; pay attention to indices used.
    static long long cnt[2005][2]; // enough for 2*n+5 if n <= 1000
    // We won't strictly re-initialize for each test, but that's okay as long as we fill needed indices carefully.

    // We'll fill only in the range [1..n].
    // Make sure we don't read uninitialized data if frequencies > n.
    // (For a random test with small N, this might not blow up, but let's fill everything up to 2n.)
    for(int i = 0; i <= 2*n+1; i++){
        cnt[i][0] = cnt[i][1] = -1;  // default
    }

    // Now assign:
    if(n <= 2*n+1){ // trivial check
        cnt[n][0] = n+1;
        cnt[n][1] = n+1;

        for(int i = n-1; i >= 1; i--){
            int inc = (n - i);
            cnt[i][0] = (n + 1 - inc);
            cnt[i][1] = (n + 1 + inc);
        }
        // If you want to handle frequencies > n properly, consider filling more of cnt here.
        // For small N in stress tests, this might suffice.
    }

    vector<vector<long long>> a(n, vector<long long>(n));
    auto ans1 = a;
    auto ans2 = a;

    vector<long long> fcnt(2*n+5, 0LL);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
            fcnt[a[i][j]]++;
        }
    }

    if(n==1){
        cout << a[0][0] << "\n";
        return;
    }

    // goal = [1..n]
    vector<long long> goal(n);
    iota(goal.begin(), goal.end(), 1LL);

    int index=0;
    // find a row whose frequencies match "goal"
    for(int i=0; i<n; i++){
        vector<long long> nums;
        nums.reserve(n);
        for(int j=0; j<n; j++){
            nums.push_back(fcnt[a[i][j]]);
        }
        sort(nums.begin(), nums.end());
        if(nums == goal){
            index = i;
            break;
        }
    }

    // build ans1 using cnt[..][0]
    map<long long,long long> asgn;
    for(int i=0; i<n; i++){
        long long num = fcnt[a[index][i]];
        // protect if num>2n or if cnt[num][0] is -1
        if(num < 2*n+5 && cnt[num][0] != -1){
            asgn[a[index][i]] = cnt[num][0];
        } else {
            // fallback if out-of-range
            asgn[a[index][i]] = 1;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(asgn.count(a[i][j])){
                ans1[i][j] = asgn[a[i][j]];
            } else {
                long long num = fcnt[a[i][j]];
                // if out-of-range or not set, fallback:
                if(num < 2*n+5 && cnt[num][1] != -1){
                    ans1[i][j] = cnt[num][1];
                } else {
                    ans1[i][j] = 1;
                }
            }
        }
    }

    // build ans2 using cnt[..][1]
    asgn.clear();
    for(int i=0; i<n; i++){
        long long num = fcnt[a[index][i]];
        if(num < 2*n+5 && cnt[num][1] != -1){
            asgn[a[index][i]] = cnt[num][1];
        } else {
            asgn[a[index][i]] = 1;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(asgn.count(a[i][j])){
                ans2[i][j] = asgn[a[i][j]];
            } else {
                long long num = fcnt[a[i][j]];
                if(num < 2*n+5 && cnt[num][0] != -1){
                    ans2[i][j] = cnt[num][0];
                } else {
                    ans2[i][j] = 1;
                }
            }
        }
    }

    // Check function
    auto checkValid = [&](const vector<vector<long long>> &cur) -> bool {
        // check rows
        for(int r=0; r<n; r++){
            auto temp = cur[r];
            sort(temp.begin(), temp.end());
            for(int i2=1; i2<n; i2++){
                if(temp[i2] != temp[i2-1] + 1) {
                    return false;
                }
            }
        }
        // check columns
        for(int c=0; c<n; c++){
            vector<long long> temp;
            temp.reserve(n);
            for(int r=0; r<n; r++){
                temp.push_back(cur[r][c]);
            }
            sort(temp.begin(), temp.end());
            for(int i2=1; i2<n; i2++){
                if(temp[i2] != temp[i2-1] + 1) {
                    return false;
                }
            }
        }
        return true;
    };

    bool pos1 = checkValid(ans1);
    bool pos2 = checkValid(ans2);

    // comparator for 2D arrays
    auto isLexSmaller = [&](const vector<vector<long long>> &A,
                            const vector<vector<long long>> &B){
        for(int r=0; r<n; r++){
            for(int c=0; c<n; c++){
                if(A[r][c] < B[r][c]) return true;
                if(A[r][c] > B[r][c]) return false;
            }
        }
        return false;
    };

    if(pos1 && pos2){
        if(isLexSmaller(ans1, ans2)){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    cout << ans1[i][j] << (j+1<n ? ' ':'\n');
                }
            }
        } else {
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    cout << ans2[i][j] << (j+1<n ? ' ':'\n');
                }
            }
        }
    } else if(pos1){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << ans1[i][j] << (j+1<n ? ' ':'\n');
            }
        }
    } else if(pos2){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << ans2[i][j] << (j+1<n ? ' ':'\n');
            }
        }
    } else {
        // fallback: just print ans1 if neither passes, though by problem statement
        // at least one should pass in valid tests.
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << ans1[i][j] << (j+1<n ? ' ':'\n');
            }
        }
    }
}

// ======================================================
// Brute-force reference solver for small N
// ======================================================
bool canMap1to1(const vector<vector<long long>>& T,
                const vector<vector<long long>>& F){
    int N = T.size();
    unordered_map<long long, long long> forward, backward;
    forward.reserve(N*N);
    backward.reserve(N*N);

    for(int r=0; r<N; r++){
        for(int c=0; c<N; c++){
            long long tv = T[r][c];
            long long fv = F[r][c];
            if(forward.count(tv)){
                if(forward[tv] != fv) return false;
            } else {
                // check if something else already maps to fv
                if(backward.count(fv)){
                    if(backward[fv] != tv) return false;
                }
                forward[tv] = fv;
                backward[fv] = tv;
            }
        }
    }
    return true;
}

// build original NxN addition table
vector<vector<long long>> buildOriginalTable(int N){
    vector<vector<long long>> table(N, vector<long long>(N));
    for(int r=0; r<N; r++){
        for(int c=0; c<N; c++){
            table[r][c] = (r+1) + (c+1);
        }
    }
    return table;
}

bool isLexSmaller(const vector<vector<long long>>& A,
                  const vector<vector<long long>>& B){
    int N = A.size();
    for(int r=0; r<N; r++){
        for(int c=0; c<N; c++){
            if(A[r][c] < B[r][c]) return true;
            if(A[r][c] > B[r][c]) return false;
        }
    }
    return false;
}

// Brute force all row permutations and column permutations for small N
// to find the lexicographically smallest T that can map to finalTable
// via a 1-to-1 global value rename.
vector<vector<long long>> solveReference(const vector<vector<long long>>& finalTable){
    int N = finalTable.size();
    auto orig = buildOriginalTable(N);

    vector<int> rowP(N), colP(N);
    iota(rowP.begin(), rowP.end(), 0);
    iota(colP.begin(), colP.end(), 0);

    bool found = false;
    vector<vector<long long>> best(N, vector<long long>(N, LLONG_MAX));

    do {
        do {
            // build a permuted table T
            vector<vector<long long>> T(N, vector<long long>(N));
            for(int r=0; r<N; r++){
                for(int c=0; c<N; c++){
                    T[r][c] = orig[rowP[r]][colP[c]];
                }
            }
            // check if T can map -> finalTable
            if(canMap1to1(T, finalTable)){
                if(!found){
                    best = T;
                    found = true;
                } else {
                    if(isLexSmaller(T, best)){
                        best = T;
                    }
                }
            }
        } while(next_permutation(colP.begin(), colP.end()));
    } while(next_permutation(rowP.begin(), rowP.end()));

    return best;
}

// ======================================================
// Random final table generator
// ======================================================
static mt19937 rng(0); // fixed seed for consistent tests

vector<vector<long long>> generateRandomFinal(int N){
    // build original
    auto tbl = buildOriginalTable(N);

    // random row swaps
    for(int r=0; r<N; r++){
        int r2 = uniform_int_distribution<int>(r, N-1)(rng);
        swap(tbl[r], tbl[r2]);
    }
    // random col swaps
    for(int c=0; c<N; c++){
        int c2 = uniform_int_distribution<int>(c, N-1)(rng);
        for(int r=0; r<N; r++){
            swap(tbl[r][c], tbl[r][c2]);
        }
    }
    // random global value swaps
    int swapsCount = uniform_int_distribution<int>(0, N)(rng);
    for(int i=0; i<swapsCount; i++){
        long long a = uniform_int_distribution<long long>(2, 2LL*N)(rng);
        long long b = uniform_int_distribution<long long>(2, 2LL*N)(rng);
        if(a==b) continue;
        for(int r=0; r<N; r++){
            for(int c=0; c<N; c++){
                if(tbl[r][c] == a) tbl[r][c] = b;
                else if(tbl[r][c] == b) tbl[r][c] = a;
            }
        }
    }
    return tbl;
}

// ======================================================
// Main: runs multiple tests for N=2..5, each with T=100 random cases
// ======================================================
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // We'll do random tests up to N=5, which we can handle by brute force.
    for(int N=2; N<=5; N++){
        int T = 100; // number of tests per N
        bool allPassed = true;
        for(int t=1; t<=T; t++){
            auto finalTable = generateRandomFinal(N);

            // Build input as a string
            ostringstream inData;
            inData << N << "\n";
            for(int r=0; r<N; r++){
                for(int c=0; c<N; c++){
                    inData << finalTable[r][c] << (c+1<N ? ' ':'\n');
                }
            }

            // Run your solution
            // We'll capture its output in a string
            istringstream iss(inData.str());
            ostringstream oss;
            {
                // temporarily redirect cin/cout
                streambuf* oldIn = cin.rdbuf();
                streambuf* oldOut = cout.rdbuf();
                cin.rdbuf(iss.rdbuf());
                cout.rdbuf(oss.rdbuf());

                solveCandidate();

                // restore
                cin.rdbuf(oldIn);
                cout.rdbuf(oldOut);
            }

            // Parse your solution's output into a 2D vector
            vector<vector<long long>> cand(N, vector<long long>(N));
            {
                istringstream parseOut(oss.str());
                for(int r=0; r<N; r++){
                    for(int c=0; c<N; c++){
                        if(!(parseOut >> cand[r][c])){
                            // in case of parse fail, fill something
                            cand[r][c] = -999999;
                        }
                    }
                }
            }

            // Run reference
            auto ref = solveReference(finalTable);

            // Compare
            if(cand != ref){
                cerr << "Mismatch found! N=" << N << ", test=" << t << "\n"
                     << "Final table:\n" << inData.str() << "\n"
                     << "Your output:\n" << oss.str() << "\n"
                     << "Reference:\n";
                for(int r=0; r<N; r++){
                    for(int c=0; c<N; c++){
                        cerr << ref[r][c] << (c+1<N ? ' ':'\n');
                    }
                }
                cerr << endl;
                allPassed = false;
                break; // break from test loop
            }
        }
        if(allPassed){
            cerr << "All tests passed for N=" << N << "!\n";
        } else {
            break;
        }
    }
    cerr << "Done.\n";

    return 0;
}
