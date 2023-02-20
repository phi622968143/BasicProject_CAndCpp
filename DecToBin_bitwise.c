#include <stdio.h>
//program to demo how bitwise can use to convert num sys. 
int main()
{
  int decimal_num, c, result;

  printf("Enter an integer in decimal number system\n");
  scanf("%d", &decimal_num);
  
  for (c = 31; c >= 0; c--)
  { //shift to the bit inorder(print leftest bit first)
    result = decimal_num >> c;
    
    // using & to check 0 or 1 
    // 1 mean 00000000 00000000 00000000 00000001 in 32 bits
    // so if result do AND only affect the last bit which makes true or false value.
    // also check fundation of cs chapter 4.
    if (result & 1)
      printf("1");
    else
      printf("0");
  }
}
