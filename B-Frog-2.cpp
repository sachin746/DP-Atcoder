#include <bits/stdc++.h>
using namespace std;

int main (){
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i =0 ;i<n;i++){
        cin>>v[i];
    }
    vector<int>dp(n, INT_MAX);
    dp[0] = 0;
    for(int i =1;i<n;i++){
        for(int j = i-1;j>=max(0,i-k);j--){
            dp[i] = min(dp[j] + abs(v[i] -v[j]), dp[i]);
        } 
        dp[i] = min(dp[i-1] + abs(v[i] -v[i-1]), dp[i]);
    }
    cout<<dp[n-1];
    return 0;
}
