#include <iostream>

using namespace std;

int swap(int a){
    if(a==1){
        return 0;
    } else if (a==0) {
        return 1;
    }
}

int main()
{
    int light[3][3] = {{1,1,1},{1,1,1},{1,1,1}};
    for (int i = 1; i<=9; i++){
        int input;
        cin >> input;
        while (input--){
            switch(i){
                case 1:
                    light[0][0] = swap(light[0][0]);
                    light[0][1] = swap(light[0][1]);
                    light[1][0] = swap(light[1][0]);
                    break;
                case 2:
                    light[0][0] = swap(light[0][0]);
                    light[0][1] = swap(light[0][1]);
                    light[0][2] = swap(light[0][2]);
                    light[1][1] = swap(light[1][1]);
                    break;
                case 3:
                    light[0][1] = swap(light[0][1]);
                    light[0][2] = swap(light[0][2]);
                    light[1][2] = swap(light[1][2]);
                    break;
                case 4:
                    light[0][0] = swap(light[0][0]);
                    light[1][0] = swap(light[1][0]);
                    light[2][0] = swap(light[2][0]);
                    light[1][1] = swap(light[1][1]);
                    break;
                case 5:
                    light[0][1] = swap(light[0][1]);
                    light[1][0] = swap(light[1][0]);
                    light[1][1] = swap(light[1][1]);
                    light[1][2] = swap(light[1][2]);
                    light[2][1] = swap(light[2][1]);
                    break;
                case 6:
                    light[0][2] = swap(light[0][2]);
                    light[1][1] = swap(light[1][1]);
                    light[1][2] = swap(light[1][2]);
                    light[2][2] = swap(light[2][2]);
                    break;
                case 7:
                    light[1][0] = swap(light[1][0]);
                    light[2][0] = swap(light[2][0]);
                    light[2][1] = swap(light[2][1]);
                    break;
                case 8:
                    light[1][1] = swap(light[1][1]);
                    light[2][0] = swap(light[2][0]);
                    light[2][1] = swap(light[2][1]);
                    light[2][2] = swap(light[2][2]);
                    break;
                case 9:
                    light[2][2] = swap(light[2][2]);
                    light[2][1] = swap(light[2][1]);
                    light[1][2] = swap(light[1][2]);
                    break;
            }
        }
    }
    for (int  i=0; i<3; i++){
            for (int j=0; j<3;j++){
                cout << light [i][j];
                if (j==2){
                    cout << endl;
                }
            }
        }
    return 0;
}
