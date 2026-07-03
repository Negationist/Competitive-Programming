#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int row;
    int col;
   for (int i=0; i<5; i++){
    for (int j=0; j<5; j++){
        int a;
        cin >> a;
        if (a==1){
            row = i+1;
            col = j+1;
        }
    }
   }
    row = abs(row-3);
    col = abs(col-3);
    cout << row + col;
    return 0;
}
