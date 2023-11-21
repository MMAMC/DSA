#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#define V 9
int
minDistance (int dist[], bool visitedSet[])
{
  
int min = INT_MAX, min_index;
  
for (int v = 0; v < V; v++)
    {
      
if (visitedSet[v] == false && dist[v] <= min)
	{
	  
min = dist[v];
	  
min_index = v;
	
}
    
}
  
return min_index;

}


void
printPath (int parent[], int j)
{
  
if (parent[j] == -1)
    {
      
return;
    
}
  
printPath (parent, parent[j]);
  
printf ("%d ", j);

}


void
printSolution (int dist[], int parent[], int src, int dest)
{
  
printf ("Vertex\tDistance\tPath\n");
  
for (int i = 0; i < V; i++)
    {
      
printf ("%d\t%d\t\t%d ", i, dist[i], src);
      
printPath (parent, i);
      
printf ("\n");
    
} 
printf ("Shortest path from %d to %d: ", src, dest);
  
printPath (parent, dest);
  
printf ("\n");

} 
void

dijkstra (int graph[V][V], int src, int dest)
{
  
int dist[V];
  
bool visitedSet[V];
  
int parent[V];
  
for (int i = 0; i < V; i++)
    {
      
dist[i] = INT_MAX;
      
visitedSet[i] = false;
    
} 
dist[src] = 0;
  
parent[src] = -1;
  
for (int count = 0; count < V - 1; count++)
    {
      
int u = minDistance (dist, visitedSet);
      
visitedSet[u] = true;
      
for (int v = 0; v < V; v++)
	{
	  
if (!visitedSet[v] && graph[u][v] && dist[u] != INT_MAX
	       && dist[u] + graph[u][v] < dist[v])
	    {
	      
dist[v] = dist[u] + graph[u][v];
	      
parent[v] = u;
	    
}
	
}
    
}
  
printSolution (dist, parent, src, dest);

}


int
main ()
{
  
int graph[V][V] = { 
      {0, 4, 0, 0, 0, 0, 0, 8, 0}, 
    {4, 0, 8, 0, 0, 0, 0, 11, 0}, 
    {0, 8, 0, 7, 0, 4, 0, 0, 2}, 
    {0, 0, 7, 0, 9, 14, 0, 0, 0}, 
    {0, 0, 0, 9, 0, 10, 0, 0, 0}, 
    {0, 0, 4, 14, 10, 0, 2, 0, 0}, 
    {0, 0, 0, 0, 0, 2, 0, 1, 6}, 
    {8, 11, 0, 0, 0, 0, 1, 0, 7}, 
{0, 0, 2, 0, 0, 0, 6, 7, 0} 
  };
  
dijkstra (graph, 0, 4);
  
return 0;

}
