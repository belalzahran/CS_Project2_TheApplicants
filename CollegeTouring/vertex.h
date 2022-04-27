//
// Created by marti on 4/23/2022.
//

#ifndef VERTEX_H
#define VERTEX_H

#include <string>
using namespace std;

/*! @class Vertex
 *
 */
class Vertex{
private:

    // the id of the vertex
    /*! @var int id
     *  the id of the vertex
     */
    int id;

    // name of the city
    /*! @var string name
     *  name of the city
     */
    string name;
public:

    // constructor
    /*! @fn Vertex()
     *
     */
    Vertex()
    {
        id = NULL;
        name = "";
    };

    // constructor
    /*! @fn Vertex(int id, string name)
     *  @param int id
     *  @param string name
     */
    Vertex(int id, string name)
    {
        this->id = id;
        this->name = name;
    }

    // ACCESSORS
    // get the name of the city
    /*! @fn string GetName()
     *  get the name of the city
     */
    string GetName()
    {
        return name;
    }

    // get the id of the city
    /*! @fn int GetId()
     *  get the id of the city
     */
    int GetId()
    {
        return id;
    }
};

#endif //VERTEX_H
