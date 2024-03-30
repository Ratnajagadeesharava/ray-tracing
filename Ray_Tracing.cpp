// Ray_Tracing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//https://raytracing.github.io/books/RayTracingInOneWeekend.html#overview

#include <iostream>
#include<sstream>
#include <fstream>
#include <string>
#include <cmath>
#include "typedefs.hpp"
float scaleDownPixel(float value, float scaleValue) {
    return value / 255;
}
float scaleUpPixel(float value, float scaleValue) {
	return value * 255;
}

float clamp(float value, float min, float max) {
    if (value < min) {
		return min;
	}
    if (value > max) {
		return max;
	}
	return value;
}

float lerp(float a, float b, float t) {
	return (1 - t) * a + t * b;
}

float remap(float value, float min, float max, float new_min, float new_max) {
	return new_min + (value - min) * (new_max - new_min) / (max - min);
}

float remapClamped(float value, float min, float max, float new_min, float new_max) {
	return clamp(remap(value, min, max, new_min, new_max), new_min, new_max);
}

void write_to_file(std::string input, std::string filename) {
    std::ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        std::cerr << "file cannot be created"<< std::endl;
        return;
    }
    outputFile << input;
    outputFile.close();
    std::clog << filename << "    File written successfully." << std::endl;
}


void createPPM(int image_height,int image_width) {
    //rgb --> r '' g '' b \n
    std::stringstream sstream;
    sstream << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    std::cout <<sstream.str();
    for (int i = 0; i < image_height; i++) {
        /*std::clog << "Lines remaining:  " << (image_height - i) << "  \n" << std::flush;*/
        for (int j = 0; j < image_width; j++) {
            
            int r = i;
            int g = (i + j);
            int b = sin(j);

            sstream << r << " " << g << " " << b << "\n";
        }
    }
    write_to_file(sstream.str(), "test.ppm");
}

int main()
{
    //createPPM(256, 256);
    point camera_position = point(0, 0, 0);
    float focal_length = 1.0f;
    float aspect_ratio = 16.0f / 9.0f;
    std::cout << "Aspect ratio: " << aspect_ratio << std::endl;
    float width_temp = (aspect_ratio * 400.0f);
std::cout<<"temp width " << width_temp << std::endl;
    createPPM(400,width_temp);
    int image_width = 400;
    float view_port_width = 2.0f;
    float view_port_height = view_port_width / aspect_ratio;
    //relative to the left top point
    vec3 view_port_u = vec3(view_port_width, 0, 0);
    vec3  view_port_v = vec3(0, -view_port_height, 0);
    int image_height;
    vec3 view_port_normal = vec3(0, 0, 1);
    vec3 view_port_origin = (view_port_normal - camera_position) - (view_port_u + view_port_v) / 2;
    std::cout << view_port_normal << std::endl;


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
