#include<bits/stdc++.h>

using namespace std;

class Directions { 
private: 
    
public: 
    int value;
    char direction;
    Directions(int v = 0, char d =0)  {value = v;   direction = d;} 
}; 
int stringtovector(string str, vector <Directions> &v1){
    
    int max =0 ;
    int temp =0 ;
    char dir = 0;
    for(auto i = str.begin();i<str.end();i++){
        if(*i!=','){
            if(*i-'0'>=0&&*i-'0'<=9){
                temp=temp*10+(*i-'0');
                
                
            }
            else{
                dir=*i;
            }
        }
        else{
            //cout<<"value "<< temp <<endl;
            v1.push_back(Directions(temp,dir));
            max = (temp>max)? temp :max ;
            temp=0;
        }
    }
    
    return max;
    
}
int fill(int * prev, Directions d,map <pair<int,int>,int> &m,int a,vector <pair<int,int>> &pointofcontact){
        int dis = INT_MAX ;
        int temp =0 ;
        
        for(int i = 1 ; i <= d.value ; i++){
            switch (d.direction)
            {
            case 'R':
              prev[0]+=1;
              
              break;
            case 'L':
              prev[0]-=1;
              break;
            case 'U':
              prev[1]+=1;
              break;
            case 'D':
              prev[1]-=1;
            }
            if(m[{prev[0],prev[1]}]!=0&&m[{prev[0],prev[1]}]!=a){
                temp = abs(prev[0])+abs(prev[1]);

                pointofcontact.push_back(make_pair(prev[0],prev[1]));
                //cout<<temp<<" at "<<prev[0]<<" "<<prev[1]<<endl;
                dis = min(temp,dis);
            }
            else{

                m[{prev[0],prev[1]}]=a;
                
            }
        }

    return dis;
}


int matrixfiller(map <pair<int,int>,int> &m,vector <Directions> &v,int a,vector <pair<int,int>>& pointofcontact){
    int pre[2] ={0,0};
    int dis= INT_MAX;
    for (auto i=v.begin() ;i<v.end();i++) {
      //cout<<(*i).value<<" "<<(*i).direction<<endl;
      
      int temp =fill(pre,*i,m,a,pointofcontact);
      dis = min(dis,temp);
    }
    return dis;
}

int disTrail(vector <Directions> &v,int x , int y){
    int dis =0 ;
    int prev[2] = {0};
    for (auto i : v) {
       // cout<<(i).value<<" "<<(i).direction<<endl;
       // cout<<prev[0]<<" "<<prev[1]<<endl;
        for (int a = 1; a <= i.value ; a++) {
            switch (i.direction)
            {
            case 'R':
              prev[0]+=1;
              break;
            case 'L':
              prev[0]-=1;
              break;
            case 'U':
              prev[1]+=1;
              break;
            case 'D':
              prev[1]-=1;
            }
            dis +=1;
            if(x==prev[0]&&y==prev[1]){
                
                return dis;
            }
        
            
        }
    }
}


int main(){
    vector <pair<int,int>> pointofcontact;
    string str1,str2;
    cin>>str1>>str2;
    str1.append(",");
    str2.append(",");
    vector <Directions> v1;
    vector <Directions> v2;
    
    int ma = max (stringtovector(str1,v1),stringtovector(str2,v2));
    map <pair<int,int>,int> m;
    m[{0,0}]=1;
    
    matrixfiller(m,v1,1,pointofcontact);
    matrixfiller(m,v2,2,pointofcontact);
    vector <int>finalcosts;
    for (auto i : pointofcontact) {
        int temp =0;
        temp = disTrail(v1,i.first,i.second);
        temp+=disTrail(v2,i.first,i.second);
        finalcosts.push_back(temp);
    }
    
    cout<<*min_element(finalcosts.begin(),finalcosts.end());
    
    
    // for(auto elem : m)
    // {
    //     std::cout << elem.first.first << " " << elem.first.second << " " << elem.second << "\n";
    // }

}