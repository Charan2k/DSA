#include<iostream>
using namespace std;

bool isPalindrome(string str){
    int i=0;
    int j=str.size()-1;
    while(i<=j){
        if(str[i]!=str[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main(){
    string str;
    cin >> str;
    if(isPalindrome(str)){
        cout << "true";
    }
    else{
        cout << "false";
    }
    return 0;
}