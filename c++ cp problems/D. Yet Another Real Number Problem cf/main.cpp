#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
const int MOD = 1e9+7;

void solve(){
    int n;
    cin >> n;
    vi a(n);
    vi inc(n+1);
    inc[0] = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        inc[i+1] = inc[i];
        while(a[i]%2==0){
            a[i]/=2;
            inc[i+1]++;
        }
    }
    vi pref(n+1);
    pref[0] = 0;
    for(int i=0;i<n;i++){
        pref[i+1] = pref[i]+a[i];
    }
    vi ans;
    int bigM=0;
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=a[i]*(pref[i+1]-pref[i]);
        bigM+=(sum/MOD);
        sum%=MOD;
        if(i==0){
            ans.pb(sum);
            continue;
        }
        int newSum = pref[i];
        int newM = newSum/MOD;
        newSum%=MOD;
        int add = a[i];
        int num = inc[i+1];
        while(num>20){
            num-=20;
            add*=(1LL<<20);
            newM+=add/MOD;
            add%=MOD;
        }
        add*=(1LL<<num);
        newM+=add/MOD;
        add%=MOD;
        newSum+=add;
        newM+=newSum/MOD;
        newSum%=MOD;
        if(bigM > newM){
            ans.pb(sum);
        } else if(newM > bigM){
            ans.pb(newSum);
            bigM = newM;
        } else{
            if(newSum>=sum){
                ans.pb(newSum);
            } else{
                ans.pb(sum);
            }
        }
    }
    for(int x : ans){
        cout << x << " ";
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
