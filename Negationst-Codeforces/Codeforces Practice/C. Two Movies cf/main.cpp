#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n],b[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        for (int i=0;i<n;i++){
            cin >> b[i];
        }
        int aSum = 0, bSum = 0, u=0, d=0;
        FOR(i,n){
            if (a[i]!=b[i]){
                if (a[i]>b[i]){
                    aSum+=a[i];
                } else{
                    bSum+=b[i];
                }
            }
            else if(a[i]==1 && b[i]==1){
                u++;
            } else if(a[i]!=0){
                d++;
            }
        }
        while(u>0){
            if (aSum<=bSum){
                aSum++;
            } else{
                bSum++;
            }
            u--;
        }
        while(d>0){
            if (aSum >= bSum){
                aSum--;
            } else{
                bSum--;
            }
            d--;
        }
        cout << min(aSum,bSum) << endl;
    }
    return 0;
}
