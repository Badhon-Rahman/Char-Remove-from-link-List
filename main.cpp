#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef struct StringNode{
     string StrData;
     struct StringNode *StringNext;
     struct StringNode *StringPrevious;
}*strPtr;

strPtr head = NULL, current = NULL;

void ProduceStringList(string str){
        strPtr newStrNode = new StringNode;
        newStrNode->StrData = str;
        if(head == NULL){
            newStrNode->StringPrevious = NULL;
            newStrNode->StringNext = NULL;
            head = newStrNode;
            current = head;
        }
        else{
            newStrNode->StringPrevious = current;
            newStrNode->StringNext = NULL;
            current->StringNext = newStrNode;
            current = newStrNode;
        }
}

void RemoveCharFString(char strRm){
          strPtr removeStr = head;
          while(removeStr != NULL){
               string checkString = removeStr->StrData;
               int removeStrSize = checkString.length();

               string updatedStr = "";
               for(int i = 0; i < removeStrSize; i++){
                    if(checkString[i] != strRm)
                      updatedStr.push_back(checkString[i]);
               }

            removeStr->StrData = updatedStr;
            removeStr = removeStr->StringNext;
         }
}

void DisplayStrList(){
        strPtr displayStr = head;
        if(head == NULL){
            cout << "String List is Empty!!!" << endl;
        }
        else{
            cout << "String data: ";
            while(displayStr != NULL){
                cout << displayStr->StrData << " ";
                displayStr = displayStr->StringNext;
            }
        }
}


int main()
{
    string str[] = {"BCD", "BB", "BDD", "BBB"};
    int strSize = sizeof(str) / sizeof(str[0]);
    int i = 0;
    char removeStr = 'B';
    while(i < strSize){
        ProduceStringList(str[i]);
        i++;
    }
    RemoveCharFString(removeStr);
    DisplayStrList();
    return 0;
}
