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
vector <string> tracePath(map <string,string> input, string key){
    vector <string> v ;
    string s = key;
    v.push_back(s);
    if(s.compare("")==0){
        return v;
    }
    
            //cout<<"Here input[s] is -"<<input[s]<<endl;
    while(input[s].compare("")!=0){
        s = input[s];
        v.push_back(s);
      // cout<<s<<endl;
    }
    return v;
    
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
    vector <string> v1 = tracePath(input,"YOU");
    vector <string> v2 = tracePath(input,"SAN");
    
    // for (auto i : v1) {
    //     cout<<i<<endl;
    // }
    // for (auto i : v2) {
    //     cout<<i<<endl;
    // }
    int c =0 ;
    auto a = v1.end();
    auto b = v2.end();
    a--;
    b--;
    //cout<<*a<<" "<<*b<<endl;
    while(*(a)==*(b)){
        c++;
        a--;
        b--;
    }
    //cout<<c<<endl;
    cout<<(v1.size()+v2.size()-2-2*c);
    
}