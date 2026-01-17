#include <iostream>
#include <fstream>
#include <vector>
// #include <string>

int main(){
    long long int sol2 = 0;
    std::fstream file("try.txt");
    std::string line;
    std::vector<std::string> lines;
    
    // std::string token;
    std::vector<std::pair<long long, long long >> ranges;

    while(getline(file,line)){
        if(line.empty())break;
        size_t dash = line.find('-');
        if(dash != std::string::npos){
            ranges.push_back({stoll(line.substr(0,dash)),stoll(line.substr(dash+1))});
        }
    }
    file.clear();
    std::cout << "Got all the ranges\n";

    std::vector<std::pair<long long, long long>> merged;

    std::sort(ranges.begin(), ranges.end());
    for(const auto& [l,r]: ranges){
        if(merged.empty() || l > merged.back().second + 1){
            // no overlap
            merged.push_back({l,r});
        } else {
            merged.back().second = std::max(merged.back().second, r);
        }
    }


    long long int x;
    long long int sol = 0;
    while(getline(file,line)){
        // std::cout << line << std::endl;
        if(line.empty()) continue;
        x = std::stoll(line);
        for(auto [l,r] : merged){
            // std::cout << l << " " << r << std::endl;
            if(l <= x && x <= r){
                sol++;
                break;
            }
        }
    }
    for(auto[l,r] : merged){
        sol2 += (r-l+1);
    }

    std::cout << sol << '\n';
    std::cout << sol2 << '\n';


    return 0;
}
