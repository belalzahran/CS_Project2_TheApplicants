//
// Created by marti on 4/23/2022.
//

#ifndef VERTEX_H
#define VERTEX_H

#include <string>
using namespace std;
class Vertex{
private:
    int id; // the id of the vertex
    string name; // name of the city
public:
    // constructor
    Vertex()
    {
        id = NULL;
        name = "";
    };
    // constructor
    Vertex(int id, string name)
    {
        this->id = id;
        this->name = name;
    }
    // ACCESSORS
    // get the name of the city
    string GetName()
    {
        return name;
    }
    // get the id of the city
    int GetId()
    {
        return id;
    }
};

#endif //VERTEX_H
