#include <bits/stdc++.h>
using namespace std;

// For checking if input is coming from a terminal.
#ifdef _WIN32
    #include <io.h>
    #define isatty _isatty
#else
    #include <unistd.h>
#endif

// -------------------------
// FAST SOLUTION (adapted from your code)
// -------------------------
string fastSolve(const string &a, const string &b) {
    vector<pair<int,int>> b1, b2;
    int cnt = 1;
    for (int i = 1; i < (int)a.size(); i++) {
        if(a[i] == a[i-1])
            cnt++;
        else {
            b1.push_back({a[i-1]-'0', cnt});
            cnt = 1;
        }
    }
    b1.push_back({a.back()-'0', cnt});

    cnt = 1;
    for (int i = 1; i < (int)b.size(); i++) {
        if(b[i] == b[i-1])
            cnt++;
        else {
            b2.push_back({b[i-1]-'0', cnt});
            cnt = 1;
        }
    }
    b2.push_back({b.back()-'0', cnt});

    // Handle edge cases
    if(b2.size() == 1) {
        if(b2[0].first == 1) {
            if(b1.size() == 1 && b1[0].first == 1 && b1[0].second >= b2[0].second)
                return "yes";
            else
                return "no";
        }
    }
    if(b1.size() == 1) {
        if(b2.size() != 1)
            return "no";
        else {
            if(b1[0].second >= b2[0].second && b1[0].first == b2[0].first)
                return "yes";
            else
                return "no";
        }
    }
    // Both a and b have multiple blocks.
    int l1 = 0, r1 = (int)b1.size()-1, l2 = 0, r2 = (int)b2.size()-1;
    if(b2[0].first == 1) {
        if(b1[0].first == 1 && b1[0].second >= b2[0].second) {
            l1++;
            l2++;
        } else {
            return "no";
        }
    }
    if(b2[r2].first == 1) {
        if(b1[r1].first == 1 && b1[r1].second >= b2[r2].second) {
            r1--;
            r2--;
        } else {
            return "no";
        }
    }
    for (int i = l2; i <= r2; i++) {
        if(b2[i].first == 0) {
            int k = b2[i].second;
            while(k>0 && l1 <= r1) {
                if(b1[l1].first == 0)
                    k -= b1[l1].second;
                l1++;
            }
            if(k > 0)
                return "no";
        } else {
            bool flag = false;
            while(l1 <= r1) {
                if(b1[l1].first == 1 && b1[l1].second >= b2[i].second) {
                    flag = true;
                    l1++;
                    break;
                }
                l1++;
            }
            if(!flag)
                return "no";
        }
    }
    return "yes";
}

// Reads test cases from input and runs the fast solution.
void fastSolution() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        string a, b;
        cin >> a >> b;
        cout << fastSolve(a, b) << "\n";
    }
}

// -------------------------
// BRUTE-FORCE SOLUTION (for small n only)
// -------------------------

bool brute(const string &s, const string &target, unordered_map<string, bool> &memo) {
    if(s == target && s.size() == target.size())
        return true;
    if(s.size() == target.size())
        return s == target;
    if(memo.count(s))
        return memo[s];
    for (int i = 0; i < (int)s.size()-1; i++) {
        char merged = (s[i] == '1' && s[i+1] == '1') ? '1' : '0';
        string ns = s.substr(0, i) + merged + s.substr(i+2);
        if(brute(ns, target, memo))
            return memo[s] = true;
    }
    return memo[s] = false;
}

string bruteSolve(const string &B, const string &C) {
    unordered_map<string, bool> memo;
    bool res = brute(B, C, memo);
    return res ? "yes" : "no";
}

// -------------------------
// HELPER FUNCTIONS FOR TEST CASE HANDLING
// -------------------------

string runFastTest(const string &input) {
    stringstream ss(input);
    int t;
    ss >> t;
    ostringstream oss;
    for (int tc = 0; tc < t; tc++) {
        int n, m;
        ss >> n >> m;
        string B, C;
        ss >> B >> C;
        oss << fastSolve(B, C) << "\n";
    }
    return oss.str();
}

