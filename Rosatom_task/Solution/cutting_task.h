#include "rectangle.h"

#include <vector>
#include <algorithm>
#include <iostream>

#include <QDebug>

bool compareRectangles(const Rectangle& r1, const Rectangle& r2);

void calculate_coord_rectangles(std::vector<Rectangle>& rectangles, const int length_main, const int width_main, const int count_list, int& count_of_manufactured);
