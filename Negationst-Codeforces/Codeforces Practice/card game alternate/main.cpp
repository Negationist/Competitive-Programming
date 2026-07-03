#include <bits/stdc++.h>

using namespace std;

void solve(){
    int ways = 0;
    int e[4];
    int sunWins = 0
    int slavWins = 0;
    for (int i=0;i<4;i++){
        cin >> e[i];
    }
    if(e[0]>e[2] && e[1]>e[3]){
        sunWins++;
    }
    cout << ways <<endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
