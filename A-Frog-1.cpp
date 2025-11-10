#include <bits/stdc++.h>
using namespace std;

int main (){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i =0 ;i<n;i++){
        cin>>v[i];
    }
    vector<int>dp(n, INT_MAX);
    dp[0] = 0;
    for(int i =1;i<n;i++){
        if(i-2>=0){
            dp[i] = dp[i-2] + abs(v[i]-v[i-2]);  
        }
        dp[i] = min(dp[i-1] + abs(v[i] -v[i-1]), dp[i]);
    }
    cout<<dp[n-1];
    return 0;
}
