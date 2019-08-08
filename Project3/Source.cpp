#include <iostream>
#include <string>
#include <vector>

using namespace std;

int question = 14;

//1.1 Is Unique
bool isUnique(string my_string) {
	bool uniqueness = true;
	for (int i = 0; i < my_string.size(); i++) {
		for (int j = i + 1; j < my_string.size(); j++) {
			if (my_string[i] == my_string[j]) {
				uniqueness = false;
				return uniqueness;
			}
		}
	}
	return uniqueness;
}

//1.2 Check Permutation
bool isPermutation(string string_a, string string_b) {
	bool isPerm = false;
	if (string_a.size() != string_b.size()) {
		return isPerm;
	}
	vector<int> checked(sizeof(string_b), 0);
	for (int i = 0; i < string_a.size(); i++) {
		for (int j = 0; i < string_b.size(); j++) {
			if (string_a[i] == string_b[j] && checked[j] != 1) {
				checked[j] = 1;
				break;
			}
			else if (j == string_b.size()) {
				return isPerm;    //then it�s not a permutation
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

//1.3 URLify
string URLify(string my_string) {
	string new_string;
	for (int i = 0; i < my_string.size(); i++) {
		if (my_string[i] == ' ') {
			new_string += "%20";
		}
		else {
			new_string += my_string[i];
		}
	}
	return new_string;
}

//1.4 Palindrome permutation
bool palinPerm(string my_string) {
	bool result = false;
	vector<int> checked(my_string.size(), 0);
	int odd = 0;
	//a word is a permutation of a palindrome if every letter is present in even numbers except at most 1
	for (int i = 0; i < my_string.size(); i++) {
		if(checked[i] == 1) {
			continue;
		}
		else {
			int count = 1;
			checked[i] = 1;
			for (int j = i + 1; j < my_string.size(); j++) {
				if (checked[j] == 1) {
					break;
				}
				else if (my_string[i] == my_string[j]) {
					count += 1;
					checked[j] = 1;
					cout << "Found occurence of letter: " << my_string[i] << ". Count at: " << count << endl;
				}
			}
			if (count % 2) {
				cout << "Odd number occurrence of letter: " << my_string[i] << endl;
				odd += 1;
				if (odd > 1) {
					return result;
				}
			}
		}
	}
	result = true;
	return result;
}



int main() {
	bool result;
	string string_a = "bazingo";
	string string_b = "nogo";
	string stringy = "Hello my name is Meredith.";
	string stringyy = "racecar";

	switch(question) {
	case 11:
		//1.1 test
		result = isUnique(string_a);
		if (result == 1) {
			std::cout << "String '" << string_a << "' has all unique characters." << std::endl;
		}
		else {
			std::cout << "String '" << string_a << "' is NOT unique- contains repeating characters." << std::endl;
		}

	case 12:
		//1.2 test
		result = isPermutation(string_a, string_b);
		if (result == 1) {
			std::cout << "'" << string_b << " is a permutation of '" << string_a << "'." << std::endl;
		}
		else {
			std::cout << "'" << string_b << "' is NOT a permutation of '" << string_a << "'." << std::endl;
		}

	case 13:
		//1.3 test
		cout << URLify(stringy) << endl;

	case 14:
		//1.4 test
		cout << palinPerm(stringyy) << endl;
	}
	
	system("pause");
	return 0;
}