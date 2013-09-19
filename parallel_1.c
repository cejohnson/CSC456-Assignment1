#include <stdio.h>
#include <math.h>
#include <omp.h>

// Run on login.hpc.ncsu.edu
// Currently doesn't work, but below does
// grendel.ece.ncsu.edu

// To compile:
// gcc -Wall -std=c99 serial.c -o serial -lm
//
// Don't forget to link that pesky math library at the end

// Stuff I added or changed denoted with "//" at the end

#define CONSTANT 50000 //
#define PI 3.14159265358979323846 //

int main(int argc, char *argv[]) {
  int numPartitions = CONSTANT*10000; //

  double upperLimit = CONSTANT*PI; //

  double interval = 0, integral = 0;
  int i = 0;//, j = 0;

  interval = upperLimit / numPartitions; //

  #pragma omp parallel for reduction(+:integral)
  for (i = 0; i < numPartitions; i++) {
    //Code goes here
    //Approximation of Sine wave

    // Using the equation provided
    integral += sin((i*interval + (i+1)*interval) / 2) * interval; //
  }

  printf("Estimate of integral is: %10.8lf\n", integral);
  return 0;
}