#include<bits/stdc++.h>
using namespace std;
  
#define ll long long
#define mod 1000000007
#define test ll t; scanf("%lld",&t); while(t--)

int main(){
    test{
        ll n,k;
        scanf("%lld%lld",&n,&k);
        ll a[n],psum=0,sum=0;
        for(ll i=0;i<n;i++){
            scanf("%lld",&a[i]);
            psum+=a[i]>0?a[i]:0;
            sum+=a[i];
        }
        if(n<=k){
            printf("%lld\n",psum);
            continue;
        }
        ll dp[n],minimum=a[n-1];
        dp[n-1]=a[n-1];
        for(ll i=n-2;i>=n-k-1;i--){
            if(minimum<0){
                dp[i]=a[i]+minimum;
            }
            else{
                dp[i]=a[i];
            }
            minimum=min(minimum,dp[i]);
        }
        for(ll i=n-k-2;i>=0;i--){
            minimum=INT_MAX;
            for(ll j=i+1;j<=i+k+1;j++){
                minimum=min(minimum,dp[j]);
            }
            dp[i]=a[i]+minimum;
        }
        minimum=INT_MAX;
        for(ll i=0;i<=k;i++){
            minimum=min(minimum,dp[i]);
        }
        printf("%lld\n",sum-minimum);
    }
    return 0;
}