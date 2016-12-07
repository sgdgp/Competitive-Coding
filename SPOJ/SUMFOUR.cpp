#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int n;
    cin>>n;
    vector <int> a(n),b(n),c(n),d(n);
    vector <int> e,f;

    for(int i=0;i<n;i++) cin>>a[i]>>b[i]>>c[i]>>d[i];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int t1 = a[i]+b[j];
            int t2 = (c[i]+d[j])*(-1);
            e.push_back(t1);
            f.push_back(t2);
        }
    }
    sort(e.begin(),e.end());
    sort(f.begin(),f.end());
    int ans = 0;
    for(int i=0;i<e.size();i++){
        int lo=lower_bound(f.begin(),f.end(),e[i])-f.begin();
        int hi=upper_bound(f.begin(),f.end(),e[i])-f.begin();
        ans += hi-lo;
    }
    cout<<ans<<endl;
    return 0;
}