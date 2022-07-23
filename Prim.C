#include<stdio.h>
#include<stdlib.h>

#define MAX 10
#define TEMP 0
#define PRIM 1
#define infinity 9999
#define NIL -1

struct edge
{
     int u, v;
};

int n, adj[MAX][MAX], predecessor[MAX], status[MAX], length[MAX];
void create_graph();
void maketree(int r, struct edge tree[MAX]);
int min_temp();

int main()
{
     int wt_tree = 0, i, root;
     struct edge tree[MAX];
     system("cls");
     printf("\nVertices are numbered from 0 to end, say, 0, 1, 2,... 19;\
Key in edge in the format <start vertex> <SPACE> <end vertex>, say, without\
quotes\", \" 0 19\".\n\n");

     create_graph();

     printf("\nEnter root vertex : ");
     scanf("%d", &root);

     maketree(root, tree);
     printf("\nEdges to be included in spanning tree are :\n");
     for(i = 1; i <= n-1; i++)
     {
	  printf("%d-->", tree[i].u);
	  printf("%d\n", tree[i].v);
	  wt_tree += adj[tree[i].u][tree[i].v];
     }
     printf("\nWeight of spanning tree is : %d\n",wt_tree);

     getch();
     return(0);
}

void maketree(int r, struct edge tree[MAX])
{
     int current, i, count = 0;

     for(i = 0; i < n; i++)
     {
	  predecessor[i] = NIL;
	  length[i] = infinity;
	  status[i] = TEMP;
     }
     length[r] = 0;
     while(1)
     {
	  current = min_temp();
	  if(current == NIL)
	  {
	       if(count == n-1)
		    return;
	       else
	       {
		    printf("\nGraph is not connected, No spanning tree\
possible");
		    exit(1);
	       }
	  }
	  status[current] = PRIM;

	  if(current != r)
	  {
	       count++;
	       tree[count].u = predecessor[current];
	       tree[count].v = current;
	  }

	  for(i = 0; i < n; i++)
	  {
	       if(adj[current][i] > 0 && status[i] == TEMP)
	       {
		    if(adj[current][i] < length[i])
		    {
			 predecessor[i] = current;
			 length[i] = adj[current][i];
		    }
	       }
	  }
     }
}


int min_temp()
{
     int i, min = infinity, k = -1;

     for(i = 0; i < n; i++)
     {
	  if(status[i] == TEMP && length[i] < min)
	  {
	       min = length[i];
	       k = i;
	  }
     }
     return(k);
}


void create_graph()
{
     int i, max_edges, origin, destin, wt;
     printf("\nEnter number of vertices : ");
     scanf("%d", &n);
     max_edges = n*(n-1)/2;
     for(i = 1; i <= max_edges; i++)
     {    printf("\nEnter edge %d(-1 -1 to quit): ", i);
	  scanf("%d %d", &origin, &destin);
	  if((origin == -1) && (destin == -1))
	  break;
	  printf("\nEnter weight for this edge : ");
	  scanf("%d", &wt);
	  if(origin >= n || destin >= n || origin < 0 || destin < 0)
	  {
	       printf("\nInvalid edge!");
	       i--;
	  }
	  else
	  {
	       adj[origin][destin] = wt;
	       adj[destin][origin] = wt;
	  }
     }
}
