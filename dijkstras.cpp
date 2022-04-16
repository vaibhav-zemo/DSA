#include <iostream>
#include <climits>
using namespace std;

int findmindis(bool *visited, int *dis, int n)
{
    int mindis = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && (mindis == -1 || dis[i] < dis[mindis]))
        {
            mindis = i;
        }
    }
    return mindis;
}

void dijkstras(int **edges, int n)
{
    bool *visited = new bool[n];
    int *dis = new int[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        dis[i] = INT_MAX;
    }
    dis[0] = 0;

    for (int i = 0; i < n; i++)
    {
        int mindis = findmindis(visited, dis, n);
        visited[i] = true;
        for (int j = 0; j < n; j++)
        {
            if (edges[mindis][j] != 0 && !visited[j])
            {
                int distance = dis[mindis] + edges[mindis][j];
                if (distance < dis[j])
                {
                    dis[j] = distance;
                }
            }
        }
    }

    cout << "Output:- \n";
    for (int i = 1; i < n; i++)
    {
        cout << "Distance of " << i << " from " << 0 << " is " << dis[i] << endl;
    }
}

int main()
{
    int n, e;
    cout << "Enter the no. of vertex and edges:- \n";
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

    dijkstras(edges, n);

    return 0;
}