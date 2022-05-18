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


/*!
  * \brief The WeightedEdge class
  *
  * This class works in conjunction with the Graph class
  */
 class WeightedEdge
 {

 friend bool operator > (const WeightedEdge& lEdge, const WeightedEdge& rEdge)
 {
    // Relational operator is flipped as to force the smaller value at the top of the stl priority queue
    return lEdge.weight < rEdge.weight;
 }

 public:

 WeightedEdge() : startIndex{0}, endIndex{0} {}

 WeightedEdge(int startIndex, int endIndex, const double weight, Labels label) :
    startIndex{startIndex},
    endIndex{endIndex},
    weight{weight},
    label{label} {}


 // Returns the index of the vertex at the opposite end of the edge
 int Opposite(int vertexIndex) const
 {
    return vertexIndex == startIndex ? endIndex : startIndex;
 }


    int startIndex;    //Starting vertex index
    int endIndex;      //Ending vertex index
    double weight;     //Weight of the edge
    Labels label;  //Label of the edge (Used for DFS)
 };

 /********************************************************************
 * struct WeightedEdgePairComparator
 * This comparator is used for the comparison of pair values in the
 * priority queue
 *********************************************************************/
 struct WeightedEdgePairComparator
 {
    bool operator() (const std::pair<double,int>& lPair, const std::pair<double,int>& rPair)
    {
        return lPair.first > rPair.first;
    }
 };

#endif //VERTEX_H
