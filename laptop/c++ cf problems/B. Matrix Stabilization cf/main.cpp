#include <bits/stdc++.h>
//REDO LATER

using namespace std;

int n,m;

void solve(){
    cin >> n >> m;
    long long ans=0;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[n][m];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int inc = 0;
            if(i>0) inc = max(arr[i][j]-arr[i-1][j],0);
            if(i<n-1) inc = max(arr[i][j]-arr[i+1][j],0);
            if(j<m-1) inc = max(arr[i][j]-arr[i][j+1],0);
            if(j>0) inc = max(arr[i][j]-arr[i][j-1],0);
            ans+=inc;
        }

    cout << ans << endl;
}
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
