//
// Created by Kjoye on 2022/7/25.
//

#include <bits/stdc++.h>

using namespace std;

//邻接表数据结构
typedef struct ArcNode{  //边表
    int adjvex;    //该边指向的顶点在顶点表中位置
    ArcNode *next;   //指向下一个边
}ArcNode;

typedef struct VNode{  //顶点表
    char data;   //顶点信息
    ArcNode *first;  //第一个和该顶点关联的边
}VNode,AdjList[10];

typedef struct ALGraph{
    AdjList vertices;  //邻接表
    int Vnum,Enum;  //顶点数和边数
}ALGraph;

void convert(ALGraph g,int arr[10][10]){
    ArcNode *p;
    for (int i = 0; i < 10; ++i) {
        p = g.vertices[i].first;
        while (p){
            arr[i][p->adjvex] = 1;
            p = p->next;
        } //while
    } //for
}

int main() {

    return 0;
}
