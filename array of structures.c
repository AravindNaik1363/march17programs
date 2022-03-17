#include<stdio.h>
#include<conio.h>
void main()
{
  struct emp
  {
    char name[20];
    char status[25];
    int age;
  }
  v[2]={"Annie","Jackson",25,"David","Bush",27};//array of 2 structures
  int i;
  for(i=0;i<=1;i++)
  {
    printf("\n%s%s",v[i].name,v[i].status);//when i=0,prints v[0].name as Annie and v[0].status as Jackson
                                           //when i=1,prints v[1].name as David and v[1].status as Bush
  }
  getch();
}
