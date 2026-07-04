#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;

void solve(){
    int n;
    cin >> n;
    int l = 1, r = 1;
    int extra = 0;
    for(int i=0;i<n;i++){
        char x1,x2;
        int y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1=='x' && x2=='x'){
            if(y1>y2){
                l+=extra;
                extra = 0;
            } else if(y2>y1){
                r+=extra;
                extra = 0;
            } else{
                int sum = l+r+extra;
                sum*=(y1-1);
                extra+=(sum);
                continue;
            }
        } else if(x1=='x'){
            l+=extra;
            extra = 0;
        } else if(x2=='x'){
            r+=extra;
            extra = 0;
        } else{
            extra+=(y1+y2);
            //cout << l << " " << r << " " << extra << "!\n";
            continue;
        }
        if(x1=='x'){
            extra+=(l*(y1-1));
        } else{
            extra+=y1;
        }
        if(x2=='x'){
            extra+=(r*(y2-1));
        } else{
            extra+=y2;
        }
        //cout << l << " " << r << " " << extra << "!\n";
    }
    cout << l+r+extra << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
