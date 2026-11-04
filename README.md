# Video Game Search Engine

## Requirements

- CMake 4.3 or later
- A C++20 compiler
- The supplied game data CSV file

## Prepare the data file

Due to GitHub 's file size limit, the CSV file is not included in this repository. You must obtain the CSV file separately and place it in the correct location for the program to run.

The program loads its data from the relative path `Data/games.csv`. From the repository root:

1. Create a folder named `Data`.
2. Copy the supplied CSV file into `Data`.
3. Name the file `games.csv`, so the path is `Data/games.csv`.

The CSV must have a header row and the expected game data columns. The loader reads the game ID from column 1, name from column 2, price from column 7, supported languages from column 11, and Windows, Mac, and Linux support from columns 18, 19, and 20, respectively (columns are counted starting at 1).

## Build and run with CMake

Run these commands from the repository root in PowerShell:

```powershell
cmake -S . -B build -G Ninja
cmake --build build
./build/DSAProject2.exe
```

Run the executable with the repository root as its working directory so it can find `Data/games.csv`.

## Use the program

At startup, the program loads the CSV and reports how many records were loaded or skipped. Use the menu to search/filter games, sort the filtered results, view load statistics, display filtered game names, or exit. Search results and sorting require a successful CSV load.