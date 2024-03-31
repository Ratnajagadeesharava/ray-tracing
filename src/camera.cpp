
#include "camera.hpp"


Camera::Camera()
{
	

}
void write_to_file(std::string input, std::string filename) {
	std::ofstream outputFile(filename);
	if (!outputFile.is_open()) {
		std::cerr << "file cannot be created" << std::endl;
		return;
	}
	outputFile << input;
	outputFile.close();
	std::clog << filename << "    File written successfully." << std::endl;
}

void Camera::createPPM()
{
	std::cout<< origin_pixel_position<< std::endl;
	std::stringstream sstream;
	sstream << "P3\n" << image_width << ' ' << image_height << "\n255\n";
	
	std::stringstream log_string ;
	for (int i = 0; i < image_height; i++) {
		/*std::clog << "Lines remaining:  " << (image_height - i) << "  \n" << std::flush;*/
		for (int j = 0; j < image_width; j++) {
			point curren_pixel_position = origin_pixel_position +pixel_delt_u*j + pixel_delt_v * i;
			ray r(curren_pixel_position,curren_pixel_position - camera_position);
			color c = RayColor(r, &log_string);
			float red = 255.999 * c.get_x();
			float green = 255.999 * c.get_y();
			float blue = 255.999 * c.get_z();
			sstream << red << " " << green << " " << blue << "\n";
			//ray r(camera_position, origin_pixel_position + j * pixel_delt_u + i * pixel_delt_v);
			
		}
	}
	write_to_file(sstream.str(), "../Ray_tracing/test.ppm");
	write_to_file(log_string.str(), "../Ray_tracing/log.txt");
}

void Camera::cast_rays()
{

}

color Camera::RayColor(ray r, std::stringstream *log_string)
{
	Sphere sphere (point(0, 0, -3), 1.0);
	sphere.Color = color(1.0, 1.0, 0);

	Sphere sphere2(point(0, 1.0, -2), 0.2);
	sphere2.Color = color(1.0, 0.0, 0);
	if (sphere2.isRayHitSpehere(r)) {
		return sphere2.Color;	
	}
	if (sphere.isRayHitSpehere(r)) {
		
		return sphere.Color;

	}
	vec3 unit_direction = r.getDirection().unit_vector();
	auto a = 0.5 * (unit_direction.get_y() + 1.0);
	return color(1.0, 1.0, 1.0)*(1.0 - a)   +  color(0.5, 0.7, 1.0) *a;
}




