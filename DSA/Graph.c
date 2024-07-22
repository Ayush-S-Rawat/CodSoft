#include <stdio.h>
#define FALSE 0
#define TRUE !(FALSE)
#define MAX 100
int adj[MAX][MAX], visited[MAX], n;
void raise(char *error)
{
    printf("\033[31m");
    printf(error);
    printf("\033[0m");
}
void clear()
{
    n = 0;
    for (int i = 0; i < MAX; ++i)
    {
        visited[i] = 0;
        for (int j = 0; j < MAX; ++j)
        {
            adj[i][j] = 0;
        }
    }
}
void createGraph()
{
    int i, max_edges, origin, destin;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    if (n > MAX)
    {
        raise("ERROR: OVERFLOW -m please enter a value that does not exceed 100\n");
        return;
    }
    max_edges = n * (n - 1);
    for (i = 1; i <= max_edges; i++)
    {
        printf("Enter edge %d( -1 -1 to stop adding edges ) : ", i);
        scanf("%d %d", &origin, &destin);
        if ((origin == -1) && (destin == -1))
            break;
        if (origin >= n || destin >= n || origin < 0 || destin < 0)
        {
            raise("ERROR: -m invalid edge!\n");
            i--;
        }
        else
        {
            adj[origin][destin] = 1;
        }
    }
}
void bfs(int start)
{
    int queue[MAX], rear = -1, front = -1, i, j;
    printf("BFS : ");
    for (i = 0; i < n; i++)
        visited[i] = 0;
    queue[++rear] = start;
    visited[start] = 1;
    while (rear != front)
    {
        i = queue[++front];
        printf("%d ", i);
        for (j = 0; j < n; j++)
        {
            if (adj[i][j] && !visited[j])
            {
                queue[++rear] = j;
                visited[j] = 1;
            }
        }
    }
}
void dfs(int start)
{
    int stack[MAX], top = -1, i, j;
    printf("DFS : ");
    for (i = 0; i < n; i++)
        visited[i] = 0;
    stack[++top] = start;
    visited[start] = 1;
    while (top != -1)
    {
        i = stack[top--];
        printf("%d ", i);
        for (j = n - 1; j >= 0; j--)
        {
            if (adj[i][j] && !visited[j])
            {
                stack[++top] = j;
                visited[j] = 1;
            }
        }
    }
}
int main()
{
    int in;
    clear();
    while (TRUE)
    {
        printf("\n--------------------------------------- GRAPH TRAVERSAL ---------------------------------------\n");
        printf("EXIT:\t0\nSET:\t1\nBFS:\t2\nDFS:\t3\n");
        printf("ENTER CHOICE: ");
        scanf("%d", &in);
        if (!in)
            break;
        if (in == 1)
        {
            clear();
            createGraph();
        }
        else if (in == 2)
        {
            printf("\n------------------------- BREADTH FIRST GRAPH TRAVERSAL -----------------------\n");
            if (!n)
            {
                raise("ERROR: EmptyGraph -m no vertices to be traversed\n");
                continue;
            }
            printf("\nEnter the starting vertex: ");
            scanf("%d", &in);
            bfs(in);
        }
        else if (in == 3)
        {
            printf("\n------------------------- DEPTH FIRST GRAPH TRAVERSAL -----------------------\n");
            if (!n)
            {
                raise("ERROR: EmptyGraph -m no vertices to be traversed\n");
                continue;
            }
            printf("\nEnter the starting vertex: ");
            scanf("%d", &in);
            dfs(in);
        }
        else
            raise("ERROR: InvalidInput -m input must be an integer value between 0 and 3\n");
    }
    return 0;
}