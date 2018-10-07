#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> split(string& input);

struct turn{
	int time;
	string turn;
};

struct node{
	int x;
	int y;
};

class snake{

public:
	vector<node> body;
	string direction;

	snake(){
		node head = {1,1};
		this->body.push_back(head);
		this->direction = "E";
	};

	bool update(vector<string>& apples, vector<turn>& turns, int time, int N){

		int head_x = (this->body.end() -1)->x;
		int head_y = (this->body.end() -1)->y;
		
		//move forward
		if (direction == "E"){
			node new_head={head_x,head_y+1};
			this->body.push_back(new_head);
		}
		else if (direction == "S"){
			node new_head={head_x+1,head_y};
			this->body.push_back(new_head);
		}
		else if (direction == "W"){
			node new_head={head_x,head_y-1};
			this->body.push_back(new_head);
		}
		else{
			node new_head={head_x-1,head_y};
			this->body.push_back(new_head);
		}

		//check if hit itself
		bool hit = alive(N);
		if (hit == false) return hit;

		//check if hit apple and move the body
		string head_location;
		head_location += to_string((this->body.end() -1)->x);
		head_location += " ";
		head_location += to_string((this->body.end() -1)->y);
		
		std::vector<string>::iterator it = find(apples.begin(),apples.end(), head_location);	
		
		//didn't hit apple
		if (it == apples.end()){
			this->body.erase(this->body.begin());
		}
		//hit apple
		else{
			//apples.erase(it) causes seg fault.
			apples.erase(it);
		}

		//check turns and set direction
		for (auto& v: turns){
			if (v.time > time) break;
			if (v.time == time){
				//if D
				if (v.turn == "D"){
					if (this->direction == "E") this->direction = "S";
					else if (this->direction == "S") this->direction = "W";
					else if (this->direction == "W") this->direction = "N";
					else this->direction = "E";
				}
				//if L
				if (v.turn == "L"){
					if (this->direction == "E") this->direction = "N";
					else if (this->direction == "S") this->direction ="E";
					else if (this->direction == "W") this->direction ="S";
					else this->direction = "W";
				}
			}
			
		}
		return true;

	};

	bool alive(int N){
		
		bool alive = true;
		bool hit = false;
		vector<node>::iterator it = this->body.begin();
		node head = *(this->body.end() -1);
		//if hit body
		for (;it < this->body.end()-1; ++it){
			if (head.x == it->x && head.y == it->y){
				hit = true;
				break;
			}
		}
		//if out of board
		if (hit == false){
			if (head.x > N || head.x < 1 || head.y > N || head.y < 1) hit = true;
		}

		if (hit == true) alive = false;

		return alive;
	};
};

int main(){

	int time = 1;
	snake Dummy;

	//take input
	int N, K, L;
	vector<string> apples;
	vector<turn> turns;
	string input;
	getline(cin, input);
	N = stoi(input);
	getline(cin, input);
	K = stoi(input);
	for (int i=0; i<K; ++i) {
		getline(cin,input);
		apples.push_back(input);
	}
	getline(cin, input);
	L = stoi(input);
	vector<string> temp_string;
	for (int i=0; i<L; ++i){
		getline(cin,input);
		temp_string = split(input);
		turn temp_turn ={stoi(temp_string.at(0)), temp_string.at(1)};
		turns.push_back(temp_turn);
	}

	
	while (Dummy.update(apples, turns, time, N)){
	
		++time;

	}

	cout << time;

}

vector<string> split(string& input){
	int ind = input.find(" ");
	vector<string> output;
	output.push_back(input.substr(0,ind));
	output.push_back(input.substr(ind+1));
	return output;

}

