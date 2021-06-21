#include<iostream>
using namespace std;

int count = 0;

bool isSafe(int **arr, int i, int j, int n){
    for(int k = 0; k < i; k++){
        if(arr[k][j] == 1){
            return false;
        }
    }
    int row = i;
    int col = j;
    while(row>=0 && col >= 0){
        if(arr[row][col] == 1){
            return false;
        }
        row--; col--;
    }
    row = i;
    col = j;
    while(row>=0 && col <n){
        if(arr[row][col] == 1){
            return false;
        }
        row--; col++;
    }
    return true;
}

bool nQueen(int **arr, int i, int n){
    if(i >= n){
        count++;
        return false;
    }
    for(int j = 0; j<n; j++){
        if(isSafe(arr, i, j, n)){
            arr[i][j] = 1;
            if(nQueen(arr,i+1,n)){
                return true;
            }
            arr[i][j] = 0;
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    int** arr = new int*[n];
    for(int i=0; i<n; i++){
        arr[i] = new int[n];
        for(int j=0; j<n; j++){
            arr[i][j] = 0;
        }        
    }
    nQueen(arr,0,n);
    cout << count;
    return 0;
}