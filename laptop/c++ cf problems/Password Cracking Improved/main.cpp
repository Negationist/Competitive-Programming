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
    int n,ans;
    cin >> n;
    string s = {};
    cout << "? 0\n";
    cout.flush();
    cin >> ans;
    if(ans==0){
        s.push_back('1');
    } else{
        s.push_back('0');
    }
    if(n==1){
        cout << "! " << s << "\n";
        cout.flush();
        return;
    }
    while(true){
        int ans0,ans1;
        cout << "? " << s << "0" << "\n";
        cout.flush();
        cin >> ans0;
        cout << "? " << s << "1" << "\n";
        cout.flush();
        cin >> ans1;
        if(ans0){
            s.push_back('0');
        } else if(ans1){
            s.push_back('1');
        } else{
            break;
        }
        if(s.size()==n){
            cout << "! " << s << "\n";
            cout.flush();
            return;
        }
    }
    while(true){
        int ans0,ans1;
        cout << "? " << "0" << s << "\n";
        cout.flush();
        cin >> ans0;
        if(ans0){
            s.insert(0,1,'0');
        } else {
            s.insert(0,1,'1');
        }
        if(s.size()==n){
            cout << "! " << s << "\n";
            cout.flush();
            return;
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
