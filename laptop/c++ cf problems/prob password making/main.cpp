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
    int n = 8;
    vi pow10(15);
    pow10[0] = 1;
    for(int i=1;i<15;i++){
        pow10[i] = pow10[i-1]*10;
    }
    int inc = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                vi perm;
                for(int l=0;l<8;l++){
                    if(l!=i && l!=j && l!=k){
                        perm.pb(l);
                    }
                }
                do{
                    int place = 0;
                    int res = 0;
                    for(int x : perm){
                        while(place==i || place==j || place==k) ++place;
                        res+=pow10[place]*x;
                        ++place;
                    }
                    cout << res << "\n";
                    ++inc;
                    if(inc==40) return;
                } while(next_permutation(perm.begin(),perm.end()));
            }
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
