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

// *************************************************
//                 TODO
// *************************************************
// 1) get your program so you can run 6 test cases
// 2) get your program to run 3 operations
// 3) right now your program can only run 1 test case, after that it scans
//    for another test case number and repreats.  it cannot do multiple
//    operations as well; only one operation really well

const int SIZE_OF_ROW = 10;
const int SIZE_OF_COL = 10;

// PROTOTYPES
void rowSwap( int inputArr[][SIZE_OF_COL], int sizeOfRow, int opp1, int opp2);
void colSwap( int inputArr[][SIZE_OF_COL], int sizeOfRow, int opp1, int opp2);
void incrementByOne( int inputArr[][SIZE_OF_COL], int sizeOfRow );
void decrementByOne( int inputArr[][SIZE_OF_COL], int sizeOfRow );
void transpose( int inputArr[][SIZE_OF_COL], int holder[][SIZE_OF_COL], int sizeOfRow );

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
    int mainArray[SIZE_OF_ROW][SIZE_OF_COL];
    int arrHolder[SIZE_OF_ROW][SIZE_OF_COL];

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
            // **
            // {
            //   {1, 2, 3, 4}
            //   {5, 6, 7, 8}
            //   {9, 1, 2, 3}
            //   {4, 5, 6, 7}
            // }
            // want to switch row 2 with row 4
            rowSwap( mainArray, dimensionOfMatrix, rowColOppOne, rowColOppTwo );
        }

        if ( operation == "col" ) {
          // {
          //   {1, 2, 3, 4}
          //   {5, 6, 7, 8}
          //   {9, 1, 2, 3}
          //   {4, 5, 6, 7}
          // }
          // want to switch col 2 with row 4
            colSwap( mainArray, dimensionOfMatrix, rowColOppOne, rowColOppTwo );
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
            incrementByOne( mainArray, dimensionOfMatrix );
        }

        if ( operation == "dec" ) {
            decrementByOne( mainArray, dimensionOfMatrix );
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
            transpose( mainArray, arrHolder, dimensionOfMatrix );
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

// FUNCTIONS
void rowSwap( int inputArr[][SIZE_OF_COL], int sizeOfRow, int opp1, int opp2) {
    // array holders for each row/col
    int firstRowColSwitch[SIZE_OF_ROW];
    int secondRowColSwitch[SIZE_OF_ROW];

    // populate the array holders
    for ( int k = 0; k < sizeOfRow; k++ ) {
        firstRowColSwitch[k] = inputArr[opp1 - 1][k];
        secondRowColSwitch[k] = inputArr[opp2 - 1][k];
    }

    // make the row switches on the inputArr
    for (int a = 0; a < sizeOfRow; a++) {
        inputArr[opp1 - 1][a] = secondRowColSwitch[a];
        inputArr[opp2 - 1][a] = firstRowColSwitch[a];
    }
}

void colSwap( int inputArr[][SIZE_OF_COL], int sizeOfRow, int opp1, int opp2) {
    // array holders for each row/col
    int firstRowColSwitch[SIZE_OF_ROW];
    int secondRowColSwitch[SIZE_OF_ROW];

    // populate the array holders
    for ( int k = 0; k < sizeOfRow; k++ ) {
        firstRowColSwitch[k] = inputArr[k][opp1 - 1];
        secondRowColSwitch[k] = inputArr[k][opp2 - 1];
    }

    // make the row switches on the inputArr
    for (int a = 0; a < sizeOfRow; a++) {
        inputArr[a][opp1 - 1] = secondRowColSwitch[a];
        inputArr[a][opp2 - 1] = firstRowColSwitch[a];
    }
}

void incrementByOne( int inputArr[][SIZE_OF_COL], int sizeOfRow ) {
    for ( int i = 0; i < sizeOfRow; i++ ) {
        int numReset = 0;
        for ( int j = 0; j < sizeOfRow; j++ ) {
            int currentVal = inputArr[i][j];
            cout << "currentVal: " << currentVal << endl;
            if ( ( currentVal + 1 ) % 10 == 0 ) {
                inputArr[i][j] = numReset;
            } else {
                currentVal++;
                cout << "currentVal++: " << currentVal << endl;
                inputArr[i][j] = currentVal;
            }
        }
    }
}

void decrementByOne( int inputArr[][SIZE_OF_COL], int sizeOfRow ) {
    for ( int i = 0; i < sizeOfRow; i++ ) {
        int numReset = 0;
        for ( int j = 0; j < sizeOfRow; j++ ) {
            int currentVal = inputArr[i][j];
            cout << "currentVal: " << currentVal << endl;
            if ( ( currentVal - 1 ) % 10 == -1 ) {
                inputArr[i][j] = numReset;
            } else {
                currentVal--;
                cout << "currentVal--: " << currentVal << endl;
                inputArr[i][j] = currentVal;
            }
        }
    }
}

void transpose( int inputArr[][SIZE_OF_COL], int holder[][SIZE_OF_COL], int sizeOfRow ) {
  for ( int i = 0; i < sizeOfRow; i++ ) {
      for ( int j = 0; j < sizeOfRow; j++ ) {
          holder[j][i] = inputArr[i][j];
      }
  }
}
