#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool is_prime (int a){


    for(int i=2; i<= a/2; i++)
    
    {
      if(a%i ==0)
      {
       return false;
      }
    }
    return true;

}

int main()
{

int x;
scanf("%d",&x);
bool is_prime = true;

for(int i=2; i<= x/2; i++)
{
    if(x%i == 0)
    {
      is_prime = false;
    }
}

if (is_prime)

{
    printf("The number is prime");
}
else{
    printf("The number is not prime");
}


return EXIT_SUCCESS;

}
