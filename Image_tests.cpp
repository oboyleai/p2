// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Image_test_helpers.h"
#include "unit_test_framework.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Sets various pixels in a 2x2 Image and checks
// that Image_print produces the correct output.
TEST(test_print_basic)
{
  Image *img = new Image; // create an Image in dynamic memory

  const Pixel red = {255, 0, 0};
  const Pixel green = {0, 255, 0};
  const Pixel blue = {0, 0, 255};
  const Pixel white = {255, 255, 255};

  Image_init(img, 2, 2);
  Image_set_pixel(img, 0, 0, red);
  Image_set_pixel(img, 0, 1, green);
  Image_set_pixel(img, 1, 0, blue);
  Image_set_pixel(img, 1, 1, white);

  // Capture our output
  ostringstream s;
  Image_print(img, s);

  // Correct output
  ostringstream correct;
  correct << "P3\n2 2\n255\n";
  correct << "255 0 0 0 255 0 \n";
  correct << "0 0 255 255 255 255 \n";
  // cout << Image_get_pixel(img, 1, 1).;
  // cout << endl
  //      << endl
  //      << endl;
  // Image_print(img, cout);
  ASSERT_EQUAL(s.str(), correct.str());

  delete img; // delete the Image
}

// make max size tests

TEST(testSetGetPixelBasic)
{
  Image *img = new Image;
  const Pixel white = {255, 255, 255};
  Image_init(img, 2, 2);
  Image_set_pixel(img, 1, 1, white);
  Pixel imgPxl = Image_get_pixel(img, 1, 1);
  bool pixelEquals = Pixel_equal(imgPxl, white);
  ASSERT_TRUE(pixelEquals);
  delete img;
}

TEST(testWidth)
{
  Image *img = new Image;
  Image_init(img, 2, 2);
  const Pixel ming = {0, 0, 0};
  Image_fill(img, ming);
  ASSERT_EQUAL(Image_width(img), 2);
  delete img;
}

TEST(testHeight)
{
  Image *img = new Image;
  Image_init(img, 2, 2);
  const Pixel ming = {0, 0, 0};
  Image_fill(img, ming);
  ASSERT_EQUAL(Image_height(img), 2);
  delete img;
}

// should tests at all pixels?
TEST(testGetPixel)
{
  Image *img = new Image;
  Image_init(img, 2, 2);
  const Pixel pFill = {0, 0, 0};
  Image_fill(img, pFill);
  const Pixel pSet = {20, 21, 22};
  Image_set_pixel(img, 1, 1, pSet);
  const Pixel pGet = Image_get_pixel(img, 1, 1);
  ASSERT_EQUAL(pGet.r, pSet.r);
  ASSERT_EQUAL(pGet.b, pSet.b);
  ASSERT_EQUAL(pGet.g, pSet.g);
  delete img;
}

TEST(testImageFIll)
{
  Image *img = new Image;
  const int width = 2, height = 2;
  Image_init(img, width, height);
  Pixel pFill = {0, 0, 0};
  Image_fill(img, pFill);
  bool pixelsEqual;
  Pixel currPixel;
  for (int row = 0; row < height; row++)
  {
    for (int col = 0; col < width; col++)
    {
      currPixel = Image_get_pixel(img, row, col);
      pixelsEqual = Pixel_equal(currPixel, pFill);
      ASSERT_TRUE(pixelsEqual);
    }
  }
  delete img;
}

TEST(testImageFill1x1)
{
  Image *img = new Image;
  const int width = 1, height = 1;
  Image_init(img, width, height);
  Pixel pFill = {10, 10, 10};
  Image_fill(img, pFill);
  Pixel imgPixel = Image_get_pixel(img, 0, 0);
  bool pixelsEqual = Pixel_equal(imgPixel, pFill);
  ASSERT_TRUE(pixelsEqual);
  delete img;
}

// osstream init test using image equals

TEST(testImageInitStreamNormal)
{
  istringstream is;
  Image *img = new Image;
  string perfectImageString =
      "P3\n2 2\n255\n123 0 36 255 200 8 \n147 99 68 3 164 202 \n";
  is.str(perfectImageString);
  Image_init(img, is);
  ostringstream os;
  Image_print(img, os);
  ASSERT_EQUAL(os.str(), perfectImageString);
  delete img;
}
// large data size tests?

TEST(testImageInitStreamTerribleInput)
{
  istringstream is;
  string terribleInput = "P3 2 \n2 255 123\n 0 36\t255 200\n8 147\t99 68\t\t\t\t3 164 202";
  Image *img = new Image;
  string perfectImageString =
      "P3\n2 2\n255\n123 0 36 255 200 8 \n147 99 68 3 164 202 \n";
  is.str(terribleInput);
  Image_init(img, is);
  ostringstream os;
  Image_print(img, os);
  ASSERT_EQUAL(os.str(), perfectImageString);
  delete img;
}

TEST_MAIN() // Do NOT put a semicolon here
