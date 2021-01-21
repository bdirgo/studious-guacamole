// Include header files (gives you access to standard library functions).
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Foward declaration of functions.                
// A function must be either declared or defined before it is used.
// This lets you use a function that you will define later in the file.
// Each declaration gives the return type, the name, and the parameters.
void swap1(int x, int y);
void swap2(int *x, int *y);
int function3(int x, int y);
void* lsearch(void* key, void* base, int n, int elemSize, int (*cmpfn)(void*, void*));
int intCmp(void* elem1, void* elem2);
int StrCmp(void* elem1, void* elem2);

// Every C program has one main function. This is where the program starts.
int main(int argc, char** argv) {

  int x = 0; // Always initialize a variable before using it
  int y = 0;
    
  int *p;
  p = &x; // Make p a pointer to x

  *p = 1; // Set the value the p points to (x) to 1

  // printf is declared in stdio.h
  printf("The value of x is: %d\n", x);

  x = 0;
  y = 1;
  swap1(x, y);
  printf("swap1(0, 1) = (%d, %d)\n", x, y);
  
  x = 0;
  y = 1;
  swap2(&x, &y);
  printf("swap2(0, 1) = (%d, %d)\n", x, y);

  int intArray[] = {4, 3, 2, 7, 11, 9};
  int size = 6;
  int number = 7;
  int* found = lsearch(&number, intArray, size, sizeof(int), intCmp);
  printf("%d\n", *found);

  char *notes[] = {"Aflat", "Fsharp", "B", "Gflat", "D"};
  char *favoriteNote = "B";
  char **foundNote = lsearch(&favoriteNote, notes, 5, sizeof(char *), StrCmp);
  printf("%s\n", *foundNote);

  // The return value from main is typically used to indicate if the program succeeded
  // 0 means successful, anything else means there was an error
  return 0;
}

// Other function definitions.
// This is where we implement the functions we declared above.
void swap1(int x, int y) {
  int temp;
  temp = x;
  x = y;
  y = temp;
  return;
}

void swap2(int *x, int *y) {
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
  return;
}

int function3(int x, int y) {
  switch (x) {
    case 0:
      x = x + 0 * y;
      break;
    case 1:
      x = x + 1 * y;
      break;
    case 2:
      x = x + 2 * y;
      break;
    default:
      x = x + 4 * y;
      break;
  }

  return x;
}

void* 
lsearch(void* key, void* base, int n, int elemSize, int (*cmpfn)(void*, void*))
{
  for (int i = 0; i < n; i++)
  {
    void* elemAddr = (char *)base + i * elemSize;
    if (cmpfn(key, elemAddr) == 0)
    {
      return elemAddr;
    }
  }
  return NULL;
}

int intCmp(void* elem1, void* elem2)
{
  int *ip1 = elem1;
  int *ip2 = elem2;
  return *ip1 - *ip2;
}

int StrCmp(void *elem1, void* elem2)
{
  char *s1 = * (char **)elem1;
  char *s2 = * (char **)elem2;
  return strcmp(s1, s2);
}