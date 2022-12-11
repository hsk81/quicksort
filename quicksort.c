#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(
    long *array, size_t length);
void quicksort(
    long *array, long lhs, long rhs);

void sort(
    long *array, size_t length)
{
  if (length > 0)
  {
    quicksort(array, 0, length - 1);
  }
}

void quicksort(
    long *array, long lhs, long rhs)
{
  if (rhs <= lhs)
  {
    return;
  }
  const long pivot = array[(lhs + rhs) / 2];
  long i = lhs;
  long j = rhs;
  while (i <= j)
  {
    while (array[i] < pivot)
    {
      i++;
    }
    while (array[j] > pivot)
    {
      j--;
    }
    if (i <= j)
    {
      long n = array[i];
      array[i] = array[j];
      array[j] = n;
      i++;
      j--;
    }
  }
  quicksort(array, lhs, j);
  quicksort(array, i, rhs);
}

void print(
    long *array, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void parse(
    const char *source[], long *array, size_t size)
{
  for (int i = 0; i < size; i++)
  {
    if (strncmp("0x", source[i], 2) == 0) {
      array[i] = strtol(source[i], (char **)NULL, 16);
    } else {
      array[i] = strtol(source[i], (char **)NULL, 10);
    }
  }
}

int main(
    int argc, const char *argv[])
{
  size_t size = argc - 1;
  if (size == 0)
  {
    return 0;
  }
  long *array = malloc(size * sizeof(long));
  parse(argv + 1, array, size);
  sort(array, size);
  print(array, size);
  free(array);
  return 0;
}
