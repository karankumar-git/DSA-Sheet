int brute(int arr[],int n){
    int maxProfit = 0;
    for(int i = 0 ; i<n-1;i++){
        for(int j = i+1; j<n; j++){
            if(arr[j]>arr[i]){
                maxProfit = max(arr[j]-arr[i],maxProfit);
            }
        }
    }
    return maxProfit;
}

int optimal(int arr[],int n){
    int minPrice = arr[0];
    int maxProfit = 0;
    for(int i = 1 ; i<n ;i++){
        maxProfit = max(arr[i]-minPrice,maxProfit);
        minPrice = min(arr[i],minPrice);
    }
    return maxProfit;

}