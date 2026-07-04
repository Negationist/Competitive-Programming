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
    int n,m;
    cin >> n >> m;
    string a,b;
    cin >> a >> b;
    vi c,d;
    int cnt = 0;
    for(int i=0;i<a.size();i++){
        if(a[i]=='0'){
            if(cnt){
                c.pb(cnt);
                cnt = 0;
            }
        } else{
            ++cnt;
        }
    }
    if(cnt){
        c.pb(cnt);
    }
    cnt = 0;
    for(int i=0;i<b.size();i++){
        if(b[i]=='0'){
            if(cnt){
                d.pb(cnt);
                cnt = 0;
            }
        } else{
            ++cnt;
        }
    }
    if(cnt){
        d.pb(cnt);
    }
    bool lose = false;
    int l = 0, r = c.size()-1;
    int i = 0, j = d.size()-1;
    if(b[0]=='1'){
        if(a[0]!='1'){
            lose = true;
        } else if(d[i]>c[l]){
            lose = true;
        } else{
            i++;
            l++;
        }
    }
    if(b.back()=='1' && i<=j){ //check on this
        if(l>r){
            lose = true;
        } else if(a.back()!='1'){
            lose = true;
        } else if(d[j]>c[r]){
            lose = true;
        } else{
            --r;
            --j;
        }
    }
    while(i<=j && l<=r){
        if(d[i]<=c[l]){
            i++;
            l++;
        } else{
            i++;
        }
    }
    if(l<=r){
        lose = true;
    }
    if(lose){
        cout << "no\n";
    } else{
        cout << "yes\n";
    }
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
