#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector <int> b,c;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                int temp1 = (a[i]*a[j])+a[k];
                int temp2 = (a[i]+a[j])*a[k];
                b.push_back(temp1);

                if(a[k]!=0)
                   c.push_back(temp2);
            }
        }
    }

    ll ans = 0;
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());

    for(int i=0;i<b.size();i++){
        ll lo=lower_bound(c.begin(),c.end(),b[i])-c.begin();
        ll hi=upper_bound(c.begin(),c.end(),b[i])-c.begin();
        ans += hi-lo;
    }
    cout<<ans<<endl;

    return 0;
}