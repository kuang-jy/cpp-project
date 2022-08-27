//
// Created by Kjoye on 2022/7/25.
//

#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int numVertices,numEdges;
    char VerticesList[10];
    int Edge[10][10];
}MGraph;

int IsExistEL(MGraph g){
    int count;
    for (int i = 0; i < g.numVertices; ++i) {
        int degree = 0;
        for (int j = 0; j < g.numVertices; ++j)
            degree+=g.Edge[i][j];
        if(degree % 2 != 0) count++;
    }
    return count == 0 || count == 2 ? 1 : 0;
}

int main() {

    return 0;
}
