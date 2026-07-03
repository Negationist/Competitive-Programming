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
    int n;
    cin >> n;
    int a = 0, b=0;
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        if(z>0) a++;
        else b++;
    }
    for(int i=1;i<=a;i++){
        cout << i << " ";
    }
    for(int i=1;i<=b;i++){
        cout << a-i << " ";
    }
    cout << "\n";
    for(int i=0;i<b;i++){
        cout << "1 0 ";
    }
    for(int i=1;i<=a-b;i++){
        cout << i << " ";
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
