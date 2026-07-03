#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int line;
    int spaces = abs(2*n-2*line);
    for (int line=0;line<=2*n;line++){
        cout << "spaces = " <<spaces;
        for (int a=0;a<spaces;a++){
        cout << " ";
        }
        if(line<=n){
            for (int a=0; a<4*line+1;a++){
                if (a%2==1){
                cout << " ";
                }
                if(a%2==0){
                cout << -abs((a/2)-line)+line;
                }
            }
        cout << endl;
        }
    }

    return 0;
}
