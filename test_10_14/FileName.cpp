 #define _CRT_SECURE_NO_WARNINGS

//给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

//岛屿总是被水包围，并且每座岛屿只能由水平方向和 / 或竖直方向上相邻的陆地连接形成。

//此外，你可以假设该网格的四条边均被水包围。


// void dfs(char** grid,int i,int j,int* gridColSize,int gridSize)
// {
    //此函数，是是直接遍历左右，设置终止条件
//     if(i<0||j<0||i==gridSize||j==(*gridColSize)||grid[i][j]=='0')
//     {
//         return ;
//     }
//     grid[i][j]='0';
//     dfs(grid,i-1,j,gridColSize,gridSize);
//     dfs(grid,i+1,j,gridColSize,gridSize);
//     dfs(grid,i,j-1,gridColSize,gridSize);
//     dfs(grid,i,j+1,gridColSize,gridSize);
// }
//void dfs(char** grid, int i, int j, int* gridColSize, int gridSize)
//{//此函数是对每一个坐标进行判断
//    if (grid[i][j] == '1')
//    {
//        grid[i][j] = '0';
//    }
//    else {
//        return;
//    }
//    if (i != 0)//不为0，说明还能上
//    {
//        dfs(grid, i - 1, j, gridColSize, gridSize);
//    }
//    if (i != gridSize - 1)//不为底，说明还能下
//    {
//        dfs(grid, i + 1, j, gridColSize, gridSize);
//    }
//    if (j != 0)//不为0，说明还能左
//    {
//        dfs(grid, i, j - 1, gridColSize, gridSize);
//    }
//    if (j != (*gridColSize) - 1)//不为底，说明还能右
//    {
//        dfs(grid, i, j + 1, gridColSize, gridSize);
//
//    }
//
//}
//int numIslands(char** grid, int gridSize, int* gridColSize) {
//    //本题思路：利用dfs递归的方式遍历陆地的上下左右进行遍历
//    int ret = 0;
//    int i, j;
//    for (i = 0; i < gridSize; i++)
//    {
//        for (j = 0; j < *gridColSize; j++)
//        {
//            if (grid[i][j] == '1')
//            {
//                dfs(grid, i, j, gridColSize, gridSize);
//                ret++;
//            }
//        }
//    }
//    return ret;
//}


//有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，
//那么城市 a 与城市 c 间接相连。
//省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。
//给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，
//而 isConnected[i][j] = 0 表示二者不直接相连。
//返回矩阵中 省份 的数量

//void dfs(int** isConnected, int row, int* isConnectedColSize, int isConnectedSize)
//{
//    for (int i = 0; i < *isConnectedColSize; i++)//城市是可以通过间接连接的所以就需要遍历行的每一个元素
//    {
//        if (isConnected[row][i] == 1)
//        {
//            isConnected[row][i] = 0;
//            if (row != i)//找到与之像连接的城市进行遍历
//            {
//                dfs(isConnected, i, isConnectedColSize, isConnectedSize);
//            }
//        }
//    }
//}
//int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
//    //本题思路：就是利用dfs递归进行遍历数组，但是要注意城市与城市对的间接连接
//    int ret = 0;
//    int i, j;
//    for (i = 0; i < isConnectedSize; i++)
//    {
//        for (j = 0; j < *isConnectedColSize; j++)
//        {
//            if (isConnected[i][j] == 1)
//            {
//                dfs(isConnected, i, isConnectedColSize, isConnectedSize);//遍历数组
//                ret++;
//            }
//        }
//    }
//    return ret;
//}



//用一个大小为 m x n 的二维网格 grid 表示一个箱子。你有 n 颗球。箱子的顶部和底部都是开着的。

//箱子中的每个单元格都有一个对角线挡板，跨过单元格的两个角，可以将球导向左侧或者右侧。
//将球导向右侧的挡板跨过左上角和右下角，在网格中用 1 表示。
//将球导向左侧的挡板跨过右上角和左下角，在网格中用 - 1 表示。
//在箱子每一列的顶端各放一颗球。每颗球都可能卡在箱子里或从底部掉出来。如果球恰好卡在两块挡板之间的 "V" 形图案
//或者被一块挡导向到箱子的任意一侧边上，就会卡住。
//返回一个大小为 n 的数组 answer ，其中 answer[i] 是球放在顶部的第 i 列后从底部掉出来的那一列对应的下标
//如果球卡在盒子里，则返回 - 1 




