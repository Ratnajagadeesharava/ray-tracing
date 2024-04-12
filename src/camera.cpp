#include "camera.hpp"

Camera::Camera()
{
}

void write_to_file(std::string input, std::string filename)
{
    std::ofstream outputFile(filename);
    if (!outputFile.is_open())
    {
        std::cerr << "file cannot be created" << std::endl;
        return;
    }
    outputFile << input;
    outputFile.close();
    std::clog << filename << "    File written successfully." << std::endl;
}

void Camera::createPPM()
{
    std::cout << origin_pixel_position << std::endl;
    std::stringstream sstream;
    sstream << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    std::stringstream log_string;
    for (int i = 0; i < image_height; i++)
    {
        for (int j = 0; j < image_width; j++)
        {
            point current_pixel_position = origin_pixel_position + pixel_delt_u * j + pixel_delt_v * i;
            ray r(current_pixel_position, current_pixel_position - camera_position);
            color c = RayColor(r, &log_string);
            float red = 255.999 * c.get_x();
            float green = 255.999 * c.get_y();
            float blue = 255.999 * c.get_z();
            sstream << red << " " << green << " " << blue << "\n";
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
    Sphere sphere(point(0, 0, -3), 1.0);
    sphere.Color = color(1.0, 1.0, 0);

    float t = sphere.isRayHitSpehere(r);
    if (t > 0.0)
    {
        vec3 N = (r.at(t) - sphere.center).unit_vector();
        return color(abs(N.get_x()), abs(N.get_y()), abs(N.get_z()));
    }

    vec3 unit_direction = r.getDirection().unit_vector();
    auto a = 0.5 * (unit_direction.get_y() + 1.0);
    return color(1.0, 1.0, 1.0) * (1.0 - a) + color(0.5, 0.7, 1.0) * a;
}
