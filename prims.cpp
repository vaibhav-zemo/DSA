#include <iostream>
#include <climits>
using namespace std;

int find_min_vertice(bool *visited, int *weight, int n)
{
    int min_vertice = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && (min_vertice == -1 || weight[i] < weight[min_vertice]))
        {
            min_vertice = i;
        }
    }
    return min_vertice;
}
 
void prims(int **edges, int n)
{
    bool *visited = new bool[n];
    int *parent = new int[n];
    int *weight = new int[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        weight[i] = INT_MAX;
    }
    parent[0] = -1;
    weight[0] = 0;

    for (int i = 0; i < n; i++)
    {
        int min_vertice = find_min_vertice(visited, weight, n);
        visited[min_vertice] = true;
        for (int j = 0; j < n; j++)
        {
            if (edges[min_vertice][j] != 0 && !visited[j])
            {
                if (edges[min_vertice][j] < weight[j])
                {
                    weight[j] = edges[min_vertice][j];
                    parent[j] = min_vertice;
                }
            }
        }
    }

    cout << "The output is:- \n";
    for (int i = 1; i < n; i++)
    {
        if (i < parent[i])
        {
            cout << i << " " << parent[i] << " " << weight[i]<<endl;
        }
        else
        {
            cout << parent[i] << " " << i << " " << weight[i]<<endl;
        }
    }
}

int main()
{
    int n, e;
    cout << "Enter the number of vertices and edges:- \n";
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    cout << "Enter the connections:- \n";
    for (int i = 0; i < e; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;

        edges[s][d] = w;
    }

    prims(edges, n);

    return 0;
}