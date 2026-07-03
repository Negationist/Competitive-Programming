#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void rage(){
    cout << "! IMPOSSIBLE\n";
    cout.flush();
}

int ask(int a, int b){
    cout << "? " << a << " " << b << "\n";
    cout.flush();
    int z;
    cin >> z;
    return z;
}

void solve(){
    int n;
    cin >> n;
    string ans;
    int j = 2;
    int cnt;
    while(true){
        cnt = ask(1,j);
        if(!cnt && j==n){
            rage();
            return;
        }
        if(cnt){
          int a = j-1-cnt; //ones
          int b = cnt; //zeros
          j++;
          for(int i=0;i<a;i++) ans.pb('1');
          for(int i=0;i<b;i++) ans.pb('0');
          ans.pb('1');
          break;
        }
        j++;
    }
    while(j<=n){
        int num = ask(1,j);
        if(num>cnt){
            ans.pb('1');
            cnt = num;
        } else{
            ans.pb('0');
        }
        j++;
    }
    cout << "! " << ans << "\n";
    cout.flush();
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
