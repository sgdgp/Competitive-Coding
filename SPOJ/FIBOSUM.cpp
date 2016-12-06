// Finding the fibonacci number in O(log n) time
// no other method applicable here as n can be as large as 10^9

// use matrix multipplication


#include <bits/stdc++.h>
#define ll long long
const ll MOD = 1e9 + 7;

using namespace std;

void mult(ll ans[2][2],ll M[2][2]){
    ll L[2][2];
    int i,j,k;
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            L[i][j]=0;
            for(k=0;k<2;k++){
                L[i][j] =(L[i][j] + (ans[i][k]) * (M[k][j])%MOD)%MOD;
            }
        }
    }
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
            ans[i][j] = L[i][j];
}

ll fib(int n){
    int temp = 1;
    int i,j,k;
    ll ans[2][2] = {{1,0} , {0,1}};
    ll M[2][2] = {{0,1} , {1,1}};
    while(n > 0){
        if(n & temp){
            n -= temp;
            mult(ans,M);
        }
        temp <<= 1;
        mult(M,M);
    }
    return ans[0][1] % MOD;
}

ll sum(ll n){
    return fib(n+2) - 1;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        ll ans = ((( sum(m) - sum(n-1) )%MOD)+MOD)%MOD;
        cout<<ans<<endl;
    }
    return 0;
}
