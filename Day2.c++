// CPP program to take unknown number 
// of integers from user. 
#include <bits/stdc++.h>
using namespace std; 

vector <int> stringToArray (string str){
    vector <int> v;
    int temp =0  ;
    for(auto i = str.begin() ; i<= str.end() ; i++){
        
        if(*i!=','){
         
            temp = temp*10 + (*i - '0');
            
        }
        else{
            
            v.push_back(temp);
            temp = 0;
            
        }
    }
    return v;
}
int proccess (vector<int> &v){
    auto begin = v.begin();
    for(auto i =v.begin() ; i <v.end() ; i+=4){
        if(*i==1){
            *(begin+*(i+3))=*(begin+*(i+1))+ *(begin+*(i+2));
        }
        else if(*i==2){
            *(begin+*(i+3))=*(begin+*(i+1))* *(begin+*(i+2)); 
        }
        else if(*i==99){
            break;
        }
    }
    return 0;
    
}

int main() 
{ 
    string str ;
    
    cin>>str;
    str.append(",");
    vector <int> array = stringToArray(str);
    vector <int> arr = array;
    for(int i =0 ; i<100 ; i++){
        for(int j = 0 ; j<100 ; j++){
        
            arr= array;
            *(arr.begin()+1) = i ;
            *(arr.begin()+2) = j ;
            proccess(arr);
            if(arr.at(0)==19690720){
                cout<<i<< " " <<j;
            }
        }
    }
        

    
    
    
    
} 
