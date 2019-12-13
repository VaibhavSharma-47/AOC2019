#include <bits/stdc++.h>

using namespace std;

class Body {
    public:
    Body* p ;
    Body(Body &parent);
};
Body::Body(Body &parent){
    p=&parent;
}
int inputToMap(map <string,string> &input,string str){
    //cout<<"here";
    vector <string> temp ;
    string t ;
    for (auto i : str) {
        if(i!=')'){
            t.append(1,i);
            
        }
        else{
            temp.push_back(t);
            t.clear();
            
        }
    }
    //cout<<"Child "<<temp[1]<<"parent "<<temp[0];
    input [{temp[1]}] = temp[0];
    return 1;
}

int main(){
    map <string,string> input;
    string str;
    while(cin>>str){
        str.append(")");
        //cout<<str<<endl;
        inputToMap(input,str);
    }
    int count =0 ;
    string s;
    cout<<input.size()<<endl;
    //cout<<input["A"].compare("")<<endl;
    for (auto i : input) {

            //cout<<i.first<<" "<<i.second<<endl;
            s = i.second;
            if(s.compare("")==0){
                continue;
            }
            count++;
            //cout<<"Here input[s] is -"<<input[s]<<endl;
            while(input[s].compare("")!=0){
                count++;
                s = input[s];
              // cout<<s<<endl;
            }
            //cout<<count<<endl;

    }
    cout<<count;
}