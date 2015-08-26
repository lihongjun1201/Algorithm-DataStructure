/*************************************************************************
	> File Name: activity_select.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 26 Aug 2015 06:01:37 AM PDT
 ************************************************************************/

#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

#if 0 
    
    算法导论第16章 贪心算法
    一.活动安排
    
#endif


//活动结构体
typedef struct tag {
    int id;
    int start_time;
    int end_time;
} Activity_t;

//算法导论p414 测试数据
Activity_t as[] = { {1,1,4},{2,3,5},{3,0,6},{4,5,7},{5,3,9},{6,5,9},{7,6,10},
                    {8,8,11},{9,8,12},{10,2,14},{11,12,16}};

vector<Activity_t> activities(as,as+11);    
//-------------------------------------------------------------------------



bool cmp(const Activity_t a, const Activity_t b) {
    return a.end_time < b.end_time;
}

//递归贪心法
vector<Activity_t> result;

void activity_selector_recursive(vector<Activity_t> &as,int k) {
    
    int m = k + 1;
    while ( m <= as.size() && as[m].start_time < as[k].end_time )
        m += 1;

    if ( m <= as.size() ) {
        cout << m << endl;
        result.push_back(as[m]);
        activity_selector_recursive(as,m);
    } 
}

//迭代贪心法
void greedy_selector(vector<Activity_t> &as) {
    int n = as.size();
    int k = 1;
    for (int m = 2; m <= n; ++m) {
        if (as[m].start_time >= as[k].end_time) {
            result.push_back(as[m]);
            k = m;
        }
    }
}




int main(void) {
#if 0
    cout << "请输入活动个数:" << endl;
    int n;
    cin >> n;

    vector<Activity_t> activities;
    int id = 1;
    while (n--) {
        cout << "请输入该活动的开始 & 结束时间：" <<endl;
        int st,et;
        cin >> st >> et;
        Activity_t activity;
        
        activity.id = id++;
        activity.start_time = st;
        activity.end_time = et;

        activities.push_back(activity);
    }
#endif
    

    sort(activities.begin(),activities.end(),cmp); //按活动结束时间排序
    result.push_back(activities[0]); //先选择活动集合中 最早结束的一个
    
    //activity_selector_recursive(activities,0);
    greedy_selector(activities);

    cout << "共可以排下 " << result.size() << " 个活动" << endl<<endl;
    cout << "最多可以安排活动顺序如下：" <<endl;
    for (auto a : result) {
        
        cout << a.id << " ";
    }
    cout << endl;



   

    return 0;
}


