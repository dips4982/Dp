#include<iostream>
#include<bits/stdc++.h>

using namespace std;

long long int dp[1000001];
const int mod = 1e9+7;


int solve(int n) {

    dp[0] = 1;
    dp[1] = 1;

    for(int i=2;i<=n;i++){
        dp[i]=0;
        for(int dice=1;dice<=6;dice++){
            if(i-dice>=0){
                dp[i] = (dp[i] + dp[i-dice]) % mod;
            }
        }
    }

    return dp[n];
}


int main() {
    int n;
    cin>>n;
    cout<<solve(n)<<endl;
    return 0;
}