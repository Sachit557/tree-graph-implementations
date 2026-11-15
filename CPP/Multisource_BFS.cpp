/*
 CSES - Monsters (1194)
 Multi-source BFS to calculate the minimum time for monsters to reach each cell.
 Player BFS with safety checks to find a valid escape path.
 Path reconstruction using stored movement directions.
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio()                 \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr)

void Sachit0007();

int main()
{
    fastio();

    int t = 1;
    auto start = chrono::high_resolution_clock::now();
    while (t--)
        Sachit0007();
    auto end = chrono::high_resolution_clock::now();

    cerr << "\nTime: "
         << chrono::duration<double, milli>(end - start).count()
         << " ms\n";

    return 0;
}

void bfs(std::vector<std::vector<char>> &graph, std::pair<int, int> &src, std::vector<std::vector<int>> &mon)
{
    int n = graph.size(), m = graph[0].size();
    char dir[n][m] = {'.'};

    std::vector<std::vector<int>> dist(n, std::vector<int>(m, -1));
    std::queue<std::pair<int, int>> q;
    q.push(src);
    dist[src.first][src.second] = 0;

    std::pair<int, int> vertex, dest;
    int i, j;
    bool f = 0;
    while (!q.empty())
    {
        vertex = q.front();
        q.pop();
        i = vertex.first;
        j = vertex.second;
        if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
        {
            dest.first = i;
            dest.second = j;
            f = 1;
            break;
        }

        if (i + 1 < n && graph[i + 1][j] != '#' && dist[i + 1][j] == -1)
        {
            dist[i + 1][j] = dist[i][j] + 1;
            if (dist[i + 1][j] < mon[i + 1][j] || mon[i + 1][j] == -1)
                q.push({i + 1, j});
            dir[i + 1][j] = 'D';
        }

        if (i - 1 >= 0 && graph[i - 1][j] != '#' && dist[i - 1][j] == -1)
        {
            dist[i - 1][j] = dist[i][j] + 1;
            if (dist[i - 1][j] < mon[i - 1][j] || mon[i - 1][j] == -1)
                q.push({i - 1, j});
            dir[i - 1][j] = 'U';
        }

        if (j + 1 < m && graph[i][j + 1] != '#' && dist[i][j + 1] == -1)
        {
            dist[i][j + 1] = dist[i][j] + 1;
            if (dist[i][j + 1] < mon[i][j + 1] || mon[i][j + 1] == -1)
                q.push({i, j + 1});
            dir[i][j + 1] = 'R';
        }

        if (j - 1 >= 0 && graph[i][j - 1] != '#' && dist[i][j - 1] == -1)
        {
            dist[i][j - 1] = dist[i][j] + 1;
            if (dist[i][j - 1] < mon[i][j - 1] || mon[i][j - 1] == -1)
                q.push({i, j - 1});
            dir[i][j - 1] = 'L';
        }
    }

    if (!f)
    {
        cout << "NO" << endl;
        return;
    }

    std::vector<char> path;
    i = dest.first;
    j = dest.second;
    while (i != src.first || j != src.second)
    {
        path.push_back(dir[i][j]);
        if (dir[i][j] == 'L')
            ++j;
        else if (dir[i][j] == 'R')
            --j;
        else if (dir[i][j] == 'U')
            ++i;
        else
            --i;
    }

    reverse(path.begin(), path.end());
    cout << "YES" << endl;
    cout << path.size() << endl;
    for (const auto &it : path)
        cout << it;
    cout << endl;
}

void Sachit0007()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<char>> graph(n, std::vector<char>(m));
    std::vector<std::vector<int>> dist(n, std::vector<int>(m, -1));
    std::pair<int, int> src;
    std::queue<std::pair<int, int>> q;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 'A')
            {
                src.first = i;
                src.second = j;
                graph[i][j] = '.';
            }

            else if (graph[i][j] == 'M')
            {
                q.push({i, j});
                dist[i][j] = 0;
                graph[i][j] = '.';
            }
        }
    }

    std::pair<int, int> vertex;
    while (!q.empty())
    {
        vertex = q.front();
        q.pop();
        if (graph[vertex.first][vertex.second] == '#')
            continue;
        if (vertex.first + 1 < n && dist[vertex.first + 1][vertex.second] == -1 && graph[vertex.first + 1][vertex.second] != '#')
        {
            q.push({vertex.first + 1, vertex.second});
            dist[vertex.first + 1][vertex.second] = dist[vertex.first][vertex.second] + 1;
        }

        if (vertex.first - 1 >= 0 && dist[vertex.first - 1][vertex.second] == -1 && graph[vertex.first - 1][vertex.second] != '#')
        {
            q.push({vertex.first - 1, vertex.second});
            dist[vertex.first - 1][vertex.second] = dist[vertex.first][vertex.second] + 1;
        }

        if (vertex.second + 1 < m && dist[vertex.first][vertex.second + 1] == -1 && graph[vertex.first][vertex.second + 1] != '#')
        {
            q.push({vertex.first, vertex.second + 1});
            dist[vertex.first][vertex.second + 1] = dist[vertex.first][vertex.second] + 1;
        }

        if (vertex.second - 1 >= 0 && dist[vertex.first][vertex.second - 1] == -1 && graph[vertex.first][vertex.second - 1] != '#')
        {
            q.push({vertex.first, vertex.second - 1});
            dist[vertex.first][vertex.second - 1] = dist[vertex.first][vertex.second] + 1;
        }
    }

    bfs(graph, src, dist);
}
