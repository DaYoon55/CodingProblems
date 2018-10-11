#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

vector<char> directions;
int N;

//move left. Other directions can be done with this by rotation.
void move(vector<int>& vec){
    
    int i;
    int cur = 0;
    vector<int> to_slide;
    
    //set first cur
    while (cur < N && vec.at(cur) == 0) ++cur;
    
    
    //v.at(cur) != -1 or cur == N
    if (cur == N) ;
    else{
        while (cur != N){
            //find find
            for (i= cur+1; i<N; ++i){
                if (vec.at(i) == 0) {
                    if (i == N-1) to_slide.push_back(vec.at(cur));
                }
                else {
                    //if not merge,
                    if (vec.at(i) != vec.at(cur)){
                        
                        if (vec.at(cur) != 0){
                            to_slide.push_back(vec.at(cur));
                        
                            //next_cur
                            cur = i;

                            //break
                            break;
                        }
                        else{
                            ++cur;
                            break;
                        }
                    }
                    //if merge
                    else{
                        to_slide.push_back(vec.at(cur) + vec.at(i));
                        
                        //next_cur
                        cur = i+1;
                        
                        break;
                        
                    }
                }
            }
            //if i == N
            if (i >= N) {
                if (cur == N-1) to_slide.push_back(vec.at(cur));
                break;
            }
        }
    }
    
    while (to_slide.size() != N) to_slide.push_back(0);
    vec = to_slide;
    
}

//lrud
void move(vector<vector<int> >& board, char direction){
    
    
    vector<int> rotate;
	
	if (direction == 'l'){
		for (auto& v:board){
            
            move(v);
            
		}
	}
	else if (direction == 'r'){
        for (auto& v:board){
            
            rotate.clear();
            for (int i=N-1; i > -1; --i) rotate.push_back(v.at(i));
            move(rotate);
            for (int i=N-1; i > -1; --i) v.at(N-1 - i) = rotate.at(i);
        }
	}
	else if (direction == 'u'){
        for (int col = 1; col < N+1; ++col){
            
            rotate.clear();
            for (int row=1; row < N+1; ++row) rotate.push_back(board[row-1][col-1]);
            move(rotate);
            for (int row=1; row < N+1; ++row) board[row-1][col-1] = rotate.at(row - 1);
        }
	}
    //d
    else{
        for (int col = 1; col < N+1; ++col){
            
            rotate.clear();
            for (int row=N; row > 0; --row) rotate.push_back(board[row-1][col-1]);
            move(rotate);
            for (int row=N; row > 0; --row) board[row-1][col-1] = rotate.at(N-row);
        }
    }

};

int max(vector<vector<int> >& board){
	int max = -1;
	for (auto& v:board){
		for (auto& w:v){
            
			if (max < w) max = w;
		}
	}
	return max;
}

int DFS(vector<vector<int> >& board, int depth){
    
    /*
    //print
    for (int j=0; j<N; ++j){
        for (int i=0; i<N; ++i){
            cout << board[j][i] << " ";
        }
        cout << endl;
    }
     */

	int output = -1;
	int temp;
	vector<vector<int> > board_copy;

	//if depth == 0
	if (depth == 0){
		output = max(board);
        
	}
	//else
	else {
		for (auto& v:directions){
            
            //cout << "direction: " << v << endl;
            
			board_copy = board;
			move(board_copy, v);
            
			temp = DFS(board_copy,depth-1);
            
			if (output < temp) output = temp;
		}
	}

	return output;
};

int main(){
    
    

	directions.push_back('l');
	directions.push_back('r');
	directions.push_back('u');
	directions.push_back('d');

    
    
	//take input
	cin >> N;

	vector<vector<int> > board;
	vector<int> temp;
	int int1;
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			cin >> int1;
			temp.push_back(int1);
		}
		board.push_back(temp);
		temp.clear();
	}

	cout << DFS(board, 5);
    
    
     
    /*
    N = 4;
    vector<int> temp;
    srand(time(NULL));
    vector<vector<int> > board;
    int int1;
    
    for (int j =0; j<N; ++j){
        temp.clear();
        for (int i=0; i<N; ++i){
            //temp.push_back(rand()%4);
            cin >> int1;
            temp.push_back(int1);
        }
        board.push_back(temp);
    }
    
    
    
    cout << DFS(board, 1);
    */
    
}
