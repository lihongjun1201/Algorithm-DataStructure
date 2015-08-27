/*************************************************************************
	> File Name: BFS_DFS.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 27 Aug 2015 12:46:34 AM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
#include<memory>

using namespace std;


//图的顶点
typedef struct node {
    int id;                     //顶点id
    string node_name;           //顶点名称
    string color;               //顶点颜色
    int first_discovery_time;   //首次发现时间
    int final_visited_time;     //最终访问时间

    vector<shared_ptr<struct node>> adj_nodes;  //该点的邻接表（保存相邻可到达的顶点）

    //构造函数
    node(int i,string n):id(i),node_name(n),color("white"),
                         first_discovery_time(0),
                         final_visited_time(0){}
}Node_t;



//图
typedef struct graph {
    vector<shared_ptr<Node_t>> nodes;  //保存图的每个顶点
}Graph_t;

int mtime;


#if 1

//深度优先搜索
void _dfs_visit(Graph_t &g, shared_ptr<Node_t> node) {
    mtime = mtime + 1;       
    node->first_discovery_time = mtime; //盖时间戳
    node->color = "gray";    //访问过的顶点颜色变为灰色

    for (int i = 0; i < node->adj_nodes.size(); ++i) {
        if (node->adj_nodes[i]->color == "white")
            _dfs_visit(g,node->adj_nodes[i]);
    }
    
    //当该点的出边所指的邻居点没有未曾访问过的点时，访问并输出该点
    node->color = "black";
    mtime = mtime + 1;
    node->final_visited_time = mtime;  //盖最终访问时间戳
    
    cout <<"访问" << node->node_name << "顶点" << endl;
}

//图的深度优先搜索函数
void dfs(Graph_t &g) {
    int mtime = 0;  //全局时间
    
    for ( int i = 0; i < g.nodes.size(); ++i) {
        if (g.nodes[i]->color == "white") {
            _dfs_visit(g,g.nodes[i]);
        }
    }
    cout << endl;
}

#endif

Graph_t graph;


//初始化图
void initGraph(Graph_t &graph) {
    //创建图中的各个顶点
    shared_ptr<Node_t> spu(new Node_t(1,"u") );
    shared_ptr<Node_t> spv(new Node_t(2,"v") );
    shared_ptr<Node_t> spw(new Node_t(3,"w") );
    shared_ptr<Node_t> spx(new Node_t(4,"x") );
    shared_ptr<Node_t> spy(new Node_t(5,"y") );
    shared_ptr<Node_t> spz(new Node_t(6,"z") );
 
    //各个点都加入自己的出边邻居

    //u的出边：u->v , u->x
    spu->adj_nodes.push_back(spv);
    spu->adj_nodes.push_back(spx);
    
    
    //v: v->y
    spv->adj_nodes.push_back(spy);

    //w->y ,w->z
    spw->adj_nodes.push_back(spy);
    spw->adj_nodes.push_back(spz);

    //x->v
    spx->adj_nodes.push_back(spv);

    //y->x
    spy->adj_nodes.push_back(spx);

    //z->z
    spz->adj_nodes.push_back(spz);

    //构建图
    graph.nodes.push_back(spu);
    graph.nodes.push_back(spv);
    graph.nodes.push_back(spw);
    graph.nodes.push_back(spx);
    graph.nodes.push_back(spy);
    graph.nodes.push_back(spz);
}


void showGraph(Graph_t &graph) {
    for ( int i = 0; i < graph.nodes.size(); ++i) {
        cout << "顶点序号: " << graph.nodes[i]->id << endl;
        cout << "顶点名称: " << graph.nodes[i]->node_name << endl;
        cout << "顶点颜色: " << graph.nodes[i]->color << endl;
        cout << "首次发现时间: " << graph.nodes[i]->first_discovery_time << endl;
        cout << "最终访问时间: " << graph.nodes[i]->final_visited_time << endl;
        cout << "该点出边所指邻居个数： "<< graph.nodes[i]->adj_nodes.size() << " ";

        
        cout << endl << "邻居为: " << endl ;
        
        for ( int j = 0; j < graph.nodes[i]->adj_nodes.size(); ++j ) {
            cout << graph.nodes[i]->node_name << "->" 
                 << graph.nodes[i]->adj_nodes[j]->node_name << ", ";
        }

        cout <<endl<<endl;        
    }
    
    cout << endl;
}


int main(void) {
    initGraph(graph);
    
    cout << "图的深度访问顺序为：" << endl;
    dfs(graph);
    
    showGraph(graph);
    
#if 0
    for ( int i = 0; i < graph.nodes.size(); ++i) {
            cout << graph.nodes[i]->id << " ";
            cout << graph.nodes[i]->node_name << " ";
            cout << graph.nodes[i]->color << " ";
            cout << graph.nodes[i]->first_discovery_time << " ";
            cout << graph.nodes[i]->final_visited_time << " ";
            cout << endl;
        }
        cout << endl;
#endif



    return 0;
}



