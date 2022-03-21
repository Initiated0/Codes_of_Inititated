#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> PII;
vector <PII> V[100];
int n, INF = 1e9+9, s; // s is the starting node and n is the number of nodes

struct Node{
    int u, cost;
    Node(){} //default constructor
    Node(int _u, int _cost)
    {
        u = _u;
        cost = _cost;
    }
};
//normal priority queue has MAX heap. so to override it in decreasing order
//we do this
bool operator< (Node A, Node B)//this is for Min heap.
{
    return A.cost > B.cost;
}

priority_queue< Node >PQ;
int cost[100];
int taken[100];

void prim()
{
    for(int i = 0; i<n; i++)
        cost[i] = INF, taken[i] = 0;

    cost[s] = 0;
    PQ.push(Node(s, 0));
    int ans = 0;

    while(!PQ.empty())
    {
        Node x = PQ.top(); PQ.pop();

        if(taken[x.u])
        {
            continue;
        }

        taken[x.u] = 1;
        ans += x.cost;

        for(PII v : V[x.u])
        {
            if(taken[v.first]) continue;
            if(v.second < cost[v.first])
            {
                PQ.push(Node(v.first, v.second));
                cost[v.first] = v.second;
            }
        }
    }
    printf("Cost of MST(PRIM's) : %d\n");
}


int main()
{
    cout<<INF<<endl;

    return 0;
}
