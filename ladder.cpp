#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct step{
    int row;
    int col;
    
    step(int row, int col){
        this->row = row;
        this->col = col;
    }
    
    step operator=(step step1){
        row = step1.row;
        col = step1.col;
        return *this;
    }
    
    bool operator==(step step1){
        return (this->row == step1.row && this->col == step1.col);
    }
};

step next_step(step step1, int N, int H){
    step next_step(0,0);
    //if step1.col = N-1
    if (step1.col == N-1){
        //if step1.row = H
        if (step1.row == H){
            //last step is {0,0}
            next_step.row =0;
            next_step.col =0;
        }
        //else
        else{
            next_step.row = step1.row +1;
            next_step.col = 1;
        }
    }
    //if step1.col != N-1
    else{
        next_step.row = step1.row;
        next_step.col = step1.col +1;
    }
    return next_step;
};


class ladder{
    int N, H;
    vector<vector<bool> > steps;
    
public:
    ladder(int N, int H, vector<vector<bool> > steps){
        this->H = H;
        this->N = N;
        this->steps = steps;
    };
    
    bool run(){
        bool output = true;
        int runner[2] = {0,0};
        for (int col=1; col<N+1; ++col){
            runner[0] = 1;
            runner[1] = col;
            while (runner[0] != H+1){
                //if runner[1] = 1
                if (runner[1]==1){
                    if (steps[runner[0]-1][runner[1]-1] == true){
                        runner[0] += 1;
                        runner[1] += 1;
                    }
                    else runner[0] +=1;
                }
                //if runner[1] = N
                else if (runner[1]==N){
                    if (steps[runner[0]-1][runner[1]-2] == true){
                        runner[0] += 1;
                        runner[1] -= 1;
                    }
                    else runner[0] += 1;
                }
                else{
                    if (steps[runner[0]-1][runner[1]-1] == true){
                        runner[0] += 1;
                        runner[1] += 1;
                    }
                    else if (steps[runner[0]-1][runner[1]-2] == true){
                        runner[0] += 1;
                        runner[1] -= 1;
                    }
                    else runner[0] += 1;
                }
            }
            if (runner[1]!=col){
                output = false;
                break;
            }
        }
        return output;
    };
    
    bool legal_step(step step1){
        bool output = false;
        //if already on ladder
        if (steps[step1.row-1][step1.col-1] == true) ;
        //if not check if illegal
        else {
            //if step1.col ==1
            if (step1.col == 1){
                if (steps[step1.row-1][step1.col] == true) ;
                else output = true;
            }
            //if step1.col == N-1
            else if (step1.col == N-1){
                if (steps[step1.row-1][step1.col-2] == true) ;
                else output = true;
            }
            //else
            else{
                if (steps[step1.row-1][step1.col] == true || steps[step1.row-1][step1.col-2] == true) ;
                else output = true;
            }
        }
        
        return output;
    };
    
    bool add_steps(vector<step> step1){
        bool output = true;
        for (int i=0;i < step1.size(); ++i){
            if (legal_step(step1.at(i))) steps[step1.at(i).row-1][step1.at(i).col-1] = true;
            //remove added steps
            else {
                output = false;
                for (int j=0; j < i; ++j) steps[step1.at(j).row-1][step1.at(j).col-1] = false;
                
                break;
            }
        }
        return output;
        
    }
    
    bool add_steps(step step1){
        vector<step> steps;
        steps.push_back(step1);
        return add_steps(steps);
    }
    
    void remove_steps(vector<step> step1){
        for (auto& v: step1) steps[v.row-1][v.col-1] = false;
    }
    
    void remove_steps(step step1){
        vector<step> steps;
        steps.push_back(step1);
        remove_steps(steps);
    }
    
    
    bool DFS(vector<step>& steps, int depth, step latest_step=step(0,0)){
        bool output = false;
        
        if (depth==0){
            
            if (add_steps(steps)) {
                output = run();
                remove_steps(steps);
            }
            
        }
        else if (depth>0){
            if (steps.size() == 0){
                
                for (step cur_step = step(1,1); !(cur_step==step(0,0)); cur_step = next_step(cur_step,N,H)){
                    steps.push_back(cur_step);
                    output = DFS(steps, depth-1, cur_step);
                    steps.pop_back();
                    if (output) break;
                }
            }
            else{
                for (step cur_step = next_step(latest_step,N,H); !(cur_step == step(0,0)); cur_step = next_step(cur_step,N,H)){
                    steps.push_back(cur_step);
                    output = DFS(steps, depth-1, cur_step);
                    steps.pop_back();
                    if (output) break;
                    
                }
                
            }
        }
        else ;
        
        
        return output;
    }
    
    int find_the_ladder(){
        bool found = false;
        int depth;
        vector<step> steps;
        
        //run
        for (depth = 0; depth<4 && found == false; depth++){
            
            found = DFS(steps, depth);
        }
        --depth;
        
        if (!found) depth = -1;
        
        return depth;
    }
};

int main(){
    
    //get N,M,H
    int N,M,H;
    cin >> N >> M >> H;
    
    //make double vector
    vector<vector<bool> > steps;
    vector<bool> temp;
    
    for (int i=0; i<N-1; ++i) temp.push_back(false);
    
    for (int i=0; i<H; ++i) steps.push_back(temp);
    
    //get steps
    
    int step[2];
    
    for (int i=0; i<M; ++i){
        cin >> step[0] >> step[1];
        steps[step[0]-1][step[1]-1] = true;
    }
    
    //make ladder
    
    ladder my_ladder(N,H,steps);
    
    cout << my_ladder.find_the_ladder();
}

