#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n,k,ans=0;
        cin >> n >> k;
        if(k>0){
            k-=n;
            ans++;
        }
        for(int i=2;k>0;i++){
            k-=((n-i/2));
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
