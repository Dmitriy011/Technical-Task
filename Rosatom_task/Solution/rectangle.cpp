#include "rectangle.h"

bool Rectangle::operator > (const Rectangle& other) const
{
    return this->square > other.square;
}

int Rectangle::get_length() const
{
     return this->length;
}

int Rectangle::get_width() const
{
    return this->width;
}

void Rectangle::swap_length_width()
{
    int tmp = this->length;

    this->length = this->width;
    this->width = tmp;
}
