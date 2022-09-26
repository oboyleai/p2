// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Matrix_test_helpers.h"
#include "unit_test_framework.h"
#include "iostream"

using namespace std;

// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Fills a 3x5 Matrix with a value and checks
// that Matrix_at returns that value for each element.
TEST(test_fill_basic)
{
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  const int value = 42;
  Matrix_init(mat, 3, 5);
  Matrix_fill(mat, value);

  for (int r = 0; r < height; ++r)
  {
    for (int c = 0; c < width; ++c)
    {
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }

  delete mat; // delete the Matrix
}

// ADD YOUR TESTS HERE
// You are encouraged to use any functions from Matrix_test_helpers.h as needed.

// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()

// maybe need a matrix at
// TEST(testMatrixAt)
// {
//   Matrix *mat = new Matrix;
//   const int width = 4, height = 4, valInitial = 0;
//   Matrix_fill(mat, valInitial);

//   delete mat;
// }

// fill tests: 1x1, 1x10, 10x1 ?? any more

TEST(testFillBorder1x1)
{
  Matrix *mat = new Matrix;

  const int width = 1;
  const int height = 1;
  const int valFill = 40, valInitial = 1;
  Matrix_init(mat, width, height);
  cout << Matrix_width(mat) << endl;
  Matrix_fill(mat, valInitial);
  Matrix_fill_border(mat, valFill);
  ASSERT_EQUAL(*Matrix_at(mat, 0, 0), valFill);
  delete mat;
}

void printHelp(Matrix *mat, int r, int c)
{
  cout << "(" << r << ", " << c << ")"
       << ": " << *Matrix_at(mat, r, c) << endl;
}
// maybe need test case that does 5x4 and 4x5??
TEST(testFillBorder4by4)
{
  Matrix *mat = new Matrix;
  const int valFill = 40, valInitial = 1, w = 4, h = 4;
  Matrix_init(mat, w, h);
  Matrix_fill(mat, valInitial);
  Matrix_fill_border(mat, valFill);

  // tests that outer square is changed properly

  for (int c = 0; c < w; c += w - 1)
  {
    for (int r = 0; r < h; r++)
    {
      ASSERT_EQUAL(*Matrix_at(mat, r, c), valFill);
    }
  }

  //
  // for (int r = 0; r < h; r += h - 1)
  // {
  //   for (int c = 0; c < w; c++)
  //   {
  //     cout << "(" << r << ", " << c << "): " << *Matrix_at(mat, r, c) << endl;

  //     ASSERT_EQUAL(*Matrix_at(mat, r, c), valInitial);
  //   }
  // }

  // // tests that inner square isn't modified
  // for (int r = 1; r < w - 1; r++)
  // {
  //   for (int c = 1; c < h - 1; c++)
  //   {
  //     ASSERT_NOT_EQUAL(*Matrix_at(mat, r, c), valFill);
  //   }
  // }
  delete mat;
}

TEST(testFillBorder1x4)
{
  Matrix *mat = new Matrix;
  const int valFill = 40, valInitial = 1, w = 1, h = 4;
  Matrix_init(mat, w, h);
  Matrix_fill(mat, valInitial);
  Matrix_fill_border(mat, valFill);
  for (int r = 0; r < h; r++)
  {
    // printHelp(mat, r, 0);
    ASSERT_EQUAL(*Matrix_at(mat, r, 0), valFill);
  }
  delete mat;
}

TEST(testFillBorder4x1)
{
  Matrix *mat = new Matrix;
  const int valFill = 40, valInitial = 1, w = 4, h = 1;
  Matrix_init(mat, w, h);
  Matrix_fill(mat, valInitial);
  Matrix_fill_border(mat, valFill);
  for (int c = 0; c < w; c++)
  {
    ASSERT_EQUAL(*Matrix_at(mat, 0, c), valFill);
  }
  delete mat;
}

TEST(testFillBorder2x10)
{
  Matrix *mat = new Matrix;
  const int valFill = 40, valInitial = 1, w = 2, h = 10;
  Matrix_init(mat, w, h);
  Matrix_fill(mat, valInitial);
  Matrix_fill_border(mat, valFill);

  for (int c = 0; c < w; c += w - 1)
  {
    for (int r = 0; r < h; r++)
    {
      ASSERT_EQUAL(*Matrix_at(mat, r, c), valFill);
    }
  }
  delete mat;
}

TEST(testFillBorder10x2)
{
  Matrix *mat = new Matrix;
  const int valFill = 40, valInitial = 1, w = 10, h = 2;
  Matrix_init(mat, w, h);

  Matrix_fill(mat, valInitial);

  Matrix_fill_border(mat, valFill);

  for (int c = 0; c < w; c += w - 1)
  {
    for (int r = 0; r < h; r++)
    {
      ASSERT_EQUAL(*Matrix_at(mat, r, c), valFill);
    }
  }
  delete mat;
}

TEST(testMaxBasic)
{
  // how do you set a value in matrix
  Matrix *mat = new Matrix;
  Matrix_init(mat, 50, 50);
  Matrix_fill(mat, 0);
  int max = 1;
  *Matrix_at(mat, 20, 20) = max;
  // printHelp(mat, 20, 20);
  ASSERT_EQUAL(Matrix_max(mat), max);
  delete mat;
}

TEST(testMaxNegative)
{
  // how do you set a value in matrix
  Matrix *mat = new Matrix;
  Matrix_init(mat, 50, 50);
  Matrix_fill(mat, -8);
  int max = -2;
  *Matrix_at(mat, 20, 20) = max;
  ASSERT_EQUAL(Matrix_max(mat), max);
  delete mat;
}

// // how would this work with autograder?
TEST(testMaxTwoMax)
{
  // how do you set a value in matrix
  Matrix *mat = new Matrix;
  Matrix_init(mat, 50, 50);
  Matrix_fill(mat, -8);
  int max = -2;
  *Matrix_at(mat, 20, 20) = max;
  ASSERT_EQUAL(Matrix_max(mat), max);
  delete mat;
}

// // what happens if there is no max, but you use the max funcition
// // there is nothing in the rme with that, same with two maxs

// // tests a basic implementation
TEST(testColumnMinValRowBasic)
{
  Matrix *mat = new Matrix;
  Matrix_init(mat, 50, 50);
  int fillVal = 0;
  Matrix_fill(mat, fillVal);
  int min = -1;
  int colVal = 20;
  *Matrix_at(mat, 0, colVal) = min;
  // printHelp(mat, 0, colVal);
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 0, 0, 50), colVal);
  delete mat;
}

