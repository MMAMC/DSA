#include <stdio.h>
int hash(int key) 
{
return key % 7;
}


int main()
{
int value = 123;
int hash_value = hash(value);
printf("The hash value of %d is %d\n", value, hash_value);
return 0;
}
