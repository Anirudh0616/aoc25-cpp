#include<iostream>
#include<vector>
#include<fstream>

long long SOL = 0;

int invalid(std::string str){
    long long n = str.size();
    // std::cout << n << std::endl;
    // if(n%2!=0){
    //     int x = 0;
    //     char prev = str[0];
    //     for(long long j=1;j<n;j++){
    //         if(prev == str[j]){
    //             x = 1;
    //             prev = str[j];
    //         } else {
    //             x = 0;
    //             return 0; 
    //         }
    //     }
    //     if(x){
    //         return 1;
    //     }
    // }
    std::string temp = str + str;
    temp = temp.substr(1, 2*n-2);
    return temp.find(str) != std::string::npos;
    // std::cout << str.substr(0,n/2-1) << std::endl;
    // return str.compare(0, n/2, str, n/2, n/2) == 0;
}


int main(){
    std::cout << "Reading file..."; 
    std::fstream file("input.txt");
    std::string line;

    getline(file, line);

    std::vector<std::string> lefts;
    std::vector<std::string> rights;

    std::string token;
    for(int i =0;i<line.size();i++){
        char c = line[i];
        if(c==','){
            size_t dash = token.find('-');
            if(dash != std::string::npos){
                lefts.push_back(token.substr(0,dash));
                rights.push_back(token.substr(dash+1));
                // std::cout << token << std::endl;
            }
            token.clear();
        } else{
            token.push_back(c);
        }
    }
    if(!token.empty()){
        size_t dash = token.find('-');
        if(dash != std::string::npos){
            lefts.push_back(token.substr(0,dash));
            rights.push_back(token.substr(dash+1));
        }
        // std::cout << token << std::endl;
        token.clear();
    }
    
    for(int i =0;i<lefts.size();i++){
        long long l = stoll(lefts[i]);
        long long r = stoll(rights[i]);
        for(long long j = l;j<=r;j++){
            // std::cout << j << std::endl;
            if(invalid(std::to_string(j))){
                SOL+= j;
            }
        }
    }
    std::cout << SOL << std::endl;

    return 0;
}
