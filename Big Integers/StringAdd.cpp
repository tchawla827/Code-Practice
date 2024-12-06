#include <bits/stdc++.h>
using namespace std;

int charToInt(char x)
{
    return x - '0';
}

char intTochar(int x)
{
    return x + '0';
}

string addString(string s1, string s2)
{
    int l1 = s1.length();
    int l2 = s2.length();
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    int i = 0;
    int j = 0;
    int carry = 0;
    int sum = 0;
    string res;
    while (i < l1 && j < l2)
    {
        sum = (charToInt(s1[i++]) + charToInt(s2[j++])) + carry;
        res.push_back(intTochar(sum % 10));
        carry = (sum / 10);
    }
    while (i < l1)
    {
        sum = charToInt(s1[i]) + carry;
        res.push_back(intTochar(sum % 10));
        carry = (charToInt(s1[i++]) + carry) / 10;
    }
    while (j < l2)
    {
        sum = charToInt(s2[j]) + carry;
        res.push_back(intTochar(sum % 10));
        carry = (charToInt(s2[j++]) + carry) / 10;
    }
    if (carry)
        res.push_back(intTochar(carry));
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    string s1, s2;
    cout << "Enter First Number : ";
    cin >> s1;
    cout << "Enter Second Number : ";
    cin >> s2;
    cout << "Sum : ";
    string res = addString(s1, s2);
    cout << res << endl;
}
