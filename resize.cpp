// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Image.h"
#include "processing.h"
#include <iostream>
#include "Matrix.h"
#include <cmath>
#include <string>
#include <fstream>
using namespace std;
int main(int argc, char *argv[])
{
  string errMsg = "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\nWIDTH and HEIGHT must be less than or equal to original\n";
  if (argc != 5 && argc != 4)
  {
    cout << errMsg;
    return 1;
  }

  //  *outputFileName, *widthImg, *heightImg
  char *inputFilename;
  char *outputFileName;
  char *widthImg;
  char *heightImg;
  inputFilename = *(argv + 1);
  outputFileName = *(argv + 2);
  widthImg = *(argv + 3);
  if (argc == 4)
  {
    heightImg = widthImg;
  }
  else
  {
    heightImg = *(argv + 4);
  }

  ifstream fin;
  string filName;
  fin.open(inputFilename);
  if (!fin.is_open())
  {
    cout << "Error opening file: " << inputFilename << endl;
    return 1;
  }
  else
  {
    Image *imgIn = new Image;
    Image_init(imgIn, fin);

    int imgHeight = stoi(heightImg);
    int imgWidth = stoi(widthImg);

    if (imgHeight > 0 && imgHeight <= Image_height(imgIn) &&
        imgWidth > 0 && imgWidth <= Image_width(imgIn))
    {
      seam_carve(imgIn, stoi(widthImg), stoi(heightImg));
      ofstream fout(outputFileName);
      Image_print(imgIn, fout);
    }
    else
    {
      cout << errMsg;
      return 1;
    }
  }

  // add functionality to throw if filename isn't good
}