TEST(testColumnMinValRowSmallColRange)
{
  Matrix *mat = new Matrix;
  Matrix_init(mat, 50, 50);
  int fillVal = 0;
  Matrix_fill(mat, fillVal);
  int min = -1;
  int colVal = 20;
  *Matrix_at(mat, 3, colVal) = min;
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 3, 18, 22), colVal);
  delete mat;
}

// what is this?

TEST(testColumnMinValInRowTwoMin)
{
  Matrix *mat = new Matrix;
  Matrix_init(mat, 50, 50);
  int fillVal = 2;
  Matrix_fill(mat, fillVal);
  int min = 1;
  int colVal1 = 19, colVal2 = 20;
  *Matrix_at(mat, 3, colVal1) = min;
  *Matrix_at(mat, 3, colVal2) = min;
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 3, 18, 22), colVal1);
  delete mat;
}

// // test out of range
// // how does one do this?

TEST(testMatrixMinValueInRow)
{
  Matrix *mat = new Matrix;
  Matrix_init(mat, 50, 50);
  int fillVal = 10;
  Matrix_fill(mat, fillVal);
  int min = 1;
  int colVal = 20;
  *Matrix_at(mat, 0, colVal) = min;
  ASSERT_EQUAL(Matrix_min_value_in_row(mat, 0, 0, 50), min);
  delete mat;
}

TEST(testMatrixMinValRowTwoMin)
{
  Matrix *mat = new Matrix;
  Matrix_init(mat, 50, 50);
  int fillVal = 0;
  Matrix_fill(mat, fillVal);
  int min = -1;
  int colVal = 20;
  *Matrix_at(mat, 3, colVal) = min;
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 3, 18, 22), 20);
  delete mat;
}

TEST(testMatrixMinValRowSameRange)
{
  Matrix *mat = new Matrix;
  Matrix_init(mat, 50, 50);
  int fillVal = 0;
  Matrix_fill(mat, fillVal);
  int min = -1;
  int colVal = 19;
  *Matrix_at(mat, 3, colVal) = min;
  *Matrix_at(mat, 3, colVal + 1) = min;
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 3, 18, 22), colVal);
  delete mat;
}

TEST_MAIN() // Do NOT put a semicolon here
