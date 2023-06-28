#include<iostream>
#include<vector>

using namespace std;

char getSymbol(string text);
int main() {
	//string text = "The Tao gave birth to machine language. Machine language gave birth to the assembler. The assembler gave birth to the compiler. Now there are ten thousand languages. Each language has its purpose, however humble. Each language expresses the Yinand Yang of software. Each language has its place within the Tao. But do not program in COBOL if you can avoid it. --Geoffrey James, \"The Tao of Programming\" ";
	string text = "C makes it easy for you to shoot yourself in the foot. C++ makes that harder, but when you do, it blows away your whole leg. (ñ) Bjarne Stroustrup";
	string word = "";
	vector<string> words;
	vector<char> letters;
	int n = text.size();
	for (int i = 0; i < n; i++) {
		if (text[i] != ' ') {
			word += text[i];
		}
		else {
			words.push_back(word);
			word.clear();
		}
	}
	for (auto word : words) {
		letters.push_back(getSymbol(word));
	}
	string symbols(letters.begin(), letters.end());
	cout << getSymbol(symbols);


	return 0;
}
char getSymbol(string testWord) {
	char outChar = '0';
	bool unique = true;
	int n = testWord.size();
	for (int i = 0; i < n; i++) {
		for (int s = i + 1; s < (n); s++) {
			if (testWord[i] == testWord[s]) {
				unique = false;
				break;
			}
		}
		if (unique) {
			outChar = testWord[i];
			break;
		}
		unique = true;
	}
	return outChar;
}