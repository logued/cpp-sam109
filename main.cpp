// sam109
// 
// Topic:   struct  (or structure)
// When we define a struct, we are creating an aggregate type of our own
// which is very similar to a class, except that fields are public and a
// struct does not normally have member functions.
//
// Sample based on example on structures (structs) from cplusplus.com
// Structs are often used as Plain Old Data Types (PODs) (with no constructors, destructors or methods)
//
// Demonstrates:
// Defining a struct and declaring a struct object
// Accessing the members of a struct (which are all public by default)
// Passing a struct object by value and by reference
// Arrays of Struct

// Structs are normally used when we want to store a data structure or record of data -
// such as a record of data read from a file.

#include <iostream>
#include <string>
#include <sstream>

using namespace std;
const int ARRAY_SIZE = 3; //

// Define a Movie_struct data type.
// It will be visible from here to the end of this file. (called scope)
//
struct Movie_struct {
    string title;       // fields are public by default
    int year;
};

// function prototypes
void print_movie_pass_by_value(Movie_struct movie);
void update_movie_pass_by_reference(Movie_struct& movie);
void populateMovieArray(Movie_struct movieArray[], int size);

int main()
{
    cout << "sam109 - Struct demo" << endl;

    Movie_struct scifiMovie; // declares a struct (object) in stack memory

    // we use the member access operator dot "." to access individual members (fields)

    scifiMovie.title = "2001 A Space Odyssey";    // possible because struct members are public
    scifiMovie.year = 1968;

    cout << "Our selected SciFi Movie is: ";
    print_movie_pass_by_value(scifiMovie);    // passes a copy of the struct data

    Movie_struct bestMovie;                // declare a struct (object)  called 'bestMovie' of type Movie_struct
    cout << "What is your favourite movie? " << endl;
    cout << "Enter title: ";
    getline(cin, bestMovie.title);    // reads string input directly into the struct

    string input;   // creates a string object (variable)
    cout << "Enter year: ";
    getline(cin, input);    // read input to temp input string
    stringstream(input) >> bestMovie.year; // convert to int

    cout << "And bestMovie is:\n ";

    print_movie_pass_by_value( bestMovie );  // pass copy of struct data into function


    // if we want to pass a struct into a function so that the struct can be modified
    // by that function, then we must declare a reference parameter in the function header

    update_movie_pass_by_reference( scifiMovie );
    // note that the call looks the same as for "by value", but the parameter declaration is different


    ///Array of struct ////////////////////////////////////////////////

    Movie_struct movieArray[ARRAY_SIZE];    // defines an array of structs on the STACK

    populateMovieArray( movieArray, sizeof(movieArray)/sizeof(Movie_struct) );     // pass an array, and number of elements

    cout << "Demo: Array of struct" << endl;
    for (int i = 0; i < ARRAY_SIZE; i++)
        cout << i << ": " << movieArray[i].title << ", " << movieArray[i].year << endl;

    return 0;
}

//TODO
// Write a function that will accept an array of Movie_struct objects
// as an argument and output details of all movieArray.
// Remember to declare a function prototype.

//   Pass-by-Value
//
//   The parameter declared here is simply a struct called 'movie'
//   Its type is 'Movie_struct' and it is created on the stack as an automatic variable.
//   When the function is called, and a struct is passed as an argument,
//   the contents of that argument are copied into the local parameter struct.
//   So, the function can access only the copy of the struct data passed in.
//   Any changes made to the 'movie' struct are local to the function,
//   and these changes can have no effect on the original struct (passed from main).
//
//   The local 'movie' struct is discarded (from the stack) when the function exits.
//   Note that this can be an expensive operation, as all the field values of the
//   struct being passed must be copied into the struct fields of the parameter.
//   For efficiency, it is usually preferable to pass a struct using a reference parameter.

void print_movie_pass_by_value(Movie_struct movie) {
    cout <<  "Title: " << movie.title << ", Year: " << movie.year << endl;
}

//  Pass-by-Reference
//
//  Below, we declare a parameter of type reference to Movie_struct.
//  The reference 'movie' is another name for the original movie object,
//  it has full access to the original object, and can update its contents.
//
//  Passing by reference is efficient, and recommended, because we don't have to copy
//  the argument's data into the function.
//  We can declare the reference as  type "reference to const Movie_struct"
//  if we intend to access, but not update, the original movie object.
//   fn( const Movie_struct & movie )

void update_movie_pass_by_reference( Movie_struct& movie) {   // reference to a Movie_struct
    cout << "Current movie title: " << movie.title << endl;
    cout << "Current movie year : " << movie.year << endl;

    cout << "Enter details of your new favourite movie: " << endl;
    cout << "Enter title: ";
    getline(cin, movie.title);    // read directly into the struct, using the reference

    string input;   // creates a string object (variable)
    cout << "Enter year: ";
    getline(cin, input);
    stringstream(input) >> movie.year; // converts to int

    // the updates have been entered directly into the original movie struct object.
}


// Passing an Array (using Array Notation)
//
// When we pass an array in C++, what is passed is actually the address of
// the start of the array. This gives the function access to the array elements.
// However, we normally declare this using array-notation,
// and then we access the array elements using array-notation and array indexing.

void populateMovieArray( Movie_struct movieArray[], int size) {
    movieArray[0].title = "Jaws";
    movieArray[0].year = 1978;
    
    movieArray[1].title = "Alien";
    movieArray[1].year = 1987;
    
    movieArray[2].title = "Rug Rats";
    movieArray[2].year = 1995;
}

