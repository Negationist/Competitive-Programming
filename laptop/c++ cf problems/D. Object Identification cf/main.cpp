#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;

int ask(int i, int j){
    cout << i << " " << j << "?\n";
    cout.flush();
    int z;
    cin >> z;
    return z;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi a(n);
        for(int i=0;i<n;i++) cin >> a[i];

        int win;
        cin >> win;
        if(win==-1){
            return 0;
        }
    }
    return 0;
}
