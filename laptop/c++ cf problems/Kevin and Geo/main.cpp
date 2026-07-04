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
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    int index = -1;
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]){
            index = i; //always best to take biggest eq, if there are 2 its trivial
        }
    }
    if(index==-1){
        cout << -1 << "\n";
        return;
    }
    int c = a[index];
    a.erase(a.begin()+index);
    a.erase(a.begin()+index-1);
    for(int i=1;i<n-2;i++){
        if(a[i]-a[i-1]<2*c){
            cout << a[i] << " " << a[i-1] << " " << c << " " << c << "\n";
            return;
        }
    }
    cout << -1 << "\n";
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
