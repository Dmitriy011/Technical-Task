#include "level.h"

bool Level::place_without_turn(Rectangle& rectangle, int& rest_length, int& heigth)
{
    bool is_successed = rest_width >= rectangle.get_width() && rest_length >= rectangle.get_length();

    if(is_successed == true)
    {
        rest_width = rest_width - rectangle.get_width();

        if(is_empty == true)
        {
            rest_length = rest_length - rectangle.get_length();
        }
        is_empty = false;

        rectangle.x = rest_width;
        rectangle.y = heigth;
    }

    return is_successed;
}

bool Level::place_with_turn(Rectangle& rectangle, int& rest_length, int& heigth)
{
    bool is_successed = rest_width >= rectangle.get_length() && rest_length >= rectangle.get_width();

    if(is_successed == true)
    {
        rest_width = rest_width - rectangle.get_length();

        if(is_empty == true)
        {
            rest_length = rest_length - rectangle.get_width();
        }
        is_empty = false;

        rectangle.x = rest_width;
        rectangle.y = heigth;
        rectangle.is_rotated  = true;
    }

    return is_successed;
}

void Level::add_inline(Rectangle& rectangle)
{
    rest_width = rest_width - rectangle.get_width();

    rectangle.x = rest_width;
    rectangle.y = cur_heigth;
}

bool Level::is_space_available_inRow(Rectangle& rectangle)
{
    if(is_empty == true)
    {
        return false;
    }

    return rest_width >= rectangle.get_width();
}
