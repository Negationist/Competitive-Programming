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
    multiset<int> a;
    stack<int> b;
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        a.insert(z);
    }
    for(int i=0;i<m;i++){
        int z;
        cin >> z;
        b.push(z);
    }
    while(b.size()){
        if(a.count(b.top())){
            a.erase(a.find(b.top()));
            b.pop();
        } else{
            int temp = b.top();
            if(temp==1){
                cout << "NO\n";
                return;
            }
            b.pop();
            b.push(temp/2);
            b.push(temp/2+(temp&1));
        }
    }
    if(!a.size()){
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
