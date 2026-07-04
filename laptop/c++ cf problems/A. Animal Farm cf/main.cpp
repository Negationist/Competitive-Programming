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
    int n;
    cin >> n;
    int mx = 0;
    int ans = 0;
    vi temp;
    while(n--){
        string s;
        int z;
        cin >> s >> z;
        if(s=="pig"){
            mx = max(mx,z);
        } else{
            temp.pb(z);
        }
    }
    sort(temp.begin(),temp.end());
    for(int i=0;i<temp.size();i++){
        if(temp[i]<mx){
            ans+=temp[i];
        } else{
            break;
        }
    }
    cout << ans+mx << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
