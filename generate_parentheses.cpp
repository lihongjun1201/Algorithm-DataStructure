/*************************************************************************
	> File Name: generate_parentheses.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 24 Aug 2015 01:32:49 AM PDT
 ************************************************************************/

#include<iostream>
#include <string>
#include <vector>
using namespace std;


//利用图的深度优先搜索解决
//图中有9个节点（或者加上 （0,0））
//节点表示含有多少个 （ & ）
//画图便于理解

void dfs(int n, int x, int y, string now, vector<string> &answer) {
    if (y == n) {
        answer.push_back(now);
        return;
    }
    if (x < n) {
        dfs(n, x + 1, y, now + "(", answer);
    }
    if (x > y) {
        dfs(n, x, y + 1, now + ")", answer);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> answer;
    dfs(n,0,0,"",answer);
    return answer;
}




#if 0
int main(void) {
    vector<string> all = generateParenthesis(3);
    for (auto s : all) {
        cout << s << endl;
    }
    
    return 0;
}
#endif
