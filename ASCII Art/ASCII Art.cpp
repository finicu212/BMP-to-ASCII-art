#include <iostream>
#include "../includes/EasyBMP/EasyBMP.h"

int main()
{
    BMP image;
    image.ReadFromFile("photo.bmp");

    std::cout << image.TellWidth() << ", " << image.TellHeight();

    return 0;
}