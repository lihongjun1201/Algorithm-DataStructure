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

#include <unistd.h>

using namespace std;

//-----------   UTU-8编码，可处理中英文  --------------//


//处理UTF-8 中文与英文编码问题
size_t nBytesCode(const char ch)
{
	size_t nBytes = 0;
	if(ch &(1 << 7))
	{//对中文进行处理-utf8编码
		if((ch & 0xF0) == 0xC0 || (ch & 0xF0) == 0xD0)   //  1111 0000
		{												 // &11xx xxxx
			nBytes += 2;								 //  1100 0000	
		}												 //  1101 0000
		else if((ch & 0xF0) == 0xE0)
		{
			nBytes += 3;
		}
		else if((ch & 0xF0) == 0xF0)
		{
			nBytes += 4;
		}
		else if((ch & 0xFF) == 0xF8)
		{
			nBytes += 5;
		}
		else if((ch & 0xFF) == 0xFE)
		{
			nBytes += 6;
		}
	}
	else
	{//1字节编码或英文
		nBytes += 1;	
	}
	return nBytes;
}

//获取字符串逻辑长度（而非实际存储物理长度）
std::size_t length(const std::string &str)
{
	std::size_t ilen = 0;
	for(std::size_t idx = 0; idx != str.size(); ++idx)
	{
		int nBytes = nBytesCode(str[idx]);
		idx += (nBytes - 1);
		++ilen;
	}
	return ilen;
}


//三者取最小
int triple_min(const int &a, const int &b, const int &c)
{
	return a < b ? (a < c ? a : c) : (b < c ? b : c);
}




int minInThree(int a,int b,int c) {
    int t = a < b ? a : b;
    return t < c ? t : c;
}


int getShortestEditDistance(string a, string b) {
    int la = length(a);
    int lb = length(b);

    cout << la << " "  << lb << endl;

    int dp_table[la+1][lb+1] ;

    for (int i = 0; i <= la; ++i)
        dp_table[i][0] = i;
   
    for (int j = 0; j <= lb; ++j)
        dp_table[0][j] = j;

    
    string suba,subb;
    for (int dist_i = 1, a_idx = 0; dist_i < la + 1; ++dist_i, ++a_idx) {
        int nBytes = nBytesCode(a[a_idx]);

        suba = a.substr(a_idx,nBytes);
        a_idx += (nBytes - 1);

        for(int dist_j = 1,b_idx = 0; dist_j < lb + 1 ;++dist_j,++b_idx) {
            nBytes = nBytesCode(b[b_idx]);
            subb = b.substr(b_idx,nBytes);
            b_idx += (nBytes - 1);

            int cost = suba == subb ? 0 : 1;
            
            int deletion = dp_table[dist_i-1][dist_j] + 1;
            int insertion = dp_table[dist_i][dist_j-1] + 1;
            int replace = dp_table[dist_i-1][dist_j-1] + cost;

            dp_table[dist_i][dist_j] = minInThree(deletion,insertion,replace);
        }
    }

    /*  打印编辑距离表
    for (int i = 0; i < la + 1; ++i) {
        for (int j = 0; j < lb + 1; ++j) {
            cout << dp_table[i][j] << " ";
        }
        cout << endl;
    }
    */

    return dp_table[la][lb];
}



#if 0
//处理纯英文字符串

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

#endif


int main(void) {

#if 1
    
    int dis0 = getShortestEditDistance("lhjfay","lhjgay");
    cout << "get最短编辑路径为：" << dis0  <<endl;
   

    int dis1 = getShortestEditDistance("jary","jerry");
    cout << "get最短编辑路径为：" << dis1  <<endl;
    
    int dis2 =  getShortestEditDistance("kitten","sitting");
    cout << "get最短编辑路径为：" << dis2 <<endl;
    
    int dis3 =  getShortestEditDistance("sailn","failing");
    cout << "get最短编辑路径为：" << dis2 <<endl;
#endif 

    
    int dis4 = getShortestEditDistance("你妈妈喊你回家吃饭","我妈妈叫我回家吃饭");
    cout << "中文----最短编辑路径为：" << dis4 <<endl;
    
    int dis5 =  getShortestEditDistance("周杰伦","周婕纶");
    cout << "中文----最短编辑路径为：" << dis5 <<endl;

    int dis6 = getShortestEditDistance("你妈妈喊你回家吃饭","你妈妈喊你回家吃饭");
    cout << "中文----最短编辑路径为：" << dis6 <<endl;
    
    int dis7 =  getShortestEditDistance("乔丹篮球之神","乔峰丐帮之神");
    cout << "中文----最短编辑路径为：" << dis7 <<endl;





    return 0;
}







