#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int B = 1e9+7;
uniform_int_distribution<int> dist(1,B-1);
int A = dist(rng);

void computehash(string &s, vi &h){
    int n = s.size();
    h[0] = s[0];
    for(int i=1;i<n;i++){
        h[i] = (h[i-1]*A + s[i])%B;
    }
}

void makepower(vi &pow,int n){
    pow[0] = 1;
    for(int i=1;i<n;i++){
        pow[i] = pow[i-1]*A;
        pow[i]%=B;
    }
}

void solve(){
    int n;
    cin >> n;
    int q;
    cin >> q;
    string s;
    cin >> s;
    vi next(n,n+1);
    vector<stack<pii>> stck(2);
    for(int i=0;i<n;i++){
        while(stck[i%2].size() && stck[i%2].top().ff!=s[i]){
            int cur = stck[i%2].top().ss;
            next[cur] = i;
            stck[i%2].pop();
        }
        stck[i%2].push({s[i],i});
    }
    vi a(n);
    vi b(n);
    computehash(s,a);
    reverse(s.begin(),s.end());
    computehash(s,b);
    vi pow(n);
    makepower(pow,n);
    reverse(s.begin(),s.end());
    while(q--){
        int l,r;
        cin >> l >> r;
        int num = r-l+1;
        l--;
        r--;
        if(next[l]>r && next[l+1]>r){
            if(s[l]==s[l+1]){
                cout << 0 << "\n";
            } else{
                num-=(num%2);
                int res = (2+num)*(num)/2/2;
                cout << res << "\n";
            }
            continue;
        }
        int x = a[r];
        if(l>0){
            int res = a[l-1]*pow[r-l+1];
            res%=B;
            x-=res;
            x+=B;
            x%=B;
        }
        int L = n-1-r, R = n-1-l;
        int y = b[R];
        if(L>0){
            int res = b[L-1]*pow[R-L+1];
            res%=B;
            y-=res;
            y+=B;
            y%=B;
        }
        num-=(x==y);
        int res = (2+num)*(num-1)/2;
        cout << res << "\n";
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
