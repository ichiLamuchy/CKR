

/*
Write a function setbits(x,p,n,y) that returns x with the n bits t
hat begin at position p set to the rightmost n bits of y, 
leaving the other bits unchanged
*/


/*
WIP note: 

this is also useful http://joequery.me/notes/learning-c-4/


the add that onto X for position P

1: use getbits ish function to extract the n bits from y  & ~(~0 << n) is the filter so Y & ~(~0 << n) 
2: the aobve will need some 0 at the end (<<) when last step taking place
3: find position p (p+1), and find number of bits on suffix after the nbits end - p+1-n (this will be applied on step 2)
4: use "|" to make the nbits from posiopn p to be 1 and followed by p+1-n bits on 0
5: how to achive step 4 is first convert the to (~(~0 << n))<< p+1-n  do if n is 4 and p is 6 it should be 00001111000
6: x | (~(~0 << n))<< p+1-n to get ready on compare to step 2 out come
7: then bitwise operation of the step 6 & 2 (x | (~(~0 << n))<< p+1-n) & (y  &  ~(~0 << n)) << (p+1-n)) in theory
*/
