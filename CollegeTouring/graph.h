#ifndef GRAPH_H
#define GRAPH_H

//
// Created by marti on 4/23/2022.
//

#include <list>
#include <iterator>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <QDebug>
#include "vertex.h"

using namespace std;

/*! @class Graph
 *
 */
class Graph{
private:

    int v;  // # of nodes in the list

    /*! @var list<pair<Vertex,int>> *adjList
     *  adjacency list
     */
    list<pair<Vertex,double>> *adjList;

    /*! @var vector<Vertex> vertices
     *  vector of all vertices
     */
    vector<Vertex> vertices;

    /*! @struct dfs - "distance from start"
     *  @var int distance
     *  @var int preV
     *  This struct is within the scope of the Graph class
     *  struct for distance and previous node for shortest path
     */
    struct dfs{
        double distance;   // Weight of the edge
        int preV;       // Parent node to the current Vertex
        // Current vertex ID = idx of a vector of these
    };


public:

    /*! @fn Graph()
     *
     */
    Graph()
    {
        this->v = 0;
        this->adjList = new list<pair<Vertex,double>>[0];
    }


    /*!
     * \brief Graph - Copy Constructor
     * \param otherGraph
     *
     * Creates new Graph object and copies the other graph's values into its own.
     */
    Graph(const Graph& otherGraph)
    {
        adjList = otherGraph.adjList;
        v = otherGraph.v;
        vertices = otherGraph.vertices;
    }

    // constructor
    /*! @fn Graph(int v)
     *  @param int v
     */
    Graph(int v)
    {
        this->v = v;
        adjList = new list<pair<Vertex,double>>[v];
    };


    // function to add edges to the adjacency list
    /*! @fn void addEdge(Vertex a, Vertex b, int weight)
     *  @param Vertex a
     *  @param Vertex b
     *  @param int weight
     *  function to add edges to the adjacency list
     */
    void addEdge(Vertex a, Vertex b, double weight)

    {
        // The vertex's ID will match up with the index of the list
        adjList[a.GetId()].push_back(make_pair(b,weight));
        adjList[b.GetId()].push_back(make_pair(a,weight));

        if(int(vertices.size()) <= a.GetId() || int(vertices.size()) <= b.GetId())
        {
            vertices.resize(a.GetId() > b.GetId() ? a.GetId() + 1 : b.GetId() + 1);
        }

        vertices[a.GetId()] = a;
        vertices[b.GetId()] = b;
    }


    /*!
     * \brief At
     * \param vertexIndex
     * \return Vertex at the given index
     *
     * Returns the vertex at the given position.
     */
    Vertex& At(int vertexIndex)
    {
        return vertices[vertexIndex];
    }


    /*!
     * \brief PerformDFS
     * \param vertexIndex
     *
     * This function will perform a Depth-First search on the graph,
     * printing the visited vertices and outputting the discovery/back
     * edges.
     */
    double PerformDFS(int vertexIndex) const
    {
        // Copy constructs a graph object because the RecursiveDFS function modifies
        // the adjacency list structure.
        Graph graphCopy(*this);

        // Due to the nature of the algorithm, these variables are necessary to keep
        // track of the distance traveled on discovery edges + backtracked on discovery edges.
         double distanceTraveled = 0;

         // Init. all idx to be false
         vector<bool> visited(v, false);

         // This stack will be used for storing previously visited vertices for
         // backtracking
         stack<int> prevIndexes;

         // Source vertex
         int sourceVertex = vertexIndex;

         // Default backtrack vertexID
         int backtrackID = -1;

         this->RecursiveDFS(graphCopy, prevIndexes, visited, sourceVertex, vertexIndex, backtrackID, distanceTraveled);
         qDebug() << "Total Distance of DFS: " << distanceTraveled;
         return distanceTraveled;
    }

