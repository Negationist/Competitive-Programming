#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    int t,x0,y0,xf,yf,time=0;
    cin >> t >> x0 >> y0 >> xf >> yf;
    if(x0==xf&&y0==yf){
        cout << time;
    }
    while(t--){
    time++;
    int d1 = xf-x0;
    int d2 = yf-y0;
        char c;
        cin >> c;
        switch(c){
            case 'W':
                if(d1<0){
                    x0--;
                }
                break;
            case 'E':
                if(d1>0){
                    x0++;
                }
                break;
            case 'S':
                if(d2<0){
                    y0--;
                }
                break;
            case 'N':
                if(d2>0){
                    y0++;
                }
                break;
        }
        if(x0==xf&&y0==yf){
        cout << time;
        return 0;
        }
    }
    cout << -1;

    return 0;
}
