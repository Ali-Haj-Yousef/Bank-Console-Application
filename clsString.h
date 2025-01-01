#pragma once
#include<iostream>
#include<vector>
using namespace std;

class clsString{
	string _value;

	public:
		clsString(string value){
			_value = value;
		}

		void print(){
			cout << _value;
		}

		static short length(string str){
			return str.length();
		}

		short length(){
			return length(_value);
		}

		static short countSpecificLetter(char c, string str, bool caseSensitive){
			short counter = 0;
			for(short i = 0; i < str.length(); i++){
				if(caseSensitive && str[i] == c)
					counter++;
				else if(!caseSensitive && tolower(str[i]) == tolower(c))
					counter++;
			}
			return counter;
		}

		short countSpecificLetter(char c, bool caseSensitivity){
			return countSpecificLetter(c, _value, caseSensitivity);
		}

		static short countLetters(string str){
			short counter = 0;
			for(short i = 0; i < str.length(); i++)
				if(isalpha(str[i]))
					counter++;
			return counter;
		}

		short countLetters(){
			return countLetters(_value);
		}

		static short countCapitalLetters(string str){
			short counter = 0;
			for(short i = 0; i < str.length(); i++){
				if(isalpha(str[i]) && isupper(str[i]))
					counter++;
			}
			return counter;
		}

		short countCapitalLetters(){
			return countCapitalLetters(_value);
		}

		static short countSmallLetters(string str){
			short counter = 0;
			for(short i = 0; i < str.length(); i++){
				if(isalpha(str[i]) && islower(str[i]))
					counter++;
			}
			return counter;
		}

		short countSmallLetters(){
			return countSmallLetters(_value);
		}

		static void printFirstLetters(string str){
			cout << "First Letters of this string:\n";
			for(short i = 0; i < str.length(); i++)
				if(i == 0)
					cout << str[i] << endl;
				else if(str[i] == ' ' && i != str.length() - 1)
					cout << str[i + 1] << endl;
		}

		void printFirstLetters(){
			printFirstLetters(_value);
		}

		static short countStringWords(string str){
			string word;
			short pos, counter = 0;
			while((pos = str.find(" ")) != std::string::npos){
				word = str.substr(0, pos);
				if(word != "")
					counter++;
				str.erase(0, pos + 1);
			}
			if(str != "")
				counter++;
			return counter;
		}

		short countStringWords(){
			return countStringWords(_value);
		}

		static void printStringWords(string str){
			string word;
			short pos;
			cout << "Your string words are:\n\n";
			while((pos = str.find(" ")) != std::string::npos){
				word = str.substr(0, pos);
				if(word != "")
					cout << word << endl;
				str.erase(0, pos + 1);
			}
			if(str != "")
				cout << str;
		}

		void printStringWords(){
			printStringWords(_value);
		}

		static vector<string> splitString(string str, string delim){
			vector<string> vString;
			string word;
			short pos;
			while((pos = str.find(delim)) != std::string::npos){
				word = str.substr(0, pos);
				if(word != "")
					vString.push_back(word);
				str.erase(0, pos + delim.length());
			}
			if(str != "")
				vString.push_back(str);
			return vString;
		}

		vector<string> splitString(string delim){
			return splitString(_value, delim);
		}

		static string joinString(vector<string> &stringsVector, string delim){
			string str;
			for(string& token : stringsVector)
				str += token + delim;
			str = str.substr(0, str.length() - delim.length());
			return str;
		}

		static string removePunctuations(string str){
			vector<string> stringVector = splitString(str, " ");
			for(string& word : stringVector)
				if(ispunct(word[word.length() - 1]))
					word = word.substr(0, word.length() - 1);
			return joinString(stringVector, " ");
		}

		string removePunctuations(){
			return removePunctuations(_value);
		}

		static string toUpper(string str){
			for(short i = 0; i < str.length(); i++)
				str[i] = toupper(str[i]);
			return str;
		}

		string toUpper(){
			return toUpper(_value);
		}

		static string toLower(string str){
			for(short i = 0; i < str.length(); i++)
				str[i] = tolower(str[i]);
			return str;
		}

		string toLower(){
			return toLower(_value);
		}

		static string replaceWord(string originalString, string word, string newWord, string delim, bool caseSensitivity){
			string newString;
			if(!caseSensitivity){
				newString = toLower(originalString);
				word = toLower(word);
			}
			else
				newString = originalString;
			short pos = newString.find(word);
			while(pos != std::string::npos){
				newString.replace(pos, word.length(), newWord);
				pos = newString.find(word);
			}
			if(!caseSensitivity){
				vector<string> originalStringVector = splitString(originalString, delim);
				vector<string> newStringVector = splitString(newString, delim);
				vector<string> wordVector = splitString(word, delim);
				vector<string> newWordVector = splitString(newWord, delim);
				short i = 0, j = 0;
				while(i < originalStringVector.size()){
					if(toLower(originalStringVector[i]) == newStringVector[j]){
						newStringVector[j] = originalStringVector[i];
						i++;
						j++;
					}
					else{
						i += wordVector.size();
						j += newWordVector.size();
					}
				}
				newString = joinString(newStringVector, delim);
			}
			return newString;
		}

		string replaceWord(string originalWord, string newWord, bool caseSensitivity){
			return replaceWord(_value, originalWord, newWord, " ", caseSensitivity);
		}

		static string reverseWords(string str, string delim){
			string revString;
			vector<string> stringVector = splitString(str, delim);
			for(short i = stringVector.size() - 1; i > -1; i--)
				revString += stringVector[i] + delim;
			revString = revString.substr(0, revString.length() - delim.length());
			return revString;
		}

		string reverseWords(){
			return reverseWords(_value, " ");
		}

		static string trimLeft(string str){
			short leftPointer = 0;
			while(str[leftPointer] == ' ')
				leftPointer++;
			str = str.erase(0, leftPointer);
			return str;
		}

		string trimLeft(){
			return trimLeft(_value);
		}

		static string trimRight(string str){
			short rightPointer = str.length() - 1;
			while(str[rightPointer] == ' ')
				rightPointer--;
			str = str.erase(rightPointer + 1, str.length());
			return str;
		}

		string trimRight(){
			return trimRight(_value);
		}

		static string trim(string str){
			return trimRight(trimLeft(str));
		}

		string trim(){
			return trim(_value);
		}

		static string upperFirstLetters(string str){
			for(short i = 0; i < str.length(); i++)
				if(i == 0)
					str[i] = toupper(str[i]);
				else if(str[i] == ' ' && i != str.length() - 1)
					str[i + 1] = toupper(str[i + 1]);
			return str;
		}

		string upperFirstLetters(){
			return upperFirstLetters(_value);
		}

		static string invertLetterCase(string str){
			for(short i = 0; i < str.length(); i++){
				if(isupper(str[i]))
					str[i] = tolower(str[i]);
				else
					str[i] = toupper(str[i]);
			}
			return str;
		}

		string invertLetterCase(){
			return invertLetterCase(_value);
		}

		static bool isVowel(char c){
			char vowels[] = {'a', 'e', 'o', 'i', 'u', 'A', 'I', 'U', 'E', 'O'};
			for(short i = 0; i < 10; i++)
				if(vowels[i] == c)
					return true;
			return false;
		}

		bool isVowel(){
			return isVowel(_value[0]);
		}

		static short countVowels(string str){
			short counter = 0;
			for(short i = 0; i < str.length(); i++)
				if(isVowel(str[i]))
					counter++;
			return counter;
		}

		short countVowels(){
			return countVowels(_value);
		}
};



