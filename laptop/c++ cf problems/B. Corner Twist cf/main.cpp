#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,m;
    cin >> n >> m;
    string a[n],b[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
    }
    for(int i=0;i<n;i++){
        int sum1 = 0;
        int sum2 = 0;
        for(int j=0;j<m;j++){
           sum1+=(a[i][j]-'0');
           sum2+=(b[i][j]-'0');
        }
        sum1%=3;
        sum2%=3;
        if(sum1 != sum2){
            cout << "NO\n";
            return;
        }
    }
    for(int i=0;i<m;i++){
        int sum1 = 0;
        int sum2 = 0;
        for(int j=0;j<n;j++){
           sum1+=(a[j][i]-'0');
           sum2+=(b[j][i]-'0');
        }
        sum1%=3;
        sum2%=3;
        if(sum1 != sum2){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
