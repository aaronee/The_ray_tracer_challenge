//
// Created by Khoa Huynh on 2020-07-08.
//

#include "Canvas.h"
Canvas::Canvas(Color background_color) : canvas_color{background_color} {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j){
            canvas_array[i][j] = background_color;
        }
    }
}
Canvas::~Canvas() {
    delete [] ppm;
}
bool Canvas::write_pixel(uint32_t x_val, uint32_t y_val, Color color_to_pixel) {
    if(x_val<width && y_val<height){
        canvas_array[y_val][x_val] = color_to_pixel;
        return 1;
    } else{
        return 0;
    }
}
Color Canvas::get_pixel(uint32_t x_val, uint32_t y_val) const {
    Color ret_col;
    ret_col = canvas_array[y_val][x_val];
    return ret_col;
}

char* Canvas::to_ppm() {
    char* ret_ppm = new char[2000];
    sprintf(ret_ppm, "P3\n");
    sprintf(ret_ppm+strlen(ret_ppm),"%d %d\n",width,height);
    sprintf(ret_ppm+strlen(ret_ppm),"255\n");

    float max_color_value{0};
    for (int i = 0; i <height ; ++i) {
        for (int j = 0; j < width; ++j) {
            max_color_value = (max_color_value<canvas_array[i][j].get_x()) ? canvas_array[i][j].get_x() : max_color_value;
            max_color_value = (max_color_value<canvas_array[i][j].get_y()) ? canvas_array[i][j].get_y() : max_color_value;
            max_color_value = (max_color_value<canvas_array[i][j].get_z()) ? canvas_array[i][j].get_z() : max_color_value;
        }
    }
    for (int k = 0; k <height ; ++k) {
        for (int i = 0; i < width ; ++i) {
            uint32_t scale_color = canvas_array[k][i].get_x() * 255 / max_color_value;
            if (scale_color > 255)
                scale_color = 255;
            else if (scale_color < 0)
                scale_color = 0;
            sprintf(ret_ppm + strlen(ret_ppm), "%d ", scale_color);

            scale_color = canvas_array[k][i].get_y() * 255 / max_color_value;
            if (scale_color > 255)
                scale_color = 255;
            else if (scale_color < 0)
                scale_color = 0;
            sprintf(ret_ppm + strlen(ret_ppm), "%d ", scale_color);

            scale_color = canvas_array[k][i].get_z() * 255 / max_color_value;
            if (scale_color > 255)
                scale_color = 255;
            else if (scale_color < 0)
                scale_color = 0;
            sprintf(ret_ppm + strlen(ret_ppm), "%d ", scale_color);
        }
        sprintf(ret_ppm+strlen(ret_ppm), "\n");
    }
    return ret_ppm;
}
void Canvas::to_array(uint16_t (*ret_array)[240]) {
    uint8_t red{};
    uint8_t green{};
    uint8_t blue{};

    float max_color_value{0};
    for (int i = 0; i <height ; ++i) {
        for (int j = 0; j < width; ++j) {
            max_color_value = (max_color_value<canvas_array[i][j].get_x()) ? canvas_array[i][j].get_x() : max_color_value;
            max_color_value = (max_color_value<canvas_array[i][j].get_y()) ? canvas_array[i][j].get_y() : max_color_value;
            max_color_value = (max_color_value<canvas_array[i][j].get_z()) ? canvas_array[i][j].get_z() : max_color_value;
        }
    }
    for (int k = 0; k <height ; ++k) {
        for (int i = 0; i < width ; ++i) {
            red = 0;
            red = canvas_array[k][i].get_x() * 255 / max_color_value;
            if (red > 255)
                red = 0xff;
            else if (red < 0)
                red = 0x00;
            red = red>>3;
            ret_array[k][i] |= (red<<11);

            green = 0;
            green = canvas_array[k][i].get_y() * 255 / max_color_value;
            if (green > 255)
                green = 0xff;
            else if (green < 0)
                green = 0x00;
            green = green >>2;
            ret_array[k][i] |= (green<<5);

            blue=0;
            blue = canvas_array[k][i].get_z() * 255 / max_color_value;
            if (blue > 255)
                blue = 0xff;
            else if (blue < 0)
                blue = 0x00;
            blue = blue >> 3;
            ret_array[k][i] |= blue;
        }
    }
}