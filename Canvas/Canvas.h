//
// Created by Khoa Huynh on 2020-07-08.
//

#ifndef RACETRACER_CANVAS_H
#define RACETRACER_CANVAS_H
#include "Color.h"
#include "array"
#include "cstring"

class Color;
class Canvas {
private:
    static const uint32_t width=240;
    static const uint32_t height=240;
    Color canvas_array[height][width];
    Color canvas_color;
    char *ppm = nullptr;
public:
    Canvas(Color background_color = Color{0,0,0});
    ~Canvas();
    bool write_pixel(uint32_t x_val, uint32_t y_val, Color color_to_pixel);
    Color get_pixel(uint32_t x_val, uint32_t y_val) const;
    char* to_ppm();
    void to_array(uint16_t ret_array[][240]);
};


#endif //RACETRACER_CANVAS_H
