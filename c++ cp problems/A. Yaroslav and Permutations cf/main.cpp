#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

map<int,int>m;

int main()
{
    int t, most=0;
    cin >> t;
    for (int i=0;i<t;i++){
        int a;
        cin >> a;
        m[a]++;
    }
    for(auto it = m.begin(); it!=m.end();it++){
        most = max(most,it->second);
    }
    if (most > (t+1)/2){
        cout << "NO";
    } else{
        cout << "YES";
    }

    return 0;
}
