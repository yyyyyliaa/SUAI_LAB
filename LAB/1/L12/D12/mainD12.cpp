/*Создайте класс SquareTriangle с координатами 3-х вершин. 
В конструкторе предусмотреть проверку того, что треугольник прямоугольный. 
Реализовать элементы-функции для масштабирования, поворота на 90, зеркального отражения от оси ординат.*/

/*Написать функцию, считающую пощадь треугольника и функцию "склеивания" треугольников в прямоугольник*/

#include <iostream>
#include "squareTriangleDop.h"
using namespace std;
 
int main() {

    double coordX[3];
    double coordY[3];

    double coordX1[3];
    double coordY1[3];

    // double coordXRec[4];
    // double coordYRec[4];

    cout<<"Enter coordinates of first triangle:"<<endl;
    for (int i = 0; i <= 2; i++){
            cout<<"Enter coordinate x" << i << ":";
            cin >> coordX[i];
            cout<<"Enter coordinate y"<< i << ":";
            cin >> coordY[i];
            cout<<endl;
    }

    cout<<endl;
    
    cout<<"Enter coordinates of second triangle:"<<endl;
    for (int i = 0; i <= 2; i++){
            cout<<"Enter coordinate x" << i << ":";
            cin >> coordX1[i];
            cout<<"Enter coordinate y"<< i << ":";
            cin >> coordY1[i];
            cout<<endl;
    }

    
    int check;
    Rectaingle rec (coordX, coordY,coordX1, coordY1);

    rec.printIndexBase();


    return 0;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    // int check;
    // SquareTriangle treug (coordX, coordY);
    // SquareTriangle treug1 (coordX1, coordY1);

    // check = treug.rightTriangle();
    // if (check==1) {
    //     //cout<< "This is a right triangle"<<endl;
    //     double square = treug.square();
    //     cout << "Square of first triangle:" << square << endl;

    // }
    // else cout<<"This is not a right triangle"<<endl;

    // check = treug1.rightTriangle();
    // if (check==1) {
    //     //cout<< "This is a right triangle"<<endl;
    //     double square = treug.square();
    //     cout << "Square of second triangle:" << square << endl;

    // }
    // else cout<<"This is not a right triangle"<<endl;

    // check = treug.rightTriangle()+treug1.rightTriangle();
    // if (check==2) {
    //     cout<< "Both triangles are right"<<endl;

    //     //initRectangle(coordX, coordY, coordX1, coordY1, coordXRec, coordYRec);

    //     cout<<"Coordinate rectangle:"<< endl;
    //     for(int i = 0; i<4; i++){
    //         cout << "(" << coordXRec[i] << "; " << coordYRec[i] << ")" << endl;
    //     }   

    // }
    // else cout<<"Merging triangles is impossible"<<endl;
}