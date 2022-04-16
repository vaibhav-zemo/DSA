#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

void DFS_print(int n, int **edges, int sv, bool *visited)
{
    cout << sv << endl;
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (sv == i)
        {
            continue;
        }

        if (edges[sv][i] == 1)
        {
            if (visited[i])
            {
                continue;
            }

            DFS_print(n, edges, i, visited);
        }
    }
    return;
}

void DFS(int n, int **edges)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            DFS_print(n, edges, i, visited);
        }
    }
    delete[] visited;
}

void BFS_print(int n, int **edges, int sv, bool *visited)
{
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    while (!q.empty())
    {
        int front = q.front();
        cout << front << endl;
        q.pop();

        for (int i = 0; i < n; i++)
        {
            if (i == front)
            {
                continue;
            }
            if (edges[front][i] == 1)
            {
                if (visited[i])
                {
                    continue;
                }
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

void BFS(int n, int **edges)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == true)
        {
            continue;
        }

        BFS_print(n, edges, i, visited);
    }
    delete[] visited;
}

bool has_path(int n, int **edges, int sv, int x, bool *visited)
{
    bool flag = false;
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == x && edges[sv][i] && !visited[i])
        {
            return true;
        }
        if (i != sv && !visited[i] && edges[sv][i] && has_path(n, edges, i, x, visited))
        {
            flag = true;
            break;
        }
    }
    return flag;
}

vector<int> get_path_DFS(int n, int **edges, int x, int y, bool *visited)
{
    vector<int> v;
    visited[x] = true;
    for (int i = 0; (i < n) && (v.empty()); i++)
    {
        if (i == y && edges[x][i] && !visited[i])
        {
            v.push_back(i);
        }
        else if (i != x && !visited[i] && edges[x][i])
        {
            v = get_path_DFS(n, edges, i, y, visited);
        }
    }
    if (!v.empty())
    {
        v.push_back(x);
    }
    return v;
}

vector<int> get_path_BFS(int n, int **edges, int x, int y, bool *visited)
{
    vector<int> v;
    bool flag = false;
    unordered_map<int, int> map;
    visited[x] = true;
    queue<int> q;
    q.push(x);
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (i == y && edges[front][y] && !visited[i])
            {
                visited[i] = true;
                map[i] = front;
                v.push_back(i);
                flag = true;
                break;
            }
            if (i != front && !visited[i] && edges[front][i])
            {
                map[i] = front;
                visited[i] = true;
                q.push(i);
            }
        }
    }
    if (flag)
    {
        for (int i = 0; v[i] != x; i++)
        {
            v.push_back(map[v[i]]);
        }
        return v;
    }
    else
    {
        vector<int> v2;
        return v2;
    }
}

void DFS(int n, int **edges, int sv, bool *visited)
{
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i != sv && !visited[i] && edges[sv][i])
        {
            DFS(n, edges, i, visited);
        }
    }
}

bool isConnected(int n, int **edges, int sv)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    DFS(n, edges, sv, visited);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            return false;
        }
    }
    return true;
}

vector<int> DFS_Connected(int n, int **edges, int sv, bool *visited)
{
    vector<int> v;
    vector<int> ans;
    v.push_back(sv);
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i != sv && !visited[i] && edges[sv][i])
        {
            ans = DFS_Connected(n, edges, i, visited);
            for (int i = 0; i < ans.size(); i++)
            {
                v.push_back(ans[i]);
            }
        }
    }
    return v;
}

vector<vector<int>> Connected_Components(int n, int **edges, int sv)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    vector<vector<int>> v;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            v.push_back(DFS_Connected(n, edges, i, visited));
        }
    }
    return v;
}

int main()
{
    int n, ed;
    cout << "Enter number of vertices and edges\n";
    cin >> n >> ed;

    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    cout << "Enter the connected vertices in pairs\n";
    for (int i = 0; i < ed; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    vector<vector<int>> v = Connected_Components(n, edges, 0);
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    // cout << isConnected(n, edges, 0);

    // cout << "Enter the path which you have to find" << endl;
    // int x, y;
    // cin >> x >> y;
    // vector<int> v = get_path_BFS(n, edges, x, y, visited);
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i] << " ";
    // }

    delete[] visited;

    // cout << has_path(n, edges, x, y, visited);
    // cout << "BFS" << endl;
    // BFS(n, edges);
    // cout << "DFS" << endl;
    // DFS(n, edges);

    return 0;
}