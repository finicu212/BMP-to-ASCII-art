#include <iostream>
#include <fstream>
#include "../includes/EasyBMP/EasyBMP.h"

float getMostIntenseColor(RGBApixel pixel)
{
    float mostIntense = pixel.Red;
    if (pixel.Blue > mostIntense)
        mostIntense = pixel.Blue;
    if (pixel.Green > mostIntense)
        mostIntense = pixel.Green;

    return mostIntense;
}

int main()
{
    BMP image;
    image.ReadFromFile("../input/photo2.bmp");
    std::ofstream out;
    out.open("out.txt");

    if (!out.is_open())
    {
        std::cerr << "Failed opening output file";
        return 1;
    }

    // source: http://paulbourke.net/dataformats/asciiart/
    char intensityRamp[] = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";

    for (int i = 0; i < image.TellHeight(); i+=2)
    {
        for (int j = 0; j < image.TellWidth(); j++)
        {
            RGBApixel currPixel = image.GetPixel(j, i);

            int intensityRampIdx = getMostIntenseColor(currPixel) / 256 * strlen(intensityRamp);
            out << intensityRamp[intensityRampIdx];
        }
        out << "\n";
    }

    out.close();
    return 0;
}