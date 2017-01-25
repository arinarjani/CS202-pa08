/// @author Arin Arjani
/// @file pa08.cpp
/// @version The date as 2017-01-27
/// @brief A brief description of the program (no more
/// than one or two paragraphs)
/// @note Time taken to develop, write, test and debug solution.
/// @note Tutored by __________ on YYYY-MM-DD. (as required)

// cin ( >> ) and cout ( << )
#include <iostream>
// allows for formating data output
#include <iomanip>
// be able to input string and work with them
#include <string>

// not need for std::cin for instance
using namespace std;

// prototypes
// ISSUE: HOW DO I PASS IN THE SIZES OF THE ARRAY WITHOUT KNOWING
//        THE SIZE FROM THE START?  I HAVE TO GET IT FROM THE FILE.
//        THIS MEANS I CANNOT USE A CONSTANT OR EVEN DECLARE PROTOTYPES RIGHT?
// void rowSwap( int inputArr[][], int size);
// void colSwap();
// void incrementByOne();
// void decrementByOne();
// void transpose();

// *************************************************
//                 TODO
// *************************************************
// 1) get your program so you can run 6 test cases
// 2) get your program to run 3 operations
// 3) right now your program can only run 1 test case, after that it scans
//    for another test case number and repreats.  it cannot do multiple
//    operations as well; only one operation really well

