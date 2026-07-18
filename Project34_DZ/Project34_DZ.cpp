#include <iostream>
#include "CircleInSquare.h"

using namespace std;

int main() {

    CircleInSquare fig(5.0);
    fig.printInfo();

    fig.setFigureSide(20.0);
    fig.printInfo();

    fig.setFigureRadius(3.0);
    fig.printInfo();

}