#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a[500000];

int main(){
    map <int,int> m;

    a[0] = 0;
    m[a[0]] = 1;

    for(int i=1;i<500000;i++){
        ll temp = a[i-1]-i;
        if(temp>0){
            if(m.find(temp)!=m.end()){
                a[i] = a[i-1] + i;
                m[a[i]] = 1;
            }
            else
            {
                a[i] = temp;     
                m[a[i]] = 1; 
            }
        }
        else{
            a[i] = a[i-1] + i;     
            m[a[i]] = 1;
        }
    }
    
    //for(int i=0;i<12;i++)cout<<a[i]<<endl;
    while(1){
        int k;
        cin>>k;
        if(k==-1)
            break;
       cout<<a[k]<<endl;

    }
    return 0;
}