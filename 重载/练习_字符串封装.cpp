#include <iostream>
#include <string.h>
using namespace std;

class MyString
{
   friend ostream& operator<<(ostream &cout, MyString & str);
   friend istream& operator>>(istream& cin, MyString & str);
private:
    char *pString;
    int m_Size;
public:
    MyString(){};
    MyString(char * str){
        this->pString = new char[strlen(str) + 1];
        strcpy(this->pString, str);
        this->m_Size = strlen(str);
    }
    MyString(const MyString  &str){
        this->pString = new char[strlen(str.pString) + 1];
        strcpy(this->pString, str.pString);
        this->m_Size = strlen(str.pString);
    };
    ~MyString(){
        if(this->pString != NULL){
            delete[] this->pString;
            this->m_Size = 0;
        }
    };
    MyString& operator=(MyString & str){
        if(this->pString != NULL){
            delete[] this->pString;
            this->m_Size = 0;
        }
        this->pString = new char[strlen(str.pString) + 1];
        strcpy(this->pString, str.pString);
        this->m_Size = strlen(str.pString);
    };
    char& operator[](int index){
        return this->pString[index];
    };

    MyString operator+(const char* str){
        int newSize = strlen(this->pString) + strlen(str) + 1;
        char *tmp = new char[newSize];
        // strcpy(tmp, this->pString);
        // for (size_t i = 0; i < strlen(str); i++)
        // {
        //     tmp[strlen(this->pString) + i] = str[i];
        // }
        
        // this->pString = new char[newSize + 1];
        // strcpy(this->pString, tmp);
        // delete[] tmp;

        memset(tmp, 0, newSize);

        strcat(tmp, this->pString);
        strcat(tmp, str);

        MyString newString(tmp);
        delete[] tmp;
        return newString;
    };
    
};



ostream& operator<<(ostream &cout, MyString & str){
    cout << str.pString;
    return cout;
}

istream& operator>>(istream& cin, MyString & str){
    if(str.pString != NULL){
        delete[] str.pString;
        str.m_Size = 0;
    }

    char buf[1024];
    cin >> buf;
    str.pString = new char[strlen(buf) + 1];
    strcpy(str.pString, buf);
    str.m_Size = strlen(buf);
    return cin;
}

int main() {
    MyString str = "abc";
    MyString str2 = str;
    MyString str3;
    // str3 = str2 = str;
    // cout << str3 << endl;
    // cout << str[0] << endl;
    // str[0] = 'b';
    // cout << str << endl;
    MyString str4 = str + "de";
    cout << str4 << endl;
    return 0;
}