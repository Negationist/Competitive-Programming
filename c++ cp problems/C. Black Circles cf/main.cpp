#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

void solve(){
    int n;
        cin >> n;
        pair<int,int>* pointArray[n];
        for(int i=0;i<n;i++){
            int a,b;
            cin >> a >> b;
            pointArray[i] = new pair<int,int> (a,b);
        }
        long long x0,y0,xf,yf;
        cin >> x0 >> y0 >> xf >> yf;
        long long distance = (xf-x0)*(xf-x0)+(yf-y0)*(yf-y0);
        for(int i=0;i<n;i++){
            int x = pointArray[i]->first;
            int y = pointArray[i]->second;
            double d = (xf-x)*(xf-x)+(yf-y)*(yf-y);
            if (d <= distance){
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES" << endl;
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
