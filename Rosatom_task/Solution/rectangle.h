#pragma once

#include <vector>

class Rectangle
{
public:
    int x, y;
    bool is_rotated;

    Rectangle(int _length, int _width): length(_length), width(_width)
    {
        square = _length * _width;

        is_rotated = false;
        this->x = 400;
        y = 0;
    }

    Rectangle(int _length, int _width, int x_isnt_fit): length(_length), width(_width)
    {
        square = _length * _width;

        is_rotated = false;
        this->x = x_isnt_fit;
        y = 0;
    }

    bool operator > (const Rectangle& sother) const;

    int get_length() const;

    int get_width() const;

    void swap_length_width();

private:
    int length;
    int width;
    int square;
};
