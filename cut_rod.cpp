/*************************************************************************
	> File Name: cut_rod.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 25 Aug 2015 07:31:33 AM PDT
 ************************************************************************/

#include<iostream>
using namespace std;


//算法导论15章 动态规划
//切割钢条

//价格数组
int price[11] = {0,1,5,8,9,10,17,17,20,24,30};



//自顶向下递归实现
int cut_rod_r1(int p[],int n) {
    if (n == 0)
        return 0;
    
    int q = 0;
    for (int i = 1; i < n; ++i) {
        q = max(q,p[i] + cut_rod_r1(p,n-i));
    }

    return q;
}


//------------------------- 动态规划求解 ---------------------//

int _cut_rod_dp_bottomUp(int p[], int n, int r[]) {
    int q ;
    if (r[n] >= 0) 
        return r[n];
    if (0 == n) {
       q = 0;
    } else {
        q = -1;
        for (int i = 1; i < n; ++i) {
            q = max(q,p[i] + _cut_rod_dp_bottomUp(p,n-i,r));
        }
    } 
}

int cut_rod_dp_bottomUp(int p[], int n) {
    int result[n];
    return _cut_rod_dp_bottomUp(p,n,result);
}


int cut_rod_dp_best(int p[],int n) {
    int r[11] ;
    r[0] = 0;
    for (int j = 1; j <= n; ++j) {
        int q = -1;
        for (int i = 1; i <= j; ++i) {
            q = max(q,p[i] + r[j - i]);    
        }
        r[j] = q;
    }

    return r[n];
}



int main(void) {
    int max_get1 = cut_rod_r1(price,10 + 1);  //数组长度为n + 1
    cout << "递归，切割钢条的最大收益为：" << max_get1 << endl;
    
    int max_get2 = cut_rod_dp_best(price,10);
    cout << "递归版动态规划，切割钢条的最大收益为：" << max_get2 << endl;

    int max_get3 = cut_rod_dp_best(price,10);
    cout << "最优动态规划，切割钢条的最大收益为：" << max_get3 << endl;
    return 0;
}
