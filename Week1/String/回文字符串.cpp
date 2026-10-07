#include <iostream>
#include <string>
using namespace std;

// 双指针判断s[l]~s[r]是否回文
bool isPal(string &s, int l, int r)
{
    while(l < r)
    {
        if(s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        string s;
        cin >> s;
        int n = s.size();
        int pos = n - 1;
        // 从右往左，跳过所有指定字符
        while(pos >= 0 && (s[pos] == 'l' || s[pos] == 'q' || s[pos] == 'b'))
        {
            pos--;
        }
        if(pos < 0)
        {
            cout << "Yes" << endl;
        }
        else
        {
            if(isPal(s,0,pos))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}
