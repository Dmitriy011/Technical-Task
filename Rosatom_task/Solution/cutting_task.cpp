#include "rectangle.h"
#include "level.h"

#include <vector>
#include <algorithm>
#include <iostream>

#include <QDebug>

bool compareRectangles(const Rectangle& r1, const Rectangle& r2)
{
    return r1 > r2;
}

void calculate_coord_rectangles(std::vector<Rectangle>& rectangles, const int length_main, const int width_main, const int count_list, int& count_of_manufactured)
{
    std::sort(rectangles.begin(), rectangles.end(), compareRectangles);

    std::vector<Level> level_vec;
    Level lvl0(width_main, 0);
    level_vec.push_back(lvl0);

    int rest_length = length_main;
    int heigth = 0;
    size_t cur_lvl = 0;

    for (int i = 0; i < count_list; ++i)
    {
        bool is_successed = level_vec[cur_lvl].place_without_turn(rectangles[i], rest_length, heigth);

        if(is_successed == true)
        {
            count_of_manufactured++;
            continue;
        }
        else
        {
            bool is_successed = level_vec[cur_lvl].place_with_turn(rectangles[i], rest_length, heigth);

            if(is_successed == true)
            {
                count_of_manufactured++;
                continue;
            }
            else
            {
                bool is_placed = false;
                for(size_t j = 0; j <= cur_lvl; j++)
                {
                    if(level_vec[j].is_space_available_inRow(rectangles[i]) == true)
                    {
                        level_vec[j].add_inline(rectangles[i]);

                        count_of_manufactured++;
                        is_placed = true;
                        break;
                    }
                }

                if(is_placed == false)
                {
                    heigth = length_main - rest_length;

                    Level newlvl(width_main, heigth);
                    level_vec.push_back(newlvl);
                    cur_lvl ++;

                    if(i != 0)
                    {
                        i--;
                    }
                    else
                    {
                        break;
                    }

                    bool is_height_sufficient = (rest_length - rectangles[i + 1].get_width()) >= 0  || (rest_length - rectangles[i + 1].get_length() >= 0);
                    if(is_height_sufficient == false)
                    {
                        break;
                    }
                }
            }
        }
    }
}

