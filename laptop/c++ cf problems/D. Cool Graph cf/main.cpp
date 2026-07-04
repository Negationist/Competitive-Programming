#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
const int big = 5e5;

vi sieve(big,0);

void sieveFill(){
    for(int i=2;i<=sqrt(big);i++){
        for(int j=i*i;j<=big;j+=i){
            sieve[j] = 1;
        }
    }
}

void solve(){
    int n;
    cin >> n;
    vi a(n);
    int cnt = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(!sieve[a[i]]) cnt++;
    }
    if(cnt>1){
        cout << -1 << "\n";
        return;
    } else if(cnt==0){
        cout << 2 << "\n";
        return;
    }
    sort(begin(a),end(a));
    if(!sieve[a[0]]){
        bool flag = true;
        for(int i=1;i<n;i++){
            if(a[i]%2==0 && a[i]>=a[0]*2) continue;
            for(int j=3;j*j<=a[i];j++){
                if(a[i]%j==0){
                    a[i]-=j;
                    break;
                }
                if(a[i]-j<2*a[0]){
                    flag = false;
                    break;
                }
            }
            if(a[i]<2*a[0]){
                flag = false;
            }
        }
        if(flag){
            cout << a[0] << "\n";
        } else cout << -1 << "\n";
    } else{
        cout << -1 << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    sieveFill();
    while(t--){
        solve();
    }
    return 0;
}
