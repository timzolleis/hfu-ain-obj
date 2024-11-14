#include <cassert>

#include "../shared/city/city.h"

void testCity() {
    tz::City city("Mordor", 47, 11, nullptr, 0);
    assert(city.getNumberOfPOIs()==0);
    try {
        tz::City city("Mordor", 47, 11, nullptr, 23);
        assert(false);
    } catch (...) {
    }
    tz::City empty("Mordor", 47, 11);
    assert(empty.getNumberOfPOIs()==0);
}


void testAddPoi() {
    std::string pois[]={"Sauron", "Minas Morgul"};
    tz::City city("Mordor", 47, 11,pois,2);
    city.add("Orodruin");
    assert(city.getNumberOfPOIs()==3);
    assert(city.getPOI(2)=="Orodruin");
    tz::City empty("Mordor", 47, 11);
    empty.add("Orodruin");
    assert(empty.getNumberOfPOIs()==1);
    assert(empty.getPOI(0)=="Orodruin");
}

void testRemovePoi() {
    std::string pois[]={"Sauron", "Minas Morgul", "Orodruin"};
    tz::City city("Mordor", 47, 11, pois, 3);
    tz::City copy1=city;
    assert(true==copy1.remove("Orodruin"));
    assert(copy1.getNumberOfPOIs()==2);
    assert(false== copy1.remove("Shire"));
    tz::City copy2=city;
    assert(true==copy2.remove("Sauron"));
    assert(copy2.getNumberOfPOIs()==2);
    assert(copy2.getPOI(0)=="Minas Morgul");
    std::string saurons[]={"Sauron","Sauron","Sauron"};
    tz::City same("Mordor", 47, 11, saurons, 3);
    assert(true==same.remove("Sauron"));
    assert(same.getNumberOfPOIs()==0);
}


int main() {
    testRemovePoi();
    return 0;
}