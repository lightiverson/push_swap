# Push_swap

This project sorts integers on a stack datatype, with a limited set of instructions.

The goal of this project is to learn how to succesfully manipulate various types of searching/sorting algorithms. And to choose the most appropriate solution for your complexity needs.

## Todo

- Create function to check stack a for duplicates, right after it is created.
- Replace atoi with new strtoi, which has built in checks for overflow and underflow and uses exit().
- ~~Replace sort_three function with beta function. Make sure stacks of three are sorted correctly within two moves.~~
- ~~Create new sort_five function that uses pa + pa + sort_three(stack_a) + [[ new functions written to merge from stack_b into stack_a ]]~~

## FAQ
How to execute push_swap with random arguments:
ARGS=$(shuf -i 0-10000 -n 5 | tr '\n' ' '); ./push_swap $(echo $ARGS)
ARGS=$(shuf -i 0-10000 -n 5 | tr '\n' ' '); ./push_swap $(echo $ARGS) | wc -l

#### Result

Tbd

#### Status

In progress

## Installation

Clone this repo

```bash
  git clone https://github.com/lightiverson/push_swap.git
  cd push_swap
```

## Usage/Examples

```bash
make
./push_swap
```

## Authors

- [@lightiverson](https://www.github.com/lightiverson)