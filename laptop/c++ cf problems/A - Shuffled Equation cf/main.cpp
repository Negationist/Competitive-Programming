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

void solve(){
    vi a(3);
    for(int i=0;i<3;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    do{
        if(a[0]*a[1]==a[2]){
            cout << "Yes\n";
            return;
        }
    } while(next_permutation(a.begin(),a.end()));
    cout << "No\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
