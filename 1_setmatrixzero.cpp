#include<bits/stdc++.h>
using namespace std;

void brute(int arr[3][3]){
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            if(arr[i][j]==0){
                for(int k = 0; k< 3; k++){
                    if(arr[k][j] == 1){
                        arr[k][j] = -1;
                    }
                }
                for(int k = 0; k<3; k++){
                    if(arr[i][k] == 1){
                        arr[i][k] = -1;
                    }
                }
            }
        }
    }

    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            if(arr[i][j] == -1){
                arr[i][j] = 0;
            }
        }
    }
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            cout<< arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
void better(int arr[3][3]){
    int col[3] = {0};
    int row[3] = {0};
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            if(arr[i][j]==0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            if(row[i]==1 || col[j] == 1){
                arr[i][j] = 0;
            }
        }
    }

    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            cout<< arr[i][j]<<" ";
        }
        cout<<endl;
    }

}

void optimal(int arr[3][3]){
    int col0 = 1;
    for(int i = 0; i<3; i++){
        if(arr[i][0] == 0){
                col0 = 0;
        }
        for(int j = 1; j<3; j++){
            if(arr[i][j]==0){
                arr[i][0] = 0;
                arr[0][j] = 0;
            }
        }
    }
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            if(j==0 && col0 == 0){
                arr[i][j] = 0;
                continue;
            }
            if(arr[0][j] == 0 || arr[i][0]==0){
                arr[i][j] = 0;
            }
        }
    }
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            cout<< arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    // int n;
    // cin>>n;

    int arr1[3][3];
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            cin >> arr1[i][j];
        }
    }
    // brute(arr1);
    // better(arr1);
    optimal(arr1);
}