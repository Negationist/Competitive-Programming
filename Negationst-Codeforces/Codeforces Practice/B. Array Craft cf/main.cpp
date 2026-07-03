#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

void solve(){
    int n,x,y;
    cin >> n >> x >> y;
    int a[n];
    for (int i=y-2;i>=0;i--){
        if(i%2==(y-2)%2){
            a[i] = -1;
        } else{
            a[i] = 1;
        }
    }
    for (int i=x-2;i<=n-1;i++){
        if(i%2==(x-2)%2){
            a[i] = -1;
        } else{
            a[i] = 1;
        }
    }
    for(int i=y-1;i<=x-1;i++){
        a[i] = 1;
    }
    for(int x : a){
        cout << x << " ";
    }
    cout << endl;
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
