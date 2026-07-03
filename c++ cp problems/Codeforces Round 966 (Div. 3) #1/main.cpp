#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        string x;
        cin >> x;
        if (x[0]=='1' && x[1]=='0'){
            x.erase(0,2);
        } else{
            cout << "NO" << endl;
            return 0;
        }
        int n = stoi(x);
        if(n>=2){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
