/*************************************************************************
	> File Name: Island_num.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 24 Aug 2015 05:19:46 AM PDT
 ************************************************************************/

#include<iostream>
#include <vector>

using namespace std;

vector<vector<char> >
graph1 = { {'1','1','1','1','0'},
           {'1','1','0','1','0'},
           {'1','1','0','0','0'},
           {'0','0','0','0','0'}};

vector<vector<char> >
graph2 = { {'1','1','0','0','0'},
           {'1','1','0','0','0'},
           {'0','0','1','0','0'},
           {'0','0','0','1','1'}};

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


int getIslandNum(vector<vector<char> > &g) {
    int Island_num = 0;
    
    for (int i = 0; i < g.size(); ++i) {
         for (int j = 0; j < g[i].size(); ++j) {
            if ('1' == g[i][j]) {
                dfs(g,i,j);
                ++Island_num;
            }
        }
    }
    return Island_num;
}


int main(void) {
    int result1 = getIslandNum(graph1);
    cout << result1 << endl;
    
    int result2 = getIslandNum(graph2);
    cout << result2 << endl;

    return 0;
}
