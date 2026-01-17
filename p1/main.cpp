#include<iostream>
#include<fstream>
#include<vector>
// #include<stdlib.h>

using namespace std;

int SOL = 0;

void right(string s, int* n){
    int rot = stoi(s.substr(1));
    //cout << rot;
    if(rot >= 100){
        SOL += rot / 100;
        rot = rot % 100;
    }
    *n = (*n + rot);
    if(*n >= 100){
        SOL++;
        *n = *n % 100;
        if(*n == 0){
            return;
        }
    }
    if(*n == 0){
        SOL++;
        return;
    }
    
    //cout << " " << *n  << endl;
}
void left(string s, int* n){
    int rot = stoi(s.substr(1));
    // cout << rot ;
    if(rot >= 100){
        SOL += rot / 100;
        rot = rot % 100;
    }
    int curr = *n;
    *n = (*n - rot);
    // cout << " " << *n;
    if(*n < 0){
        *n = 100 + *n;
        if(curr==0){
            return;
        }
        SOL++;
        if(*n==0){
            return;
        }
    }
   // cout << " " << *n;
    // //*n = *n % 99;
    // cout << " " << *n  << endl;
    if(*n==0){
        SOL++;
    }
}



int main(){
    fstream file("input.txt");
    string line;
    vector<string> lines;

    while(getline(file,line)){
        lines.push_back(line);
    }
    int curr = 50;

    for(int i = 0; i<lines.size();i++){
        char c = lines[i][0];
        // cout << c;
        if(c=='R'){
            right(lines[i], &curr);
        } else {
            left(lines[i], &curr);
        }
    }

    cout << SOL << endl;
    cout << "current n :" << curr << endl;
    return 0;
}
