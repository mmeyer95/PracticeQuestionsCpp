#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isUnique(string my_string) {
	bool uniqueness = true;
	for(int i = 0; i < my_string.size(); i++) {
		for(int j = i + 1; j < my_string.size(); j++) {
			if(my_string[i] == my_string[j]) {
				uniqueness = false;
				return uniqueness;
			}
		}
	}
	return uniqueness;
}

//initially assuming spaces will not be considered
bool isPermutation(string string_a, string string_b) {
	bool isPerm = false;
	if(string_a.size() != string_b.size()) {
		return isPerm;
	}
	vector<int> checked(sizeof(string_b),0);
	for(int i = 0; i < string_a.size(); i++) {
		for(int j = 0; i < string_b.size(); j++){
			if(string_a[i] == string_b[j] && checked[j] != 1) {
				checked[j] = 1;
				break;
			}
			else if (j == string_b.size()) {
				return isPerm;    //then it’s not a permutation
			}
		}
	}
	//check that all letters have been accounted for in the second string
	for (int i = 0; i < checked.size(); i++) {
		if (checked[i] != 1) {
			return isPerm;
		}
	}
	isPerm = true;
	return isPerm;
}



int main() {
	string string_a = "bazingo";
	bool result = isUnique(string_a);
	if (result == 1) {
		std::cout << "String '"<< string_a <<"' has all unique characters." << std::endl;
	}
	else {
		std::cout << "String '" << string_a << "' is NOT unique- contains repeating characters." << std::endl;
	}
	system("pause");

	string string_b = "nogo";
	result = isPermutation(string_a, string_b);
	if (result == 1) {
		std::cout << "'" << string_b << " is a permutation of '" << string_a << "'." << std::endl;
	}
	else {
		std::cout << "'" << string_b << "' is NOT a permutation of '" << string_a << "'." << std::endl;
	}

	system("pause");
	return 0;
}