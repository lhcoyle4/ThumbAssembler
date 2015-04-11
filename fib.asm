; an example assembly file to be assembled
  .text
  .global main
main:
  PUSH {lr, r4 - r7} 
  MOV r4, #0  ; for the n - 1 term of fib sequence
  MOV r5, #1  ; for n term of fib
  MOV r6, #1  ; for n + 1 term of fib
  MOV r7, #20 ; loop iterator, # of terms to count to
fib:
  ADD r6, r5, r4 ; adds r5(n term) and r4(n - 1 term) together and puts result in r6(n + 1 term)
  MOV r4, r5 ; updates the n -1 term
  MOV r5, r6 ; updates n term
  SUBS r7, #1 ; subtract 1 from the loop iterator and update the status flags
  BNE fib ; if it isn't zero, then branch back to start of fib loop
  POP {pc, r4 - r7}
  .end ; end of program, last calculated term of fib sequence will be in r5.