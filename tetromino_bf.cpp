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

struct tetromino{
    //NW, SE is for tight rect box NW at (1,1) initially.
    location NW;
    int width;
    int height;
    vector<location> locs;
    
    tetromino(){
        
    }
    
    void clear(){
        locs.clear();
    }
    
    tetromino(int width, int height, location loc1, location loc2, location loc3, location loc4){
        this->NW = location(1,1);
        this->width = width;
        this->height = height;
        this->locs.push_back(loc1);
        this->locs.push_back(loc2);
        this->locs.push_back(loc3);
        this->locs.push_back(loc4);
    }
    
    void shift(int row_inc, int col_inc){
        NW.row += row_inc;
        NW.col += col_inc;
        
        for (auto& v: this->locs){
            v.row += row_inc;
            v.col += col_inc;
        }
    }
    
    int sum(){
        int ans = 0;
        for (auto& v: this->locs) ans += board[v.row -1][v.col -1];
        
        return ans;
    }
    
    
};


int main() {
    vector<int> row;
    int temp;
    int max = 0;
    vector<tetromino> tets;
    tetromino tet1;
    location loc1;
    location loc2;
    location loc3;
    location loc4;
    
    
    cin >> N >> M;
    
    for (int i=0; i<N; ++i){
        row.clear();
        for (int j=0; j<M; ++j){
            cin >> temp;
            row.push_back(temp);
            
        }
        board.push_back(row);
    }
    
    
    //make 19 tets
    
    //1.1
    tet1.width = 4;
    tet1.height = 1;
    loc1 = location(1,1);
    loc2 = location(1,2);
    loc3 = location(1,3);
    loc4 = location(1,4);
    tet1.locs.push_back(loc1);
    tet1.locs.push_back(loc2);
    tet1.locs.push_back(loc3);
    tet1.locs.push_back(loc4);
    tets.push_back(tet1);
    tet1.clear();
    
    //1.2
    tet1.width = 1;
    tet1.height = 4;
    loc1 = location(1,1);
    loc2 = location(2,1);
    loc3 = location(3,1);
    loc4 = location(4,1);
    tet1.locs.push_back(loc1);
    tet1.locs.push_back(loc2);
    tet1.locs.push_back(loc3);
    tet1.locs.push_back(loc4);
    tets.push_back(tet1);
    tet1.clear();
    
    //2
    tet1.width = 2;
    tet1.height = 2;
    loc1 = location(1,1);
    loc2 = location(1,2);
    loc3 = location(2,1);
    loc4 = location(2,2);
    tet1.locs.push_back(loc1);
    tet1.locs.push_back(loc2);
    tet1.locs.push_back(loc3);
    tet1.locs.push_back(loc4);
    tets.push_back(tet1);
    tet1.clear();
    
    //3.1 |-
    tet1.width = 2;
    tet1.height = 3;
    loc1 = location(1,1);
    loc2 = location(1,2);
    loc3 = location(2,1);
    loc4 = location(3,1);
    tet1.locs.push_back(loc1);
    tet1.locs.push_back(loc2);
    tet1.locs.push_back(loc3);
    tet1.locs.push_back(loc4);
    tets.push_back(tet1);
    tet1.clear();
    
    //3.2 |_
    tet1.width = 2;
    tet1.height = 3;
    loc1 = location(1,1);
    loc2 = location(2,1);
    loc3 = location(3,1);
    loc4 = location(3,2);
    tet1.locs.push_back(loc1);
    tet1.locs.push_back(loc2);
    tet1.locs.push_back(loc3);
    tet1.locs.push_back(loc4);
    tets.push_back(tet1);
    tet1.clear();
    
    //3.3 -|
    tet1.width = 2;
    tet1.height = 3;
    loc1 = location(1,1);
    loc2 = location(1,2);
    loc3 = location(2,2);
    loc4 = location(3,2);
    tet1.locs.push_back(loc1);
    tet1.locs.push_back(loc2);
    tet1.locs.push_back(loc3);
    tet1.locs.push_back(loc4);
    tets.push_back(tet1);
    tet1.clear();
    
    //3.4 _|
    tet1.width = 2;
    tet1.height = 3;
    loc1 = location(1,2);
    loc2 = location(2,2);
    loc3 = location(3,2);
    loc4 = location(3,1);
    tet1.locs.push_back(loc1);
    tet1.locs.push_back(loc2);
    tet1.locs.push_back(loc3);
    tet1.locs.push_back(loc4);
    tets.push_back(tet1);
    tet1.clear();
    
    //3.5
    tet1.width = 3;
    tet1.height = 2;
    loc1 = location(1,1);
    loc2 = location(2,1);
    loc3 = location(2,2);
    loc4 = location(2,3);
    tet1.locs.push_back(loc1);
    tet1.locs.push_back(loc2);
    tet1.locs.push_back(loc3);
    tet1.locs.push_back(loc4);
    tets.push_back(tet1);
    tet1.clear();
    
    //3.6
    tet1.width = 3;
    tet1.height = 2;
    loc1 = location(1,1);
    loc2 = location(1,2);
    loc3 = location(1,3);
    loc4 = location(2,1);
    tet1.locs.push_back(loc1);
    tet1.locs.push_back(loc2);
    tet1.locs.push_back(loc3);
    tet1.locs.push_back(loc4);
    tets.push_back(tet1);
    tet1.clear();
    
    //3.7
    tet1.width = 3;
    tet1.height = 2;
    loc1 = location(1,3);
    loc2 = location(2,1);
    loc3 = location(2,2);
    loc4 = location(2,3);
    tet1.locs.push_back(loc1);
    tet1.locs.push_back(loc2);
    tet1.locs.push_back(loc3);
    tet1.locs.push_back(loc4);
    tets.push_back(tet1);
    tet1.clear();
    
    //3.8
    tet1.width = 3;
    tet1.height = 2;
    loc1 = location(1,1);
    loc2 = location(1,2);
    loc3 = location(1,3);
    loc4 = location(2,3);
    tet1.locs.push_back(loc1);
    tet1.locs.push_back(loc2);
    tet1.locs.push_back(loc3);
    tet1.locs.push_back(loc4);
    tets.push_back(tet1);
    tet1.clear();
    
    //4.1
    tet1.width = 2;
    tet1.height = 3;
    loc1 = location(1,1);
    loc2 = location(2,1);
    loc3 = location(2,2);
    loc4 = location(3,2);
    tet1.locs.push_back(loc1);
    tet1.locs.push_back(loc2);
    tet1.locs.push_back(loc3);
    tet1.locs.push_back(loc4);
    tets.push_back(tet1);
    tet1.clear();
    
    //4.2
    tet1.width = 2;
    tet1.height = 3;
    loc1 = location(1,2);
    loc2 = location(2,2);
    loc3 = location(2,1);
    loc4 = location(3,1);
    tet1.locs.push_back(loc1);
    tet1.locs.push_back(loc2);
    tet1.locs.push_back(loc3);
    tet1.locs.push_back(loc4);
    tets.push_back(tet1);
    tet1.clear();
    
    //4.3
    tet1.width = 3;
    tet1.height = 2;
    loc1 = location(1,1);
    loc2 = location(1,2);
    loc3 = location(2,2);
    loc4 = location(2,3);
    tet1.locs.push_back(loc1);
    tet1.locs.push_back(loc2);
    tet1.locs.push_back(loc3);
    tet1.locs.push_back(loc4);
    tets.push_back(tet1);
    tet1.clear();
    
    //4.4
    tet1.width = 3;
    tet1.height = 2;
    loc1 = location(2,1);
    loc2 = location(2,2);
    loc3 = location(1,2);
    loc4 = location(1,3);
    tet1.locs.push_back(loc1);
    tet1.locs.push_back(loc2);
    tet1.locs.push_back(loc3);
    tet1.locs.push_back(loc4);
    tets.push_back(tet1);
    tet1.clear();
    
    //5.1
    tet1.width = 3;
    tet1.height = 2;
    loc1 = location(1,2);
    loc2 = location(2,2);
    loc3 = location(2,1);
    loc4 = location(2,3);
    tet1.locs.push_back(loc1);
    tet1.locs.push_back(loc2);
    tet1.locs.push_back(loc3);
    tet1.locs.push_back(loc4);
    tets.push_back(tet1);
    tet1.clear();
    
    //5.2
    tet1.width = 3;
    tet1.height = 2;
    loc1 = location(1,1);
    loc2 = location(1,2);
    loc3 = location(1,3);
    loc4 = location(2,2);
    tet1.locs.push_back(loc1);
    tet1.locs.push_back(loc2);
    tet1.locs.push_back(loc3);
    tet1.locs.push_back(loc4);
    tets.push_back(tet1);
    tet1.clear();
    
    //5.3
    tet1.width = 2;
    tet1.height = 3;
    loc1 = location(1,2);
    loc2 = location(2,2);
    loc3 = location(3,2);
    loc4 = location(2,1);
    tet1.locs.push_back(loc1);
    tet1.locs.push_back(loc2);
    tet1.locs.push_back(loc3);
    tet1.locs.push_back(loc4);
    tets.push_back(tet1);
    tet1.clear();
    
    //5.4
    tet1.width = 2;
    tet1.height = 3;
    loc1 = location(1,1);
    loc2 = location(2,1);
    loc3 = location(3,1);
    loc4 = location(2,2);
    tet1.locs.push_back(loc1);
    tet1.locs.push_back(loc2);
    tet1.locs.push_back(loc3);
    tet1.locs.push_back(loc4);
    tets.push_back(tet1);
    tet1.clear();
    
    
    
    //find max
    int v_width;
    int v_height;
    int n=0;
    
    for (auto& v: tets){
        v_width = v.width;
        v_height = v.height;
        for (int i=v_height; i <= N ; ++i){
            for (int j=v_width; j <= M ; ++j){
                temp = v.sum();
                if (temp > max) max = temp;
                v.shift(0,1);
            }
            v.shift(1, v_width - M -1);
        }
        
        //cout << n << " " << max << endl;
        //++n;
    }
    
    
    cout << max;
    
    
    /*
    for (auto& v: tets){
        int a[v.height][v.width];
        for (int i=0; i<v.height; ++i){
            for (int j=0; j<v.width; ++j){
                a[i][j]=0;
            }
        }
        
        for (auto& w: v.locs){
            a[w.row-1][w.col-1] = 1;
        }
        for (int i=0; i<v.height; ++i){
            for (int j=0; j<v.width; ++j){
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        cout << "height:" << v.height << " " << "width:" << v.width << endl;
        cout << "change shape" << endl;
    }
    */
    
}
