#include <iostream>
#include <vector>
#include <fstream>
#include <cctype>

std::string trim(const std::string& s) {
    size_t start = 0;
    while (start < s.size() && std::isspace((unsigned char)s[start]))
        start++;

    size_t end = s.size();
    while (end > start && std::isspace((unsigned char)s[end - 1]))
        end--;

    return s.substr(start, end - start);
}

int main(){
    long long sol = 0;
    
    std::fstream file("actual.txt");

    std::vector<std::string> grid;

    std::string line;

    while(getline(file, line)){
        grid.push_back(line); 
    }

    std::vector<long long> blanks;

    for(long long int c =0; c< grid[0].size();c++){
        int blank = 0;
        for(const auto&i : grid){
            if(i[c] == ' '){
                blank = 1;
            } else {
                blank = 0;
                break;
            }
        }
        if(blank == 1){
            blanks.push_back(c);
        }
    }

    std::vector<std::vector<std::string>> nums;

    nums.resize(blanks.size() + 1);

    long long j = 0;
    long long lastc = 0;
    for(const auto&i : grid){
        j = 0;
        lastc = 0;
        for(const auto&c : blanks){
            nums[j].push_back(i.substr(lastc,c-lastc));
            lastc = c;
            j++;
        }
        nums[j].push_back(i.substr(lastc, grid[0].size()-lastc));
    }

    long long int subsol;
    for(const auto&j : nums){
        if(trim(j[j.size() - 1]) == "*"){
            std::cout << "MULT" << std::endl;
            subsol = 1;
            for(auto&i: j){
                std::string s = trim(i);
                if(s == "*") break;
                long long now = stoll(s);
                subsol *= now;
            }
        } else {
            std::cout << "ADD" << std::endl;
            subsol = 0;
            for(auto&i: j){
                std::string s = trim(i);
                if(s == "+") break;
                long long now = stoll(s);
                subsol += now;
            }
        }

        sol += subsol;

    }

    std::cout << sol;

    return 0;
}
