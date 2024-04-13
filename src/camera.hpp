#pragma once
#include "typedefs.hpp"
#include "Hittable_List.hpp"
#include "Sphere.h"
#include "ray.hpp"
class Camera
{
private:
	point camera_position = point(0, 0, 0);
	float focal_length = 1.0f;
	float aspect_ratio = 16.0f / 9.0f;
	float view_port_width = 2.0f;
	float view_port_height = view_port_width / aspect_ratio;
	vec3 view_port_u = vec3(view_port_width, 0, 0);
	vec3 view_port_v = vec3(0, -view_port_height, 0);
	int image_height = 400;
	int image_width = (int)(aspect_ratio * image_height);
	vec3 view_port_normal = vec3(0, 0, -focal_length);
	vec3 view_port_origin = (view_port_normal -
		camera_position) - (view_port_u + view_port_v) / 2;
	vec3 pixel_delt_u = view_port_u / image_width;
	vec3 pixel_delt_v = view_port_v / image_height;
	vec3 origin_pixel_position = view_port_origin + pixel_delt_u / 2 + pixel_delt_v / 2;

	
public:
	Camera();
	static color RayColor(ray r, std:: stringstream *log_string, Hittable_List world);
	void render(Hittable_List world);

};

