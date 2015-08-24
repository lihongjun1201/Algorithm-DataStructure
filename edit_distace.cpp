/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 20 Aug 2015 07:04:34 AM PDT
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;

//最短编辑距离，可以求两个字符串的相似程度
//相等时编辑距离 = 0；
//动态规划求解




//三者最小
int minInThree(int a,int b,int c) {
    int t = a < b ? a : b;
    return t < c ? t : c;
}


int getShortestEditDistance(string a, string b) {
    int la = a.size();
    int lb = b.size();

    int dp_table[la+1][lb+1] ;

    for (int i = 0; i <= la; ++i)
        dp_table[i][0] = i;
   
    for (int j = 0; j <= lb; ++j)
        dp_table[0][j] = j;

    for (int i = 1; i < la + 1; ++i) {
        for (int j =1; j < lb + 1; ++j) {
            int cost = a[i-1] == b[j-1] ? 0 : 1; //相等则需要替换

            int deletion = dp_table[i-1][j] + 1;
            int insertion = dp_table[i][j-1] + 1;
            int replace = dp_table[i-1][j-1] + cost;

            dp_table[i][j] = minInThree(deletion,insertion,replace);
        }
    }

    for (int i = 0; i < la + 1; ++i) {
        for (int j = 0; j < lb + 1; ++j) {
            cout << dp_table[i][j] << " ";
        }
        cout << endl;
    }


    return dp_table[la][lb];
}


int main(void) {
    int dis1 = getShortestEditDistance("jary","jerry");
    cout << "get最短编辑路径为：" << dis1  <<endl;
    
    int dis2 =  getShortestEditDistance("kitten","sitting");
    cout << "get最短编辑路径为：" << dis2 <<endl;
    
     int dis3 =  getShortestEditDistance("sailn","failing");
    cout << "get最短编辑路径为：" << dis2 <<endl;


    return 0;
}








