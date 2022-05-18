#ifndef VERTEX_H
#define VERTEX_H

#include <string>
using namespace std;

/*!
 * \brief The Labels enum
 *
 * Used to track the label of vertices and edges. Used for DFS
 */
enum Labels
{
 UNEXPLORED, /* vertex or edge defaults to this value */
 DISCOVERY, /* edge */
 VISITED, /* vertex */
 BACK /* edge */
};

/*! @class Vertex
 *
 */
class Vertex{
private:
    /*! @var int id
     *
     */
    int id;

    /*! @var string name
     *
     */
    string name;

    /*! @var Labels label
     *
     */
    Labels label;

public:

    // constructor
    /*! @fn Vertex()
     *
     */
    Vertex()
    {
        this->id = NULL;
        this->name = "";
        this->label = UNEXPLORED;
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
        this->label = UNEXPLORED;
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

    /*!
     * \brief getLabel
     * \return label
     *
     * Returns label of the city
     */
    Labels getLabel()
    {
        return label;
    }

    void setID(int id)
    {
        this->id = id;
    }
};


#endif //VERTEX_H
