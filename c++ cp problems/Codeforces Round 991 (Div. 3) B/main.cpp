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
    int sum1 = 0;
    int sum2 = 0;
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        if(i%2==0){
            sum1+=z;
        } else{
            sum2+=z;
        }
    }
    int num1 = n/2;
    if(n%2==1) num1++;
    int num2 = n/2;
    if(sum1%num1!=0 || sum2%num2!=0){
        cout << "no\n";
        return;
    }
    if((sum1/num1)!=(sum2/num2)){
        cout << "no\n";
    } else{
        cout << "yes\n";
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
