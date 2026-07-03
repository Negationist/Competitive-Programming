#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
    int n,x,ans=0;
    cin >> n >> x;
    for (int a=1;a<=x-2;a++){
        for (int b=1;a*b<=n && a+b<=x;b++){
           int highestC = min(((n-a*b)/(a+b)),x-a-b);
           if (highestC>0){
            ans += highestC;
           }
        }
    }
        cout << ans << endl;
    }

    return 0;
}