int main() {
    int testCases;
    int dimensionOfMatrix;
    int numOfOperations;
    int rowColOppOne = 0;
    int rowColOppTwo = 0;
    string operation;
    char currentValOfArr;
    int startOfCharNumbers = 48;
    int timesAround;

    cin >> testCases >> dimensionOfMatrix;

    timesAround = testCases;

    while ( cin && timesAround > 0 ) {
        // order as follows: 1) num of testCases ( numOfMatricies )
        //                   2) size of matrix ( need to square it )
        //                   3) matrix
        //                   4) numOfOperations
        //                   5) operation

        // get first few numbers from file
        // cin >> testCases >> dimensionOfMatrix;

        cout << "testCases: " << testCases << endl;
        cout << "dimesionsOfMatix: " << dimensionOfMatrix<< endl;

        // declare array with size given
        int mainArray[dimensionOfMatrix][dimensionOfMatrix];

        // mainArray holders for each row/col
        int firstRowColSwitch[dimensionOfMatrix];
        int secondRowColSwitch[dimensionOfMatrix];

        // array for when I transpose
        int arrHolder[dimensionOfMatrix][dimensionOfMatrix];


        // fill mainArray with values given
        for ( int i = 0; i < dimensionOfMatrix; i++ ) {
            for ( int j = 0; j < dimensionOfMatrix; j++ ) {
              cin >> currentValOfArr;
              // for testing purposes
              cout << "currentValOfArr:" << currentValOfArr << endl;
              mainArray[i][j] = static_cast<int>(currentValOfArr - startOfCharNumbers);
            }
        }

        // for testing purposes
         for ( int i = 0; i < dimensionOfMatrix; i++ ) {
             for ( int j = 0; j < dimensionOfMatrix; j++ ) {
               cout << mainArray[i][j];
             }
             cout << endl;
         }

        // get number of operations
        cin >> numOfOperations >> operation;

        // for testing purposes
         cout << "numOfOperations: " << numOfOperations << endl;
         cout << "operation: " << operation << endl;

        if ( operation == "row" || operation == "col" ) {
            cin >> rowColOppOne >> rowColOppTwo;
        }

        // for testing purposes
         cout << "rowColOppOne: " << rowColOppOne << endl;
         cout << "rowColOppTwo: " << rowColOppTwo << endl;

        if ( operation == "row" ) {
            // {
            //   {1, 2, 3, 4}
            //   {5, 6, 7, 8}
            //   {9, 1, 2, 3}
            //   {4, 5, 6, 7}
            // }
            // want to switch row 2 with row 4

            // populate the array holder firstRowSwitch
            for ( int k = 0; k < dimensionOfMatrix; k++ ) {
                firstRowColSwitch[k] = mainArray[rowColOppOne - 1][k];
            }

            // populate the array holder secondRowSwitch
            for ( int q = 0; q < dimensionOfMatrix; q++ ) {
                secondRowColSwitch[q] = mainArray[rowColOppTwo - 1][q];
            }

            // make the switch on first row
            for (int a = 0; a < dimensionOfMatrix; a++) {
                mainArray[rowColOppOne - 1][a] = secondRowColSwitch[a];
            }

            // make the switch o second row
            for (int b = 0; b < dimensionOfMatrix; b++) {
                mainArray[rowColOppTwo - 1][b] = firstRowColSwitch[b];
            }
        }

        if ( operation == "col" ) {
          // {
          //   {1, 2, 3, 4}
          //   {5, 6, 7, 8}
          //   {9, 1, 2, 3}
          //   {4, 5, 6, 7}
          // }
          // want to switch col 2 with row 4
          // populate the array holder firstRowColSwitch
          for ( int k = 0; k < dimensionOfMatrix; k++ ) {
              firstRowColSwitch[k] = mainArray[k][rowColOppOne - 1];
          }

          // populate the array holder secondRowColSwitch
          for ( int q = 0; q < dimensionOfMatrix; q++ ) {
              secondRowColSwitch[q] = mainArray[q][rowColOppTwo - 1];
          }
          // make the switch on first col
          for (int a = 0; a < dimensionOfMatrix; a++) {
              mainArray[a][rowColOppOne - 1] = secondRowColSwitch[a];
          }

          // make the switch o second col
          for (int b = 0; b < dimensionOfMatrix; b++) {
              mainArray[b][rowColOppTwo - 1] = firstRowColSwitch[b];
          }
        }

        if ( operation == "inc" ) {
          // {
          //   {1, 2, 3, 4}
          //   {5, 6, 7, 8}
          //   {9, 1, 2, 3}
          //   {4, 5, 6, 7}
          // }
          // want to incremtent everything by 1 to get:
          // {
          //   {2, 3, 4, 5}
          //   {6, 7, 8, 9}
          //   {1, 2, 3, 4}
          //   {5, 6, 7, 8}
          // }

          for ( int i = 0; i < dimensionOfMatrix; i++ ) {
              int numReset = 0;
              for ( int j = 0; j < dimensionOfMatrix; j++ ) {
                  int currentVal = mainArray[i][j];
                  cout << "currentVal: " << currentVal << endl;
                  if ( ( currentVal + 1 ) % 10 == 0 ) {
                      mainArray[i][j] = numReset;
                  } else {
                      currentVal++;
                      cout << "currentVal++: " << currentVal << endl;
                      mainArray[i][j] = currentVal;
                  }
              }
          }


        }

        if ( operation == "dec" ) {
          for ( int i = 0; i < dimensionOfMatrix; i++ ) {
              int numReset = 0;
              for ( int j = 0; j < dimensionOfMatrix; j++ ) {
                  int currentVal = mainArray[i][j];
                  cout << "currentVal: " << currentVal << endl;
                  if ( ( currentVal - 1 ) % 10 == -1 ) {
                      mainArray[i][j] = numReset;
                  } else {
                      currentVal--;
                      cout << "currentVal--: " << currentVal << endl;
                      mainArray[i][j] = currentVal;
                  }
              }
          }
        }

        if ( operation == "transpose" ) {
          // {
          //   {1, 2, 3, 4}
          //   {5, 6, 7, 8}
          //   {9, 1, 2, 3}
          //   {4, 5, 6, 7}
          // }
          // after transposing:
          // {
          //   {1, 5, 9, 4}
          //   {2, 6, 1, 5}
          //   {3, 7, 2, 6}
          //   {4, 8, 3, 7}
          // }
            for ( int i = 0; i < dimensionOfMatrix; i++ ) {
                for ( int j = 0; j < dimensionOfMatrix; j++ ) {
                    arrHolder[j][i] = mainArray[i][j];
                }
            }
        }

         // for testing purposes
         if ( operation == "transpose" ) {
             cout << "Case #" << testCases << endl;
             for ( int i = 0; i < dimensionOfMatrix; i++ ) {
                 for ( int j = 0; j < dimensionOfMatrix; j++ ) {
                     cout << arrHolder[i][j];
                 }
                 cout << endl;
             }
         } else {
             cout << "Case #" << testCases << endl;
             for ( int i = 0; i < dimensionOfMatrix; i++ ) {
                 for ( int j = 0; j < dimensionOfMatrix; j++ ) {
                     cout << mainArray[i][j];
                 }
                 cout << endl;
             }
         }

         timesAround--;
 }

  return 0;
}
