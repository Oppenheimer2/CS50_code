
#include <cs50.h>
#include <stdio.h>
#include <math.h>
int main(void)
{
  //Taking long int input for large card values
  long Card_no= get_long("Enter Card number: ");
  //Storing Card values in to seperate variable for calculation of 2*sum of even position ints' int sum and odd positon int sums
  long sep1=Card_no;
  long sep2=Card_no;
  long sum=0;
  //Removing first number and storing 2nd last int
  sep1=sep1/10;
  long a=sep1%10;
  a=2*a;
  a=a/10+a%10;
  sum=a+sum;
  //Looping to add sum of digits of all 2*even positioned numbers as per Luhn's Algorithm
  while (sep1>0)
  {
    sep1=sep1/100;
    a=sep1%10;
    a=2*a;
    a=a/10+a%10;

    sum=a+sum;
  }
  // Similar protocol for odd positon numbers
  long sum2=0;

  while (sep2>0)
  {
    long b=sep2%10;
    sep2=sep2/100;
    sum2=sum2+b;
  }

  long final = sum+sum2;

  //checking divisibility by 10
  if (final%10==0)
  {
    if(Card_no/10000000000000==34 || Card_no/10000000000000==37)
    {
      printf("AMEX\n");
    }
    else if(Card_no/100000000000000==51 || Card_no/100000000000000==52 || Card_no/100000000000000==53 || Card_no/100000000000000==54 || Card_no/100000000000000==55 )
    {
      printf("MASTERCARD\n");

    }
    else if(Card_no/1000000000000==4 || Card_no/1000000000000000==4)
    {
      printf("VISA\n");
    }
    else
    {
      printf("INVALID\n");
    }

  }
  else
  {
    printf("INVALID\n");
  }
}