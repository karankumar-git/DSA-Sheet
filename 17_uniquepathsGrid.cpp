
//BRUTE FORCE APPROACH by recursion
int totalpath(int i ,int j, int m,int n){
    if(i==m-1||j==n-1){
        return 1;
    }
    if(i>=m && j>=n){
        return 0;
    }
    else{
        return totalpath(i+1,j,m,n) + totalpath(i,j+1,m,n);
    }
}
int uniquePaths(int m, int n) {
    return totalpath(0,0,m,n);
}


//BETTER - APPLY DP
int countPaths(int i,int j,int n,int m,vector<vector<int>> &dp)
{
    if(i==(n-1)&&j==(m-1)) return 1;
    if(i>=n||j>=m) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    else return dp[i][j]=countPaths(i+1,j,n,m,dp)+countPaths(i,j+1,n,m,dp);
    
}
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
   
    //dp[1][1]=1;
   int num=countPaths(0,0,m,n,dp);
    if(m==1&&n==1)
        return num;
    return dp[0][0];
}

//OPTIMAL SOLUTION - using combinators
        
int optimal(int n,int m){
    int N = n + m - 2;
    int r = m - 1; 
    double res = 1;
    
    for (int i = 1; i <= r; i++)
        res = res * (N - r + i) / i;
    return (int)res;
}