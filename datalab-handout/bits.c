/*
 * CS:APP Data Lab
 *
 * <Please put your name and userid here>
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

  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
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
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

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
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
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
//1
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  return ~( (~(~x & y)) & (~(x & ~y)) );
}
/*
 * tmin - return minimum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {

  return 1 << 31;

}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
 /*
 C语言中偶尔会遇到  !!(cond)，特别是在宏定义当中
一个感叹号!我们知道是取非
！（非零）=0
！（零）=1

两个感叹号由此推导可以知道：
！！（非零）=1
！！（零）=0
 */
 //会有溢出
 //最大值为0x7fff ffff，加一会变为0x10000000，而此数加上本身后会变为0，
 //本身加本身为0的数只有0和0x1000 0000，
 //前面判断0x7fff ffff,后面还要保证不能为0
int isTmax(int x) {
  return (!(x+1+x+1)) & (!!(x+1));
}
/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
 /*
 只有所有奇数位为1的数（二进制），与0x5555 5555进行&预算才会得到0，
 故而需要得到0x5555 5555即可，将0x55分别左移8、16、24得到3个数，
 然后将这3个数和0x55相加即可得到0x5555 5555：
 */
int allOddBits(int x) {
  //unsigned int a = 0x55;

  //unsigned int b = a+(a<<8)+(a<<16)+(a<<24);
  unsigned int a = 0x5;

  unsigned int b = a+(a<<4)+(a<<8)+(a<<12)+(a<<16)+(a<<20)+(a<<24)+(a<<28);

  return !~(b|x);
}
/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return (~x+1);
}
//3
/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
 /*
 x需要>=’0’且<=’9’，将x与临界点作差，然后判断符号位的为0还是1即可
 */
int isAsciiDigit(int x) {
  return (!((x + ~(0x30) + 1) >>31)) & !!((x + ~(0x3a) + 1) >>31);
}
/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  /*
     *if x!=0,mask=0x00000000,so y&~mask==y and z&mask==0
     *if x==0,mask=0xffffffff,so y&~mask = y&0 =0; z&mask=z
     */
    int mask= (~(!x))+1;//利用了溢出
    return (y & ~mask)|(z & mask);
}
/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  /* Three situations
   * 1. equal
   * 2. different symbol
   * 3. there's a need to do x - y operation
   */
  int mask = 0x1;
  /* Determine if equal */
  int equal_or_not = ! (x ^ y);
  /* Determine if x and y have different symbol */
  int x_symbol = (x >> 31) & mask;
  int y_symbol = (y >> 31) & mask;
  int diff_symbol = x_symbol ^ y_symbol;
  /* If so, when x is negative, x is less than y */
  int x_l_y = diff_symbol & x_symbol;
  /* Operation x - y */
  int nega_y = ~ y + 1;
  int temp = x + nega_y;
  /* Determine the symbol of difference */
  int temp_nega_or_not = (temp >> 31) & mask;
  /* Attention that with different symbol, the result only relies on x_l_y,
   * we know that they're not equal,
   * and the value of temp_nega_or_not should be screened
   */
  int result = equal_or_not | x_l_y | ((! diff_symbol) & temp_nega_or_not);
  return result;
}
//4
/*
 * logicalNeg - implement the ! operator, using all of
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int logicalNeg(int x) {
  /*
  逻辑非就是非0为1，非非0为0。利用其补码（取反加一）的性质，
  除了0和最小数（符号位为1，其余为0），
  外其他数都是互为相反数关系（符号位取位或为1）。
  0和最小数的补码是本身，不过0的符号位与其补码符号位位或为0，最小数的为1。
  利用这一点得到解决方法。
  */
  return ((x | (~x+1) )>>31)+1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  /*
  如果是一个正数，则需要找到它最高的一位（假设是n）是1的，再加上符号位，结果为n+1；
  如果是一个负数，则需要知道其最高的一位是0的
  （例如4位的1101和三位的101补码表示的是一个值：-3，最少需要3位来表示）。
  */
  int b16, b8, b4, b2, b1, b0;
  int sign = x>>31;
  x = (sign&~x)|(~sign&x);//如果x为正则不变，否则按位取反（这样好找最高位为1的，原来是最高位为0的，这样也将符号位去掉了）

  // 不断缩小范围
  b16 = (!!(x>>16))<<4;//高十六位是否有1
  x = x>>b16;//如果有（至少需要16位），则将原数右移16位
  b8 = (!!(x>>8))<<3;//剩余位高8位是否有1
  x = x>>b8;//如果有（至少需要16+8=24位），则右移8位
  b4 = (!!(x>>4))<<2;//同理
  x = x>>b4;
  b2 = (!!(x>>2))<<1;
  x = x>>b2;
  b1 = (!!(x>>1));
  x = x>>b1;
  b0 = x;

  return b16+b8+b4+b2+b1+b0+1;//+1表示加上符号位
}
//float
/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
/*
考察浮点数编码的问题。浮点数有规格化、非规格化、无穷和NaN。
无穷和NaN，乘2也是返回uf本身。
再分类讨论规格化和非规格化。
非规格化 == 阶码域全 0 ，所以保留符号位，再将frac 左移一位即可，相当于乘2的一次幂。
若 uf 为规格化，则将 uf 的指数位加 1。
*/
unsigned floatScale2(unsigned uf)
{

    if (((uf >> 23) & 0xff) == 0xff)
    {
        return uf;
    }

    if (((uf >> 23) & 0xff) == 0x00)
    {
        return (uf & (0x1 << 31)) | (uf << 1);
    }

    return uf + (1 << 23);
}
/*
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf)
{
    int exp = (uf >> 23) & 0xFF;
    int frac = uf & 0x007FFFFF;
    int sign = uf & 0x80000000;
    int bias = exp - 127;

    if (exp == 255 || bias > 30)
    {
        // exponent is 255 (NaN), or number is too large for an int
        return 0x80000000u;
    }
    else if (!exp || bias < 0)
    {
        // number is very small, round down to 0
        return 0;
    }

    // append a 1 to the front to normalize
    frac = frac | 1 << 23;

    // float based on the bias
    if (bias > 23)
    {
        frac = frac << (bias - 23);
    }
    else
    {
        frac = frac >> (23 - bias);
    }

    if (sign)
    {
        // original number was negative, make the new number negative
        frac = ~(frac) + 1;
    }

    return frac;
}
/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatPower2(int x)
{
    int INF = 0x7f800000;
    int exp = x + 127;
    if(exp <= 0)
        return 0;

    if(exp >= 255)
        return INF;

    return exp << 23;
}
