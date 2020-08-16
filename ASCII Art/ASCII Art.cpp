#include <iostream>
#include "../includes/EasyBMP/EasyBMP.h"

unsigned char getMostIntenseColor(RGBApixel pixel)
{
    unsigned char mostIntense = pixel.Red;
    if (pixel.Blue > mostIntense)
        mostIntense = pixel.Blue;
    if (pixel.Green > mostIntense)
        mostIntense = pixel.Green;

    return mostIntense;
}

int main()
{
    BMP image;
    image.ReadFromFile("../input/photo1.bmp");

    // source: http://paulbourke.net/dataformats/asciiart/
    const char *intensityRamp = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";

    for (int i = 0; i < image.TellWidth() - 1; i++)
    {
        for (int j = 0; j < image.TellHeight() - 1; j++)
        {
            RGBApixel currPixel = image.GetPixel(i, j);

            unsigned char mostIntense = getMostIntenseColor(currPixel);
            std::cout << (int) mostIntense << "\n";
        }
    }

    return 0;
}