#include<iostream>
using namespace std;
#define N 100

void readMat(int *arr[], int r, int c){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> arr[i][j];
        }
    }
}

void printMat(int *arr[], int r, int c){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout <<  arr[i][j] << " ";
        }
        cout << endl;
    }
}

int** multiply(int *m1[], int *m2[], int r, int in, int c){
    int **result = new int*[r];
    for(int i=0; i<r; i++){
        result[i] = new int[c];
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            result[i][j] = 0;
            for(int k=0; k<in; k++){
                if(m1[i][k]==0 || m2[k][j]==0){
                    continue;
                }
                result[i][j] += m1[i][k]* m2[k][j];
            }
        }
    }
    return result;
}

int main(){
    int r1,c1;
    cin >> r1 >> c1;
    int r2, c2;
    cin >> r2 >> c2;
    int **mat1 = new int*[r1];
    for(int i=0; i<r1; i++){
        mat1[i] = new int[c1];
    }
    int **mat2 = new int*[r2];
    for(int i=0; i<r2; i++){
        mat2[i] = new int[c2];
    }
    readMat(mat1,r1,c1);
    readMat(mat2,r2,c2);
    if(r2==c1){
        int **result = new int*[c2];
        result = multiply(mat1,mat2,r1,c1,c2);
        printMat(result,r1,c2);
    }
    else{
        cout << "cannot be multiplied with the given dimensions";
    }
    return 0;
}
