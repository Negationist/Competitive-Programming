#include <iostream>
#include <iomanip>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cmath>
using namespace std;

const double TOL = 1e-10;
const long long MOD = 1000000007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n, k;
        double p;
        cin >> n >> k >> p;

        // For an n‐bit number the “hidden number” must have its most–significant bit set.
        // Thus the adversary (minimizer) chooses the worst–case state:
        // if k == 1 then only the MSB is on; if k > 1, then the remaining k-1 ones are put in the lowest bits.
        int init;
        if(k == 1)
            init = 1 << (n - 1);
        else
            init = (1 << (n - 1)) | ((1 << (k - 1)) - 1);

        // --- BFS to find all reachable states ---
        // A state is represented as an integer whose binary representation tells which bits are on.
        // In a move, you may choose ANY bit i (0 <= i < n) that is 0 and “turn it on.”
        // Then, in the new state (called base = s with bit i set to 1),
        // find the nearest turned–on bit to the left (i.e. with index > i) and to the right (i.e. with index < i).
        // For each neighbor (if it exists) that neighbor is turned off (i.e. its bit cleared) with probability p, independently.

        unordered_set<int> seen;
        vector<int> states;
        queue<int> qu;
        qu.push(init);

        while(!qu.empty()){
            int s = qu.front();
            qu.pop();
            if(seen.count(s))
                continue;
            seen.insert(s);
            states.push_back(s);

            // Try all moves: for every bit i (0 <= i < n) that is off, simulate the move.
            for (int i = 0; i < n; i++){
                if ((s >> i) & 1) continue; // already on, skip

                int base = s | (1 << i); // first set bit i to 1

                // Find the nearest 1 to the left (i.e. with an index greater than i)
                int L = -1;
                for (int j = i + 1; j < n; j++){
                    if ((base >> j) & 1) { L = j; break; }
                }
                // Find the nearest 1 to the right (i.e. with an index less than i)
                int Rn = -1;
                for (int j = i - 1; j >= 0; j--){
                    if ((base >> j) & 1) { Rn = j; break; }
                }

                // List outcomes according to which neighbors exist.
                // Each outcome is the new state after possibly turning off neighbor bits.
                // (Note: if a neighbor doesn't exist, then nothing happens in that direction.)
                vector<int> nextStates;
                if (L != -1 && Rn != -1) {
                    // both neighbors exist: there are four outcomes.
                    // outcome 1: neither neighbor turns off.
                    nextStates.push_back(base);
                    // outcome 2: only the left neighbor (at L) turns off.
                    nextStates.push_back(base & ~(1 << L));
                    // outcome 3: only the right neighbor (at Rn) turns off.
                    nextStates.push_back(base & ~(1 << Rn));
                    // outcome 4: both neighbors turn off.
                    nextStates.push_back(base & ~(1 << L) & ~(1 << Rn));
                } else if (L != -1) {
                    // only L exists: two outcomes.
                    nextStates.push_back(base);            // L stays on
                    nextStates.push_back(base & ~(1 << L));  // L turns off
                } else if (Rn != -1) {
                    // only R exists: two outcomes.
                    nextStates.push_back(base);            // R stays on
                    nextStates.push_back(base & ~(1 << Rn)); // R turns off
                } else {
                    // no neighbor exists; only one outcome.
                    nextStates.push_back(base);
                }
                // Enqueue any new state we haven't seen.
                for (int ns : nextStates) {
                    if (!seen.count(ns))
                        qu.push(ns);
                }
            }
        } // end BFS

        // --- Value Iteration ---
        // Let V(s) be the optimal expected final value from state s.
        // We have the Bellman equation:
        //    V(s) = max { F(s), max_{i with s[i]==0} Q(s,i) }
        // where F(s) is the integer value of s and Q(s,i) is the expected value if we make a move at bit i.
        // (In our interpretation, F(s) = s since s is the integer value corresponding to its bits.)
        unordered_map<int, double> V;
        for (int s : states) {
            V[s] = double(s);
        }

        bool updated = true;
        while(updated){
            updated = false;
            // For each state, compute the best value.
            for (int s : states) {
                double best = double(s); // the “stop” option
                // Try every possible move (flip an off bit)
                for (int i = 0; i < n; i++){
                    if ((s >> i) & 1) continue;  // bit already on
                    int base = s | (1 << i);
                    int L = -1;
                    for (int j = i + 1; j < n; j++){
                        if ((base >> j) & 1) { L = j; break; }
                    }
                    int Rn = -1;
                    for (int j = i - 1; j >= 0; j--){
                        if ((base >> j) & 1) { Rn = j; break; }
                    }

                    double q_val = 0.0;
                    if (L != -1 && Rn != -1) {
                        // two neighbors => 4 outcomes.
                        q_val += (1 - p) * (1 - p) * V[base];
                        q_val += p * (1 - p) * V[ base & ~(1 << L) ];
                        q_val += p * (1 - p) * V[ base & ~(1 << Rn) ];
                        q_val += p * p * V[ base & ~(1 << L) & ~(1 << Rn) ];
                    } else if (L != -1) {
                        // only left neighbor exists => 2 outcomes.
                        q_val += (1 - p) * V[base];
                        q_val += p * V[ base & ~(1 << L) ];
                    } else if (Rn != -1) {
                        // only right neighbor exists => 2 outcomes.
                        q_val += (1 - p) * V[base];
                        q_val += p * V[ base & ~(1 << Rn) ];
                    } else {
                        // no neighbor exists.
                        q_val += V[base];
                    }

                    if (q_val > best)
                        best = q_val;
                }
                if (fabs(best - V[s]) > TOL) {
                    V[s] = best;
                    updated = true;
                }
            }
        }

        // The answer is the optimal expected value from the initial state, taken modulo MOD.
        // (An answer within 1e-8 of the correct value is accepted.)
        double ans = fmod(V[init], MOD);
        if(ans < 0) ans += MOD; // ensure nonnegative
        cout << fixed << setprecision(8) << ans << "\n";
    }
    return 0;
}
