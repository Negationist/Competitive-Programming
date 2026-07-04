#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,d;
    int a[2] = {}, b[2] = {}, aI=0, bI = 0;
    cin >> c >> d;
    for(int i=c;i<=d;i++){
        string x;
        cin >> x;
        if(x == "Fizz" && aI<2){
            a[aI] = i;
            aI++;
        } else if(x == "Buzz" && bI<2){
            b[bI] = i;
            bI++;
        } else if (x=="FizzBuzz"){
            if(aI < 2){
                a[aI] = i;
                aI++;
            }
            if (bI < 2){
                b[bI] = i;
                bI++;
            }
        }
    }
    if (aI>0){
        cout << abs(a[1]-a[0]) << " ";
    } else{
        cout << d+1 << " ";
    }
    if(bI > 0){
        cout << abs(b[1]-b[0]);
    } else{
        cout << d+2;
    }
    return 0;
}
