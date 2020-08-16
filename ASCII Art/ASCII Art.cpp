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

    for (int i = 0; i < image.TellHeight(); i++)
    {
        for (int j = 0; j < image.TellWidth(); j++)
        {
            RGBApixel currPixel = image.GetPixel(j, i);

            unsigned char mostIntense = getMostIntenseColor(currPixel);
            std::cout << static_cast<int>(mostIntense) << "\n";
        }
    }

    return 0;
}