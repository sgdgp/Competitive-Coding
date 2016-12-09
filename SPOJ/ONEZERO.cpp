#include <bits/stdc++.h>
#define ll long long
#define FILL(a,x) memset(a,x,sizeof(a))
using namespace std;


int parent[200005];
int value[200005];

queue <int> q;
int main(){
    int k;
    int cS;
    int temp;
    cin>>k;
    while(k--){
        int n;
        cin>>n;

        FILL(parent,-1);
        while(!q.empty())
            q.pop();


       q.push(1);
       parent[1] = 0;
       while(!q.empty()){
           cS = q.front();
           q.pop();
           if(cS == 0){
               stack<int> s;
               while(parent[cS]){
                   s.push(value[cS]);
                   cS=parent[cS];
               }
                s.push(1);
                while(!s.empty()){
                    printf("%d",s.top());
                    s.pop();
                }
                cout<<endl;
                break;
           }
           else{
                temp=(cS*10)%n;
                if(parent[temp]==-1){
                    q.push(temp);
                    parent[temp]=cS;
                    value[temp]=0;
                }
                temp=((cS*10)+1)%n;
                if(parent[temp]==-1){
                    q.push(temp);
                    parent[temp]=cS;
                    value[temp]=1;
                }
           }
       }     

    }
    return 0;
}