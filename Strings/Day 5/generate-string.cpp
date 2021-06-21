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

bool canGenerateString(string pool,string str){
    for(int i=0; i<pool.length(); i++){
        int index = isPresentInCharmap(pool[i]);
        if(index!=-1){
            charmap[index].second = charmap[index].second + 1;
        }
        else{
            charmap.push_back(make_pair(pool[i],1));
        }
    }
    bool flag;
    for(int i=0; i<str.length();i++){
        flag = false;
        for(auto &j: charmap){
            if(j.first == str[i] && j.second>0){
                j.second--;
                flag = true;
                break;
            }
        }
        if(!flag){
            return false;
        }
    }
    return true;
}

int main(){
    string pool,str;
    getline(cin,pool);
    getline(cin,str);
    if(canGenerateString(pool,str)){
        cout << "true";
    }
    else{
        cout << "false";
    }
    return 0;
}