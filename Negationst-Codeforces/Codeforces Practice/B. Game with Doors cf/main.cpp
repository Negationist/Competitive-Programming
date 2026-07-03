#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int l,r,L,R;
        cin >> l >> r >> L >> R;
        if (r<L || R<l){
            cout << 1 << endl;
        } else{
           int a = max(l,L);
           int b = min (r,R);
           a = max(min(l,L),a-1);
           b = min(max(R,r),b+1);
           cout << b-a << endl;
        }

    }
    return 0;
}
