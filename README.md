TODO:

- [x] 2-3 instructions for 3 integers
- [x] 12 instructions for 5 integers
- [/] 700 instructions for 100 integers
- [/] 5000 instructions for 500 integers

- [x] working base algo
- [x] detect if inserting from reverse order is shorter 
- [x] sort the stacks once first and then find the minimal swap for generataed number positions 
- [x] ability to copy / revert stack in order to test multiple strategies path for generating number positions
- [x] use swap when inserting on B stack (so that later we may merge sa/sb in ss instructions)
- [x] split compliations in 2 independant instructions list
- [x] merge the 2 independants instructions list when possible that we could optimise using ss/rr/rrr
- [x] split_swap strategy: instead of spliting 2 stack in the middle, take all number greater or lower than the mediam value
- [x] add more strategies with sort algos that have best locality of reference for handling bigger array
i