//
// Created by moran on 03/12/16.
//

#include "LuxuryCab.h"

/**
 * constractor.
 * @param id cab id.
 * @param km number of km of cab.
 * @param cabType cab type.
 * @param color ca color.
 * @param cabSpeed cab speed.
 * @param cabTarif cab tarif.
 * @return nothing.
 */
LuxuryCab::LuxuryCab(int id, double km, enum CarType cabType, enum Color
color, int cabSpeed, double cabTariff) :
        Cab(id, km, cabType, color) {
    speed = cabSpeed;
    tariff = cabTariff;
}

/**
 * get speed of cab.
 * @return speed of cab.
 */
int LuxuryCab::getSpeed() {
    return this->speed;
}

/**
 * get tarif of cab.
 * @return tarif of cab.
 */
double LuxuryCab::getTariff() {
    return this->tariff;
}

/**
 * destructor.
 */
LuxuryCab::~LuxuryCab() {

}

BOOST_CLASS_EXPORT(LuxuryCab)