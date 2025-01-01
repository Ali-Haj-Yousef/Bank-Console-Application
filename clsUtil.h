#ifndef CLSUTIL_H
#define CLSUTIL_H
#pragma once
#include <iostream>
using namespace std;
#include <ctime>
#include <string>

class clsUtil
{
private:
    static string getTextOfOnes(short nb){
        switch(nb){
            case 1:
                return " one";
            case 2:
                return " two";
            case 3:
                return " three";
            case 4:
                return " four";
            case 5:
                return " five";
            case 6:
                return " six";
            case 7:
                return " seven";
            case 8:
                return " eight";
            case 9:
                return " nine";
            default:
                return "";
        }
    }

    static string getTextOf11To19(short nb){
        switch(nb){
            case 11:
                return " eleven";
            case 12:
                return " twelve";
            case 13:
                return " thirteen";
            case 14:
                return " fourteen";
            case 15:
                return " fifteen";
            case 16:
                return " sixteen";
            case 17:
                return " seventeen";
            case 18:
                return " eighteen";
            case 19:
                return " nineteen";
            default:
                return "";
        }
    }

    static string getTextOfTens(short nb){
        switch(nb){
            case 1:
                return " ten";
            case 2:
                return " twenty";
            case 3:
                return " thirty";
            case 4:
                return " fourty";
            case 5:
                return " fifty";
            case 6:
                return " sixty";
            case 7:
                return " seventy";
            case 8:
                return " eighty";
            case 9:
                return " ninety";
            default:
                return "";
        }
    }

    static string getText(short nb, short index){
        switch(index){
            case 1:
                if(10 < nb && nb <20)
                    return getTextOf11To19(nb);
                else
                    return getTextOfOnes(nb);
            case 2:
                return getTextOfTens(nb);
            case 3:
                return getTextOfOnes(nb) + " hundreds";
            default:
                return "";
        }
    }

    static string getTextOfLevel(short level){
        switch(level){
            case 1:
                return "";
            case 2:
                return " thousands";
            case 3:
                return " millions";
            case 4:
                return " billions";
            default:
                return "";
        }
    }

public:
    static int randomNumber(int from, int to){
        return rand() % (to - from + 1) + from;
    }

    static void sRand(){
        srand((unsigned)time(NULL));
    }

    enum enCharacterType{
        SmallLetter = 1,
        CapitalLetter = 2,
        Digit = 3,
        SpecialCharacter = 4,
        MixChars = 5
    };

    static char getRandomCharacter(enCharacterType charType){
        switch(charType){
            case enCharacterType::SmallLetter:
                return char(randomNumber(97, 122));
            case enCharacterType::CapitalLetter:
                return char(randomNumber(65, 90));
            case enCharacterType::SpecialCharacter:
                return char(randomNumber(32, 47));
            case enCharacterType::Digit:
                return char(randomNumber(48, 57));
            case enCharacterType::MixChars:
                return getRandomCharacter(getRandomCharacterType());
        }
    }

    static string generateWord(enCharacterType charType, short length){
        string word = "";
        for(short i = 1; i <= length; i++)
            word += getRandomCharacter(charType);
        return word;
    }

    static string generateKey(enCharacterType charType){
        string key = "";
        for(short i = 1; i <= 4; i++){
            key += generateWord(charType, 4);
            if(i < 4)
                key += "-";
        }
        return key;
    }

    static void generateKeys(short keysNb, enCharacterType charType){
        for(short i = 1; i <= keysNb; i++)
            cout << "Key[" << i << "] : " << generateKey(charType) << endl;
    }

    static enCharacterType getRandomCharacterType(){
        return (enCharacterType)randomNumber(1, 3);
    }

    static void shuffleArray(short ar[100], short arLength){
        for(short i = arLength - 1 ; i > 1; i--){
            short swapPos = randomNumber(0,i - 1);
            swap(ar[i], ar[swapPos]);
        }
    }

    static void fillArrayWithRandomNumbers(short ar[], short arrayLength, short from, short to){
        for(short i = 0; i < arrayLength; i++)
            ar[i] = randomNumber(from, to);
    }

    static void fillArrayWithRandomWords(string ar[], short arrayLength, enCharacterType charType, short wordLength){
        for(short i = 0; i < arrayLength; i++)
            ar[i] = generateWord(charType, wordLength);
    }

    static void fillArrayWithRandomKeys(string ar[], short arrayLength, enCharacterType charType){
        for(short i = 0; i < arrayLength; i++)
            ar[i] = generateKey(charType);
    }

    static string tabs(short tabsNb){
        string space = "";
        for(short i = 1; i <= tabsNb; i++)
            space += "\t";
        return space;
    }

    static string encryptText(string name, short key){
        for(int i = 0; i < name.length(); i++)
            name[i] += key;
        return name;
    }

    static string decryptText(string name, short key){
        for(int i = 0; i < name.length(); i++)
            name[i] -= key;
        return name;
    }

    static string getTextNumber(int number, short index = 1, short level = 1){
        if(number > 0){
            if(index == 4){
                index = 1;
                level++;
            }
            if(index == 1){
                short nb = number % 100;
                if(10 < nb && nb < 20)
                    return getTextNumber(number / 100, index + 2, level) + getText(nb, index) + getTextOfLevel(level);
                else{
                    nb = number % 10;
                    return getTextNumber(number / 10, index + 1, level) + getText(nb, index) + getTextOfLevel(level);
                }
            }
            else{
                short nb = number % 10;
                return getTextNumber(number / 10, index + 1, level) + getText(nb, index);
            }
        }
        else if(index == 1 && level == 1)
            return "zero";
        else
            return "";
    }



};

#endif // CLSUTIL_H
