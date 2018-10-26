package PhoneScreen;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.Stack;
//-- resolve task interdependency
//https://www.geeksforgeeks.org/topological-sorting/
import java.util.*;

// Data structure to store graph edges
class Edge
{
    int source, dest;

    public Edge(int source, int dest) {
        this.source = source;
        this.dest = dest;
    }
};

// Class to represent a graph object
class TopologicalSortDFS
{
    // An array of Lists to represent adjacency list
    List<List<Integer>> adjList = null;

    // Constructor
    TopologicalSortDFS(List<Edge> edges, int N)
    {
        // allocate memory
        adjList = new ArrayList<>(N);
        for (int i = 0; i < N; i++) {
            adjList.add(i, new ArrayList<>());
        }

        // add edges to the undirected graph
        for (int i = 0; i < edges.size(); i++)
        {
            int src = edges.get(i).source;
            int dest = edges.get(i).dest;

            // add an edge from source to destination
            adjList.get(src).add(dest);
        }
    }
}


// This class represents a directed graph using adjacency
// list representation
class Graph
{
    private int V;   // No. of vertices
    private LinkedList<Integer> adj[]; // Adjacency List

    //Constructor
    Graph(int v)
    {
        V = v;
        adj = new LinkedList[v];
        for (int i=0; i<v; ++i)
            adj[i] = new LinkedList();
    }

    // Function to add an edge into the graph
    void addEdge(int v,int w) { adj[v].add(w); }

    // A recursive function used by topologicalSort
    void topologicalSortUtil(int v, boolean visited[],
                             Stack stack)    {
        // Mark the current node as visited.
        visited[v] = true;
        Integer i;

        // Recur for all the vertices adjacent to this
        // vertex
        Iterator<Integer> it = adj[v].iterator();
        while (it.hasNext())
        {
            i = it.next();
            if (!visited[i])
                topologicalSortUtil(i, visited, stack);
        }

        // Push current vertex to stack which stores result
        stack.push(new Integer(v));
    }

    // The function to do Topological Sort. It uses
    // recursive topologicalSortUtil()
    void topologicalSort()
    {
        Stack stack = new Stack();

        // Mark all the vertices as not visited
        boolean visited[] = new boolean[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        // Call the recursive helper function to store
        // Topological Sort starting from all vertices
        // one by one
        for (int i = 0; i < V; i++) {
            if (visited[i] == false)
                topologicalSortUtil(i, visited, stack);
        }
        // Print contents of stack
        while (stack.empty()==false)
            System.out.print(stack.pop() + " ");
    }

    // Driver method
    public static void main(String args[])
    {
        // https://www.geeksforgeeks.org/topological-sorting/
        // Create a graph given in the above diagram
        Graph g = new Graph(6);
        g.addEdge(5, 2);
        g.addEdge(5, 0);
        g.addEdge(4, 0);
        g.addEdge(4, 1);
        g.addEdge(2, 3);
        g.addEdge(3, 1);

        System.out.println("Following is a Topological " +
                "sort of the given graph");
        g.topologicalSort();
    }
}

class TopologicalSort
{
    // Perform DFS on graph and set departure time of all
    // vertices of the graph
    static int DFS(TopologicalSortDFS graph, int v, boolean[] discovered,
                   int[] departure, int time)
    {
        // mark current node as discovered
        discovered[v] = true;

        // set arrival time
        time++;

        // do for every edge (v -> u) the same as the binary matrix
        for (int u : graph.adjList.get(v))
        {
            // u is not discovered
            if (!discovered[u]) {
                time = DFS(graph, u, discovered, departure, time);
            }
        }

        // ready to backtrack
        // set departure time of vertex v
        departure[time] = v;
        time++;

        return time;
    }

    // performs Topological Sort on a given DAG
    public static void doTopologicalSort(TopologicalSortDFS graph, int N)
    {
        // departure[] stores vertex number having its departure
        // time equal to the index of it
        int[] departure = new int[2*N];
        Arrays.fill(departure, -1);

        // Note if we had done the other way around i.e. fill
        // array with departure time by using vertex number
        // as index, we would need to sort the array later

        // stores vertex is discovered or not
        boolean[] discovered = new boolean[N];
        int time = 0;

        // perform DFS on all undiscovered vertices
        for (int i = 0; i < N; i++) {
            if (!discovered[i]) {
                time = DFS(graph, i, discovered, departure, time);
            }
        }

        // Print the vertices in order of their decreasing
        // departure time in DFS i.e. in topological order
        for (int i = 2*N - 1; i >= 0; i--) {
            if (departure[i] != -1) {
                System.out.print(departure[i] + " ");
            }
        }
    }

    // Topological Sort Algorithm for a Direct Acyclic Graph (DAG) using DFS
    // Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices
    // such that for every directed edge uv, vertex u comes before v in the ordering.
    // Topological Sorting for a graph is not possible if the graph is not a DAG.
    // Applications:
    // Topological Sorting is mainly used for scheduling jobs from the given dependencies among jobs.
    // In computer science, applications of this type arise in instruction scheduling, ordering of formula
    // cell evaluation when recomputing formula values in spreadsheets, logic synthesis, determining the order
    // of compilation tasks to perform in makefiles, data serialization, and resolving symbol dependencies in linkers


    public static void main(String[] args)
    {
        // vector of graph edges as per above diagram .. assume it is the packages dependency
        // https://www.geeksforgeeks.org/topological-sorting/
        List<Edge> edges = Arrays.asList(
                new Edge(5, 1), new Edge(2, 3),
                new Edge(4, 3), new Edge(3, 1),
                new Edge(2, 5), new Edge(3, 5)
        );

        // Set number of vertices in the graph
        final int N = 6;

        // create a graph from edges
        TopologicalSortDFS graph = new TopologicalSortDFS(edges, N);

        // perform Topological Sort
        doTopologicalSort(graph, N);
    }
}

