//
// Created by moran on 03/12/16.
//

#include "StandardCab.h"

/**
 * constractor.
 * @param id cab id.
 * @param km number of km of cab.
 * @param cabType cab type.
 * @param color cab color.
 * @param cabSpeed cab speed.
 * @param cabTarif cab tarif.
 * @return nothing.
 */
StandardCab::StandardCab(int id, double km, enum CarType cabType,
                         enum Color color, int
                         cabSpeed, double cabTariff) :
        Cab(id, km, cabType, color) {
    speed = cabSpeed;
    tariff = cabTariff;
}

/**
 * get speed of cab.
 * @return speed of cab.
 */
int StandardCab::getSpeed() {
    return this->speed;
}

/**
 * get tarif of cab.
 * @return tarif of cab.
 */
double StandardCab::getTariff() {
    return this->tariff;
}

/**
 * destructor.
 */
StandardCab::~StandardCab() {

}
BOOST_CLASS_EXPORT(StandardCab)