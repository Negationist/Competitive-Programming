#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
//thanks jiangly, ill be red soon
using namespace std;

void solve(){
    int n;
    cin >> n;
    vi l(n),r(n),L(n,-1),R(n,-1);
    for(int i=0;i<n;i++){
        cin >> l[i] >> r[i];
    }
    vi p(n);
    iota(p.begin(),p.end(),0);
    sort(p.begin(),p.end(),
         [&](int i, int j){
                if(l[i]!=l[j]){
                    return l[i]<l[j];
                }
                return r[i]>r[j];
            }
         );
    set<int> cur;
    for(int j=0;j<n;j++){
        int i = p[j];
        auto it = cur.lower_bound(r[i]);
        if(it!=cur.end()){
            R[i] = *it;
        }
        cur.insert(r[i]);
        if(j+1<n && l[i] == l[p[j+1]] && r[i] == r[p[j+1]]){
            R[i] = r[i];
        }
    }
    sort(p.begin(),p.end(),
         [&](int i, int j){
                if(r[i]!=r[j]){
                    return r[i]>r[j];
                }
                return l[i]<l[j];
            }
         );
         cur.clear();
    for(int j=0;j<n;j++){
        int i = p[j];
        auto it = cur.upper_bound(l[i]);
        if(it!=cur.begin()){
            it--;
            L[i] = *it;
        }
        cur.insert(l[i]);
        if(j+1<n && l[i] == l[p[j+1]] && r[i] == r[p[j+1]]){
            L[i] = l[i];
        }
    }
    for(int i=0;i<n;i++){
        if(L[i]==-1){
            cout << 0 << "\n";
        } else{
            cout << R[i]-L[i]+l[i]-r[i] << "\n";
        }
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
