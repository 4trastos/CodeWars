#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct
{
  unsigned  numb;
} prime_stream_t;

bool    is_prime(unsigned numb)
{
  unsigned    i;
  
  if (numb <= 1)
    return (false);
  if (numb == 2)
    return (true);
  if (numb % 2 == 0)
    return (false);
  i = 3;
  while (i * i <= numb)
  {
    if (numb % i == 0)
      return (false);
    i += 2;
  }
  return (true);
}

unsigned    prime_stream_next(prime_stream_t *stream);

void    prime_stream_destroy(prime_stream_t *stream);

prime_stream_t *prime_stream_new(void)
{
  prime_stream_t  *stream;

  stream = malloc(sizeof(prime_stream_t));
  if (!stream)
    return (NULL);
  stream->numb = 0;
  return (stream);
}

unsigned prime_stream_next(prime_stream_t *stream)
{
  unsigned  numb;
  int       flag;

  if (stream->numb == 0)
  {
    stream->numb = 2;
    return (2);
  }
  numb = stream->numb + 1;
  flag = 0;
  while (!flag)
  {
    if (is_prime(numb))
      flag = 1;
    else
      numb++;
  }
  stream->numb = numb;
  return (numb);
}


void prime_stream_destroy(prime_stream_t *stream)
{
  free(stream);
  return;
}