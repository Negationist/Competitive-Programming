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
    int vert=0,horz=0;
    string s;
    cin >> s;
    if(n==2){
        if(s[0]==s[1]) cout << "RH\n";
        else cout << "NO\n";
        return;
    }
    for(int i=0;i<n;i++){
        if(s[i]=='N'){
            vert++;
        } else if(s[i]=='S'){
            vert--;
        } else if(s[i]=='E'){
            horz++;
        } else{
            horz--;
        }
    }
    vert+=200002;
    horz+=200002;
    if(vert%2==1 || horz%2==1){
        cout << "NO\n";
        return;
    }
    vert = 0; horz = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='N'){
            if(vert>0 && i!= 0){
                vert--;
                cout << "H";
            } else{
                vert++;
                cout << "R";
            }
        } else if(s[i]=='S'){
            if(vert>0){
                vert--;
                cout << "R";
            } else{
                vert++;
                cout << "H";
            }
        } else if(s[i]=='E'){
            if(horz>0){
                horz--;
                cout << "H";
            } else{
                horz++;
                cout << "R";
            }
        } else  {
            if(horz>0){
                horz--;
                cout << "R";
            } else{
                horz++;
                cout << "H";
            }
    }
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
