#include <iostream>
#include <vector>

using namespace std;

int num_ways(string input_st, vector<string> &nums, vector<int> &memo);
bool bad_char(string input_st);
vector<string> get_next_nodes(string input_st, vector<string> &nums);

int main(){
	string input_st;
	int ans=0;
	vector<string> nums;
	vector<int> memo;

	getline(cin,input_st);

	if (bad_char(input_st)) ans = 0;
	else{

		for (int i=1; i<27; ++i){
			nums.push_back(to_string(i));
		}
		
		memo.push_back(1);
		for (int i=0; i<input_st.size(); ++i){
			memo.push_back(-1);
		}
	
		ans = num_ways(input_st, nums, memo);
	}
	cout << ans << endl;
	return 0;
}

bool bad_char(string input_st){
	bool bad_char = true;

	for (int i=0; i<input_st.size(); ++i){
		bad_char = true;
		for (int j=0; j<10; ++j){
			if (input_st.at(i) == to_string(j).at(0)){
				if (j==0){
					if (i==0) ;
					else if (input_st.at(i-1) == '1' || input_st.at(i-1) == '2') bad_char = false;
				}
				else{
					bad_char = false;
				}
			}
		}
		if (bad_char){
			break;
		}
	}

	return bad_char;
}

int num_ways(string input_st, vector<string> &nums, vector<int> &memo){

	int ans = 0;
	//if memoed before
	if (memo.at(input_st.size()) != -1) ans += memo.at(input_st.size());
	//get next nodes (context sensitive)
	else{
		vector<string> next_nodes = get_next_nodes(input_st, nums);

		//call next nodes
		for (auto& node: next_nodes){
			//if memoed before
			if (memo.at(node.size()) != -1) ans += memo.at(node.size());
			else{
				memo.at(node.size()) = num_ways(node, nums, memo);
				ans += memo.at(node.size());
			}
		}
	}

	return ans;
}

vector<string> get_next_nodes(string input_st, vector<string> &nums){

	vector<string> output;
	if (input_st.substr(0,2) != "10" && input_st.substr(0,2) != "20")
		output.push_back(input_st.substr(1));

	if (input_st.size() != 1){	
		bool find = false;
		for (int i=0; i<nums.size(); ++i){
			if (input_st.substr(0,2) == nums.at(i)){
				find = true;
				break;
			}
		}
		if (find == true) output.push_back(input_st.substr(2));
	}

	return output;
}

