#include<iostream>
#include<vector>
using namespace std;

vector<pair<char,int>> charmap;

int isPresentInCharmap(char ch){
    int index=0;
    for(auto i: charmap){
        if(i.first == ch){
            return index;
        }index++;
    }
    return -1;
}
string runLengthEncoder(string str){
    int index;
    for(int i=0; i<str.length(); i++){
        index = isPresentInCharmap(str[i]);
        if(index!=-1){
            charmap[index].second = charmap[index].second + 1;
        }
        else{
            charmap.push_back(make_pair(str[i],1));
        }
    }
    string encoded;
    for(auto i: charmap){
        if(i.second>9){
            while(i.second>9){
                char ch = 9+48;
                encoded += ch;
                encoded += i.first;
                i.second -= 9;
            }
            char ch = i.second+48;
            encoded += ch;
            encoded += i.first;
        }
        else{
            char ch = i.second + 48;
            encoded += ch;
            encoded += i.first;
        }
    }
    return encoded;
}

int main(){
    string str;
    cin >> str;
    string encoded = runLengthEncoder(str);
    cout << encoded << endl;
    for(auto i: charmap){
        cout << i.first << ":" << i.second << endl;
    }
    return 0;
}