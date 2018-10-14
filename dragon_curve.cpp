#include <iostream>
#include <vector>

using  namespace std;

struct dragon_curve;
struct location;

int N;
vector<dragon_curve> curves;
//misprint on problem
int lattice[101][101];
vector<location> temp_curve;

struct location{
    
    int x;
    int y;
    
    location(){
        this->x = 0;
        this->y = 0;
    }
    
    location(int x, int y){
        this->x = x;
        this->y = y;
    }
    
    location operator=(location loc){
        this->x = loc.x;
        this->y = loc.y;
        
        return *this;
    }
    
    bool operator==(location loc){
        return (this->x == loc.x && this->y == loc.y);
    }
};

//last loc should've been transltated to 0
void rotate(vector<location>& locs){
    //e(-ipi/2) = cos(pi/2) -isin(pi/2) = -i; (x+iy)(-i) = y-ix
    int temp;
    for (auto& v: locs){
        temp = v.x;
        v.x = -v.y;
        v.y = temp;
    }
};

void translate(vector<location>& locs, int x_inc, int y_inc){
    
    for (auto& v: locs){
        v.x += x_inc;
        v.y += y_inc;
    }
};

struct dragon_curve {
    
    int g;
    vector<location> locs;
    
    dragon_curve(int x, int y, int d, int g){
        location loc1 = location(x,y);
        location loc2 = loc1;
        
        if(d == 0){
            ++loc2.x;
        }
        else if(d == 1){
            --loc2.y;
        }
        else if(d == 2){
            --loc2.x;
        }
        else{
            ++loc2.y;
        }
        
        locs.push_back(loc1);
        locs.push_back(loc2);
        
        evolve(g);
    }
    
    void evolve(int g){
        
        //cout << "evolve:" << g << endl;
        //for (auto& v: locs) cout << v.x << " " << v.y << endl;
        
        if (g == 0) ;
        else{
            //elongate
            location end = *(this->locs.end() -1);
            temp_curve.clear();
            temp_curve = this->locs;
            translate(temp_curve, -end.x, -end.y);
            rotate(temp_curve);
            translate(temp_curve, end.x, end.y);
            
            //for (auto& v: temp_curve) this->locs.push_back(v);
            for (vector<location>::iterator it = temp_curve.end() -1; it >= temp_curve.begin(); --it) locs.push_back(*it);
            
            evolve(g-1);
            
        }
        
    }
    
};

int main(){
    
    for (int i=0; i< 101; ++i){
        for (int j=0; j< 101; ++j) lattice[i][j] = 0;
    }
    
    
    int x, y, d, g;
    location loc;
    
    cin >> N;
    
    for (int i=0; i<N; ++i){
     
        cin >> x >> y >> d >> g;
        dragon_curve temp = dragon_curve(x,y,d,g);
        curves.push_back(temp);
        
    }
    
    
    
    
    for (auto& v:curves){
        for (auto& w: v.locs) {
            
            if (0 <= w.x && w.x <= 100 && 0 <= w.y && w.y <= 100)
                lattice[w.x][w.y] = 1;
            //cout << w.x << " " << w.y << endl;
        }
    }
    
    
    
    int ans = 0;
    
    
    for (int i=0; i< 100; ++i){
        for (int j=0; j< 100; ++j){
            if (lattice[i][j] == 1 && lattice[i][j+1] == 1 && lattice[i+1][j] == 1 && lattice[i+1][j+1] == 1) ++ans;
        }
    }
     
    
    cout << ans;
    
}


/*
 0: x좌표가 증가하는 방향 (→)
 1: y좌표가 감소하는 방향 (↑)
 2: x좌표가 감소하는 방향 (←)
 3: y좌표가 증가하는 방향 (↓)
 */
