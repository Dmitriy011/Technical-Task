#pragma once

#include <vector>

#include "rectangle.h"

class Level
{
public:

    Level(int rest_width, int cur_heigth)
    {
        this->rest_width = rest_width;
        this->cur_heigth = cur_heigth;

        is_empty = true;
    }

    bool place_without_turn(Rectangle& rectangle, int& rest_length, int& heigth);

    bool place_with_turn(Rectangle& rectangle, int& rest_length, int& heigth);

    void add_inline(Rectangle& rectangle);

    bool is_space_available_inRow(Rectangle& rectangle);

private:
    int rest_width;
    int cur_heigth;
    bool is_empty;
};
