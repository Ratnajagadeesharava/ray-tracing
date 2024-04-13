// Ray_Tracing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//https://raytracing.github.io/books/RayTracingInOneWeekend.html#overview


#include "typedefs.hpp"
#include "camera.hpp"
#include "Hittable_List.hpp"


int main()
{
    Hittable_List world;

    std::shared_ptr<Sphere> sphere1 =std::make_shared<Sphere>( new Sphere(point(0, 0, -3), 1.0));
    sphere1->Color = color(1.0, 1.0, 0);
    world.addHittableObject(sphere1);

   
    Camera* camera = new Camera();
    
    camera->render(world);

}