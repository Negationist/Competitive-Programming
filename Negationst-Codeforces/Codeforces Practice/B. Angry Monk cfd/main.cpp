#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n,k,most=0;
        long long ans = 0;
        cin >> n >> k;
        int arr[k];
        FOR(i,k){
            int a;
            cin >> a;
            most = max(most,a);
            int inc = (2*a-1);
            ans+=inc;
        }
        int dec = (2*most-1);
        cout << ans-dec << endl;
    }
    return 0;
}
