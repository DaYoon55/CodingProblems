#include <iostream>
#include <vector>

using namespace std;

vector<char> directions;
//N row, M col
int N, M;
vector<vector <char> > board;
int min_num;

void display(vector<vector <char> >& b){
    for (auto& v:b){
        for (auto& w:v){
            cout << w ;
        }
        cout << endl;
    }
    
}

vector<vector <char> > tilt(vector<vector <char> >& board, char direction){
    
    int B_row = -1;
    int B_col = -1;
    int R_row = -1;
    int R_col = -1;
    bool B_found = false;
    bool R_found = false;
    vector<vector <char> > next_board = board;
    
    //find 'B' and 'R'
    for (int i=0; i<N; ++i){
        for (int j=0; j<M; ++j){
            if (board[i][j]=='R'){
                R_row = i+1;
                R_col = j+1;
                R_found = true;
            }
            else if (board[i][j]=='B'){
                B_row = i+1;
                B_col = j+1;
                B_found = true;
            }
            if (B_found && R_found) break;
        }
        if (B_found && R_found) break;
    }
    
    bool B_dead = false;
    bool R_dead = false;
    int B_row2=B_row;
    int B_col2=B_col;
    int R_row2=R_row;
    int R_col2=R_col;
    
    //find where 'B' and 'R' should go
    if (direction == 'l'){
        
        char to;
        //B move first
        if (B_col2 < R_col2){
            //B
            to = next_board[B_row2-1][B_col2-2];
            while(to != '#'){
                //if to == '.'
                if (to == '.') --B_col2;
                
                //if to == 'O'
                else if (to == 'O'){
                    --B_col2;
                    B_dead = true;
                    break;
                }
                to = next_board[B_row2-1][B_col2-2];
            }
            //update
            if (B_dead) next_board[B_row-1][B_col-1] = '.';
            else{
                next_board[B_row-1][B_col-1] = '.';
                next_board[B_row2-1][B_col2-1] = 'B';
            }
            
            //R
            to = next_board[R_row2 -1][R_col2 -2];
            while(to != '#'){
                //if to == '.'
                if (to == '.') --R_col2;
                
                //if to == 'O'
                else if (to == 'O'){
                    --R_col2;
                    R_dead = true;
                    break;
                }
                //if to == 'B'
                else{
                    break;
                }
                
                to = next_board[R_row2-1][R_col2-2];
            }
            
            //update
            if (R_dead) next_board[R_row -1][R_col -1] = '.';
            else{
                next_board[R_row-1][R_col-1] = '.';
                next_board[R_row2-1][R_col2-1] = 'R';
            }
            
        }
        //R move first
        else{
            //R
            to = next_board[R_row2-1][R_col2-2];
            while(to != '#'){
                //if to == '.'
                if (to == '.') --R_col2;
                
                //if to == 'O'
                else if (to == 'O'){
                    --R_col2;
                    R_dead = true;
                    break;
                }
                to = next_board[R_row2-1][R_col2-2];
            }
            //update
            if (R_dead) next_board[R_row -1][R_col -1] = '.';
            else{
                next_board[R_row-1][R_col-1] = '.';
                next_board[R_row2-1][R_col2-1] = 'R';
            }
            
            //B
            to = next_board[B_row2 -1][B_col2 -2];
            while(to != '#'){
                //if to == '.'
                if (to == '.') --B_col2;
                
                //if to == 'O'
                else if (to == 'O'){
                    --B_col2;
                    B_dead = true;
                    break;
                }
                //if to == 'R'
                else{
                    break;
                }
                
                to = next_board[B_row2-1][B_col2-2];
            }
            
            //update new_board
            if (B_dead) next_board[B_row-1][B_col-1] = '.';
            else{
                next_board[B_row-1][B_col-1] = '.';
                next_board[B_row2-1][B_col2-1] = 'B';
            }
            
        }
        
    }
    else if (direction == 'r'){
        char to;
        //B move first
        if (B_col2 > R_col2){
            //B
            to = next_board[B_row2-1][B_col2];
            while(to != '#'){
                //if to == '.'
                if (to == '.') ++B_col2;
                
                //if to == 'O'
                else if (to == 'O'){
                    ++B_col2;
                    B_dead = true;
                    break;
                }
                to = next_board[B_row2-1][B_col2];
            }
            
            //update new_board
            if (B_dead) next_board[B_row-1][B_col-1] = '.';
            else{
                next_board[B_row-1][B_col-1] = '.';
                next_board[B_row2-1][B_col2-1] = 'B';
            }
            
            //R
            to = next_board[R_row2 -1][R_col2];
            while(to != '#'){
                //if to == '.'
                if (to == '.') ++R_col2;
                
                //if to == 'O'
                else if (to == 'O'){
                    ++R_col2;
                    R_dead = true;
                    break;
                }
                //if to == 'B'
                else{
                    break;
                }
                
                to = next_board[R_row2-1][R_col2];
            }
            //update
            if (R_dead) next_board[R_row -1][R_col -1] = '.';
            else{
                
                next_board[R_row-1][R_col-1] = '.';
                next_board[R_row2-1][R_col2-1] = 'R';
                
            }
            
            
        }
        
        
        //R move first
        else{
            //R
            to = next_board[R_row2-1][R_col2];
            while(to != '#'){
                //if to == '.'
                if (to == '.') ++R_col2;
                
                //if to == 'O'
                else if (to == 'O'){
                    ++R_col2;
                    R_dead = true;
                    break;
                }
                to = next_board[R_row2-1][R_col2];
            }
            
            //update
            if (R_dead) next_board[R_row -1][R_col -1] = '.';
            else{
                next_board[R_row-1][R_col-1] = '.';
                next_board[R_row2-1][R_col2-1] = 'R';
            }
            
            //B
            to = next_board[B_row2 -1][B_col2];
            while(to != '#'){
                //if to == '.'
                if (to == '.') ++B_col2;
                
                //if to == 'O'
                else if (to == 'O'){
                    ++B_col2;
                    B_dead = true;
                    break;
                }
                //if to == 'R'
                else{
                    break;
                }
                
                to = next_board[B_row2-1][B_col2];
            }
         
        
            if (B_dead) next_board[B_row-1][B_col-1] = '.';
            else{
                next_board[B_row-1][B_col-1] = '.';
                next_board[B_row2-1][B_col2-1] = 'B';
            }
        }
        
        //update new_board
        
    }
    
    else if (direction == 'd'){
        
        char to;
        //B move first
        if (B_row2 > R_row2){
            //B
            to = next_board[B_row2][B_col2-1];
            while(to != '#'){
                //if to == '.'
                if (to == '.') ++B_row2;
                
                //if to == 'O'
                else if (to == 'O'){
                    ++B_row2;
                    B_dead = true;
                    break;
                }
                to = next_board[B_row2][B_col2-1];
            }
            //update new_board
            if (B_dead) next_board[B_row-1][B_col-1] = '.';
            else{
                next_board[B_row-1][B_col-1] = '.';
                next_board[B_row2-1][B_col2-1] = 'B';
            }
            
            //R
            to = next_board[R_row2][R_col2-1];
            while(to != '#'){
                //if to == '.'
                if (to == '.') ++R_row2;
                
                //if to == 'O'
                else if (to == 'O'){
                    ++R_row2;
                    R_dead = true;
                    break;
                }
                //if to == 'B'
                else{
                    break;
                }
                
                to = next_board[R_row2][R_col2-1];
            }
            
            //update
            if (R_dead) next_board[R_row -1][R_col -1] = '.';
            else{
                next_board[R_row-1][R_col-1] = '.';
                next_board[R_row2-1][R_col2-1] = 'R';
            }
            
            
        }
        //R move first
        else{
            //R
            to = next_board[R_row2][R_col2-1];
            while(to != '#'){
                //if to == '.'
                if (to == '.') ++R_row2;
                
                //if to == 'O'
                else if (to == 'O'){
                    ++R_row2;
                    R_dead = true;
                    break;
                }
                to = next_board[R_row2][R_col2-1];
            }
            //update
            if (R_dead) next_board[R_row -1][R_col -1] = '.';
            else{
                next_board[R_row-1][R_col-1] = '.';
                next_board[R_row2-1][R_col2-1] = 'R';
            }
            
            //B
            to = next_board[B_row2][B_col2-1];
            while(to != '#'){
                //if to == '.'
                if (to == '.') ++B_row2;
                
                //if to == 'O'
                else if (to == 'O'){
                    ++B_row2;
                    B_dead = true;
                    break;
                }
                //if to == 'R'
                else{
                    break;
                }
                
                to = next_board[B_row2][B_col2-1];
            }
            
            //update new_board
            if (B_dead) next_board[B_row-1][B_col-1] = '.';
            else{
                next_board[B_row-1][B_col-1] = '.';
                next_board[B_row2-1][B_col2-1] = 'B';
            }
            
        }
        
        
        
    }
    // 'u'
    else{
        
        
        char to;
        //B move first
        if (B_row2 < R_row2){
            //B
            to = next_board[B_row2-2][B_col2-1];
            while(to != '#'){
                //if to == '.'
                if (to == '.') --B_row2;
                
                //if to == 'O'
                else if (to == 'O'){
                    --B_row2;
                    B_dead = true;
                    break;
                }
                to = next_board[B_row2-2][B_col2-1];
            }
            //update new_board
            if (B_dead) next_board[B_row-1][B_col-1] = '.';
            else{
                next_board[B_row-1][B_col-1] = '.';
                next_board[B_row2-1][B_col2-1] = 'B';
            }
            
            //R
            to = next_board[R_row2-2][R_col2-1];
            while(to != '#'){
                //if to == '.'
                if (to == '.') --R_row2;
                
                //if to == 'O'
                else if (to == 'O'){
                    --R_row2;
                    R_dead = true;
                    break;
                }
                //if to == 'B'
                else{
                    break;
                }
                
                to = next_board[R_row2-2][R_col2-1];
            }
            //update
            if (R_dead) next_board[R_row -1][R_col -1] = '.';
            else{
                next_board[R_row-1][R_col-1] = '.';
                next_board[R_row2-1][R_col2-1] = 'R';
            }
            
            
        }
        //R move first
        else{
            //R
            to = next_board[R_row2-2][R_col2-1];
            while(to != '#'){
                //if to == '.'
                if (to == '.') --R_row2;
                
                //if to == 'O'
                else if (to == 'O'){
                    --R_row2;
                    R_dead = true;
                    break;
                }
                to = next_board[R_row2-2][R_col2-1];
            }
            //update
            if (R_dead) next_board[R_row -1][R_col -1] = '.';
            else{
                next_board[R_row-1][R_col-1] = '.';
                next_board[R_row2-1][R_col2-1] = 'R';
            }
            
            //B
            to = next_board[B_row2-2][B_col2-1];
            while(to != '#'){
                //if to == '.'
                if (to == '.') --B_row2;
                
                //if to == 'O'
                else if (to == 'O'){
                    --B_row2;
                    B_dead = true;
                    break;
                }
                //if to == 'R'
                else{
                    break;
                }
                
                to = next_board[B_row2-2][B_col2-1];
            }
            
            //update new_board
            if (B_dead) next_board[B_row-1][B_col-1] = '.';
            else{
                next_board[B_row-1][B_col-1] = '.';
                next_board[B_row2-1][B_col2-1] = 'B';
            }
            
        }
        
    }
    
    return next_board;
    
};

