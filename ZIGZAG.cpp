// ZIGZAG.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// litcode madium task
// in: zigzag str = "0123456789a" and nam of rows (3)
// out: res = "0481357926a"


#include <iostream>
#include <string>
#include <vector>

using namespace std;

//mine decision math method (faster then convert2 with switching)
string convert(string s, int numRows) {
    if (numRows == 1) return s;
    string res;
    vector<string> S(numRows + 1, ""); //arr res strings
    int j=0;
    numRows--;
    int period = numRows * 2; //period to new branch of Z
    for (int i = 0; i < s.length(); i++) {
        j = numRows - abs( i%period - numRows); // get rows for s[i]
        S[j].push_back(s[i]);
//        cout << "S[j] = " << S[j] << endl;
    }
    for (int i = 0; i <= numRows; i++)
        res = res + S[i];
    return res;
}
string convert2(string s, int numRows) {
    if (numRows == 1) return s;
    string res;
    vector<string> S(numRows+1, "");
    int size = s.length();
    int index = 0;
    int down = 1;
    for (int i = 0; i < size; i++) {
        S[index].push_back(s[i]);
        cout << "S[j] = " << S[index] << endl;
        if (down) {
            index++;
        } else index--;
        if (index == 0) {
            down = 1;
        } else 
        if(index == numRows-1) {
            down = 0;
        }
    }
    for (int i = 0; i <= numRows; i++)
        res = res + S[i];
    return res;
}

int main()
{
    //string str = "PAYPALISHIRING";
    string str = "0123456789a";
    string res = "";
    int numRows = 3;  
    res = convert(str, numRows);


    cout << "str = " << str << endl;
    cout << "res = " << res << endl;

    std::cout << "end!\n";
}
