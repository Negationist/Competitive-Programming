#include <bits/stdc++.h>
#define ll long long
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
    int n,m,k;
    cin >> n >> m >>k;
    ll sum = 0;
    vi a(n),b(m);
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum+=a[i];
    }
    for(int i=0;i<m;i++){
        cin >> b[i];
    }
    vector<vi> ops(m+1,vi()); //operations and cost
    int sze = 1LL<<m;
    vi mask(sze);
    mask[0] = ~0;
    for(int i=1;i<sze;i++){
        int msb = 31-__builtin_clz(i);
        mask[i] = mask[i-(1LL<<msb)]&b[msb];
        ops[__builtin_popcount(i)].pb(mask[i]);
    }
    /*for(int i=0;i<=m;i++){
        cout << "ops for " << i << "are ";
        for(int x : ops[i]){
            cout << x <<  " ";
        }
        cout << "\n";
    }*/
    priority_queue<int> q;
    for(int i=0;i<n;i++){
        vi temp(m+1);
        temp[0] = a[i];
        for(int j=1;j<=m;j++){
            int mn = INT_MAX;
            for(auto x : ops[j]){
                mn = min(mn,x&a[i]);
            }
            temp[j] = mn;
        }
        for(int i=1;i<=m;i++){
            q.push(temp[i-1]-temp[i]);
        }
        cout << "for " << a[i] << ". temp is ";
        for(int x : temp){
            cout << x << " ";
        }
        cout << "\n";
    }
    int inc = 0;
    while(inc<k && q.size()){
        sum-=q.top();
        q.pop();
        ++inc;
    }
    cout << sum << "\n";
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
