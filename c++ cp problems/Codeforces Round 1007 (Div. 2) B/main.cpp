#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
using ll = long long;
using ld = long double;
void solve(){
    int n;
    cin >> n;
    int tot = (n)*(n+1)/2;
    int num = sqrt(tot);
    if(num*num==tot){
        cout << -1 << "\n";
    } else{
        int sum = 2;
        cout << 2 << " ";
        for(int i=1;i<=n;i+=2){
            cout << i << " ";
            sum+=i;
        }
        for(int i=4;i<=n;i+=2){
            int temp = sum+i;
            int num = sqrt(temp);
            if(num*num==temp){
                cout << i+2 << "  " << i << "\n";
                i+=2;
                sum = temp+i;
            } else{
                cout << i << " ";
                sum = temp;
            }
        }
        cout << "\n";
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
