#include <cs50.h>
#include <stdio.h>

int main(void)
{

    //Use get_long to get the user's input
    long number;

    number = get_long("Number: ");

    //Luhn's Algorithm Part 1
    //Multiply every other digit by 2, starting with the nubmer's second to last digit
    //Then add those products' digits together.

    //seperate every other digit starting with the number's second to last

    long number1 = number;
    int digits[8]; // create digits[0] through digits [7] for storing int
    int digitsA[8];
    int digitsB[8];


    number1 /= 10; // divide by 10

    for (int i = 0; i < 8; i++)
    {
        digits[i] = number1 % 10 * 2;
        digitsA[i] = digits[i] / 10;
        digitsB[i] = digits[i] % 10;
        number1 /= 100;
    }
    //Get the sum of the digits
    //There's got to be a way to make this a loop?

    int digitSum = 0;
    digitSum = digitsA[0] + digitsB[0] + digitSum;
    digitSum = digitsA[1] + digitsB[1] + digitSum;
    digitSum = digitsA[2] + digitsB[2] + digitSum;
    digitSum = digitsA[3] + digitsB[3] + digitSum;
    digitSum = digitsA[4] + digitsB[4] + digitSum;
    digitSum = digitsA[5] + digitsB[5] + digitSum;
    digitSum = digitsA[6] + digitsB[6] + digitSum;
    digitSum = digitsA[7] + digitsB[7] + digitSum;

    // Now let's add that sum to the sum of the digits that weren't
    // mulitplied by 2 (starting from the end)

    long number2 = number;
    int digits2[8]; // create digits[0] through digits [7] for storing int
    int digitsA2[8];
    int digitsB2[8];

    for (int j = 0; j < 8; j++)
    {
        digits2[j] = number2 % 10;
        number2 /= 100;
    }

    int digitSum2 = 0;
    digitSum2 = digits2[0] + digitSum2;
    digitSum2 = digits2[1] + digitSum2;
    digitSum2 = digits2[2] + digitSum2;
    digitSum2 = digits2[3] + digitSum2;
    digitSum2 = digits2[4] + digitSum2;
    digitSum2 = digits2[5] + digitSum2;
    digitSum2 = digits2[6] + digitSum2;
    digitSum2 = digits2[7] + digitSum2;

    int check = digitSum + digitSum2;

    int invalid = check % 10;

    //count the number of characters entered

    long number3 = number;
    int count = 0;

    while (number3 != 0)//count the number of digits entered by user
    {
        number3 /= 10;
        ++count;
    }

    //exclude invalid enties


    // Visa uses 13 and 16 digit numbers
    // Visa numbers start with 4.

    if (count == 13 && invalid == 0)
    {
        printf("VISA\n"); // Check for starting with 4
    }

    long number4 = number;
    int visa = 0;

    long number5 = number;
    int mastercardCheck = 0;
    int mastercard = 0;

    if (count == 16 && invalid == 0)
    {
        visa = number4 / 1000000000000000;

        if (visa == 4)
        {
            printf("VISA\n");
        }
        else
        {
            mastercardCheck = number5 / 100000000000000;

            if (mastercardCheck == 51 || mastercardCheck == 52 || mastercardCheck == 53 || mastercardCheck == 54 || mastercardCheck == 55)
            {
                mastercard = mastercard + 1;
                if (count == 16 && invalid == 0 && mastercard == 1)
                {
                    printf("MASTERCARD\n");
                }
            }
            else
            {
                printf("INVALID\n");
            }
        }
    }

    long number6 = number;
    int amexCheck = 0;
    int amex = 0;

    if (count == 15 && invalid == 0)
    {
        amexCheck = number6 / 10000000000000;

        if (amexCheck == 34 || amexCheck == 37)
        {
            amex = amex + 1;
            if (count == 15 && invalid == 0 && amex == 1)
            {
                printf("AMEX\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }

    if (count < 13 || count == 14 || count > 16 || invalid != 0)
    {
        printf("INVALID\n");
    }
}

/**********************************************************\

 $$$$$$\  $$$$$$$\  $$$$$$$$\ $$$$$$$\  $$$$$$\ $$$$$$$$\
$$  __$$\ $$  __$$\ $$  _____|$$  __$$\ \_$$  _|\__$$  __|
$$ /  \__|$$ |  $$ |$$ |      $$ |  $$ |  $$ |     $$ |
$$ |      $$$$$$$  |$$$$$\    $$ |  $$ |  $$ |     $$ |
$$ |      $$  __$$< $$  __|   $$ |  $$ |  $$ |     $$ |
$$ |  $$\ $$ |  $$ |$$ |      $$ |  $$ |  $$ |     $$ |
\$$$$$$  |$$ |  $$ |$$$$$$$$\ $$$$$$$  |$$$$$$\    $$ |
 \______/ \__|  \__|\________|\_______/ \______|   \__|

ASCII art generated from: https://www.patorjk.com/
____________________________________________________________________________
REFERENCES:


Digit count, retrieved from, https://www.programiz.com/c-programming/examples/digits-count
C - Operators, retrieved frrom, https://www.tutorialspoint.com/cprogramming/c_operators.htm

____________________________________________________________________________
LOG:

8:17 AM

Okay today I'm writing a program called credit.

This program will prompt the user for a credit card number and
then report whether it is a valid American Express, MasterCard or Visa card
number, per the definitions of each' format.

The last line of code's output should be

AMEX\n
MASTERCARD\n
VISA\n
or
INVALID\n

The user's input will be entirely numeric, (devoid of hyphes, ) but the user's input
will not fit in a int. Best to use get_long.

The program should behave as follows:


$ ./credit
Number: 400360000000014
VISA

Get_long itseld will reject hyphens and more so

$ ./credit
Number: 4003-6000-000-0014
Number: foo
Number: 400360000000014

But it's up to me to catch inputs that are not credit card numbers

Like: 6176595959
INVALID

Test out the program with valid and invalid numbers.



Definition of Valid Credit Cards

American Express uses 15-digit numbers.
American Express numbers start with a 34 or 37.

MasterCard uses 16-digit numbers
MasterCard numbers start with 51, 52, 53, 54, or 55.

Visa uses 13 and 16 digit numbers
Visa numbers start with 4.

Also, all credits cards have a check sum built in.

Luhn's Algorithm

1. Multiply every other digit by 2, starting with the number's second-to-last
digit, and then add those products *digits* together.

2. Add the sum to the sum of the digits that weren't multiplied by 2.

3. If the total's last digit is 0 (or, put more formally, if the total modulo 10 is
congruent to 0), the number is valid.


Example:

1.
    4003-6000-0000-0014
    4003600000000014
    4.0.6.0.0.0.0.1.

    multiply each digit by 2, starting from the last:

    1*2 + 0*2 + 0*2 + 0*2 + 0*2 + 6*2 + 0*2 + 4*2

    that gives us:

    2 + 0 + 0 + 0 + 0 + 12 + 0 + 8

    Now add thoe products digits:

    2 + 0 + 0 + 0 + 0 + 1 + 2 + 0 + 8 = 13

2. Add the sum (13) to the sum of the digits that weren't multiplied by 2
(starting from the end):

13 + 4 + 0 + 0 + 0 + 0 + 0 + 3 + 0 = 20

13. Yes, the last digit in that sum (20) is a 0 so it is legit.


LOG 12:12

I found a cool example of counting digits here and I think I can use this to help
count the number of digits of the credit card:
https://www.programiz.com/c-programming/examples/digits-count

#include <stdio.h>
int main() {
    long long n;
    int count = 0;
    printf("Enter an integer: ");
    scanf("%lld", &n);

    // iterate until n becomes 0
    // remove last digit from n in each iteration
    // increase count by 1 in each iteration
    while (n != 0) {
        n /= 10;     // n = n/10
        ++count;
    }

    printf("Number of digits: %d", count);
}

I tested this code out and I'll make some adjustments to make it work for the
user input.

LOG 1:47

I got my do while loop working, so that it counts the digits and then rejects any
inputs that are not 13, 15, or 16 digits, the code is as follows:

do
   {
       number = get_long("Number: ");
       count = 0;
       while (number != 0 )
       {
       number /= 10;
       ++count;
       }
   }
   while (count < 13 || count == 14 || count > 16 );

I'll keep it in for now but I believe the assignment may not like this extra step.

LOG 2:22 PM

I've taken that part out.

It looks like one of the most challening puzzels is to count every other digit.

Here are a few ideas I looked up:

Make use of simple division / and % mod operators to get this

int number[20];
int count = 0;
long long cardNum = GetLongLong();
long long prevNum = cardNum;
while (cardNum <10)
{
  cardNum = prevNum /10;
  number[count] = prevNum % 10
  prevNum = cardNum;

  count++;
}

source: hazzelnutie on reddit.

Anotherway to do it could be this:

int digits[7]; //storage for odd digits

cardNum /=10; //throw away the least significant digit

for (int i = 0; i < 7; ++i) //for each odd digit
{
  digits[i] = cardNum % 10; //extract the digit
  cardNum /= 100; //throw away two digits
}

source: Pual R on Reddit

LOG 3:50 PM

Look like no solution works out of the box but with some minor modifications I got
this to work:

long cardNum = get_long("Number: ");

    int digits[8]; //storage for odd digits

    cardNum /=10; //throw away the least significant digit

    for (int i = 0; i < 8; i++) //for each odd digit
    {
    digits[i] = cardNum % 10; //extract the digit
    cardNum /= 100; //throw away two digits
    }

    printf("Digit 0: %i\n", digits[0]);
    printf("Digit 1: %i\n", digits[1]);
    printf("Digit 2: %i\n", digits[2]);
    printf("Digit 3: %i\n", digits[3]);
    printf("Digit 4: %i\n", digits[4]);
    printf("Digit 5: %i\n", digits[5]);
    printf("Digit 6: %i\n", digits[6]);
    printf("Digit 7: %i\n", digits[7]);

The key here is I had to use an array digits[8], because the max number of
numbers in a credit card is 16, it will only store 8, for every odd number.

This is also a clever use of the for loop.

cardNum /=10; is the same as saying CardNum = cardNum / 10 /= is divide and assignment operator.

This cuts of the first number by dividing the card number by 10.

So if the card number is:

4003600000000014

then it will cut off the 4 at the end. Making it

400360000000001

the for loop runs the following 8 times.

LOG 9:12 AM

Day Two on this program, Looks like I need to remove my counting digit program to make
sure I can do the luhn formula. The first step is to remove every other digit, useing the %
tool.

LOG 11:13 AM

My code works!

It's not done yet but it will check now if the luhns algoritum ends in a zero.

With that basic formula working, now I just need to filter the differnt card types
and type the right card to each.

LOG 1:31 PM

Okay ran a first check50 after getting it mostly working, I wanted to weed out any
odd bugs. This is what check50 found:

:) credit.c exists
:) credit.c compiles
:) identifies 378282246310005 as AMEX
:) identifies 371449635398431 as AMEX
:) identifies 5555555555554444 as MASTERCARD
:) identifies 5105105105105100 as MASTERCARD
:) identifies 4111111111111111 as VISA
:) identifies 4012888888881881 as VISA
:) identifies 4222222222222 as VISA
:) identifies 1234567890 as INVALID
:( identifies 369421438430814 as INVALID
    expected "INVALID\n", not "AMEX\n"
:) identifies 4062901840 as INVALID
:( identifies 5673598276138003 as INVALID
    expected "INVALID\n", not "MASTERCARD\n"
:) identifies 4111111111111113 as INVALID
:) identifies 4222222222223 as INVALID

From here it looks like I need to add an extra check from AMX and Mastercard,

I wan't sure if I needed to add those or not. I'll run those two cards that
failed through debug but I believe they passed the luhn's test but didn't
match the first two letters. I wasn't sure if that was possible but it looks
to be the case.

Noting the numbers the AMEX was

    identifies 369421438430814 as INVALID
    expected "INVALID\n", not "AMEX\n"

Notes how it starts with a 36, where they should all start with a 34 or 37.

The mastercard on the other hand:
    :( identifies 5673598276138003 as INVALID
    expected "INVALID\n", not "MASTERCARD\n"

Starts with a 56, where it should be a: 51, 52, 53, 54, or 55.

Yes, running the debug shows that both passed the Luhn's test but they are
invalid because the first numbers are off.

DEBUG

The following to help debug
    //Print Digits for fun
    printf("\n");
    printf("DEBUG\n");
    printf("Digit A 0: %i\n", digitsA[0]);
    printf("Digit B 0: %i\n", digitsB[0]);
    printf("Digit A 1: %i\n", digitsA[1]);
    printf("Digit B 1: %i\n", digitsB[1]);
    printf("Digit A 2: %i\n", digitsA[2]);
    printf("Digit B 2: %i\n", digitsB[2]);
    printf("Digit A 3: %i\n", digitsA[3]);
    printf("Digit B 3: %i\n", digitsB[3]);
    printf("Digit A 4: %i\n", digitsA[4]);
    printf("Digit B 4: %i\n", digitsB[4]);
    printf("Digit A 5: %i\n", digitsA[5]);
    printf("Digit B 5: %i\n", digitsB[5]);
    printf("Digit 6: %i\n", digits[6]);
    printf("Digit A 6: %i\n", digitsA[6]);
    printf("Digit B 6: %i\n", digitsB[6]);
    printf("Digit A 7: %i\n", digitsA[7]);
    printf("Digit B 7: %i\n", digitsB[7]);
    printf("Digit Sum: %i\n", digitSum);
    printf("\n");

    printf("Digit2 0: %i\n", digits2[0]);
    printf("Digit 1: %i\n", digits2[1]);
    printf("Digit 2: %i\n", digits2[2]);
    printf("Digit 3: %i\n", digits2[3]);
    printf("Digit 4: %i\n", digits2[4]);
    printf("Digit 5: %i\n", digits2[5]);
    printf("Digit 6: %i\n", digits2[6]);
    printf("Digit 7: %i\n", digits2[7]);
    printf("\n");

    printf("Number: %ld\n", number);
    printf("Digit Sum: %i\n", digitSum);
    printf("Digit Sum2: %i\n", digitSum2);
    printf("Check: %i\n", check);
    printf("Last Digit of Sum: %i\n", invalid);

    if (invalid == 0)
    {
        printf ("VALID\n");
    }
    else
        printf ("INVALID\n");

    printf("Count of Digits: %i\n", count);
    printf("First digit? %i\n", visa);
    printf("amexCheck: %i\n", amexCheck);
    printf("amex %i\n", amex);

LOG 4:00 PM

Well she's ugly but it works!




*/
