#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

void solve(){
    int n,k;
    cin >> n >> k;
    vi a(n);
    bool diff = false;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(i && a[i-1]!=a[i]){
            diff = true;
        }
    }
    if(!diff || n==1){
        cout << "YES\n";
        return;
    }
    vi b = a;
    sort(b.begin(),b.end());
    int hi = b[k-1];
    vi c,d,e;
    for(int i=0;i<n;i++){
        if(a[i]<=hi){
            c.pb(a[i]);
            if(a[i]<hi){
                d.pb((int)c.size()-1);
                e.pb(a[i]);
            }
        }
    }
    int need = (k-1) - (int)d.size();
    int num  = (int)(d.size()),l,r;
    //cout << num << "!!\n";
    if(!num){
        cout << "YES\n";
        return;
    }
    if(num&1){
        l = d[(num/2)], r = l;
        
    } else{
        l = d[(num/2)-1], r = d[num/2];
        while(l+1<=r-1){
            l++;
            r--;
        }
    }
    if(l==r){
        if(c[l]==hi){
            --need;
        }
        l--;
        r++;
    }
    multiset<int> s;
    num = -1;
    while(l>=0){
        if(c[l]==hi){
            s.insert(num);
        } else{
            num--;
        }
        --l;
    }
    num = 1;
    while(r<(int)(c.size())){
        if(c[r]==hi){
            s.insert(num);
        } else{
            num++;
        }
        ++r;
    }
    while(s.size()){
        int x = *s.begin();
        s.erase(s.find(x));
        if(s.find(-x)!=s.end()){
            need-=2;
            s.erase(s.find(-x));
        }
    }
    auto is_pal = [&](vi &cur){
        int z = cur.size();
        for(int i=0;i<z;i++){
            if(cur[i] != cur[z-1-i]){
                return false;
            }
        }
        return true;

    };
    if(need<=0 && is_pal(e)){
        cout << "YES\n";
    } else{
        cout << "NO\n";
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