void finished(vector<vector <char> >& board, bool& fin, bool& good_fin){
    
    bool is_R = false;
    bool is_B = false;
    
    for (auto& v: board){
        for (auto& w: v){
            if (w=='R') is_R = true;
            else if (w=='B') is_B = true;
        }
    }
    //if there is no R or no B, fin = true
    if (!is_R || !is_B){
        fin = true;
        //if there is no R but B, good_fin = true
        //else, good_fin = false
        if (!is_R && is_B) good_fin = true;
        else good_fin = false;
    }
    //else: fin = false
    else{
        fin = false;
        //good_fin = false
        good_fin = false;
        
    }
};

//dfs stops as soon as going further than the latest minimum
bool dfs(vector<vector <char> >& board, int remaining, int cur_height = 0){
    
    bool output = false;
    bool fin = false;
    bool good_fin = false;
    finished(board, fin, good_fin);
    
    if (fin || remaining == 0){
        if (good_fin){
            
            //display(board);
            
            if (cur_height < min_num){
                min_num = cur_height;
                output = true;
            }
        }
        else ;
        
    }
    else{
        vector<vector <char> > next_board;
        
        for (auto& v:directions){
            next_board = tilt(board, v);
            
            if (next_board != board){
                
                output = dfs(next_board, remaining -1, cur_height +1);
                
                //if (output == true) break;
                
            }
        }
    }
    
    return output;
};

int main(){
    
    directions.push_back('l');
    directions.push_back('r');
    directions.push_back('u');
    directions.push_back('d');
    min_num = 11;
    
    vector<char> temp;
    char char1;
    
    cin >> N >> M;
    
    for (int i=0; i<N; ++i){
        temp.clear();
        for (int j=0; j<M; ++j){
            cin >> char1;
            temp.push_back(char1);
        }
        board.push_back(temp);
    }
    
    
    dfs(board, 10);
    
    
    if (min_num == 11) cout << -1;
    else cout << min_num;
    
    /*
    char control;
    while (true){
        cin >> control;
        board = tilt(board, control);
        display(board);
    }
     */

}

