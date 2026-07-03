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
    string s;
    cin >> s;
    int n = s.size();
    vi a(n);
    for(int i=0;i<n;i++){
        a[i] = (int)(s[i]-'0');
    }
    for(int i=0;i<n;i++){
        int best = 0;
        for(int j=1;i-j>=0 && a[i]-j>0;j++){
            if(a[i]-j > a[i-j]){
                best = j;
            }
        }
        a[i]-=best;
        best = i-best;
        int p = i;
        while(p!=best){
            swap(a[p],a[p-1]);
            p--;
        }
    }
    for(int x : a){
        cout << x;
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
