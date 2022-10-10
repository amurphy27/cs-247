/* 
 * CS:APP Data Lab 
 * 
 * Andrew Murphy murphya6
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  /* brief description of how your implementation works */
  int Funct(arg1, arg2, ...) {
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   *
   * exploit ability of shifts to compute powers of 2
   */
  int pow2plus1(int x) {
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   *
   * exploit ability of shifts to compute powers of 2 
   */
  int pow2plus4(int x) {
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 * DeMorgan's Law
 */
int bitAnd(int x, int y) {
  return ~(~x|~y);
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 * since one byte is 8 bits I multiply the n by 8 via shifting it 3 left then shift
 * the sequence to the correct postition then bitwise & to leave only the desired byte
 */
int getByte(int x, int n) {
  return (x >> (n << 3)) & 0xff;
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 * I used a mask to get rid of the duplicated bits if there are any
 */
int logicalShift(int x, int n) {
  return (x >> n) & ~ (((0x1 << 31) >> n) << 1);
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 * I didn't meet the max ops but I have a counter that
 * goes through the whole 32-bits counting up the bits
 */
int bitCount(int x) {
  int counter = 0;
  counter += (x & 1);
  x >>= 1;
  counter += (x & 1);
  x >>= 1;
  counter += (x & 1);
  x >>= 1;
  counter += (x & 1);
  x >>= 1;
  counter += (x & 1);
  x >>= 1;
  counter += (x & 1);
  x >>= 1;
  counter += (x & 1);
  x >>= 1;
  counter += (x & 1);
  x >>= 1;
  counter += (x & 1);
  x >>= 1;
  counter += (x & 1);
  x >>= 1;
  counter += (x & 1);
  x >>= 1;
  counter += (x & 1);
  x >>= 1;
  counter += (x & 1);
  x >>= 1;
  counter += (x & 1);
  x >>= 1;
  counter += (x & 1);
  x >>= 1;
  counter += (x & 1);
  x >>= 1;
  counter += (x & 1);
  x >>= 1;
  counter += (x & 1);
  x >>= 1;
  counter += (x & 1);
  x >>= 1;
  counter += (x & 1);
  x >>= 1;
  counter += (x & 1);
  x >>= 1;
  counter += (x & 1);
  x >>= 1;
  counter += (x & 1);
  x >>= 1;
  counter += (x & 1);
  x >>= 1;
  counter += (x & 1);
  x >>= 1;
  counter += (x & 1);
  x >>= 1;
  counter += (x & 1);
  x >>= 1;
  counter += (x & 1);
  x >>= 1;
  counter += (x & 1);
  x >>= 1;
  counter += (x & 1);
  x >>= 1;
  counter += (x & 1);
  x >>= 1;
  return counter += (x & 1);
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 * doesn't meet the max ops since I had a lot of issues
 * with this one but I search the whole 32-bits for a
 * single 1, then flip if one is found or not
 */
int bang(int x) {
  int holder = 0;
  holder |= x;
  x >>= 1;
  holder |= x;
  x >>= 1;
  holder |= x;
  x >>= 1;
  holder |= x;
  x >>= 1;
  holder |= x;
  x >>= 1;
  holder |= x;
  x >>= 1;
  holder |= x;
  x >>= 1;
  holder |= x;
  x >>= 1;
  holder |= x;
  x >>= 1;
  holder |= x;
  x >>= 1;
  holder |= x;
  x >>= 1;
  holder |= x;
  x >>= 1;
  holder |= x;
  x >>= 1;
  holder |= x;
  x >>= 1;
  holder |= x;
  x >>= 1;
  holder |= x;
  x >>= 1;
  holder |= x;
  x >>= 1;
  holder |= x;
  x >>= 1;
  holder |= x;
  x >>= 1;
  holder |= x;
  x >>= 1;
  holder |= x;
  x >>= 1;
  holder |= x;
  x >>= 1;
  holder |= x;
  x >>= 1;
  holder |= x;
  x >>= 1;
  holder |= x;
  x >>= 1;
  holder |= x;
  x >>= 1;
  holder |= x;
  x >>= 1;
  holder |= x;
  x >>= 1;
  holder |= x;
  x >>= 1;
  holder |= x;
  x >>= 1;
  holder |= x;
  x >>= 1;
  holder |= x;
  holder &= 1;
  holder = ~holder + 2;
  return holder;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 0x80 << 24;
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 * since the max n can be is 32 I add the negative n
 * get the correct placement I need to shift then shift
 * x and Xor it with the orignal x to look for differences
 * meaning bits not in the bits we are trying to fit in
 */
int fitsBits(int x, int n) {
  int filledInNegate = 0x20 + (~n + 1);
  return !(x ^ ((x << filledInNegate) >> filledInNegate));
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 * I force the negative sign into the correct position
 * and manipulate it to behave correctly since sometimes
 * isNeg comes out as -1 not 1.
 */
int divpwr2(int x, int n) {
  int isNeg = (x >> 31);
  int forceNegPos = (((isNeg & 1) << n) + isNeg);
  return ((x + forceNegPos) >> n);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 * 2's complement of negation definition
 */
int negate(int x) {
  return ~x + 1;
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 * I just shift the sign bit over and return the opposite of
 * that, i also check if x is 0 since the sign is not positive
 */
int isPositive(int x) {
  return (!(x >> 31)) & (!!x);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 * Tried a couple things but none of them were even close so this one
 * gets to stay 2.
 */
int isLessOrEqual(int x, int y) {
  return 2;
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 * Since this is 2s complement the answer is the number of bits to the right
 * of the most significant bit. So I use shifts to check the left half of the
 * 32-bits for any 1 bits. If there is one there the answer is at least 16,
 * and if not then the answer is less than 16. I do this by shifting the 1 or 0
 * by 4 which is the same as multiplying by 16, this makes it so 0 stays 0. So
 * then I repeat this process for the left half of either the original left half
 * if I found any 1s or the right half if I didn't. This is done by adding the
 * previous result to the shift which is now 8 since that is half of the half of
 * the total bits. This makes sure the we now look at the left half of where we
 * either know or where there may be 1 bits. This process repeats with smaller
 * halves till we get to looking at only 1 bit that either is or isn't the most
 * significant bit. 
 */
int ilog2(int x) {
  int result = ((!!(x >> 16)) << 4);
  result += ((!!(x >> (result + 8))) << 3);
  result += ((!!(x >> (result + 4))) << 2);
  result += ((!!(x >> (result + 2))) << 1);
  return result + (!!(x >> (result + 1)));
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 * First I check for edge cases, then just flip the sign bit
 */
unsigned float_neg(unsigned uf) {
  if (!(uf ^ 0x7f800000)){
    return 0xff800000;
  }
  if (!(uf ^ 0xff800000)){
    return 0x7f800000;
  }
  if (!((0x7f800000 & uf) ^ 0x7f800000)){
    return uf;
  }
  return uf ^ 0x80000000;
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 * I have the beginning of what I thought the solution would be but didn't finish it.
 */
unsigned float_i2f(int x) {
  int powerCounter = 32;
  int powerCount = 0;
  unsigned newFloat = 0x3f800000;
  int negativeOne = (~1 + 1);
  if (!x){
    return 0;
  }
  if (!(0x80000000 & x) ^ 0x80000000){
    return 0xcf000000;
  }
  if (!((0x7f800000 & x) ^ 0x7f800000)){
    return x;
  }
  while (powerCounter > 0){
    if (!!((1 << (powerCounter + negativeOne)) & x)){
      powerCount += powerCounter;
    }
    powerCounter += negativeOne;
  }
  x <<= (32 + (~powerCount + 1));
  x = (x >> (32 + (~powerCount + 1)) & ~ (((1 << 31) >> (32 + (~powerCount + 1))) << 1));
  x <<= (22 + (~powerCount + 1));
  newFloat |= x;
  while (powerCount > 0){
    newFloat += 0x00800000;
    powerCount += negativeOne;
  }
  return newFloat;
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 * First I check for a bunch of edge cases, then I have a case where an int is
 * given (like 0x8f) that checks for if number is negative then shifts it left
 * once to double its positive value then adds the negative sign bit back if needed.
 * Last is the base case where I just add one to the exponents bits.
 */
unsigned float_twice(unsigned uf) {
  unsigned justExp;
  if (!uf){
    return 0;
  }
  if (!(uf ^ 0x80000000)){
    return 0x80000000;
  }
  if (!(uf ^ 0x7f800000)){
    return 0x7f800000;
  }
  if (!(uf ^ 0xff800000)){
    return 0xff800000;
  }
  if (!((0x7f800000 & uf) ^ 0x7f800000)){
    return uf;
  }
  if (!((0x7f800000 & uf) ^ 0)){
    unsigned isNeg = (uf >> 31) << 31;
    uf <<= 1;
    return uf | isNeg;
  }
  justExp = 0x7f800000 & uf;
  justExp += 0x00800000;
  uf &= 0x807fffff;
  return uf | justExp;
}
