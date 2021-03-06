// ECE 459 Live Coding example
// Lecture 16
// start threads 1000 times,
//  each thread iterates over 1/4 of the array and increments element by 1

#include <stdlib.h>
#include <stdio.h>
#include <thread>

#define NUM_THREADS (4)
#define ARRAY_LENGTH (1024*1024)
#define ARRAY_OFFSET (ARRAY_LENGTH / NUM_THREADS)

double * vector;

void setup(int id) {
  int i;
  for (i = id * ARRAY_OFFSET; i < (id+1) * ARRAY_OFFSET; i++) {
    vector[i] += 1.0;
  }
}

int main() {
  vector = (double *) malloc(sizeof(double) * 1024 * 1024);
  std::thread * t = new std::thread[NUM_THREADS];
  for (int j = 0; j < 1000; j++) {
    for (int i = 0; i < NUM_THREADS; i++)
      t[i] = std::thread(setup, i);
    for (int i = 0; i < NUM_THREADS; i++)
      t[i].join();
  }

  printf("vector[0] = %f\n", vector[0]);
}

