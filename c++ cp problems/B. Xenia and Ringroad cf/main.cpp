#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,pos=1;
    long long time;
    cin >> n >> m;
    for (int i=0; i<m;i++){
        int a;
        cin >> a;
        if (a-pos<0){
            time+=(n+a-pos);
        }
        else {
            time+=a-pos;
        }
        pos = a;
    }
    cout << time;
    return 0;
}
