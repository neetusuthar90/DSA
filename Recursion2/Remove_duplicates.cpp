/*
Remove Duplicates Recursively
Given a string S, remove consecutive duplicates from it recursively.

Input Format :
String S
Output Format :
Output string

Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string

Sample Input 1 :
aabccba
Sample Output 1 :
abcba

*/

#include <iostream>
using namespace std;

void DuplicatesRemove(char s[])
{
    if (s[0] == '\0')
    {
        return;
    }

    if (s[0] == s[1])
    {
        int i = 1;
        for (; s[i] != '\0'; i++)
        {
            s[i - 1] = s[i];
        }
        s[i - 1] = s[i];
        DuplicatesRemove(s);
    }
    else
    {
        DuplicatesRemove(s + 1);
    }
}

int main()
{
    char str[100];
    cin >> str;
    DuplicatesRemove(str);
    cout << "Output string is: " << str << endl;
}