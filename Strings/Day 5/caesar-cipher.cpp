#include<iostream>
using namespace std;

string cipherIt(string s, int key){
    int i=0;
    if(key>25){
        key = key%26;
    }
    while(i<s.length()){
        if(s[i]+key > 'z'){
            int temp_key = 'z' - s[i];
            temp_key = key - temp_key;
            s[i] = 'a' + temp_key - 1;
        }
        else{
            s[i] = s[i] + key;
        }
        i++;
    }
    return s;
}

int main(){
    string str;
    int key;
    cin >> str;
    cin >> key;
    string encrypted = cipherIt(str,key);
    cout << encrypted;
    return 0;
}