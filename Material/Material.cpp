//
// Created by Khoa Huynh on 2020-07-18.
//

#include "Material.h"

Material::Material(Color color_val, float ambient_val, float diffuse_val, float specular_val, float shininess_val)
:material_color(color_val),ambient(ambient_val),diffuse(diffuse_val),specular(specular_val),shininess(shininess_val){}

Color Material::get_color() {return material_color;}
float Material::get_ambient() {return ambient;}
float Material::get_diffuse() {return diffuse;}
float Material::get_specular() {return specular;}
float Material::get_shininess() {return shininess;}

void Material::set_color(Color color_val) {material_color = color_val;}
void Material::set_ambient(float ambient_val) {ambient = ambient_val;}
void Material::set_diffuse(float diffuse_val) {diffuse = diffuse_val;}
void Material::set_specular(float specular_val) {specular = specular_val;}
void Material::set_shininess(float shininess_val) {shininess = shininess_val;}

