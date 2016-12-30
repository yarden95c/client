//
// Created by yarden95c on 08/12/16.
//

#ifndef EX3_MENU_H
#define EX3_MENU_H

#include <iostream>
#include <list>
#include "Status.h"
#include "Map.h"
#include "Color.h"
#include "CarType.h"
#include "LuxuryCab.h"
#include "StandardCab.h"

class GameFlow {
private:
    Map *grid;
//TaxiCenter *taxiCenter;

public:
    GameFlow(Map *map);

    void startGame();

    void insertDriver();

    void insertARide();

    void insertAVehicle();

    void printDriverLocation();

    void startDriving();

    ~GameFlow();

};


#endif //EX3_MENU_H
