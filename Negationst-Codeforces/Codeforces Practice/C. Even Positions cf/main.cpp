#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n,cost=0;
        cin >> n;
        char arr[n];
        int pref = 0;
        for(int i=0;i<n;i++){
            char a;
            cin >> a;
            if(a=='('){
                pref++;
                cost-=i;
            } else if (a==')'){
                pref--;
                cost+=i;
            } else{
                if(pref>0){
                    pref--;
                    cost+=i;
                 } else{
                    pref++;
                    cost-=i;
                 }
            }
        }
        cout << cost << endl;
        }
        return 0;
    }

