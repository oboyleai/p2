// Project UID af1f95f547e44c8ea88730dfb185559d

#include <cassert>
#include "Image.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
// REQUIRES: img points to an Image
//           0 < width && width <= MAX_MATRIX_WIDTH
//           0 < height && height <= MAX_MATRIX_HEIGHT
// MODIFIES: *img
// EFFECTS:  Initializes the Image with the given width and height.
// NOTE:     Do NOT use new or delete here.
void Image_init(Image *img, int width, int height)
{
  img->width = width;
  img->height = height;
}

// REQUIRES: img points to an Image
//           is contains an image in PPM format without comments
//           (any kind of whitespace is ok)
// MODIFIES: *img
// EFFECTS:  Initializes the Image by reading in an image in PPM format
//           from the given input stream.
// NOTE:     See the project spec for a discussion of PPM format.
// NOTE:     Do NOT use new or delete here.
void Image_init(Image *img, std::istream &is)
{
  string rgbVal, emptyPlaceHolder, fileType, width, height, rVal, gVal, bVal;
  // reads the first line of the ppm file which is the file type
  // getline(is, fileType);
  is >> fileType;
  is >> width >> height;
  // converts the width and height which is stored as a string to
  // an int and stores it in the image stuct
  img->width = stoi(width);
  img->height = stoi(height);

  // skips the newline after width and height
  // getline(is, emptyPlaceHolder);
  is >> rgbVal;

  Matrix_init(&(img->red_channel), img->width, img->height);
  Matrix_init(&(img->green_channel), img->width, img->height);
  Matrix_init(&(img->blue_channel), img->width, img->height);
  // Test if whitespace is skipped over
  for (int row = 0; row < img->height; row++)
  {
    for (int col = 0; col < img->width; col++)
    {
      is >> rVal >> gVal >> bVal;
      *(Matrix_at(&(img->red_channel), row, col)) = stoi(rVal);
      *(Matrix_at(&(img->green_channel), row, col)) = stoi(gVal);
      *(Matrix_at(&(img->blue_channel), row, col)) = stoi(bVal);
    }
  }
}

// REQUIRES: img points to a valid Image
// EFFECTS:  Writes the image to the given output stream in PPM format.
//           You must use the kind of whitespace specified here.
//           First, prints out the header for the image like this:
//             P3 [newline]
//             WIDTH [space] HEIGHT [newline]
//             255 [newline]
//           Next, prints out the rows of the image, each followed by a
//           newline. Each pixel in a row is printed as three ints
//           for its red, green, and blue components, in that order. Each
//           int is followed by a space. This means that there will be an
//           "extra" space at the end of each line. See the project spec
//           for an example.
void Image_print(const Image *img, std::ostream &os)
{
  // prints header info of ppm file
  os << "P3" << endl;
  os << Image_width(img) << " " << Image_height(img) << endl;
  os << "255" << endl;
  for (int row = 0; row < img->height; row++)
  {
    // only ends the line after printing the first row
    if (row != 0)
    {
      os << endl;
    }
    // prints body of the ppm file
    for (int col = 0; col < img->width; col++)
    {
      os << *Matrix_at(&(img->red_channel), row, col) << " ";
      os << *Matrix_at(&(img->green_channel), row, col) << " ";
      os << *Matrix_at(&(img->blue_channel), row, col) << " ";
    }
  }
  os << endl;
}

// REQUIRES: img points to a valid Image
// EFFECTS:  Returns the width of the Image.
int Image_width(const Image *img)
{
  return img->width;
}

// REQUIRES: img points to a valid Image
// EFFECTS:  Returns the height of the Image.
int Image_height(const Image *img)
{
  return img->height;
}

// REQUIRES: img points to a valid Image
//           0 <= row && row < Image_height(img)
//           0 <= column && column < Image_width(img)
// EFFECTS:  Returns the pixel in the Image at the given row and column.
Pixel Image_get_pixel(const Image *img, int row, int column)
{
  Pixel p;
  int rVal;
  int gVal;
  int bVal;
  rVal = *(Matrix_at(&(img->red_channel), row, column));
  p.r = rVal;
  gVal = *(Matrix_at(&(img->green_channel), row, column));
  p.g = gVal;
  bVal = *(Matrix_at(&(img->blue_channel), row, column));
  p.b = bVal;
  return p;
}

// REQUIRES: img points to a valid Image
//           0 <= row && row < Image_height(img)
//           0 <= column && column < Image_width(img)
// MODIFIES: *img
// EFFECTS:  Sets the pixel in the Image at the given row and column
//           to the given color.
void Image_set_pixel(Image *img, int row, int column, Pixel color)
{
  *(Matrix_at(&(img->red_channel), row, column)) = color.r;
  *(Matrix_at(&(img->green_channel), row, column)) = color.g;
  *(Matrix_at(&(img->blue_channel), row, column)) = color.b;
}

// REQUIRES: img points to a valid Image
// MODIFIES: *img
// EFFECTS:  Sets each pixel in the image to the given color.
void Image_fill(Image *img, Pixel color)
{
  for (int row = 0; row < Image_height(img); row++)
  {
    for (int col = 0; col < img->width; col++)
    {
      *(Matrix_at(&(img->red_channel), row, col)) = color.r;
      *(Matrix_at(&(img->green_channel), row, col)) = color.g;
      *(Matrix_at(&(img->blue_channel), row, col)) = color.b;
    }
  }
}
