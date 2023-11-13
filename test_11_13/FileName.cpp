 #define _CRT_SECURE_NO_WARNINGS

//问题描述
/*当深秋的苹果树丰收时，村庄的居民们兴致勃勃地采摘着红彤彤的
苹果。他们将采摘下来的N个苹果排成了一排，形成了一个苹果序列A，第i个苹果的甜度值为A（1≤i≤ N）。
现在村民需要将苹果序列划分为连续的 M段，对于分割后的某段 Ai~r，定义其美味值表示为该段内不同下标的苹果的
甜度两两相乘的总和，即厂D - +1 Ai•Aj。
注：如果某一段只有一个苹果，它的美味值为0。
请问应当如何给苹果分段，才能使得美味值最人的一段尽可能小，你只需要输出这个最人美味值可能的最小值即可*/


#include <iostream>
using namespace std;
int m, n;
typedef long long ll;
ll arr[200010];
ll sum[200010];
int cheek(ll mid)
{
    int ret = 1;
    int num = 1;
    ll max = 0;
    for (int i = 1; i <= n; i++)
    {
        max += arr[i] * (sum[i - 1] - sum[ret - 1]);//关键一步，是两两相乘的前缀和
        if (max > mid)
        {
            num++;
            ret = i;
            max = 0;
        }
    }
    if (num <= m)
    {
        return 1;
    }
    else {
        return 0;
    }
}
int main()
{
    //本题思路：利用二分算法进行寻找最佳值，关键是范围要取到最大
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        sum[i] = arr[i] + sum[i - 1];
    }
    ll left = 0;
    ll right = 2e18;
    while (left < right)
    {
        ll mid = (left + right) >> 1;
        if (cheek(mid))
        {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    cout << right << endl;
    // 请在此输入您的代码
    return 0;
}



////1.单张扑克牌的大小顺序为：
//2. 两张相同的牌可以组成对子，对子只能与对子比较，对子和单张无法互相响应，对子的大小关系为
//33 < 44 < 55 < 66 < 77 < 88 < 99 < XX < JJ < Q0 < KK < AA < 22 < MM < FF.
//    3.ME 是最大的牌，也被称作'王炸，它能大于所有的对子和单
//    4. 当轮到某一方出牌时，出的牌必须比对手出的牌要大。如果无法响应对手出的牌，则由对手继续出牌。
//    5.每一次出牌，玩家可以出单张、对子或王炸中的一种，但必须符合1，2，3，4号规则。
//    现在浅梦和沐风从两副扑克牌中随机抽取两张牌，由浅梦先手。两人都采用最优策略出牌，
//    最先出完所有牌的人获胜。若浅梦获胜，输出 Shal1owDream；若沐风获胜，输出Joker。你能判断谁会获胜吗？


#include <iostream>
using namespace std;
#include<string>
#include<map>
#include<cmath>
int main()
{
    //本题思路：利用一个map容器来记录每张牌的分数
    //浅梦如果是对子和MF就直接赢得比赛
    //沐风是MF赢得比赛
    //谁的牌值大谁就赢
    // 请在此输入您的代码
    map<char, int>ret;
    string arr = "3456789XJQKA2MF";
    int i = 1;
    for (char ch : arr)
    {
        ret[ch] = i++;
    }
    int t = 0;
    cin >> t;
    while (t--)
    {
        string q, m;
        cin >> q >> m;
        if (q[0] == q[1] || (q == "MF" || q == "FM"))
        {
            cout << "ShallowDream" << endl;
            continue;
        }
        if (m == "MF" || m == "FM")
        {
            cout << "Joker" << endl;
            continue;
        }
        int qmax = fmax(ret[q[0]], ret[q[1]]);
        int mmax = fmax(ret[m[0]], ret[m[1]]);
        if (qmax >= mmax)
        {
            cout << "ShallowDream" << endl;
        }
        else {
            cout << "Joker" << endl;
        }

    }
    return 0;
}