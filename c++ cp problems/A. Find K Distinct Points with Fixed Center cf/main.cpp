#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int x,y,k;
        cin >> x >> y >>k;
        if(k%2==0){
        for(int i=1;i<=k/2;i++){
            cout << (x-i) << " " << (y-i) << endl;
            cout << (x+i) << " " << (y+i) << endl;
        }
        } else{
            k--;
            out << x << " " << y << endl;
            for(int i=1;i<=k/2;i++){
            cout << (x-i) << " " << (y-i) << endl;
            cout << (x+i) << " " << (y+i) << endl;
        }
        }
    }
    return 0;
}
