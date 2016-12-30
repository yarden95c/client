////
//// Created by yarden95c on 08/12/16.
////
//
//#include "GameFlow.h"
//#include "Bfs.h"
//
//using namespace std;
//
///**
// * constractur of game flow.
// * @param map map of the city
// * @return nothing
// */
//GameFlow::GameFlow(Map *map) {
//    grid = map;
//    taxiCenter = new TaxiCenter();
//}
//
///**
// * destractur
// */
//GameFlow::~GameFlow() {
//    delete (taxiCenter);
//}
//
///**
// * menu optinos of program
// */
//void GameFlow::startGame() {
//    int choice;
//    cin >> choice;
//    while (choice != 7) {
//        switch (choice) {
//            case 1:
//                this->insertDriver();
//                break;
//            case 2:
//                this->insertARide();
//                break;
//            case 3:
//                this->insertAVehicle();
//                break;
//            case 4:
//                this->printDriverLocation();
//                break;
//            case 6:
//                this->startDriving();
//                break;
//            default:
//                break;
//        }
//        cin >> choice;
//    }
//}
//
///**
// * insert a new driver to the list of driversInfo in the taxiCenter
// */
//void GameFlow::insertDriver() {
//    int id, age, experience, cabId;
//    Status status;
//    char c, statusLetter;
//    Driver *driver;
//
//    cin >> id >> c >> age >> c >> statusLetter >> c >>
//        experience >> c >> cabId;
//    status = Status(statusLetter);
//    driver = new Driver(grid, id, age, status, experience, cabId);
//    taxiCenter->addDriverInfo(driver);
//    driver = NULL;
//    // set the pointer to point on null so when
//    // the object will delete this pointer will no longer point on it
//}
//
///**
// * insert a new trip to the trips in the taxi center
// * trip doesn't have a driver yet, only in choice 6 we add a driver to
// * each trip
// */
//void GameFlow::insertARide() {
//    int id, xStart, yStart, xEnd, yEnd, numOfPassengers;
//    double tariff;
//    char c;
//    cin >> id >> c >> xStart >> c >> yStart >> c >> xEnd >> c >> yEnd >> c
//        >> numOfPassengers >> c >> tariff;
//    Point *start = new Point(xStart, yStart);
//    Point *end = new Point(xEnd, yEnd);
//    Trip *trip = new Trip(id, start, end, numOfPassengers, tariff);
//    taxiCenter->addTrip(trip);
//    start = NULL;
//    end = NULL;
//    trip = NULL;
//    // set the pointers to point on null so when
//    // the objects will delete those pointers will no longer point on them
//
//}
//
///**
// * insert a new vehicle to the cabs in the taxi center
// */
//void GameFlow::insertAVehicle() {
//    int id, taxiType;
//    char manufacturerLetter, colorLetter, c;
//    Color color;
//    CarType carType;
//    cin >> id >> c >> taxiType >> c >> manufacturerLetter >> c >> colorLetter;
//    color = Color(colorLetter);
//    carType = CarType(manufacturerLetter);
//    Cab *cab = new Cab(id, 0, carType, color);
//    taxiCenter->addCab(cab);
//    cab = NULL;
//    // set the pointer to point on null so when
//    // the object will delete this pointer will no longer point on it
//
//}
//
///**
// *printing the currrent location of a specific driver
// */
//void GameFlow::printDriverLocation() {
//    vector<Driver *> v = taxiCenter->getDriversInfo();
//    int driverId;
//    cin >> driverId;
//    for (vector<Driver *>::iterator it = v.begin(); it != v.end(); it++) {
//        if ((*it)->getDriverId() == driverId) {
//            cout << *((*it)->getCurrentLocation()) << endl;
//        }
//    }
//}
//
///**
// * set all the drivers to the closest trip and getting
// * allthe drivers to end point
// */
//void GameFlow::startDriving() {
//    Bfs bfs(grid);
//    vector<Trip *> trips = taxiCenter->getTrips();
//    vector<Driver *> drivers = taxiCenter->getDriversInfo();
//    for (vector<Trip *>::iterator it = trips.begin(); it != trips.end(); it++){
//        Point *startLocation = (*it)->getStartPoint();
//        int minSteps = 1000;
//        for (vector<Driver *>::iterator itD = drivers.begin();
//             itD != drivers.end(); itD++) {
//            if ((*itD)->isAvailable()) {
//                Point *driverLocation = (*itD)->getCurrentLocation();
//                int numOfSteps = bfs.findNumOfSteps(startLocation,
//                                                    driverLocation);
//                if (numOfSteps < minSteps) {
//                    minSteps = numOfSteps;
//                    (*it)->setDriver(*itD);
//                }
//            }
//        }
//        Point *end = (*it)->getEndPoint();
//        Driver *driver = (*it)->getDriver();
//        if(driver !=NULL) {
//            driver->setCurrLocation(end);
//        }
//        end = NULL;
//        driver = NULL;
//        startLocation = NULL;
//        // set the pointers to point on null so when
//        // the objects will delete those pointers will no longer point on them
//    }
//    int sizeOfDrivers = drivers.size();
//    while (sizeOfDrivers > 0) {
//        taxiCenter->popTrip();
//        sizeOfDrivers--;
//    } //deleting the trip who has drivers and
//}