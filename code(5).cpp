// CPP program to take unknown number 
// of integers from user. 
#include <bits/stdc++.h>
using namespace std; 

vector <int> stringToArray (string str){
    vector <int> v;
    int temp =0  ;
    auto j =- 1;
    for(auto i = 0 ; i<= str.size() ; i++){
        
        if(str[i]!=','){
            
        }
        else{
            temp = stoi(str.substr(++j,i));
            v.push_back(temp);
            j = i ;
            
        }
    }
    return v;
}

int immode(vector<int> &v,auto i){
    return *(i);
}

int postion(vector<int> &v,auto i){
    return *(v.begin()+*(i));
}

int fillcode(int *a,int number){
    for (int i = 4; i >= 0; i--) {
        a[i] = number%10;
        number=number/10;
    }
    return 1;
}

int add(vector<int> &v,auto i,int *code){
    auto begin = v.begin();

    switch (code[2]){
        case 0 :
        //postion mode
        switch(code[1]){
            case 0 :
            *(begin+*(i+3)) = postion(v,i+1)+ postion(v,i+2);
            break;
            case 1:
            *(begin+*(i+3)) =postion(v,i+1)+ immode(v,i+3);
           // cout<<"here";
            break;
        }
        break;   
        case 1:
        //immode
        switch(code[1]){
            case 0 :
            *(begin+*(i+3)) = immode(v,i+1)+ postion(v,i+2);
            break;
            case 1:
            *(begin+*(i+3)) =immode(v,i+1)+ immode(v,i+3);
            
            break;
        }
        break;
    }
    cout<<"Value written -"<<*(begin+*(i+3))<<endl;
    return 1;
    
}
int multiply(vector<int> &v,auto i,int *code){
    auto begin = v.begin();
    switch (code[2]){
        case 0 :
        
        //postion mode
        switch(code[1]){
            case 0 :
            *(begin+*(i+3)) = postion(v,i+1)* postion(v,i+2);
            break;
            case 1:
            *(begin+*(i+3)) =postion(v,i+1)* immode(v,i+2);
        
            break;
        }
        break;   
        case 1:
        //immode
        switch(code[1]){
            case 0 :
            *(begin+*(i+3)) = immode(v,i+1)* postion(v,i+2);
            break;
            case 1:
            *(begin+*(i+3)) =immode(v,i+1)* (immode(v,i+2));
            
            break;
        }
        break;
    }
    cout<<"Value written -"<<*(begin+*(i+3))<<endl;
    return 1;
}

int main() 
{ 
    string str ;
    
    cin>>str;
    str.append(",");
    vector <int> array = stringToArray(str);
   // vector <int> arr = array;
    //array[225]=1;
    //cout<<*array.end()<<endl;
    for (auto i = array.begin() ; i < array.end() ; ) {
        int code[5] = {0};
        fillcode(code,*i);
        
        cout<<"OP code - ";
        for (int i = 0; i < 5; i++) {
            cout<<code[i];
        }
        cout<<endl;
        //cout<<"code 1"<<code[1]<<" ";
        //cout<<code[5];
        if(code[3]!=0 ){
            break;
        }
        switch (code[4]){
        case 1 :
            //aadd

            add(array,i,code);
            
            i+=4;
            break;
        case 2 :
            
            //multiply
            multiply(array,i,code);
            i+=4;
            break;
        
        case 3 :
            //input
            array[*(i+1)]= 1 ;
            i+=2;
            break;
        case 4 :
            
            cout<<array[*i]<<endl;
            i+=2;
            
            //output
            break;
        default :
            i=array.end()+1;
            break;
        
        }
    //cout<<*(array.begin())<<endl;
        
    
        
    }
    //cout<<array.size()<<endl;

    // for (auto i : array) {
    //     cout<<i<<endl;
    // }

    
    
    
    
} 