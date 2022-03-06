#include <bits/stdc++.h>

using namespace std;

void showqueue(priority_queue <int> pq)
{
    priority_queue <int> gq = pq;
    while(!gq.empty())
    {
        cout<<gq.top()<<endl;
        gq.pop();
    }
    cout<<endl;
}

void showqueueINVRS(priority_queue <int, vector <int>, greater<int> > pq)
{
    priority_queue <int, vector <int>, greater<int> > gq = pq;
    while(!gq.empty())
    {
        cout<<gq.top()<<endl;
        gq.pop();
    }
    cout<<endl;
}

int main()
{
    /* normal priority queue is max heap. highest value will be on the top*/
    priority_queue <int > PQ;
    PQ.push(4);
    PQ.push(401);
    PQ.push(14);
    PQ.push(4200);
    PQ.push(240);

    showqueue(PQ);


    /*To flip normal priority queue and turn it into a min heap we must do this*/

    priority_queue< int, vector<int>, greater<int> > QP;

    QP.push(1569);
    QP.push(5463);
    QP.push(543);
    QP.push(78);
    QP.push(69);
    QP.push(6);
    showqueueINVRS(QP);

    priority_queue <string, vector <string>, greater <string> >strQ;

    strQ.push("GOT");
    strQ.push("is");
    strQ.push("the");
    strQ.push("greatest");
    strQ.push("show");
    strQ.push("ever.");

    while( !strQ.empty())
    {
        cout<<strQ.top()<<" ";
        strQ.pop();
    }
    cout<<endl;

    return 0;
}
