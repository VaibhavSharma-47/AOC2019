#include<bits/stdc++.h>

using namespace std;

int stringtoint(vector <int> &bound, string str){
    int temp = 0;
    for (auto i : str) {
        if(i!='-'){
            temp=temp*10 +(i-'0');
            //cout<<temp<<endl;
        }else{
            
            bound.push_back(temp);
            temp = 0;
        }
    }
}

int adj_same(string number){
    char prev = number[0];
    for (int i = 1; i <number.size(); i++) {
        if(number[i]==prev){
            return 1;
        }
        prev=number[i];
    }
    return 0;
}
int always_increasing(string number){
    int prev = number[0];
    for (int i = 1; i <number.size(); i++) {
        if(number[i]>=prev){
            prev=number[i];
        }
        else{
            return 0 ;
        }
    }
    return 1;
    
}

int check(string number){
    if(number.size()==6&&adj_same(number)&&always_increasing(number)){
        return 1;
    }else{
        return 0;
    }
    
}
int main(){
    string str;
    cin>>str;
    str.append("-");
    vector <int> bound;
    stringtoint(bound,str);
    for (auto i : bound) {
        std::cout << i << std::endl;
    }
    int count=0;
    //cout<<adj_same("123789");
    for (int i = bound[0]; i <= bound[1]; i++) {
        if(check(to_string(i))){
            count++;
        };
    }
    cout<<count;
    
}