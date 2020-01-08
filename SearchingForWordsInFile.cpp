#include <iostream>
#include<fstream>
#include <string>
#include <vector>
#include <algorithm> 
#include <ctype.h>
#include <iomanip>

using namespace std;

/*Helper method that compare two strings
*@param a is a string
@param b is a string
@return string that is greater
*/
bool compareString(string a, string b){
	return a < b;
}

/*Removes punctuation from given vector
*@param vec is a vector that contains punctuation
*/
void erasingPunctuation(vector<string> &vec){
	for (int i = 0; i < vec.size(); i++){
		for (int j = 0, length = vec[i].size(); j < length; j++){
			if (ispunct(vec[i][j])){
				vec[i].erase(vec[i].begin() + j);
				j--;
				length = vec[i].size();
			}
		}
	}

}

/*Replaces the uppercase letters with lovwercase letters
*@param vec is a vector that contains uppercase letters
*/
void convertingUppercaseLettersToLowercase(vector<string> &vec) {
	for (int i = 0; i < vec.size(); i++){
		for (int j = 0, length = vec[i].size(); j < length; j++){
			if (vec[i][j] >= 65 && vec[i][j] <=90){
				vec[i][j] = vec[i][j] + 32;
			}
		}
	}
}

/*Finds in which line/row word appeares and prints the number of that line/row 
*number of rows/lines starts with 1
*@param words is a vector that contains words from the file
*@param rows is a vector that contains lines of text
*/
void wordIsInFollowingRows(vector<string> words, vector<string> rows){

	cout << left << setw(20) << "word: " << "found in lines:" << endl;

	for (int i = 0; i < words.size(); i++){	

		cout << words[i] + " : ";

		for (int j = 0; j < rows.size(); j++){
			size_t found = rows[j].find(" " + words[i]+ " ");

			if (found != string::npos)
				cout << j + 1 << " ";

		}
		cout << endl;
	}

}

int main(){
	ifstream myFile("project.txt");
	ifstream copyFile("project.txt");
	string word;
	string line;
	vector<string> listWords;
	vector<string> listLines;

	if (myFile.is_open()){

		while (myFile >> word){
			listWords.push_back(word); //storing words from the file project.txt into vector
		}

	
		erasingPunctuation(listWords); 

		convertingUppercaseLettersToLowercase(listWords); 

		sort(listWords.begin(), listWords.end(), compareString); //sorting words alphabetically

		listWords.erase(unique(listWords.begin(), listWords.end()), listWords.end()); //erasing duplicate words

	}
	else{
		cout << "File is not opened." << endl;
	}

	if (copyFile.is_open()){

		while (getline(copyFile, line)){
			listLines.push_back(" " + line + " "); //storing lines of text from the file project.txt into vector and adding spaces at the beginning and end of the line
		}

		erasingPunctuation(listLines); 

		convertingUppercaseLettersToLowercase(listLines);


	}
	else{     
		cout << "File is not opened." << endl;
	}

	
	wordIsInFollowingRows(listWords, listLines);

	copyFile.close();
	myFile.close();
	return 0;
}



