#include<iostream>
#include<vector>
#include<fstream>

unsigned long long SOL = 0;


long long check(std::string str){
    long long curr;
    long long max = 0;
    // int count = 12;
    // for(long long i = 0;i<str.size()-1;i++){
    //     for(long long j=i;j<str.size();j++){
    //         if(i == j){
    //             continue;
    //         }
    //         curr = (str[i] - '0') * 10 + (str[j] - '0');
    //         if(curr > max){
    //             max = curr;
    //         }
    //     }
    // }
    int rem = str.size() - 12;

    std::string sol = "";
    sol.push_back(str[0]);
    for(long long i = 1; i<str.size();i++){
        while((str[i]-'0' > sol.back()-'0') && !sol.empty() && rem > 0){
            sol.pop_back();
            rem--;
        }
        sol.push_back(str[i]);
    }
    if(rem>0){
        std::cout << "no" << std::endl;
        sol.resize(sol.size()-rem);
    }
    sol = sol.substr(0,12);
    std::cout << sol << std::endl;
    max = stoll(sol);

    return max;
}


int main(){

    std::fstream file("input.txt"); 
    std::string line;
    std::vector<std::string> banks;

    while(getline(file,line)){
        banks.push_back(line);
    }

    std::cout << "Got all banks" << std::endl;

    for(int i = 0;i<banks.size();i++){
        std::string bank = banks[i];
        SOL += check(bank);
    }
    std::cout << std::endl;
    std::cout << SOL << std::endl;
    return 0;
}
