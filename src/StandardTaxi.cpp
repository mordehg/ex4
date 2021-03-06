#include "StandardTaxi.h"
/**
 * class: StandartdTaxi
 * this class inheritor from the Taxi class,
   it implements the moveOneStep method only
 */


/**
 * Constructor
 * @param the taxi's id, manufacture name, color, price coefficient
 * @return the build taxi with 1 as type, for luxury taxi.
 */
StandardTaxi::StandardTaxi(int id, char manu, char color) {
    this->ID = id;
    this->carType = 1;
    this->manufactuer = manu;
    this->color = color;
    this->kilometerSum = 0;
    //temp trip for flags:
    Block start = Block(Point(0,0));
    this->currentTrip = TripInfo(-1, start, start, 0, 0,0);
    this->currentTrip.currentUpdate(start);
}

/**
 * moveOnStep
 * @param the map of the game.
 * make the taxi moment, for a standard one moves 1
   block, for luxury one moves 2 blocks
 * @return 1 - if the trip get to an end
           0 - otherwise
 */
int StandardTaxi::moveOneStep(Map map) {
    return this->currentTrip.updateCurrentOneStep(1, map);
}