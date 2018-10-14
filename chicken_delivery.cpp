#include <iostream>
#include <vector>

using namespace std;

struct location;
struct home;

int N, M;
//chicken places
vector<location> chickens;
vector<home> homes;
//number of chicken places
int numc;
//inf is the final answer
int inf;

struct location{
    
    int row;
    int col;
    
    
    location(){
        row = 0;
        col = 0;
    }
    
    location(int row, int col){
        this->row = row;
        this->col = col;
    }
    
    location operator=(location loc){
        this->row = loc.row;
        this->col = loc.col;
        
        return *this;
    }
    
    bool operator==(location loc){
        return (this->row == loc.row && this->col == loc.col);
    }
};

int distance(location loc1, location loc2){
    
    return abs(loc1.row - loc2.row) + abs(loc1.col - loc2.col);
}

struct home{
    
    location loc;
    //nth value of to_chicken is the distance to the nth chicken place in vector<location> chickens.
    vector<int> to_chicken;
    
    home(int row, int col){
        loc = location(row, col);
        
    }
    
};

int chicken_distance(vector<int>& choose){
    int sum = 0;
    int dist = 0;
    int temp = 0;
    
    for (auto& v: homes){
        dist = 10000;
        for (auto& w: choose){
            temp = v.to_chicken.at(w-1);
            if (temp < dist) dist = temp;
        }
        sum += dist;
        
    }
    
    return sum;
}

void dfs(vector<int>& choose){
    
    
    if (choose.size() == M){
        //find chicken distance with this choose
        int temp = chicken_distance(choose);
        //cout << temp << endl;
        if (temp < inf) inf = temp;
    }
    else if (choose.size() == 0){
        for (int i=1; i<= numc; ++i){
            choose.push_back(i);
            dfs(choose);
            choose.pop_back();
        }
    }
    else if (numc - choose.at(0) +1 < M){
        return;
    }
    else{
        for (int i=*(choose.end() -1)+1; i<= numc; ++i){
            choose.push_back(i);
            dfs(choose);
            choose.pop_back();
        }
        
    }
     
    
}



int main(){

    cin >> N >> M;
    int temp;
    
    int city[N+1][N+1];
    
    for (int i=1; i <= N; ++i){
        for (int j=1; j <= N; ++j) {
            cin >> temp;
            city[i][j] = temp;
            if (temp == 1) homes.push_back(home(i,j));
            else if (temp == 2) chickens.push_back(location(i,j));
        }
    }
    
    numc = chickens.size();
    inf = 10000;
    
    //for each home, compute distance the to_chicken
    for (auto& v: homes){
        for (auto& w: chickens){
            v.to_chicken.push_back(distance(v.loc, w));
        }
    }

    //brute force: choose M from [1,chickens.size()]; find chicken distance for each home and for city; keep minimum found so far
    vector<int> choose;
    
    dfs(choose);
    
    cout << inf;
    
}
