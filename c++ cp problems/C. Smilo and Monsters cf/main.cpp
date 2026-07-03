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
    int n,ans=0;
    cin >> n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    if(n==1){
        if(a[0]==1){
            cout << "1\n";
        } else{
        cout << (a[0]+1)/2+1<< "\n";
        }
        return;
    }
    sort(a.begin(),a.end());
    vi pref(n);
    pref[0] = a[0];
    for(int i=1;i<n;i++){
        pref[i] = a[i]+pref[i-1];
    }
    int i1 = 0;
    int i2 = n-1;
    int gone = 0;
    while(true){
        if(i1 == i2){
            i1--;
            int sum = pref[i1]-gone+a[i2];
            ans+=(sum+1)/2;
            ans++;
            ans-=(sum==1);
            break;
        }
        if(pref[i1]-gone < a[i2]){
            i1++;
        } else{
            ans+=(a[i2]+1);
            gone+=(a[i2]);
            i2--;
            if(i1==i2){
                ans+=((pref[i1]-gone)+1)/2;
                ans++;
                ans-=(pref[i1]-gone==1);
                ans-=(pref[i1]-gone==0);
                break;
            }
        }
    }
    cout << ans << "\n";
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