    /*!
     * \brief RecursiveDFS
     * \param graph
     * \param vertexIndex
     * \param distance
     * \param visitCount
     *
     * This function implements the DFS algorithm found in the chapter 13
     * slides. distance and visitCount are passed by reference.
     */
    double RecursiveDFS(Graph& graph, stack<int>& prevIndexes, vector<bool>& visited, int sourceVertex, int vertexIndex, int& backtrackID, double& distance) const
    {
        //int source = sourceVertex;
        while (backtrackID != sourceVertex){

            // Output each visited vertex in order of DISCOVERY
            //qDebug() << "Visiting: " << QString::fromStdString(graph.vertices[vertexIndex].GetName());
            visited[vertexIndex] = true;



            //Get lowest weight edge adj. to the current node that has not been visited yet
            int closestID = graph.getShortestUnvisitedIncidentDistanceId(vertexIndex, visited);

            if (closestID != -1)
            {
                prevIndexes.push(vertexIndex);  // Push ID onto the stack for backtracking

                // Get the weight from vertexIndex to closestID
                 distance += graph.getDistance(vertexIndex, closestID);

                // Now use this vertex and visit its closest adjacent node
                RecursiveDFS(graph, prevIndexes, visited, sourceVertex, closestID, backtrackID, distance);
            }
            else    // Else if all adj nodes of this one have been visited, backtrack
            {
                backtrackID = prevIndexes.top();
                prevIndexes.pop();

                //qDebug() << "Backtrack to: " << QString::fromStdString(graph.vertices[backtrackID].GetName());
                // Now use this vertex and visit its closest adjacent node
                RecursiveDFS(graph, prevIndexes, visited, sourceVertex, backtrackID, backtrackID, distance);
            }
        }

        //qDebug() << "Total Distance of DFS: " << distance;
        return distance;
    }


    double BFS(int source)
    {
        double distance = 0;
        // Init. all idx to be false
        vector<bool> visited(v, false);
        int u = source;

        // start at root, visit adjacent nodes in order of shortest distance
        while (!this->allvisited(visited))
        {
            visited[u] = true;

            //qDebug() << "\nVisiting: " << QString::fromStdString(this->vertices[u].GetName());


            // Get next shortest distance from current node
            int v = this->getShortestUnvisitedIncidentDistanceId(source, visited);

            // If all adj nodes of the current node have not been visited
            if (v != -1){

                // Add this to total distance
                distance += this->getDistance(source, v);

                u = v;

            }
            else{
                // If all adjacent nodes of the current nodes HAVE been visited, set the source node to the closest
                // node to current and check the adj. nodes of the new source.
                source = this->getShortestIncidentDistance(u);
                // Set the source node to the shortest node from current and repeat
            }

        }

        //qDebug() << "\nTotal Distance of BFS ----->" << distance;
        return distance;
    }

    /*! @fn void graphDijkstras(int current)
     * \brief graphDijkstras
     * \param source - ID of source vertex
     * \param destination - ID of destination vertex
     *
     * TODO:
     * Change function to adhere to the current graph and whatever changes we make
     * Add function to somewhere in tripplanner that will update the table with
     * the colleges in order to make the most efficient trip
     */
    void graphDijkstras(int source, int destination)
    {
        // setting the entire visited list to false
        vector<bool> visited(v, false);
        vector<dfs> shortestDistFromStart(v);

        // fill array w default values
        for(int i = 0; i < v; i++)
        {
            shortestDistFromStart[i].distance = 100000;
        }

        visited[source] = true;
        shortestDistFromStart[source].distance = 0;

        // calling shortest path function
        shortestPath(source, visited, shortestDistFromStart);

        // print out the shortest paths
        qDebug() << "SHORTEST PATHS...\n";
        for (int i = 0; i < v; i++) {
            if (i != source)
                printPath(source, i, shortestDistFromStart);
        }
    }


    // shortest path function - Holds the actual Dijkstra's algorithm
    // Will populate the shortest path from source to ALL other destinations
    /*! @fn int shortestPath(int current, vector<bool>& visited,  dfs *shortestDistFromStart)
     *  @param int current
     *  @param vector<bool>& visited
     *  @param dfs *shortestDistFromStart
     *  shortest path function
     */
    int shortestPath(int current, vector<bool>& visited,  vector<dfs>& shortestDistFromStart) {

        // BASE CASE
        if (allvisited(visited)) {
            //cout << "DONE";
            return -1;
        }


        // loop through the adjacent nodes
        for (auto x = adjList[current].begin(); x != adjList[current].end();
        x++) {
            // set the new shortest distance
            if (true) {
                // check to see if vertex x has default distance from start
                if (shortestDistFromStart[x->first.GetId()].distance == 100000)
                {
                    // set the distance to start
                    shortestDistFromStart[x->first.GetId()].distance = x->second + shortestDistFromStart[current].distance;
                    shortestDistFromStart[x->first.GetId()].preV = current;
                    //cout << "this";
                }

                // check to see if new path is shorter then previous
                else if (shortestDistFromStart[current].distance + x->second < shortestDistFromStart[x->first.GetId()].distance)
                {
                    shortestDistFromStart[x->first.GetId()].distance = x->second + shortestDistFromStart[current].distance;
                    shortestDistFromStart[x->first.GetId()].preV = current;
                    //cout << "that";
                }
            }
        }
        //cout << "\t\tSETTING " << vertices[current] << " VISITED\n";
        visited[current] = true;
        int nextId = getShortestUnvisitedIncidentDistanceId(current, visited);
//        shortestPath(nextId, visited, shortestDistFromStart);
        //cout << nextId;
        if (nextId != -1)
            shortestPath(nextId, visited, shortestDistFromStart);
        else
        {
            shortestPath(current, visited, shortestDistFromStart);
        }
    }


