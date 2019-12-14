#include <bits/stdc++.h>

using namespace std;

int main(){
    string str;
    cin>>str;
    vector <map<int,int>> v1;
    map <int,int> temp;
    int count = 0;
    //cout<<str.size()/(25*6)<<endl;
    for (auto i : str) {
        count++;
        temp[{i-'0'}]++;
        if(count == 25*6){
            v1.push_back(temp);
            temp.clear();
            count=0;
        }
    }
    //cout<<v1.size()<<endl;
    // for (auto i : v1) {
    //     /* code */
    //     for (auto  j: i) {
    //         /* code */
    //         cout<<j.first<<" "<<j.second<<endl;
    //     }
    // }
    auto t = min_element(v1.begin(),v1.end(),
                                            [](map<int,int> &a, map <int,int> &b){
                                                return a[0]<b[0];
                                            });
    for (auto i : *t) {
        /* code */
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}