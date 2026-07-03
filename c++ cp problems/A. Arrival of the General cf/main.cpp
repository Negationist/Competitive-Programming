#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int q,l=0, s=1000, L, S;
    cin >> q;
    vector<int> n;
    while(q--){
        int e;
        cin >> e;
        n.push_back(e);
    }

    for(int i=n.size()-1; i>=0; i--){
        if (n[i]>=l){
            l = n[i];
            L = i;
        }
    }
    for(int i=0; i<n.size(); i++){
        if (n[i]<=s){
            s = n[i];
            S = i;
        }
    }
    if(S>L){
        int sum = L+(n.size()-S-1);
        cout << sum;
     } else if(S<L){
        int sum = L+(n.size()-S-1)-1;
        cout << sum;
     }
    return 0;
}
