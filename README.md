TODO:

- [x] working base algo
- [x] detect if inserting from reverse order is shorter 
- [x] sort the stacks once first and then find the minimal swap for generataed number positions 
- [x] ability to copy / revert stack in order to test multiple strategies path for generating number positions
- [x] use swap when inserting on B stack (so that later we may merge sa/sb in ss instructions)
- [ ] split compliations in 2 independant stacks, and sort stakcs one instruction for each per frame, so that we could optimise using ss/rr/rrr
- [ ] split_swap strategy: instead of spliting 2 stack in the middle, take all number greater or lower than the mediam value
