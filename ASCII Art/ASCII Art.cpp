#include <iostream>
#include <fstream>
#include <string>
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
    std::string relativePath = "../input/", imagePath;

    std::cout << "Path to file (relative to input/): ";
    std::cin >> imagePath;
    relativePath += imagePath;

    image.ReadFromFile(relativePath.c_str());
    std::ofstream out;
    out.open("out.txt");

    if (!out.is_open())
    {
        std::cerr << "Failed opening output file";
        return 1;
    }

    // source: http://paulbourke.net/dataformats/asciiart/
    const char* intensityRamp = "@%#*+=-;. ";

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
    system("notepad.exe out.txt");

    return 0;
}