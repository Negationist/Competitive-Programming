#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i,k,l,m,n,d, cnt = 0;
    cin >> k >> l >> m >> n >> d;

    int z[d] = {0};
    for (i=k; i<=d; i+=k){
        z[i-1] = 1;
    }
    for (i=l; i<=d; i+=l){
        z[i-1] = 1;
    }
    for (i=m; i<=d; i+=m){
        z[i-1] = 1;
    }
    for (i=n; i<=d; i+=n){
        z[i-1] = 1;
    }
    for (auto i : z){
        if (i==1){
            cnt++;
        }
    }
    cout << cnt;
return 0;
}
