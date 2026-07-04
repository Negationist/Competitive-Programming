#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void solve (int x) {

    for (int i = 0; i < 31; ++i) {
        int y = x & 0x3;

        if (y < 3) {
            cout << (x & 0x1) << ' ';
        } else {
            cout << "-1 ";

            x += 0x2;
        }

        x >>= 1;
    }

    cout << '\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve(27);
    return 0;
}
