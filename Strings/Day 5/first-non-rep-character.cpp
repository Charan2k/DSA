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

int indexOfFirstNonRepeatingCharacter(string str){
    for(int i=0; i<str.length(); i++){
        int index = isPresentInCharmap(str[i]);
        if(index!=-1){
            charmap[index].second = charmap[index].second + 1;
        }
        else{
            charmap.push_back(make_pair(str[i],1));
        }
    }
    char ch;
    for(auto i: charmap){
        if(i.second == 1){
            ch = i.first;
            break;
        }
    }
    for(int i=0; i<str.length(); i++){
        if(ch == str[i]){
            return i;
        }
    }
    return -1;
}

int main(){
    string str;
    cin >> str;
    cout << indexOfFirstNonRepeatingCharacter(str);
    return 0;
}