#include <bits/stdc++.h>

using namespace std;

void solve(){
    int ways = 0;
    int sun[2];
    int slav[2];
    for(int i=0; i<2;i++){
        cin >> sun[i];
    }
    for(int i=0; i<2;i++){
        cin >> slav[i];
    }
    for (int i=0; i<=1;i++){
        for(int j=0; j<=1;j++){
            int sun1 = sun[i];
            int sun2 = sun[1-i];
            int slav1 = slav[1-j];
            int slav2 = slav[j];
            int sunW = 0;
            int slavW = 0;
            if (sun1>slav1){
                sunW++;
            } else if(sun1<slav1){
                slavW++;
            }
            if (sun2>slav2){
                sunW++;
            } else if(sun2<slav2){
                slavW++;
            }
            if (sunW>slavW){
                ways++;
            }
        }
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
