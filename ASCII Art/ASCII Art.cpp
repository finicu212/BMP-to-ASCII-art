#include <iostream>
#include "../includes/EasyBMP/EasyBMP.h"

int main()
{
    BMP image;
    image.ReadFromFile("photo.bmp");

    // source: http://paulbourke.net/dataformats/asciiart/
    const char *intensityRamp = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";

    std::cout << intensityRamp << "\n";

    std::cout << image.TellWidth() << ", " << image.TellHeight();

    return 0;
}