#include <iostream>
#include <vector>

using namespace std;

void num_ways(string input_st, vector<string> &nums, int &ans);
void make_nums(vector<string> &nums);

int main(){
	string input_st;
	int ans=0;
	
	vector<string> nums;
	make_nums(nums);

	getline(cin,input_st);	

	num_ways(input_st, nums, ans);
	cout << ans;
}

void make_nums(vector<string> &nums){
	for (int i=1; i<27; ++i){
		nums.push_back(to_string(i));
	}
}

//recursive
void num_ways(string input_st, vector<string> &nums, int &ans){
	int found = false;
	
	//if input_st.len() == 1 or 0: base case
	if (input_st.size() == 0)
		ans += 1;
	else{
		for(const auto& v:nums){
			//comparison at head
			found = true;
			int v_size = v.size();
			for (int i=0; i<v_size; ++i){
				if (input_st[i] != v[i]){
					found = false;
					break;
				}
			}
			//yes
			if (found == true){
				num_ways(input_st.substr(v_size), nums, ans);
			}
			//no
			else{
			}
		}
	}
	
	}
