//
// Created by Tim Zolleis on 22.10.24.
//


#include <cassert>
#include <string>

#include "position/position.h"

void positionCompareTest() {
    std::string mordor = "Mordor";
    tz::Position position(mordor, 47, 11);
    assert(position.compare(position)==0);
    tz::Position position_name("zordor", 47, 11);
    tz::Position position_x(mordor, 48, 11);
    tz::Position position_y(mordor, 47, 12);
    assert(position.compare(position_name)<0);
    assert(position.compare(position_x)<0);
    assert(position.compare(position_y)<0);
    assert(position_name.compare(position)>0);
    assert(position_x.compare(position)>0);
    assert(position_y.compare(position)>0);
}


int main() {
    positionCompareTest();
    return 0;
}
