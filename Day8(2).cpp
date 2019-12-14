#include <bits/stdc++.h>

using namespace std;

int layerprocess(string str,auto a,int matrix[][25]){
    auto temp = str.begin();
    temp = a;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 25; j++) {
            /* code */
            //cout<<*a;
            switch (*temp) {
                case '0':
                    if(matrix [i][j]== 2){
                        matrix [i][j] = 0;
                    }
                    break;
                case '1':
                    if(matrix [i][j]== 2){
                        matrix [i][j] = 1;
                    }
                    break;
                case '2':
                
                    break;
                default:
                    ;
            }
            temp++;
        }
    }
}
int printm(int m[][25]){
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 25; j++) {
            /* code */
            cout<<m[i][j];
        }
        cout<<endl;

    }
}

int main(){
    string str;
    cin>>str;
    //vector <int [6][25]> v1;
    int matrix [6][25]  ={2};
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 25; j++) {
            /* code */
            matrix [i][j]=2;
        }

    }
    printm(matrix);
    
    //int count = 0;
    //cout<<str.size()/(25*6)<<endl;
    for (auto i = str.begin(); i < str.end(); i+=25*6) {
        cout<<*i<<endl;
        layerprocess(str,i,matrix);
        
    }
    
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 25; j++) {
            /* code */
            cout<<matrix[i][j];
        }
        cout<<endl;
    }
    return 0;
}