#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        ll n,mn,sum = 0;
        cin >> n;
        for(int i=0;i<n;i++){
            int a;
            cin >> a;
            sum+=a;
            mn = min(mn,sum);
        }
        cout << sum -2*mn << endl;
    }
    return 0;
}
