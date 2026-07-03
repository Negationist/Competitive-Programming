#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
      long long score=0;
      char ch;
      for (int i=1;i<11;i++){
        for (int j=1;j<11;j++){
        cin >> ch;
        if (ch == 'X'){
            if (i==1 || i==10 || j==1 || j==10){
                score++;
                continue;
            }
            else if (i==2 || i==9 || j==2 || j==9){
                score+=2;
                continue;
            }
            else if (i==3 || i==8 || j==3 || j==8){
                score+=3;
                continue;
            }
            else if (i==4 || i==7 || j==4 || j==7){
                score+=4;
                continue;
            }
            else if (i==4 || i==5 || j==4 || j==5){
                score+=5;
                continue;
            }
        }

        }
      }
      cout << score << endl;
    }
    return 0;
}