string runBruteTest(const string &input) {
    stringstream ss(input);
    int t;
    ss >> t;
    ostringstream oss;
    for (int tc = 0; tc < t; tc++) {
        int n, m;
        ss >> n >> m;
        string B, C;
        ss >> B >> C;
        oss << bruteSolve(B, C) << "\n";
    }
    return oss.str();
}

// -------------------------
// RANDOM TEST CASE GENERATOR (for stress testing)
// -------------------------
string generateTestCase() {
    // Use small n (1 <= n <= 10) so brute force remains feasible.
    int n = rand() % 10 + 1;
    int m;
    if(n == 1)
        m = 1;
    else
        m = rand() % n + 1; // m in [1, n]

    // Generate random binary string B of length n.
    string B;
    for (int i = 0; i < n; i++) {
        B.push_back((rand() % 2) ? '1' : '0');
    }

    string C;
    // With 50% chance, generate a reachable C by applying exactly (n - m) merge operations.
    // Otherwise, generate a random binary string of length m.
    bool reachable = (rand() % 2 == 0);
    if(m == n) {
        C = B; // zero operations: only possibility.
    } else if(reachable) {
        string cur = B;
        int ops = n - m;
        for (int i = 0; i < ops; i++) {
            int pos = rand() % (cur.size()-1);
            char merged = (cur[pos] == '1' && cur[pos+1] == '1') ? '1' : '0';
            cur = cur.substr(0, pos) + merged + cur.substr(pos+2);
        }
        C = cur;
    } else {
        for (int i = 0; i < m; i++) {
            C.push_back((rand() % 2) ? '1' : '0');
        }
    }

    ostringstream oss;
    oss << 1 << "\n";
    oss << n << " " << m << "\n";
    oss << B << "\n" << C << "\n";
    return oss.str();
}

// -------------------------
// MAIN FUNCTION: MODE SELECTION
// -------------------------
int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);

    cout << "Choose mode:\n";
    cout << "1. Interactive mode (solution mode)\n";
    cout << "2. Stress tester (10000 random test cases)\n";
    cout << "Enter your choice (1 or 2): ";

    int choice;
    if(!(cin >> choice)){
        // if no valid input, default to interactive mode
        choice = 1;
    }

    if(choice == 2) {
        srand((unsigned)time(0));
        const int ITERATIONS = 10000;
        for (int iter = 1; iter <= ITERATIONS; iter++) {
            string test = generateTestCase();
            string fastOut = runFastTest(test);
            string bruteOut = runBruteTest(test);
            if(fastOut != bruteOut) {
                cout << "Discrepancy found on test case #" << iter << ":\n";
                cout << "Test case input:\n" << test << "\n";
                cout << "Fast solution output:\n" << fastOut;
                cout << "Brute solution output:\n" << bruteOut;
                return 0;
            }
        }
        cout << "All tests passed (" << ITERATIONS << " cases).\n";
    } else {
        // If running interactively and no input is provided, use a default test case.
        if(isatty(0)) {
            // Clear any newline left in input
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // Ask user to enter input or press Enter to use default test case.
            cout << "Enter test input as per problem format or just press Enter to use a default test case:\n";
            string line;
            getline(cin, line);
            if(line.empty()){
                string defaultTest = "1\n8 4\n11011011\n1011\n";
                cerr << "No input provided. Using default test case:\n" << defaultTest << "\n";
                stringstream ss(defaultTest);
                cin.rdbuf(ss.rdbuf());
            } else {
                // Put back the line into input stream (simulate full input)
                string input = line + "\n";
                while(getline(cin, line)) {
                    input += line + "\n";
                }
                stringstream *pStream = new stringstream(input);
                cin.rdbuf(pStream->rdbuf());
            }
        }
        fastSolution();
    }
    return 0;
}
