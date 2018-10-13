#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector <int> > board;

struct location{
    
    int row;
    int col;
    
    location(){
        this->row = 0;
        this->col = 0;
    }
    
    location(int row, int col){
        this->row = row;
        this->col = col;
    }
    
    location operator=(location in){
        this->row = in.row;
        this->col = in.col;
        
        return *this;
    }
    
    bool operator==(location in){
        
        return (this->row == in.row && this->col == in.col);
    }
};

int dfs(vector<location>& shape, int max_val){
    
    int output = 0;
    bool already = false;
    location next_loc;
    
    if (shape.size() == 4){
        for (auto& v: shape) output += board[v.row -1][v.col -1];
    }
    else{
        vector<location> orig_shape = shape;
        for (auto& v: orig_shape){
            
            //cout << "V changed to " << "v row:" << v.row << "v col:" << v.col << endl;
            
            already = false;
            if (v.row -1 >0){
                //cout << "u " << "v.row: " << v.row << " v.col: " << v.col << " " << shape.size() << endl;
                
                next_loc = location(v.row -1, v.col);
                //find if no more than max_val
                if (board[next_loc.row -1][next_loc.col -1] <= max_val){
                    //find if already in
                    for (auto& w: shape){
                        if (w==next_loc) {
                            already = true;
                            break;
                        }
                    }
                    
                    //traverse if !already
                    if (!already){
                        //cout << "enter traverse: " << "u " << "v.row: " << v.row << " v.col: " << v.col << " " << shape.size() << endl;
                        //preorder
                        shape.push_back(next_loc);
                        output = max(dfs(shape, max_val),output);
                        //postorder
                        shape.pop_back();
                    }
                }
                
            }
            
            already = false;
            if (v.row +1 <= N){
                //cout << "d " << "v.row: " << v.row << " v.col: " << v.col << " " << shape.size() << endl;
                
                next_loc = location(v.row +1, v.col);
                //find if no more than max_val
                if (board[next_loc.row -1][next_loc.col -1] <= max_val){
                    //find if already in
                    for (auto& w: shape){
                        if (w==next_loc) {
                            already = true;
                            break;
                        }
                    }
                    
                    //traverse if !already
                    if (!already){
                        //cout << "enter traverse: " << "d " << "v.row: " << v.row << " v.col: " << v.col << " " << shape.size() << endl;
                        //preorder
                        shape.push_back(next_loc);
                        output = max(dfs(shape, max_val),output);
                        //postorder
                        shape.pop_back();
                    }
                }
            }
            
            already = false;
            if (v.col -1 >0){
                //cout << "l " << "v.row: " << v.row << " v.col: " << v.col << " " << shape.size() << endl;
                
                next_loc = location(v.row, v.col-1);
                //find if no more than max_val
                if (board[next_loc.row -1][next_loc.col -1] <= max_val){
                    //find if already in
                    for (auto& w: shape){
                        if (w==next_loc) {
                            already = true;
                            break;
                        }
                    }
                    
                    //traverse if !already
                    if (!already){
                        //cout << "enter traverse: " << "l " << "v.row: " << v.row << " v.col: " << v.col << " " << shape.size() << endl;
                        //preorder
                        shape.push_back(next_loc);
                        output = max(dfs(shape, max_val),output);
                        //postorder
                        shape.pop_back();
                    }
                }
            }
            
            already = false;
            if (v.col +1 <= M){
                //cout << "r " << "v.row: " << v.row << " v.col: " << v.col << " " << shape.size() << endl;
                
                next_loc = location(v.row, v.col+1);
                //find if no more than max_val
                if (board[next_loc.row -1][next_loc.col -1] <= max_val){
                    //find if already in
                    for (auto& w: shape){
                        if (w==next_loc) {
                            already = true;
                            break;
                        }
                    }
                    
                    //traverse if !already
                    if (!already){
                        //cout << "enter traverse: " << "r " << "v.row: " << v.row << " v.col: " << v.col << " " << shape.size() << endl;
                        //preorder
                        shape.push_back(next_loc);
                        output = max(dfs(shape, max_val),output);
                        //postorder
                        shape.pop_back();
                    }
                }
            }
            
        }
    }
    
    return output;
};

int main() {
    vector<int> row;
    int temp;
    int max_val= -1;
    int ans = -1;
    int temp_ans;
    vector<location> vals[1001];
    vector<location> shape;
    
    
    cin >> N >> M;
 
    for (int i=0; i<N; ++i){
        row.clear();
        for (int j=0; j<M; ++j){
            cin >> temp;
            row.push_back(temp);
            
            vals[temp].push_back(location(i+1,j+1));
            if (max_val < temp) max_val = temp;
        }
        board.push_back(row);
    }
    
    //search from large locs. Don't search since max_val/4
    for (int i= max_val; i > max_val/4; --i){
        if (vals[i].size() != 0){
            for (auto& v: vals[i]){
                
                //cout << "From main v row:" << v.row << " v col:" << v.col << endl;
                shape.push_back(v);
                temp_ans = dfs(shape, i);
                shape.pop_back();
                if (ans < temp_ans) ans = temp_ans;
            }
        }
    }
    
    cout << ans;
    
    
}
