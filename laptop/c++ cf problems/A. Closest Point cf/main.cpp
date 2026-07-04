#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    string s;
    while (t--){
        int n,a,b;
        cin >> n;
        if(n>=3){
            while(n--){
                int i;
                cin >> i;
            }
            cout << "NO\n";
            continue;
        }
        for(int i=0; i<n; i++){
            if(i==0) cin >> a;
            else cin >> b;
        }
        if (abs(a-b)<=1){
            cout << "NO\n";
        } else{
            cout << "Yes\n";
        }
    }
    return 0;
}
