#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void solve(){
    int n,w;
    cin >> n >> w;
    vi p(n);
    for(int i=1;i<n;i++){
        cin >> p[i];
        p[i]--;
    }
    vi c1(n,-1),c2(n,-1), d(n), len(n,0);
    int num = n;
    d[0] = 0;
    for(int i=1;i<n;i++){
        d[i] = d[p[i]]+1;
    }
    for(int i=0;i<n;i++){
        int x = i, y = (i+1)%n;
        while(x!=y){
            if(d[x]<d[y]) swap(x,y);
            ++len[i];
            (c1[x] == -1 ? c1[x] : c2[x]) = i;
            x = p[x];
        }
    }
    int sum = 0;
    for(int i=0;i<n-1;i++){
        int x,y;
        cin >> x >> y;
        x--;
        sum+=y;
        if(--len[c1[x]]==0) num--;
        if(--len[c2[x]]==0) num--;
        cout << 2*sum + num*(w-sum) << " ";
    }
    cout << "\n";
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
