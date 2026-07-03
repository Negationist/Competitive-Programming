#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    int n,m,c2=0,c3=INT_MAX,c4=INT_MAX,ans=-1;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int a; cin >> a;
        c2 = max(c2,a);
        c3 = min(c3,a);
    }
    c3*=2;
    for (int i=0;i<m;i++){
        int a; cin >> a;
        c4 = min(c4,a);
    }
    c4--;
    for (int i=c4;i>=c2 && i>=c3;i--){
        ans = i;
    }

    cout << ans;
    return 0;
}
