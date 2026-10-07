/*
子串匹配：
给两个字符串S1，S2，求S2是否是S1的子串，并求S2在S1中出现的次数
把S2Hash出来，在S1里找所有长度为|S2|的子串，Hash比较。
效率 O(|S1|)
*/
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

typedef unsigned long long ull;
const ull base = 131;

const int MAXN = 100010; // 假设字符串最大长度
ull pre_hash[MAXN];      // S1的前缀哈希,从1开始存
ull pow_base[MAXN];      // base的次幂

// 计算整个字符串的哈希值
ull hashs(string s) {
    ull ans = 0;
    int len = s.length();
    for (int i = 0; i < len; i++) {
        ans = ans * base + (ull)s[i];
    }
    return ans;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2; 

    int n1 = s1.length();
    int n2 = s2.length();

    // 如果 S2 比 S1 还长，不可能为子串
    if (n2 > n1) {
        cout << "S2不是S1的子串，出现次数：0" << endl;
        return 0;
    }

    // 1. 计算 S2 的 Hash 值 (目标值)
    ull target_hash = hashs(s2);

    // 2. 预处理 S1 的前缀 Hash 以及 base 的幂次
    pow_base[0] = 1;
    pre_hash[0] = 0;
    for (int i = 1; i <= n1; i++) {
        pre_hash[i] = pre_hash[i - 1] * base + (ull)s1[i - 1];
        //预处理 base 的幂次
        pow_base[i] = pow_base[i - 1] * base;
    }

    // 3. 遍历 S1，找所有长度为 |S2| 的子串，进行 Hash 比较
    int ans = 0;
    for (int i = 0; i + n2 <= n1; i++) {
        //r= i+n2,l= i+1
        ull sub_hash = pre_hash[i + n2] - pre_hash[i] * pow_base[n2];
        
        if (sub_hash == target_hash) {
            ans++;
        }
    }

    if (ans > 0) {
        cout << "S2是S1的子串" << endl;
        cout << "S2在S1中出现的次数: " << ans << endl;
    } else {
        cout << "S2不是S1的子串" << endl;
        cout << "S2在S1中出现的次数: 0" << endl;
    }

    return 0;
}