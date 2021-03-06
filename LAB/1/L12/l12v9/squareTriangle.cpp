/*Создайте класс SquareTriangle с координатами 3-х вершин.
В конструкторе предусмотреть проверку того, что треугольник прямоугольный.
Реализовать элементы-функции для масштабирования, поворота на 90, зеркального отражения от оси ординат.*/

#include <iostream>
#include "squareTriangle.h"
#include <math.h>
using namespace std;


SquareTriangle::SquareTriangle(double* coordX, double* coordY){
    setTriangle(coordX, coordY);
}

void SquareTriangle::setTriangle(double* coordX, double* coordY){
    for (int i = 0; i < 3; i++){
        p_coordX[i] = coordX[i];
        p_coordY[i] = coordY[i];
    }
}

void SquareTriangle::definitionCoord(int& indexVert, int& indexHeight, int& indexBase){
    if ((this->p_coordX[0]==this->p_coordX[1])&&(this->p_coordY[0]==this->p_coordY[2])){
        indexVert = 0;
        indexHeight = 1;
        indexBase = 2;
    }
    else if ((this->p_coordX[0]==this->p_coordX[2])&&(this->p_coordY[0]==this->p_coordY[1])){
        indexVert = 0;
        indexHeight = 2;
        indexBase = 1;
    }
    else if ((this->p_coordX[1]==this->p_coordX[0])&&(this->p_coordY[1]==this->p_coordY[2])){ 
        indexVert = 1;
        indexHeight = 0;
        indexBase = 2;
    }
    else if ((this->p_coordX[1]==this->p_coordX[2])&&(this->p_coordY[1]==this->p_coordY[0])){
        indexVert = 1;
        indexHeight = 2;
        indexBase = 0;
    }
    else if ((this->p_coordX[2]==this->p_coordX[1])&&(this->p_coordY[2]==this->p_coordY[0])){ 
        indexVert = 2;
        indexHeight = 1;
        indexBase = 0;
    }
    else if ((this->p_coordX[2]==this->p_coordX[0])&&(this->p_coordY[2]==this->p_coordY[1])){
        indexVert = 2;
        indexHeight = 0;
        indexBase = 1;
    }
}

void SquareTriangle::scaleTriangle(double n){
    int indexVert;
    int indexHeight;
    int indexBase;

    definitionCoord(indexVert, indexHeight, indexBase);
    
    p_coordY[indexHeight]= (p_coordY[indexHeight]-p_coordY[indexVert])*sqrt(n)+p_coordY[indexVert];
    p_coordX[indexBase] = (p_coordX[indexBase]-p_coordX[indexVert])*sqrt(n)+p_coordX[indexVert];
}

void SquareTriangle::turnTriangle(){
    int indexVert;
    int indexHeight;
    int indexBase;
    
    definitionCoord(indexVert, indexHeight, indexBase);

    int tmpCoordHeightX = p_coordX[indexHeight];
    int tmpCoordHeightY = p_coordY[indexHeight];

    p_coordX[indexHeight] = (p_coordY[indexVert]-p_coordY[indexBase])+p_coordX[indexVert];
    p_coordY[indexHeight] = (p_coordX[indexVert]-p_coordX[indexBase])+p_coordY[indexVert];

    p_coordX[indexBase] = tmpCoordHeightY;
    p_coordY[indexBase] = tmpCoordHeightX;

}

void SquareTriangle::mirrorTriangle(){
    int indexVert;
    int indexHeight;
    int indexBase;
    
    definitionCoord(indexVert, indexHeight, indexBase);

    int tmpCoordHeightX = p_coordX[indexHeight];
    int tmpCoordHeightY = p_coordY[indexHeight];

    p_coordX[indexHeight] = p_coordX[indexBase];
    p_coordY[indexHeight] = p_coordY[indexBase];

    p_coordY[indexBase] = p_coordY[indexVert]+(p_coordY[indexVert]-tmpCoordHeightY);
    p_coordX[indexBase] = p_coordX[indexVert]+(p_coordX[indexVert]-tmpCoordHeightX);

}

void mySort(int *array, int size){
    for (int i = 0; i < size; i++){
        for (int j = size - 1; j > i; j--){
            if (array[j - 1] > array[j]){
                int tmp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = tmp;
            }
        }
    }
}

int SquareTriangle::rightTriangle(){
    int len[3];
    len[0] = pow(p_coordX[0] - p_coordX[1], 2) + pow(p_coordY[0] - p_coordY[1], 2);
    len[1] = pow(p_coordX[1] - p_coordX[2], 2) + pow(p_coordY[1] - p_coordY[2], 2);
    len[2] = pow(p_coordX[2] - p_coordX[0], 2) + pow(p_coordY[2] - p_coordY[0], 2);

    mySort(len, 3);

    if ((len[0] + len[1]) == len[2])
        return 1;
    return 0;
}

// int SquareTriangle::checkTriangle(){
//     int len[3];
//     len[0] = sqrt(pow(p_coordX[0] - p_coordX[1], 2) + pow(p_coordY[0] - p_coordY[1], 2));
//     len[1] = sqrt(pow(p_coordX[1] - p_coordX[2], 2) + pow(p_coordY[1] - p_coordY[2], 2));
//     len[2] = sqrt(pow(p_coordX[0] - p_coordX[2], 2) + pow(p_coordY[0] - p_coordY[2], 2));

//     if ((len[0] < len[1] + len[2]) && (len[1] < len[0] + len[2]) && (len[2] < len[1] + len[0]))
//         return 1;
//     else return 0;
// }

void SquareTriangle::printTriangle(){
    for (int i = 0; i < 3; i++){
        cout << "(" << p_coordX[i] << "; " << p_coordY[i] << ")" << endl;
    }
}