/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//void dfs(int** grid, int gridSize, int* gridColSize, int* returned, int index, int row, int col)
//{
//    if (row >= gridSize)//大于行，说明已经离开箱子
//    {
//        returned[index] = col;
//        return;
//    }
//    if (col == 0)//第一列，为-1就会留在左墙壁上
//    {
//        if (grid[row][col] == -1)
//        {
//            returned[index] = -1;
//            return;
//        }
//    }
//    if (col == (*gridColSize) - 1)//最后一列，位1就会留在有墙壁上
//    {
//        if (grid[row][col] == 1)
//        {
//            returned[index] = -1;
//            return;
//        }
//    }
//    int nextrow = row + 1;//往下一层
//    int nextcol;//对左右进行判断，看是否是V字形
//    if (grid[row][col] == 1)//为1的话就会流进col+1列
//    {
//        nextcol = col + 1;
//        if (grid[row][nextcol] == -1)//判断是否是V字形
//        {
//            returned[index] = -1;
//            return;
//        }
//    }
//    if (grid[row][col] == -1)//-1的话，就会流进col-1行
//    {
//        nextcol = col - 1;
//        if (grid[row][nextcol] == 1)//判断是否为v字形
//        {
//            returned[index] = -1;
//            return;
//        }
//    }
//    dfs(grid, gridSize, gridColSize, returned, index, nextrow, nextcol);//进行下一层遍历
//}
//int* findBall(int** grid, int gridSize, int* gridColSize, int* returnSize) {
//    //本题思路：利用dfs来进行遍历数组，
//    //难点在与：有四种终止递归的条件，球将留在箱子里
//
//    int* returned = (int*)malloc(sizeof(int) * (*gridColSize));//开辟一个与列相同的数组
//    memset(returned, 1, sizeof(int) * (*gridColSize));//默认每个球都能离开箱子
//    *returnSize = *gridColSize;
//    for (int i = 0; i < *gridColSize; i++)
//    {
//        dfs(grid, gridSize, gridColSize, returned, i, 0, i);//对每一个求都从第一行开始dfs
//    }
//    return returned;
//}


//给你一个大小为 m x n 的二进制矩阵 grid ，其中 0 表示一个海洋单元格、1 表示一个陆地单元格。

//一次 移动 是指从一个陆地单元格走到另一个相邻（上、下、左、右）的陆地单元格或跨过 grid 的边界。

//返回网格中 无法 在任意次数的移动中离开网格边界的陆地单元格的数量
void dfs(int** grid, int gridSize, int ret, int row, int col)
{
    if (row < 0 || col < 0 || row == gridSize || col == ret || grid[row][col] != 1)
    {
        return;
    }
    grid[row][col] = 2;
    dfs(grid, gridSize, ret, row - 1, col);
    dfs(grid, gridSize, ret, row + 1, col);
    dfs(grid, gridSize, ret, row, col - 1);
    dfs(grid, gridSize, ret, row, col + 1);
}
//  void dfs(int** grid,int gridSize,int ret,int row,int col)
//  {
//      if(grid[row][col]!=1)
//      {
//          return ;
//      }
//      grid[row][col]=2;
//      if(row!=0)
//      {
//          dfs(grid,gridSize,ret,row-1,col);
//      }
//      if(row!=gridSize-1)
//      {
//          dfs(grid,gridSize,ret,row+1,col);
//      }
//      if(col!=0)
//      {
//          dfs(grid,gridSize,ret,row,col-1);
//      }
//      if(col!=ret-1)
//      {
//          dfs(grid,gridSize,ret,row,col+1);
//      }
// }

int numEnclaves(int** grid, int gridSize, int* gridColSize) {
    //本题思路：就是利用dfs，把数组边界中1相连的改成2，之后在遍历数组有多少一
      //遍历第一行
    int ret = *gridColSize;
    int row = 0;
    int col = 0;

    for (col = 0; col < ret; col++)
    {
        dfs(grid, gridSize, ret, row, col);
    }
    //遍历最后一行
    row = gridSize - 1;
    for (col = 0; col < ret; col++)
    {
        dfs(grid, gridSize, ret, row, col);
    }
    //遍历最左列
    col = 0;
    for (row = 0; row < gridSize; row++)
    {
        dfs(grid, gridSize, ret, row, col);
    }
    //遍历最右列
    col = ret - 1;
    for (row = 0; row < gridSize; row++)
    {
        dfs(grid, gridSize, ret, row, col);
    }
    int count = 0;
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < ret; j++)
        {
            if (grid[i][j] == 1)
            {
                count++;
            }
        }
    }
    return count;
}
