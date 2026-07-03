#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    int t,minn=INT_MAX,minTown,entry=0;
    bool singular;
    cin >> t;
    while(t--){
        entry++;
        int a;
        cin >> a;
        if(a < minn){
           minTown = entry;
           singular = true;
           minn = min(minn,a);
        } else if(a==minn){
            singular = false;
        }
    }
    if (singular){
        cout << minTown;
    } else{
        cout << "Still Rozdil";
    }
    return 0;
}
