#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> powerSets;
void powerset(vector<int> &arr, int index, vector<int> currentSet){
    if(index == arr.size()){
        powerSets.push_back(currentSet);
        return;
    }
    currentSet.push_back(arr[index]);
    powerset(arr, index+1,currentSet);
    currentSet.pop_back();
    powerset(arr,index+1,currentSet);
    return;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr;
    int temp;
    for(int i=0; i<n; i++){
        cin >> temp;
        arr.push_back(temp);
    }
    cout << "Powerset: " << endl;
    vector<int> currentSet;
    powerset(arr,0,currentSet);
    for(auto i: powerSets){
        for(auto j: i){
            cout << j << " ";
        }cout << endl;
    }
    return 0;
}