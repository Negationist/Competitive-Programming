#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n],b[n];
        b[0] = 0;
        for(int i=0;i<n;i++){
            cin >> a[i];
            if(i==0) continue;
            b[i] = max(a[i-1]+b[i-1]-a[i],0);
        }
        if(n==1){
            cout << 0 << endl;
            continue;
        }
        sort(b,b+n);
        int diff[n-1];
        for(int i=0;i<n-1;i++){
            diff[i] = b[i+1]-b[i];
        }
        long long ans = 0;
        for(int i=0;i<n-1;i++){
            long long current = (long long)diff[i] * (n-i);
            ans+=current;
        }
        cout << ans << "\n";
    }
    return 0;
}
