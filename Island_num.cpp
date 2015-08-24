/*************************************************************************
	> File Name: Island_num.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 24 Aug 2015 05:19:46 AM PDT
 ************************************************************************/

#include<iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector<vector<char> > graph1 = {{'1','1','1','1','0'},
                                {'1','1','0','1','0'},
                                {'1','1','0','0','0'},
                                {'0','0','0','0','0'}};

vector<vector<char> > graph2 = {{'1','1','0','0','0'},
                                {'1','1','0','0','0'},
                                {'0','0','1','0','0'},
                                {'0','0','0','1','1'}};


//深度优先搜索
void dfs(vector<vector<char> > &g,int x, int y) {
    if (x < 0 || x >= g.size() || 
        y < 0 || y >= g[x].size() || 
        g[x][y] != '1') 
    {
        return;
    }
    g[x][y] = '0';  //访问过的点则标记为0(深度遍历剩余的1)
    
    //顺时针方向深度搜索路径
    dfs(g, x, y + 1);
    dfs(g, x + 1,y);
    dfs(g, x, y -1);
    dfs(g, x + 1,y);
}

#if 1
//广度优先搜索
void bfs(vector<vector<char> > &g, int x, int y) {
    queue<pair<int,int> > q; //节点暂存队列
   
    //上下左右四个方向
    const int direction_x[] = {-1,1,0,0};
    const int direction_y[] = {0,0,-1,1};

    g[x][y] = '0'; //访问过的点则标记为0

    //坐标点入队，队非空时循环
    for (q.push(make_pair(x,y)); !q.empty(); q.pop()) {
        //取出队首坐标点
        x = q.front().first;
        y = q.front().second;
        
        //上下左右四个方向遍历（0：左 1：右 2：下 3：上）
        for (int i = 0; i < 4; ++i) {
            int nx = x + direction_x[i];
            int ny = y + direction_y[i];
            
            //满足条件则入队
            if ((nx >= 0) && (nx < g.size()) &&
                (ny >= 0) && (ny < g[nx].size()) &&
                (g[nx][ny] == '1'))
            {
                g[nx][ny] = '0'; //作标记    
                q.push(make_pair(nx,ny));
            }
        }
    }
}
#endif


int getIslandNum(vector<vector<char> > &g) {
    int Island_num = 0;
    
    for (int i = 0; i < g.size(); ++i) {
         for (int j = 0; j < g[i].size(); ++j) {
            if ('1' == g[i][j]) {
                //dfs(g,i,j);
                bfs(g,i,j);
                ++Island_num;
            }
        }
    }
    return Island_num;
}


//clang++ *.cpp -std=c++11

#if 1
int main(void) {
    int result1 = getIslandNum(graph1);
    cout << result1 << endl;
    
    int result2 = getIslandNum(graph2);
    cout << result2 << endl;

    return 0;
}
#endif

