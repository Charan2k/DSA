#include<iostream>
#include<vector>
using namespace std;

int stairs(int height, int max_steps){
    if(height<0){
        return 0;
    }
    else if(height<=1){
        return 1;
    }
    int count = 0;
    for(int step_size=1; step_size<=max_steps; step_size++){
        count += stairs(height-step_size, max_steps);
    }
    return count;
}

int main(){
    int height, max_steps;
    cin >> height >> max_steps;
    int temp;
    cout << stairs(height,max_steps) << endl;
    return 0;
}

//4 2
// 1111 112 121 211 22 
// 4 3
// 1111 112 121 211 13 31 22 
// 3 3
// 111 12 21 12 3  
// 5 2 
// 11111 1112 1121 1211 2111
// 122 212 221 

// 6 2
// 111111
// 11112 11121 11211 12111 21111
// 1122 1221 2211 1212 2121 2112
// 222 



