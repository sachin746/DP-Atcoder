#include <bits/stdc++.h>
using namespace std;

int main (){
    int n;
    cin>>n;
    vector<vector<int>>dp(n, vector<int>(3,INT_MIN));
    int a,b,c;
    for(int i =0 ;i<n;i++){
        cin>>a>>b>>c;
        if(i==0){
            dp[i][0] = a;
            dp[i][1] = b;
            dp[i][2] = c;
        } else {
            dp[i][0] = max(dp[i-1][1] + a, dp[i-1][2] + a);
            dp[i][1] = max(dp[i-1][0] + b, dp[i-1][2] + b);
            dp[i][2] = max(dp[i-1][0] + c, dp[i-1][1] + c);
        }
    }
    cout<<max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
    return 0;
}
