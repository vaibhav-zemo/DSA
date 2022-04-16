#include <bits/stdc++.h>
using namespace std;

class Edges
{
public:
    int source;
    int destiny;
    int weight;
};

bool compare(Edges n1, Edges n2)
{
    return n1.weight < n2.weight;
}

int findparent(int n, int *parent)
{
    if (parent[n] == n)
    {
        return n;
    }

    return findparent(parent[n], parent);
}

Edges *kruskal(Edges *input, int n, int e)
{
    sort(input, input + e, compare);
    Edges *output = new Edges[n - 1];
    int *parent = new int[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    int count = 0;
    int i = 0;
    while (count < n - 1)
    {
        Edges currentEdge = input[i];

        int sourceParent = findparent(currentEdge.source, parent);
        int destinyParent = findparent(currentEdge.destiny, parent);

        if (sourceParent != destinyParent)
        {
            output[count] = currentEdge;
            count++;
            parent[sourceParent] = destinyParent;
        }
        i++;
    }
    return output;
}

int main()
{
    int n, e;
    cout << "Enter the number of vertices and edges:- ";
    cin >> n >> e;
    Edges *input = new Edges[e];
    cout << "Enter the connections:- \n";
    for (int i = 0; i < e; i++)
    {
        int source, destiny, weight;
        cin >> source >> destiny >> weight;
        input[i].source = source;
        input[i].destiny = destiny;
        input[i].weight = weight;
    }

    Edges *output = kruskal(input, n, e);
    cout << "Output is:- \n";
    for (int i = 0; i < n - 1; i++)
    {
        if (output[i].source < output[i].destiny)
        {
            cout << output[i].source << " " << output[i].destiny << " " << output[i].weight << endl;
        }
        else
        {
            cout << output[i].destiny << " " << output[i].source << " " << output[i].weight << endl;
        }
    }

    return 0;
}