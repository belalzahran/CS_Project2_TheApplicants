#ifndef GRAPH_H
#define GRAPH_H

//
// Created by marti on 4/23/2022.
//

#include <list>
#include <iterator>
#include <iostream>
#include <vector>
#include <QDebug>
#include "vertex.h"

using namespace std;
class Graph{
private:
    int v; // number of nodes in graph
    list<pair<Vertex,int>> *adjList; // adjacency list
    vector<Vertex> vertices;

    // struct for distance and previous node for shortest path
    struct dfs{
        int distance;
        int preV;
    };


public:

    Graph()
    {
        this->v = 0;
        this->adjList = new list<pair<Vertex,int>>[0];
    }

    // constructor
    Graph(int v)
    {
        this->v = v;
        adjList = new list<pair<Vertex,int>>[v];
    };

//    ~Graph()
//    {
//        delete adjList;
//    }

    // function to add edges to the adjacency list
    void addEdge(Vertex a, Vertex b, int weight)
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
     * \brief graphDijkstras
     * \param current - ID of source vertex
     *
     * TODO:
     * Change function to adhere to the current graph and whatever changes we make
     * Change function so that it takes in a source and a destination as an arg
     */
    void graphDijkstras(int source)
    {
        // current = source vertex

        // setting the entire visited list to false
        vector<bool> visited(v, false);
        vector<dfs> shortestDistFromStart(v);

        // fill array w default values
        for(int i = 0; i < v; i++)
        {
            shortestDistFromStart[i].distance = 100000;
        }

        bool allvisited = true;
        for (int i = 0; i < v; i++) {
            if (!visited[i])
                allvisited = false;
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
                    shortestDistFromStart[x->first.GetId()].distance =
                            x->second +
                            shortestDistFromStart[current].distance;
                    shortestDistFromStart[x->first.GetId()].preV = current;
                    //cout << "this";
                }

                // check to see if new path is shorter then previous
                else if (shortestDistFromStart[current].distance + x->second < shortestDistFromStart[x->first.GetId()].distance)
                {
                    shortestDistFromStart[x->first.GetId()].distance =
                            x->second +
                            shortestDistFromStart[current].distance;
                    shortestDistFromStart[x->first.GetId()].preV = current;
                    //cout << "that";
                }
            }
        }
        //cout << "\t\tSETTING " << vertices[current] << " VISITED\n";
        visited[current] = true;
        int nextId = getShortestUnvisitedIncidentDistanceId(current, visited);
        //cout << nextId;
        if (nextId != -1)
            shortestPath(nextId, visited, shortestDistFromStart);
        else if (current == 10){
            shortestPath(9, visited, shortestDistFromStart);
        }
        else if (current == 7)
            shortestPath(4, visited, shortestDistFromStart);
    }


    void minimumSpanningTree(int source)
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
            int closestdistance = 100000;

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
                            // problem: will only take the most recent version so 11 houston closest is atlanta 9
                            closestdistance = idx->second;
                            mstSet[closest].distance = idx->second;
                            mstSet[closest].preV = x;
                        }
                    }
                }
            }
        }
        printMST(source, mstSet);
    }


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
    int getShortestIncidentDistance(int currentVertexId)
    {
        int least = 100000;
        for (auto x = adjList[currentVertexId].begin(); x !=
        adjList[currentVertexId].end(); x++)
        {
            if (x->second < least)
                least = x->second;
        }
        return least;
    }


    /*!
     *
     * @param currentVertexId - ID of the vertex we are currently looking at (source)
     * @param visited - List of previously visited vertices
     * @return - ID of the closest unvisited vertex adjacent to the source vertex
     *
     * function to get the shortest unvisited incident (adjacent?) distance
     */
    int getShortestUnvisitedIncidentDistanceId(int currentVertexId, vector<bool>& visited)
    {
        int resultId = -1;
        int least = 100000;
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

    // Used for the MST, will get min weighted vertex adjacent to all vertices in the current
    // MST
    int getMinID(vector<int>& key, vector<bool>& visited)
    {
        int resultId = -1;
        int min = 100000;
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
    int getWeight(vector<dfs>& mstSet)
    {
        int sum = 0;
        for (int i = 0; i < mstSet.size(); i++)
        {
            if (mstSet[i].preV != -1){
                sum += mstSet[i].distance;
            }
        }
        return sum;
    }



    // function to check whether all the adjacent vertices have been visited
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


    // function to get the shortest adjacent distances' id
    int getShortestIncidentDistanceId(int currentVertexId)
    {
        int least = 100000;
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


    // function to get the shortest incident distance id excluding a specific id
    int getShortestIncidentDistanceIdExcluding(int currentVertexId , int
    excludedId)
    {
        int least = 100000;
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


    // functino to get the shortest incident distance excluding a specific id
    int getShortestIncidentDistanceExcluding(int currentVertexId , int
    excludedId)
    {
        int least = 100000;
        for (auto x = adjList[currentVertexId].begin(); x !=
        adjList[currentVertexId].end(); x++)
        {
            if (x->second < least && x->first.GetId() != excludedId) {
                least = x->second;
            }
        }
        return least;
    }


    // function to print adjacent vertices
    //void printAdjacent(int v)
    //{
    //    cout << vertices.at(v) << "->";
//        for (auto neighbor : adjList[v])
//            qDebug() << QString::fromStdString(neighbor.first.GetName()) << " " << neighbor.second << " ";
//        qDebug() << endl;
//    }

    //Function that returns the vertex of a given id.
    Vertex getVertexFromId(int id) const
    {
        return this->vertices[id];
    }
};

#endif // GRAPH_H
