#include <stdio.h>
int a[20][20],q[20],s[20],visited[20];
int n,i,j,f=0,r=-1,top=-1;

void create()
{
    printf("Enter the number of cities\n");
    scanf("%d",&n);
    printf("Enter the graph in matrix form\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    return;
}

void bfs(int v)
{
    for(i=1;i<=n;i++)
        if(a[v][i] && !visited[i])
            q[++r]=i;
    if(f<=r)
    {
        visited[q[f]]=1;
        bfs(q[f++]);
    }
}

void dfs(int v1)
{
    visited[v1]=1;
    s[++top]=v1;
    printf("Nodes reachable from node %d are\n",v1);
    for(i=1;i<=n;i++)
    {
        if(a[v1][i] && !visited[i])
        {
             printf("Node %d\n",i);
             dfs(i);
        }

    }

}

void main()
{
    int v,v1,choice;
    while(1)
    {
        printf("1. Create a graph using adjacency matrix\n2. BFS method\nEnter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: create();
            break;
            case 2:printf("Enter the source vertex");
            scanf("%d",&v);
            if((v<1) && (v>n))
            {
                printf("Enter a valid source vertex\n");
                return;
            }
            for(i=1;i<=n;i++)
                visited[i]=0;
            visited[v]=1;
            bfs(v);
            printf("Nodes reachable from %d are\n",v);
            for(i=0;i<=n;i++)
                if(visited[i] && i!=v)
                printf("%d\n",i);
            break;

            default:printf("Invalid choice!");
        }
    }
}