    typedef pair<double, int> vtx;
    double sierrasDijkstras(int source, int destination)
    {
        // Priority queue with distance (double) as key, and previous vertex (int)
        // Min heap order pqueue
        std::priority_queue<vtx, vector<vtx>, greater<vtx>> pq;

        // Create a vector for distances and init all to 100000 (inf)
        vector<double> dist(this->v, 100000);

        // Insert source into pq and set distance to 0
        dist[source] = 0;
        pq.push(make_pair(0, source));

        // Loop until pq becomes empty
        while (!pq.empty()){

            // Extract min distance vertex from pq, let this be u
            int u = pq.top().second;
            pq.pop();

//            qDebug() << "\nVisiting: " << QString::fromStdString(vertices[u].GetName()) << "\n";

            for (auto x = adjList[u].begin(); x != adjList[u].end(); x++)
            {
                int v = x->first.GetId();
                double weight = x->second;

                //qDebug() << "Weight to " << QString::fromStdString(x->first.GetName()) << " == " << weight << "\n";


                // If there is a shorter path from v through u
                if (dist[v] > dist[u] + weight)
                {
                    //qDebug() << "Found shorter path! \n";
                    // Update the distance of V
                    dist[v] = dist[u] + weight;
                    //qDebug() << "New Weight from " << QString::fromStdString(vertices[u].GetName()) << " to " <<  QString::fromStdString(vertices[v].GetName())
                    //         << " == " << dist[v] << "\n";
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        // Print shortest distances stored in dist[]
//            qDebug() << "\nDistance from " <<  QString::fromStdString(vertices[source].GetName()) << "\n";
//            for (int i = 0; i < this->v; ++i)
//            {
//                QString name = QString::fromStdString(vertices[i].GetName());
//                qDebug() << name << " ------> " << dist [i];
//            }

//            qDebug() << "\n\nDistance from " <<  QString::fromStdString(vertices[source].GetName()) << "\n"
//                     << "To Destination: " << QString::fromStdString(vertices[destination].GetName()) << "\n"
//                     << " is  ------> " << dist[destination];


            return dist[destination];
    }


    /*! @fn void minimumSpanningTree(int source)
     *  @param int source
     *
     *  @return double - weight of MST
     */
    double minimumSpanningTree(int source)
    {
        // setting the entire visited list to false
        vector<bool> visited(v, false);
        vector<int> key(v);     // Distances to pick minimum from
        vector<dfs> mstSet(v);  // Array to store constructed MST

        // fill array w default values
        for(int i = 0; i < v; i++)
        {
            key[i] = 100000;
        }

        visited[source] = true;
        key[source] = 0;

        dfs Source;
        Source.distance = 0;
        Source.preV = -1;
        mstSet[source] = Source;
        // First node is always root of MST

        // update adjacent vertices key values
        for (auto idx = adjList[source].begin(); idx != adjList[source].end(); ++idx)
        {
            key[idx->first.GetId()] = idx->second;
            mstSet[idx->first.GetId()].preV = source;
        }

        int closest = 0;

        // a) Pick a vertex u which is not there in visited[u.id] and has minimum key value. (distance = key)
        // Pick the vertex with minimum key value and not already included in MST (not in mstSET or visited).
        for (int n = 0; n < v - 1; n++)
        {
            closest = getMinID(key, visited);
            visited[closest] = true;
            double closestdistance = 100000;

            // somehow get the parent and distance from the parent of closest:


            // Update all adjacent vertices of the mstList
            for (int x = 0; x < v; x++)
            {
                if (visited[x])
                {    // add adjacent vertices
                    // update adjacent vertices key values

                    for (auto idx = adjList[x].begin(); idx != adjList[x].end(); ++idx)
                    {
                        key[idx->first.GetId()] = idx->second;
                        if (idx->first.GetId() == closest && idx->second < closestdistance)
                        {
                            closestdistance = idx->second;
                            mstSet[closest].distance = idx->second;
                            mstSet[closest].preV = x;
                        }
                    }
                }
            }
        }
        //printMST(source, mstSet);
        return getWeight(mstSet);
    }


    /*! @fn void printMST(int root, vector<dfs>& mstSet)
     *  @param int root
     *  @param vector<dfs>& mstSet
     */
    void printMST(int root, vector<dfs>& mstSet)
    {
        qDebug() << "\n";
        qDebug() << "\n=================\nMST Representation of the given graph\n=================\n";
        qDebug() << "Total Weight: " << getWeight(mstSet) << "\n";
        qDebug() << "Root is: " << QString::fromStdString(getVertexFromId(root).GetName()) << "\n";
        qDebug() << "Edges:\n";
        for (int i = 0; i < mstSet.size(); i++)
        {
            if (mstSet[i].preV != -1){ //mstSet[i].preV
                qDebug() << "(" << QString::fromStdString(getVertexFromId(mstSet[i].preV).GetName()) << "," <<QString::fromStdString(getVertexFromId(i).GetName()) << ")";
                qDebug() << " ";
            }
        }
    }


    /*! @fn bool allvisited(vector<bool>& visited)
     *  @param vector<bool>& visited
     *
     */
    bool allvisited(vector<bool>& visited)
    {
        bool allvisited = true;
        for (int i = 0; i < this->v; i++) {
            if (!visited[i])
                allvisited = false;
        }
        return allvisited;
    }


    // function to print the shortest path for an id
    /*! @fn void printPath(int sourceid, int id,  vector<dfs>& shortestDistFromStart)
     *  @param int sourceid
     *  @param int id
     *  @param vector<dfs>& shortestDistFromStart
     *  function to print the shortest path for an id
     *
     *  This is used for graphDijkstras and is incompatable with other functions
     */
    void printPath(int sourceid, int id,  vector<dfs>& shortestDistFromStart)
    {
        qDebug() << "\n" << QString::fromStdString(getVertexFromId(id).GetName()) << " to Source is " <<
        shortestDistFromStart[id].distance << " miles: " << QString::fromStdString(getVertexFromId(id).GetName()) <<
        "->";
        int parentId = shortestDistFromStart[id].preV;
        while (parentId != sourceid)
        {
            qDebug() << QString::fromStdString(getVertexFromId(parentId).GetName()) << "->";
            id = parentId;
            parentId = shortestDistFromStart[id].preV;
        }
        qDebug() << QString::fromStdString(getVertexFromId(parentId).GetName()) << " ";
    }


    // ACCESSORS


    // function to get the shortest incident (adjacent?) distance
    /*! @fn int getShortestIncidentDistance(int currentVertexId)
     *  @param int currentVertexId
     *
     */
    double getShortestIncidentDistance(int currentVertexId)
    {
        double least = 100000;
        for (auto x = adjList[currentVertexId].begin(); x !=
        adjList[currentVertexId].end(); x++)
        {
            if (x->second < least)
                least = x->second;
        }
        return least;
    }


    // Will retrieve the distance between two vertices (as long as they are adjacent)
    double getDistance(int pointa, int pointb)
    {
        double nomatch = -1;
        for (auto x = adjList[pointa].begin(); x != adjList[pointa].end(); x++)
        {
            if (x->first.GetId() == pointb)
            {
                return x->second;    // Return the weight between the two vertices
            }
        }
        return nomatch;
    }

    /*! @fn int getShortestUnvisitedIncidentDistanceId(int currentVertexId, vector<bool>& visited)
     *
     * @param currentVertexId - ID of the vertex we are currently looking at (source)
     * @param visited - List of previously visited vertices
     * @return - ID of the closest unvisited vertex adjacent to the source vertex
     *
     * function to get the shortest unvisited incident (adjacent?) distance
     */
    double getShortestUnvisitedIncidentDistanceId(int currentVertexId, vector<bool>& visited)
    {
        int resultId = -1;
        double least = 100000;
        for (auto x = adjList[currentVertexId].begin(); x !=
        adjList[currentVertexId].end(); x++)
        {
            if (x->second < least && !visited[x->first.GetId()]) {
                least = x->second;
                resultId = x->first.GetId();
            }
        }
        return resultId;
    }



    // function to get the shortest adjacent distances' id
    /*! @fn int getShortestIncidentDistanceId(int currentVertexId)
     *  @param int currentVertexId
     *  function to get the shortest adjacent distances' id
     */
    double getShortestIncidentDistanceId(int currentVertexId)
    {
        double least = 100000;
        int leastId = 0;
        for (auto x = adjList[currentVertexId].begin(); x !=
        adjList[currentVertexId].end(); x++)
        {
            if (x->second < least) {
                least = x->second;
                leastId = x->first.GetId();
            }
        }
        return leastId;
    }



    /*! @fn int getMinID(vector<int>& key, vector<bool>& visited)
     *  @param vector<int>& key
     *  @param vector<bool>& visited
     *  Used for the MST, will get min weighted vertex adjacent to all vertices in the current MST
     */
    int getMinID(vector<int>& key, vector<bool>& visited)
    {
        int resultId = -1;
        double min = 100000;
        for (int x = 0; x < v; x++){
            if(key[x] < min && !visited[x])
            {
                min = key[x];
                resultId = x;
            }
        }
        return resultId;
    }


    // Used to get the total weight of the MST
    /*! @fn int getWeight(vector<dfs>& mstSet)
     *  @param vector<dfs>& mstSet
     */
    double getWeight(vector<dfs>& mstSet)
    {
        double sum = 0;
        for (int i = 0; i < mstSet.size(); i++)
        {
            if (mstSet[i].preV != -1){
                sum += mstSet[i].distance;
            }
        }
        return sum;
    }


    // function to check whether all the adjacent vertices have been visited
    /*! @fn bool allIncidentsVisited(int id, vector<bool>& visited)
     *  @param int id
     *  @param vector<bool>& visited
     *
     */
    bool allIncidentsVisited(int id, vector<bool>& visited)
    {
        bool result = true;

        // This will iterate through the adj. list of the current vertex
        // even if result ends up true for 1 vertex, unless they are all true,
        // the function will return false.
        for (auto& x : adjList[id])
        {
            if (!visited[x.first.GetId()])
                result = false;
        }
        return result;
    }


    // function to get the shortest incident distance id excluding a specific id
    /*! @fn int getShortestIncidentDistanceIdExcluding(int currentVertexId , int excludedId)
     *  @param int currentVertexId
     *  @param int excludedId
     *  function to get the shortest incident distance id excluding a specific id
     */
    double getShortestIncidentDistanceIdExcluding(int currentVertexId , int
    excludedId)
    {
        double least = 100000;
        int leastId = 0;
        for (auto x = adjList[currentVertexId].begin(); x !=
        adjList[currentVertexId].end(); x++)
        {
            if (x->second < least && x->first.GetId() != excludedId) {
                least = x->second;
                leastId = x->first.GetId();
            }
        }
        return leastId;
    }


    // function to get the shortest incident distance excluding a specific id
    /*! @fn int getShortestIncidentDistanceExcluding(int currentVertexId , int excludedId)
     *  @param int currentVertexId
     *  @param int excludedId
     *  function to get the shortest incident distance excluding a specific id
     */
    double getShortestIncidentDistanceExcluding(int currentVertexId , int
    excludedId)
    {
        double least = 100000;
        for (auto x = adjList[currentVertexId].begin(); x !=
        adjList[currentVertexId].end(); x++)
        {
            if (x->second < least && x->first.GetId() != excludedId) {
                least = x->second;
            }
        }
        return least;
    }


    //Function that returns the vertex of a given id.
    /*! @fn Vertex getVertexFromId(int id) const
     *  @param int id
     *  Function that returns the vertex of a given id.
     */
    Vertex getVertexFromId(int id) const
    {
        return this->vertices[id];
    }

    //Function that returns the id of a college in the graph.
    /*! @fn int getIdFromName(int id) const
     *  @param string collegeName
     *  Function that returns the id of the college in the graph. -1 if dne
     */
    int getIdFromName(string collegeName)
    {
        for(unsigned int index = 0; index < vertices.size(); index++)
        {
            if(vertices.at(index).GetName() == collegeName)
            {
                return index;
            }
        }
        return -1;
    }
};

#endif // GRAPH_H
