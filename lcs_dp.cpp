/*************************************************************************
	> File Name: lcs_dp.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 25 Aug 2015 05:07:05 AM PDT
 ************************************************************************/

#include<iostream>
using namespace std;

//最长公共子序列问题 动态规划求解
//算法导论15章 p200


int c[100][100]; //动态规划记录表
int b[100][100]; //方向记录表

void LCS(string x, string y) {
    int m = x.size();
    int n = y.size();
    
    for (int i = 1; i <= m; ++i)
        c[i][0] = 0;
    for (int j = 0; j <= n; ++j)
        c[0][j] = 0;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            
            if (x[i - 1] == y[j - 1]) //x & y 字符串从0开始 
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 0;
            } 
            else if (c[i - 1][j] >= c[i][j - 1]) 
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = 1;
            }
            else
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = 2;
            }
        }
    }

    cout << x << "与" << y << "最长公共子序列长度为：" << c[m][n] << endl;

    cout << endl << "打印动态规划记录表：" << endl;
    for (int i = 0; i <= m ; ++i ) {
        for (int j = 0; j <=n; ++j) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "打印方向表:" <<endl;
    for (int i = 0; i <= m ; ++i ) {
        for (int j = 0; j <=n; ++j) {
            
#if 0
            if (b[i][j] == 0)
                cout << "左上角"  << "  ";
            if (b[i][j] == 1)
                cout << "正上方" << "  ";
            if (b[i][j] == 2)
                cout << "正左方" << "  ";
 #endif
            
            cout << b[i][j] << " ";
        }
        cout << endl ;
    }

}

void print_lcs(string x,int i,int j) {
    if ( (i == 0) || (j == 0) )
        return;

    if (b[i][j] == 0) {
        print_lcs(x,i-1,j-1);
        cout << x[i-1] << " ";  //注意字符串X 下标从0开始，算法导论从1开始
    }
    else if (b[i][j] == 1)
        print_lcs(x,i-1,j);
    else
        print_lcs(x,i,j-1);
}



int main(void) {
    
    string   x = "ABCBDAB" ,y= "BDCABA";
    LCS(x,y);

   
    cout << endl;
    print_lcs(x,x.size(),y.size());
    cout << endl;


    return 0;
}
