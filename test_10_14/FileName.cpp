 #define _CRT_SECURE_NO_WARNINGS

//����һ���� '1'��½�أ��� '0'��ˮ����ɵĵĶ�ά����������������е����������

//�������Ǳ�ˮ��Χ������ÿ������ֻ����ˮƽ����� / ����ֱ���������ڵ�½�������γɡ�

//���⣬����Լ��������������߾���ˮ��Χ��


// void dfs(char** grid,int i,int j,int* gridColSize,int gridSize)
// {
    //�˺���������ֱ�ӱ������ң�������ֹ����
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
//{//�˺����Ƕ�ÿһ����������ж�
//    if (grid[i][j] == '1')
//    {
//        grid[i][j] = '0';
//    }
//    else {
//        return;
//    }
//    if (i != 0)//��Ϊ0��˵��������
//    {
//        dfs(grid, i - 1, j, gridColSize, gridSize);
//    }
//    if (i != gridSize - 1)//��Ϊ�ף�˵��������
//    {
//        dfs(grid, i + 1, j, gridColSize, gridSize);
//    }
//    if (j != 0)//��Ϊ0��˵��������
//    {
//        dfs(grid, i, j - 1, gridColSize, gridSize);
//    }
//    if (j != (*gridColSize) - 1)//��Ϊ�ף�˵��������
//    {
//        dfs(grid, i, j + 1, gridColSize, gridSize);
//
//    }
//
//}
//int numIslands(char** grid, int gridSize, int* gridColSize) {
//    //����˼·������dfs�ݹ�ķ�ʽ����½�ص��������ҽ��б���
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


//�� n �����У�����һЩ�˴���������һЩû��������������� a ����� b ֱ���������ҳ��� b ����� c ֱ��������
//��ô���� a ����� c ���������
//ʡ�� ��һ��ֱ�ӻ��������ĳ��У����ڲ�������û�������ĳ��С�
//����һ�� n x n �ľ��� isConnected ������ isConnected[i][j] = 1 ��ʾ�� i �����к͵� j ������ֱ��������
//�� isConnected[i][j] = 0 ��ʾ���߲�ֱ��������
//���ؾ����� ʡ�� ������

//void dfs(int** isConnected, int row, int* isConnectedColSize, int isConnectedSize)
//{
//    for (int i = 0; i < *isConnectedColSize; i++)//�����ǿ���ͨ��������ӵ����Ծ���Ҫ�����е�ÿһ��Ԫ��
//    {
//        if (isConnected[row][i] == 1)
//        {
//            isConnected[row][i] = 0;
//            if (row != i)//�ҵ���֮�����ӵĳ��н��б���
//            {
//                dfs(isConnected, i, isConnectedColSize, isConnectedSize);
//            }
//        }
//    }
//}
//int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
//    //����˼·����������dfs�ݹ���б������飬����Ҫע���������жԵļ������
//    int ret = 0;
//    int i, j;
//    for (i = 0; i < isConnectedSize; i++)
//    {
//        for (j = 0; j < *isConnectedColSize; j++)
//        {
//            if (isConnected[i][j] == 1)
//            {
//                dfs(isConnected, i, isConnectedColSize, isConnectedSize);//��������
//                ret++;
//            }
//        }
//    }
//    return ret;
//}



//��һ����СΪ m x n �Ķ�ά���� grid ��ʾһ�����ӡ����� n �������ӵĶ����͵ײ����ǿ��ŵġ�

//�����е�ÿ����Ԫ����һ���Խ��ߵ��壬�����Ԫ��������ǣ����Խ������������Ҳࡣ
//�������Ҳ�ĵ��������ϽǺ����½ǣ����������� 1 ��ʾ��
//���������ĵ��������ϽǺ����½ǣ����������� - 1 ��ʾ��
//������ÿһ�еĶ��˸���һ����ÿ���򶼿��ܿ����������ӵײ��������������ǡ�ÿ������鵲��֮��� "V" ��ͼ��
//���߱�һ�鵲�������ӵ�����һ����ϣ��ͻῨס��
//����һ����СΪ n ������ answer ������ answer[i] ������ڶ����ĵ� i �к�ӵײ�����������һ�ж�Ӧ���±�
//������ں�����򷵻� - 1 




/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//void dfs(int** grid, int gridSize, int* gridColSize, int* returned, int index, int row, int col)
//{
//    if (row >= gridSize)//�����У�˵���Ѿ��뿪����
//    {
//        returned[index] = col;
//        return;
//    }
//    if (col == 0)//��һ�У�Ϊ-1�ͻ�������ǽ����
//    {
//        if (grid[row][col] == -1)
//        {
//            returned[index] = -1;
//            return;
//        }
//    }
//    if (col == (*gridColSize) - 1)//���һ�У�λ1�ͻ�������ǽ����
//    {
//        if (grid[row][col] == 1)
//        {
//            returned[index] = -1;
//            return;
//        }
//    }
//    int nextrow = row + 1;//����һ��
//    int nextcol;//�����ҽ����жϣ����Ƿ���V����
//    if (grid[row][col] == 1)//Ϊ1�Ļ��ͻ�����col+1��
//    {
//        nextcol = col + 1;
//        if (grid[row][nextcol] == -1)//�ж��Ƿ���V����
//        {
//            returned[index] = -1;
//            return;
//        }
//    }
//    if (grid[row][col] == -1)//-1�Ļ����ͻ�����col-1��
//    {
//        nextcol = col - 1;
//        if (grid[row][nextcol] == 1)//�ж��Ƿ�Ϊv����
//        {
//            returned[index] = -1;
//            return;
//        }
//    }
//    dfs(grid, gridSize, gridColSize, returned, index, nextrow, nextcol);//������һ�����
//}
//int* findBall(int** grid, int gridSize, int* gridColSize, int* returnSize) {
//    //����˼·������dfs�����б������飬
//    //�ѵ����룺��������ֹ�ݹ��������������������
//
//    int* returned = (int*)malloc(sizeof(int) * (*gridColSize));//����һ��������ͬ������
//    memset(returned, 1, sizeof(int) * (*gridColSize));//Ĭ��ÿ�������뿪����
//    *returnSize = *gridColSize;
//    for (int i = 0; i < *gridColSize; i++)
//    {
//        dfs(grid, gridSize, gridColSize, returned, i, 0, i);//��ÿһ���󶼴ӵ�һ�п�ʼdfs
//    }
//    return returned;
//}


//����һ����СΪ m x n �Ķ����ƾ��� grid ������ 0 ��ʾһ������Ԫ��1 ��ʾһ��½�ص�Ԫ��

//һ�� �ƶ� ��ָ��һ��½�ص�Ԫ���ߵ���һ�����ڣ��ϡ��¡����ң���½�ص�Ԫ����� grid �ı߽硣

//���������� �޷� ������������ƶ����뿪����߽��½�ص�Ԫ�������
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
    //����˼·����������dfs��������߽���1�����ĸĳ�2��֮���ڱ��������ж���һ
      //������һ��
    int ret = *gridColSize;
    int row = 0;
    int col = 0;

    for (col = 0; col < ret; col++)
    {
        dfs(grid, gridSize, ret, row, col);
    }
    //�������һ��
    row = gridSize - 1;
    for (col = 0; col < ret; col++)
    {
        dfs(grid, gridSize, ret, row, col);
    }
    //����������
    col = 0;
    for (row = 0; row < gridSize; row++)
    {
        dfs(grid, gridSize, ret, row, col);
    }
    //����������
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
