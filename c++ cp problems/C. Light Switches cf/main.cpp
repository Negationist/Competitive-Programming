#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int bUMin = INT_MAX,bLMax = 0;
        int n,k,most=0;
        cin >> n >> k;
        int arr[n];
        FOR(i,n){
            cin >> arr[i];
            most = max(most,arr[i]);
        }
        if(n==1){
            cout << arr[0] << endl;
            continue;
        }
        int onLights = 0;
        for(int a=0;a<n;a++){
            int b = (most-arr[a])%(2*k);
            if (b>=k&&b<=2*k-1){
               bUMin = min(bUMin, b);
            }
            else if (b>=0 && b<=k-1){
                onLights++;
                bLMax = max(bLMax,b);
            }
        }
        if (onLights == n){
            cout << most << endl;
            continue;
        } else if((k-bLMax) > (2*k - bUMin)){
            cout << most + (2*k - bUMin) << endl;
        } else{
            cout << -1 << endl;
        }


    }
    return 0;
}
