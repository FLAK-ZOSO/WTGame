#pragma once

#include <experimental\map>
#include <iostream>
#include <string>
#include <vector>
#include <any>

#include "style.hpp"


unsigned int id_counter = 0;


class Object {
public:
    unsigned int id; // Need to be unique to remove the object from lists
    // Coordinates: the field's matrix will be accessed with matrix[y][x]
    int x;
    int y;
    char skin;
    Style style;
    std::pair<int, int> previous_position;
    std::map<std::string, int> int_attributes;
    std::map<std::string, char> char_attributes;

    Object(int x, int y, char skin) {
        this->id = id_counter++;
        this->x = x;
        this->y = y;
        this->skin = skin;
        this->previous_position = std::make_pair(x, y);
    }
    Object(unsigned int id, int x, int y, char skin) {
        this->id = id;
        this->x = x;
        this->y = y;
        this->skin = skin;
        this->previous_position = std::make_pair(x, y);
    }
    Object(unsigned int id, int x, int y, char skin, std::map<std::string, int> int_attributes, std::map<std::string, char> char_attributes) {
        this->id = id;
        this->x = x;
        this->y = y;
        this->skin = skin;
        this->previous_position = std::make_pair(x, y);
        this->int_attributes = int_attributes;
        this->char_attributes = char_attributes;
    }
    Object(int x, int y, char skin, std::map<std::string, int> int_attributes, std::map<std::string, char> char_attributes) {
        this->id = id_counter++;
        this->x = x;
        this->y = y;
        this->skin = skin;
        this->previous_position = std::make_pair(x, y);
        this->int_attributes = int_attributes;
        this->char_attributes = char_attributes;
    }

    ~Object() = default;


    void change_coordinates(int x, int y) {
        this->previous_position = std::make_pair(this->x, this->y);
        this->x = x;
        this->y = y;
    }
    void change_coordinates(std::pair<int, int> coordinates) {
        this->previous_position = std::make_pair(this->x, this->y);
        this->x = coordinates.first;
        this->y = coordinates.second;
    }
    void undo_coordinates() {
        this->x = this->previous_position.first;
        this->y = this->previous_position.second;
    }
};