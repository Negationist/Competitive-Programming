#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

const int MOD = 1000000007;

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    vector<double> results;

    while (t--) {
        int n, k;
        double p;
        cin >> n >> k >> p;

        int init = (1 << (n - 1)) | ((k > 1 ? (1 << (k - 1)) - 1 : 0));

        if (n < 3) {
            results.push_back(init % MOD);
            continue;
        }

        unordered_set<int> R;
        queue<int> dq;
        dq.push(init);

        while (!dq.empty()) {
            int s = dq.front();
            dq.pop();
            if (R.count(s)) continue;
            R.insert(s);

            for (int i = 1; i < n - 1; ++i) {
                if (((s >> i) & 1) == 0) {
                    int base = s | (1 << i);
                    int L = -1, Rn = -1;

                    for (int j = i + 1; j < n; ++j) {
                        if ((base >> j) & 1) {
                            L = j;
                            break;
                        }
                    }
                    for (int j = i - 1; j >= 0; --j) {
                        if ((base >> j) & 1) {
                            Rn = j;
                            break;
                        }
                    }

                    vector<int> outcomes;
                    if (L != -1 && Rn != -1) {
                        outcomes.push_back(base);
                        outcomes.push_back(base & ~(1 << L));
                        outcomes.push_back(base & ~(1 << Rn));
                        outcomes.push_back(base & ~(1 << L) & ~(1 << Rn));
                    } else if (L != -1) {
                        outcomes.push_back(base);
                        outcomes.push_back(base & ~(1 << L));
                    } else if (Rn != -1) {
                        outcomes.push_back(base);
                        outcomes.push_back(base & ~(1 << Rn));
                    } else {
                        outcomes.push_back(base);
                    }

                    for (int ns : outcomes) {
                        if (!R.count(ns)) {
                            dq.push(ns);
                        }
                    }
                }
            }
        }

        unordered_map<int, double> V;
        for (int s : R) V[s] = static_cast<double>(s);

        double tol = 1e-10;
        bool changed = true;

        while (changed) {
            changed = false;
            for (int s : R) {
                double best = static_cast<double>(s);
                for (int i = 1; i < n - 1; ++i) {
                    if (((s >> i) & 1) == 0) {
                        int base = s | (1 << i);
                        int L = -1, Rn = -1;

                        for (int j = i + 1; j < n; ++j) {
                            if ((base >> j) & 1) {
                                L = j;
                                break;
                            }
                        }
                        for (int j = i - 1; j >= 0; --j) {
                            if ((base >> j) & 1) {
                                Rn = j;
                                break;
                            }
                        }

                        double q_val = 0.0;
                        if (L != -1 && Rn != -1) {
                            q_val += pow(1 - p, 2) * V[base];
                            q_val += p * (1 - p) * V[base & ~(1 << L)];
                            q_val += p * (1 - p) * V[base & ~(1 << Rn)];
                            q_val += pow(p, 2) * V[base & ~(1 << L) & ~(1 << Rn)];
                        } else if (L != -1) {
                            q_val += (1 - p) * V[base];
                            q_val += p * V[base & ~(1 << L)];
                        } else if (Rn != -1) {
                            q_val += (1 - p) * V[base];
                            q_val += p * V[base & ~(1 << Rn)];
                        } else {
                            q_val += V[base];
                        }
                        best = max(best, q_val);
                    }
                }
                if (fabs(best - V[s]) > tol) {
                    V[s] = best;
                    changed = true;
                }
            }
        }

        double ans = fmod(V[init], MOD);
        results.push_back(ans);
    }

    for (double res : results) {
        cout << fixed << setprecision(8) << res << "\n";
    }
}

int main() {
    solve();
    return 0;
}
