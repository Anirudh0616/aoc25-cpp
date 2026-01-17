#include <iostream>
#include <fstream>
#include <vector>

std::vector<std::vector <int>> marked;

int check(std::vector <std::string> lines, int ROWS, int COLUMNS){
    
    std::vector <int> r_iterations = {-1, 0 , 1};
    std::vector <int> c_iterations = {-1, 0 , 1};

    int sol = 0;
    int currRow = 0;
    for(const auto& currline: lines){
        int currCol = 0;
        for(const auto& currchar: currline){
            int brr = 0;
            for(auto& dr : r_iterations){
                for(auto& dc: c_iterations){
                    int l = currRow + dr;
                    int r = currCol + dc;
                    if(0<=l && l <ROWS && r >= 0 && r < COLUMNS && lines[l][r] == '@'){
                        brr++; 
                    }
                }
            }
            if(currchar=='@' && brr<5){
                sol++;
                marked.push_back({currRow, currCol});
            }
            currCol++;
        }
        currRow++;
    }
    std::cout << "loop done\n";
    std::cout << sol << '\n';
    return sol;
}

std::vector<std::string> removal(std::vector<std::string> lines){
    for(auto& i :marked){
        int r = i[0];
        int c = i[1];
        lines[r][c] = 'x';
    }
    return lines;
}

int main (){
    

    std::fstream file("try.txt"); 
    std::string line;
    std::vector <std::string>lines;

    while(getline(file,line)){
        lines.push_back(line);
    }
    int COLUMNS = lines[0].size();
    int ROWS = lines.size();

    std::cout << "Received the Toilet paper\n";
    int sol = 0;
   
    while(check(lines, ROWS, COLUMNS) != 0){
        sol += check(lines, ROWS, COLUMNS);
        lines = removal(lines);
    }
    std::cout << sol;

    return 0;
}
