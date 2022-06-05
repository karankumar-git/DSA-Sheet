int bruteForce(vector<int>& h) {
    int n = h.size();
    vector<int> leftmax(n,0);
    vector<int> rightmax(n,0);
    
    int maxi = 0
    //store left max 
    for(int i = 0; i<n; i++){
        if(h[i]>maxi){
            maxi = h[i];
        }
        leftmax[i] = maxi;
    }
    
    maxi = 0;
    //store right max
    for(int i = n-1; i>=0; i--){
        if(h[i]>maxi){
            maxi = h[i];
        }
        rightmax[i] = maxi;
    }
    
    int res = 0;
    for(int i = 0; i<n; i++){
        //answer will be (min of max of left part of array and max of right part of array) - h[i];
        res+= min(leftmax[i],rightmax[i]) - h[i];
    }
    return res;
}


// 2 Pointers Approach
int optimal(vector<int>& h) {
    int n = h.size();
    int res = 0;
    int leftmax = 0,rightmax = 0;
    int l = 0, r = n-1;
    while(l<=r){
        //if there is element at right greater than current left
        if(h[l] <= h[r]){
            if(h[l] >= leftmax){
                //if it is greater
                leftmax = h[l];
            }
            else{
                res += leftmax - h[l];
            }
            l++;
        }
        // if there is element at left greater than current right
        else{
            if(h[r] >= rightmax){
                rightmax = h[r];
            }
            else{
                res += rightmax - h[r];
            }
            r--;
        }
    }
    return res;
}