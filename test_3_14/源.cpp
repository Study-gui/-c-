 #define _CRT_SECURE_NO_WARNINGS


//
//#include <iostream>
//#include<bits/stdc++.h>
//using namespace std;
//int m, n;
//const int N = 5e1 + 5;
//char g[N][N];
//int hx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
//int hy[8] = { 1, -1, 0, 0, -1, 1, 1, -1 };
//struct point
//{
//    int x, y;
//};
//void bfs1()
//{
//    queue<point>q;
//    g[0][0] = '2';
//    q.push({ 0,0 });
//    while (!q.empty())
//    {
//        point now = q.front();
//        q.pop();
//        for (int i = 0; i < 8; i++)
//        {
//            int x = now.x + hx[i];
//            int y = now.y + hy[i];
//            if (x >= 0 && y >= 0 && x <= m + 1 && y <= n + 1)
//            {
//                if (g[x][y] == '0')
//                {
//                    g[x][y] = '2';
//                    q.push({ x,y });
//                }
//            }
//        }
//    }
//}
//
//void dfs2(int i, int j)
//{
//    queue<point> q;
//    g[i][j] = '2';
//    q.push({ i,j });
//    while (!q.empty())
//    {
//        point now = q.front();
//        q.pop();
//        for (int x = 0; x < 4; x++)
//        {
//            int tx = now.x + hx[x];
//            int ty = now.y + hy[x];
//            if (tx >= 1 && ty >= 1 && tx <= m && ty <= n)
//            {
//                if (g[tx][ty] == '0' || g[tx][ty] == '1')
//                {
//                    g[tx][ty] = '2';
//                    q.push({ tx,ty });
//                }
//            }
//
//        }
//    }
//
//}
//
//
//void test()
//{
//    cin >> m >> n;
//    memset(g, '0', sizeof(g));
//    for (int i = 1; i <= m; i++)
//    {
//        for (int j = 1; j <= n; j++)
//        {
//            cin >> g[i][j];
//        }
//    }
//    bfs1();
//    int ans = 0;
//    for (int i = 1; i <= m; i++)
//    {
//        for (int j = 1; j <= n; j++)
//        {
//            if (g[i][j] == '1')
//            {
//                ans++;
//                dfs2(i, j);
//            }
//        }
//    }
//    cout << ans << endl;
//}
////本题思路：先利用bfs对整个数组不为1的进行染色，
////第二次bfs，对1的环进行染色，来找到不是环得岛
//int main()
//{
//    // 请在此输入您的代码
//    int t;
//    cin >> t;
//    while (t--)
//    {
//        test();
//    }
//    return 0;
//}


//#include <iostream>
//using namespace std;
//int main()
//{
//    // 请在此输入您的代码
//    int n;
//    cin >> n;
//    int arr[6];
//    cin >> arr[0];
//    int max = 0;
//    for (int i = 1; i < n; i++)
//    {
//        cin >> arr[i];
//        if (max < arr[i] - arr[i - 1])
//        {
//            max = arr[i] - arr[i - 1];
//        }
//    }
//    cout << max;
//    return 0;
//}


#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;
    string s1 = s;
    sort(s1.begin(), s1.end());
    int t;
    cin >> t;
    int sum = s.size() - t;
    string s2[10] = { 0 };
    char ret = s1[t];
  
    int tmp = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] <= ret && tmp < sum)
        {
            s2[tmp++] = s[i];
        }

    }
    cout << s2;
    // 请在此输入您的代码
    return 0;
}