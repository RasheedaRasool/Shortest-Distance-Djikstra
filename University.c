#include <stdio.h>
#include <conio.h>

#define INFINITY 9999
#define MAX 13
void dijkstra(int G[MAX][MAX], int n, int startnode, int endnode, char R[MAX][15]);
int main()
{
    Char s[15], e[15], R[MAX][15] = {"G02", "G03", "G04", "G05", "WC", "FeeCounter", "ATM", "Auditorium", "WC", "G07", "G06", "Exit", "Entrance"};
    int G[MAX][MAX] = {{20, 1, 1, 5, 10, 0, 0, 0, 0, 0, 0, 0, 0},
                       {1, 10, 10, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0},
                       {1, 10, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {5, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {10, 10, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 5, 0, 10, 70, 65, 0, 0, 0, 40},
                       {0, 0, 0, 0, 0, 10, 0, 60, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 70, 60, 0, 70, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 65, 0, 70, 0, 10, 0, 0, 25},
                       {0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 10, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 3, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 45},
                       {0, 0, 0, 0, 0, 40, 0, 0, 25, 0, 0, 45, 0}};
    int i, j, n = MAX, u, z;
    clrscr();
    printf("\nEnter the starting node:");
    scanf("%s", &s);
    printf("\nEnter last node:");
    scanf("%s", &e);
    for (i = 0; i < MAX; i++)
    {
        if ((strcmp(s, R[i]) == 0))
            u = i;
        if ((strcmp(e, R[i]) == 0))
            z = i;
    }
    dijkstra(G, n, u, z, R);
    getch();
    return 0;
}
void dijkstra(int G[MAX][MAX], int n, int startnode, int endnode, char R[MAX][15])
{
    int cost[MAX][MAX], distance[MAX], pred[MAX];
    int visited[MAX], count, mindistance, nextnode, I, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (G[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = G[i][j];
    for (i = 0; i < n; i++)
    {
        distance[i] = cost[startnode][i];
        pred[i] = startnode;
        visited[i] = 0;
    }
    distance[startnode] = 0;
    visited[startnode] = 1;
    count = 1;
    while (count < n - 1)
    {
        mindistance = INFINITY;
        for (i = 0; i < n; i++)
            if (distance[i] < mindistance && !visited[i])
            {
                mindistance = distance[i];
                nextnode = i;
            }
        visited[nextnode] = 1;
        for (i = 0; i < n; i++)
            if (!visited[i])
                if (mindistance + cost[nextnode][i] < distance[i])
                {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
        count++;
    }
    for (i = 0; i < n; i++)
        if (i == endnode)
        {
            printf("\nDistance=%dm\n", distance[i]);
            printf("\nPath=%s", R[i]);
            j = i;
            do
            {
                j = pred[j];
                printf(" <-%s", R[j]);
            } while (j != startnode);
        }
}