#ifndef EX2_POINT_H
#define EX2_POINT_H

#include <fstream>
#include <sstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/assign/list_of.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/iostreams/device/back_inserter.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
using namespace std;
/** Class: Point
 * a simple point class, that holds a x any y values
 */
class Point {
private:
    int x;
    int y;

    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & x;
        ar & y;
    }
public:
    /**
     * default constructor
     */
    Point() {}
    /**
     * Constructor
     * @param two integers: the x value
                            the y value
     * @return the build point with the wanted values.
     */
    Point(int inputX, int inputY);
    /**
     * destructor
     * deletes the point.
     */
    ~Point() {}

    /**
     * getX
     * @return an integer, the x value
     */
    int getX() const{ return this->x; }
    /**
     * getY
     * @return an integer, the y value
     */
    int getY() const{ return  this->y; }

    /**
     * isNeighbours
     * @param a point, return true if the tow neighbours
       and false otherwise.
     */
    bool isNeighbours(Point other);
    /**
     * override the == operator for points
     */
    const bool operator== (const Point &other);

    /**
     * printPoint
     * prints the point in the format: "(x,y)"
     */
    void printPoint();

};

#endif //EX2_POINT_H
