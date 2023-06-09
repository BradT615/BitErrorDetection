# C BitErrorDetection

This C program implements three types of error checking techniques: parity check, checksum, and two-dimensional parity check. Each technique is implemented in a separate function, and they are called from the `main` function in the following order: `parityCheck`, `checksumCheck`, and `twoDParityCheck`.

## Parity Check

The `parityCheck` function reads data from a file named "Parity.txt" and performs parity checks on the data. The file should contain 5 transmission lines, each consisting of 9 integers. The program reads the data, converts it to binary, and performs parity checks on each transmission byte. If an error is detected (odd number of ones in the byte), an error message is printed indicating the byte number. Otherwise, a message indicating no error is printed.

## Checksum

The `checksumCheck` function reads data from a file named "Checksum.txt" and performs checksum checks on the data. The file should contain 5 data streams, each consisting of 9 integers. The last integer in each stream is the checksum value. The program calculates the sum of the data items in each stream and compares it to the checksum value. If the sum and checksum match (sum + checksum = 0), a message indicating no error is printed. Otherwise, an error message is printed.

## Two-dimensional Parity Check

The `twoDParityCheck` function reads data from a file named "2D_Parity.txt" and performs two-dimensional parity checks on the data. The file should contain a single transmission block consisting of 8 data streams, each containing 10 integers. The last integer in each stream is the vertical parity, and the last integer in the block is the horizontal parity. The program checks the vertical and horizontal parity for each transmission line and reports whether they pass or fail. If any transmission line fails either the vertical or horizontal parity check, the entire block is considered to have errors.

The program prints the processed data streams, performs parity checks, and displays the results for each step.

## Usage

1. Place the input files "Parity.txt", "Checksum.txt", and "2D_Parity.txt" in the same directory as the compiled C program.
2. Compile the C program using a C compiler.
3. Run the compiled program.
4. The program will read the input files, perform the error checking techniques, and display the results.

Note: Ensure that the input files are correctly formatted and contain the required data as described above for each technique.

Feel free to modify the program and the input files to suit your specific needs.
