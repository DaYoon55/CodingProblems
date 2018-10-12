#include <iostream>

using namespace std;

bool is_pal(string::iterator begin, string::iterator end){

	bool output = false;
	if (begin == end) output = true;
	else{
		if (*begin == *end) {
			if (begin+1 <= end-1) output = is_pal(begin+1, end-1);
			else output = true;
		}
		else output = false;
	}
	return output;
}

int main(){

	string homie;
	cin >> homie;

	cout << is_pal(homie.begin(), homie.end()-1) << endl;

}
