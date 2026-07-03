#include <bits/stdc++.h>

using namespace std;

void solve(){
    bool z = false;
    int n,s,m;
    cin >> n >> s >> m;
    int a1[n];
    int b1[n];
    for (int i=0;i<n;i++){
        cin >> a1[i] >> b1[i];
        if (i==0){
        if(s<=a1[0]){
             z = true;
        }
    }
        if (i==n-1){
        if((m-b1[i])>=s){
            z = true;
        }
    }
    if((a1[i]-b1[i-1])>=s){
        z = true;
    }
    }
    if (z){
        cout << "YES" << endl;
    } else{
        cout << "NO" << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}
