// Ray_Tracing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//https://raytracing.github.io/books/RayTracingInOneWeekend.html#overview

#include <iostream>
#include<sstream>
#include <fstream>
#include <string>
#include <cmath>
#include "typedefs.hpp"
#include "camera.hpp"
#include "Utils.h"
float scaleDownPixel(float value, float scaleValue) {
    return value / 255;
}





void createRaysAlongViewPort() {

}

float distanceBetweenTwoPoints(const point p1, const point p2) {
	
    return sqrt(pow(p1.get_x() - p2.get_x(), 2) + pow(p1.get_y() - p2.get_y(), 2) + pow(p1.get_z() - p2.get_z(), 2));
}


int main()
{
    Camera* camera = new Camera();
    
    camera->createPPM();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
