#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        long double x,y,z,k;
        long long ans=0;
        cin >> x >> y >> z >> k;
        int a = x;
        while(a){
            if(fmod(k,a) != 0){
                a--;
                continue;
            }
            long double product = k/a;
            int b = y;
            while(b){
                if(fmod(product,b)!=0){
                    b--;
                    continue;
                }
                long long curZ = product/b;
                if (curZ<=z){
                long long result = (x-a+1)*(y-b+1)*(z-curZ+1);
                ans = max(result,ans);
                }
                b--;
            }
            a--;
        }
        cout << ans << endl;
    }
    return 0;
}
