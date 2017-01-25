/// @author Arin Arjani
/// @file pa08.cpp
/// @version The date as 2017-01-27
/// @brief A brief description of the program:  This program takes in
///        a number of operations to perform.  It then takes in 5 operations:
///        swap row a with b ( row 1 2 ), increment by 1 ( inc ),
///        swap column a with b ( col a b ), decrement by 1 ( dec ),
///        transpose the whole matrix ( transpose ).  Once the operations are
///        done, it outputs the matrix with the operations.
/// @note Time taken to develop, write, test and debug solution: 1 day.

// cin ( >> ) and cout ( << )
#include <iostream>
// allows for formating data output
#include <iomanip>
// be able to input string and work with them
#include <string>

// not need for std::cin for instance
using namespace std;

const int SIZE_OF_ROW = 10;  // size of all array rows
const int SIZE_OF_COL = 10;  // size of all array columns

// PROTOTYPES
void rowSwap( int inputArr[][SIZE_OF_COL], int sizeOfRow, int opp1, int opp2);
void colSwap( int inputArr[][SIZE_OF_COL], int sizeOfRow, int opp1, int opp2);
void incrementByOne( int inputArr[][SIZE_OF_COL], int sizeOfRow );
void decrementByOne( int inputArr[][SIZE_OF_COL], int sizeOfRow );
void transpose( int inputArr[][SIZE_OF_COL], int holder[][SIZE_OF_COL],
                int sizeOfRow );
void printArray( int inputArr[][SIZE_OF_COL], int holder[][SIZE_OF_COL],
                 int sizeOfRow, string opp, int t );

int main() {
    // local named variables
    int testCases;  //  number of test cases to perform ( number of matrices )
    int dimensionOfMatrix;  // size used for both row and column when printing
    int numOfOperations;  // number of operations to perform on each array
    int rowColOppOne;  // keep track of which row is being swapped in row or col
    int rowColOppTwo;  // keep track of which col is being swapped in row or col
    string operation;  // get the operation given from the file
    char currentValOfArr;  // extract each number from the array in file
    int startOfCharNumbers = 48;  // start of numbers in ASCII - decimal
    int timesAround = 1;  // shows which case # is being displayed
    int mainArray[SIZE_OF_ROW][SIZE_OF_COL];  // array for storing file contents
    int arrHolder[SIZE_OF_ROW][SIZE_OF_COL];  // array for storing transposed
                                              // array

    cin >> testCases;

    for ( int i = 0; i < testCases; i++ ) {
        cin >> dimensionOfMatrix;

        // fill mainArray with values given
        for ( int i = 0; i < dimensionOfMatrix; i++ ) {
            for ( int j = 0; j < dimensionOfMatrix; j++ ) {
                cin >> currentValOfArr;
                mainArray[i][j] = static_cast<int>(currentValOfArr
                                                   - startOfCharNumbers);
            }
        }

        // get number of operations
        cin >> numOfOperations >> operation;

        // maybe a loop for numOfOperations?
        for ( int i = 0; i < numOfOperations; i++ ) {
            if ( operation == "row" || operation == "col" ) {
                cin >> rowColOppOne >> rowColOppTwo;
            }

            if ( operation == "row" ) {
                rowSwap( mainArray, dimensionOfMatrix, rowColOppOne, rowColOppTwo );
            }

            if ( operation == "col" ) {
                colSwap( mainArray, dimensionOfMatrix, rowColOppOne, rowColOppTwo );
            }

            if ( operation == "inc" ) {
                incrementByOne( mainArray, dimensionOfMatrix );
            }

            if ( operation == "dec" ) {
                decrementByOne( mainArray, dimensionOfMatrix );
            }

            if ( operation == "transpose" ) {
                transpose( mainArray, arrHolder, dimensionOfMatrix );
             }

            // old print array function placement

            if ( numOfOperations > 1 && ( i + 1 ) < numOfOperations ) {
                cin >> operation;
            }
         }
     printArray( mainArray, arrHolder, dimensionOfMatrix, operation, timesAround );
     timesAround++;
     }

    return 0;
}

// FUNCTIONS
void rowSwap( int inputArr[][SIZE_OF_COL], int sizeOfRow, int opp1, int opp2) {
    // array holders for each row/col
    int firstRowSwitch[SIZE_OF_ROW];  // holds the first row to be swapped
    int secondRowSwitch[SIZE_OF_ROW];  // holds the second row to be swapped

    // populate the array holders
    for ( int k = 0; k < sizeOfRow; k++ ) {
        firstRowSwitch[k] = inputArr[opp1 - 1][k];
        secondRowSwitch[k] = inputArr[opp2 - 1][k];
    }

    // make the row switches on the inputArr
    for (int a = 0; a < sizeOfRow; a++) {
        inputArr[opp1 - 1][a] = secondRowSwitch[a];
        inputArr[opp2 - 1][a] = firstRowSwitch[a];
    }
}

void colSwap( int inputArr[][SIZE_OF_COL], int sizeOfRow, int opp1, int opp2) {
    // array holders for each row/col
    int firstColSwitch[SIZE_OF_ROW];  // holds the first col to be swapped
    int secondColSwitch[SIZE_OF_ROW];  // holds the second col to be swapped

    // populate the array holders
    for ( int k = 0; k < sizeOfRow; k++ ) {
        firstColSwitch[k] = inputArr[k][opp1 - 1];
        secondColSwitch[k] = inputArr[k][opp2 - 1];
    }

    // make the row switches on the inputArr
    for (int a = 0; a < sizeOfRow; a++) {
        inputArr[a][opp1 - 1] = secondColSwitch[a];
        inputArr[a][opp2 - 1] = firstColSwitch[a];
    }
}

void incrementByOne( int inputArr[][SIZE_OF_COL], int sizeOfRow ) {
    for ( int i = 0; i < sizeOfRow; i++ ) {
        int numReset = 0;  // used to reset number to 0 if gets to 10 ( L148 )
        for ( int j = 0; j < sizeOfRow; j++ ) {
            int currentVal = inputArr[i][j];  // holds current value in array
            if ( ( currentVal + 1 ) % 10 == 0 ) {
                inputArr[i][j] = numReset;
            } else {
                currentVal++;
                inputArr[i][j] = currentVal;
            }
        }
    }
}

void decrementByOne( int inputArr[][SIZE_OF_COL], int sizeOfRow ) {
    for ( int i = 0; i < sizeOfRow; i++ ) {
        int numReset = 0;  // used to reset number to 0 if gets to 10 ( L148 )
        for ( int j = 0; j < sizeOfRow; j++ ) {
            int currentVal = inputArr[i][j];  // holds current value in array
            if ( ( currentVal - 1 ) % 10 == -1 ) {
                inputArr[i][j] = numReset;
            } else {
                currentVal--;
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

void printArray( int inputArr[][SIZE_OF_COL], int holder[][SIZE_OF_COL], int sizeOfRow, string opp, int t ) {
  if ( opp == "transpose" ) {
      cout << "Case #" << t << endl;
      for ( int i = 0; i < sizeOfRow; i++ ) {
          for ( int j = 0; j < sizeOfRow; j++ ) {
              cout << holder[i][j];
          }
          cout << endl;
      }
  } else {
      cout << "Case #" << t << endl;
      for ( int i = 0; i < sizeOfRow; i++ ) {
          for ( int j = 0; j < sizeOfRow; j++ ) {
              cout << inputArr[i][j];
          }
          cout << endl;
      }
  }
}
