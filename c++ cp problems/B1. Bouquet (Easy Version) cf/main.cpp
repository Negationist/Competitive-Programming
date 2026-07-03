#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

// three pointers

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        long long m, ans =0;
        cin >> n >> m;
        int a[n];
        FOR(i,n){
            cin >> a[i];
        }
        sort(a,a+n);
        for(int i=0;i<n;){
            int j = i;
            while(a[j]==a[i]) j++;
            int l = j;
            while(a[l]==a[i]+1) l++;
            for(int c=0;c<=j-i;c++){
                if (c*a[i]>m) continue;
                long long val = c*a[i];
                long long z = min((long long)(l-j),(m-val)/(a[i]+1));
                val+=z*(a[i]+1);
                ans = max(ans,val);
            }
            i = j;
        }
        cout << ans << endl;
    }
    return 0;
}
