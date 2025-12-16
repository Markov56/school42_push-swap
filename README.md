_This project has been created as part of the 42 curriculum by rmarkov_

# Description

Push_swap is a sorting algorithm project where the goal is to sort integers using two stacks and a limited set of operations. The program calculates the most efficient sequence of moves to sort the stack with the least number of operations.

# Instructions

## Compilation

Use the provided Makefile to compile the project:

make

## Execution

Run the program by passing integers as separate arguments:

./push_swap 3 2 1 6 5

Or pass all numbers as a single string argument:

ARG="3 2 1 6 5"
./push_swap "$ARG"

## Clean

To remove object files and the executable:

make fclean

## Usage examples

$>./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
$>./push_swap 0 one 2 3
Error
$>

# Resources

https://medium.com/@ayogun/push-swap-c1f5d2d41e97
https://medium.com/@ulysse.gks/push-swap-in-less-than-4200-operations-c292f034f6c0
https://github.com/o-reo/push_swap_visualizer

AI was used to assist in planning algorithmic logic, identifying edge cases, and reviewing memory management and debugging.
