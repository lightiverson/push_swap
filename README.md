# Push_swap
This project sorts integers on a stack datatype, with a limited set of instructions.

The goal of this project is to learn how to succesfully manipulate various types of searching/sorting algorithms. And to choose the most appropriate solution for your complexity needs.

#### Result
109%

## Features
- Uses a variation on Radix sort for larger stacks (also uses Bubble sort as a helper function)
- Uses a custom algorithm (somewhat mix of Insertion sort and Merge sort)
- Includes a self made checker for bonus

## Installation
Clone this repo
```bash
    git clone https://github.com/lightiverson/push_swap.git
    cd push_swap
    make
```

## Usage/Examples
Execute push swap
```bash
    ./push_swap 0 2 1
```

Execute checker
```bash
    cd checker
    make
    ../push_swap 0 2 1 | ./checker 0 2 1
```
