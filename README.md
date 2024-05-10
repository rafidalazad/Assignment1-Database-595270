AVL and Hash Table Implementation
Description
This project implements AVL trees and hash tables in C to manage a dataset of songs and playlists. It includes unit tests for each data structure, integration tests for the entire system, and a Python script for generating test data.

Project Structure
avl_tree.c / avl_tree.h: Implementation and headers for AVL tree operations.
hash_table.c / hash_table.h: Implementation and headers for hash table operations.
data_loader.c / data_loader.h: Functions for loading data from files into the AVL tree and hash table.
main.c: Main program that integrates all components.
test_avl_tree.c: Unit tests for AVL tree functionality.
test_hash_table.c: Unit tests for hash table functionality.
songs_playlists_test_data.py: Python script to generate test data (songs.txt and playlists.txt).
Building the Project
To build the project, ensure you have a C compiler (e.g., GCC,visual studio etc) and Python installed on your system. Follow these steps for the easiest way to test it:

After Compiling the C Code
Run the following commands in your terminal:

.bash

gcc -o avl_tree avl_tree.c -I.
gcc -o hash_table hash_table.c -I.
gcc -o data_loader data_loader.c -I.
gcc -o main main.c avl_tree.c hash_table.c data_loader.c -I.
gcc -o test_avl test_avl_tree.c avl_tree.c -I.
gcc -o test_hash test_hash_table.c hash_table.c -I.

To generate test data files, run the Python script:
.bash

python3 songs_playlists_test_data.py


Running the Tests
To run the unit tests for the AVL tree and hash table:

.bash

./test_avl
./test_hash


Running the Main Program
To run the main program which integrates all components:

.bash

./main


Interpreting the Outputs
Unit Tests: The unit tests will output messages indicating whether each test has passed or failed.
Main Program: The main program will display the contents of the AVL tree and hash table, loaded with data from the generated songs.txt and playlists.txt.
Additional Notes
Ensure all paths to files are correctly set within the code if running from different directories.
Modify the TABLE_SIZE in hash_table.h if needed to adjust the capacity of the hash table based on expected load.
