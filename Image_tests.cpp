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

// IMPLEMENT YOUR TEST FUNCTIONS HERE
// You are encouraged to use any functions from Image_test_helpers.h as needed.

// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()

// no idea how to test this
// TEST(testInitWFile)
// {

//   Image *img = new Image; // create an Image in dynamic memory

//   // const Pixel red = {255, 0, 0};
//   // const Pixel green = {0, 255, 0};
//   // const Pixel blue = {0, 0, 255};
//   // const Pixel white = {255, 255, 255};

//   string fileName = "dog.ppm";
//   ifstream fin;
//   // fin.open(fileName);
//   fin.open(fileName);
//   Image_init(img, fin);
//   // ASSERT_EQUAL(Image_equal(img))
// }

// ba

TEST(testSetGetPixelBasic)
{
  Image *img = new Image; // create an Image in dynamic memory

  const Pixel white = {255, 255, 255};

  Image_init(img, 2, 2);
  Image_set_pixel(img, 1, 1, white);

  // assert(Image_get_pixel(img, 1, 1))

  Pixel imgPxl = Image_get_pixel(img, 1, 1);

  ASSERT_EQUAL(imgPxl.r, 255);
  ASSERT_EQUAL(imgPxl.g, 255);
  ASSERT_EQUAL(imgPxl.b, 255);

  delete img; // delete the Image
}

TEST_MAIN() // Do NOT put a semicolon here
