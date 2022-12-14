#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define THRESHOLD 4

/* read a matrix from a file */
void read_matrix(char* fname, float*** a, float** sa, int* m, int* n) {
  FILE* finptr;
  int i, sz;

  finptr = fopen(fname, "r");
  if (!finptr) {
    perror("ERROR: can't open matrix file\n");
    exit(1);
  }

  if (fread(m, sizeof(int), 1, finptr) != 1 ||
      fread(n, sizeof(int), 1, finptr) != 1) {
    perror("Error reading matrix file");
    exit(1);
  }
  sz = (*m) * (*n);

  *sa = (float*)malloc(sz * sizeof(float));
  if (fread(*sa, sizeof(float), sz, finptr) != sz) {
    perror("Error reading matrix file");
    exit(1);
  }

  *a = (float**)malloc((*m) * sizeof(float*));
  for (i = 0; i < *m; i++)
    (*a)[i] = &(*sa)[i * (*n)];

  fclose(finptr);
}

/* write a matrix to a file */
void write_matrix(char* fname, float* sa, int m, int n) {
  FILE* foutptr;
  int i;
  float* ptr;

  foutptr = fopen(fname, "w");
  if (!foutptr) {
    perror("ERROR: can't open matrix file\n");
    exit(1);
  }

  if (fwrite(&m, sizeof(int), 1, foutptr) != 1 ||
      fwrite(&n, sizeof(int), 1, foutptr) != 1) {
    perror("Error reading matrix file");
    exit(1);
  }

  ptr = sa;
  for (i = 0; i < m; i++) {
    if (fwrite(ptr, sizeof(float), n, foutptr) != n) {
      perror("Error reading matrix file");
      exit(1);
    }
    ptr += n;
  }

  fclose(foutptr);
}

/* dumb matrix multiplication; used for debugging purposes */
void dumb_matmul(float** a, float** b, float** c, int N) {
  int i, j, k;
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      for (k = 0; k < N; k++)
        c[i][j] += a[i][k] * b[k][j];
}

/* matrix multiplication using recursive block decomposition */
void recursive_matmul(int crow, int ccol, /* corner of C block */
                      int arow, int acol, /* corner of A block */
                      int brow, int bcol, /* corner of B block */
                      int n,              /* block size */
                      int N,              /* matrices are N*N */
                      float** a, float** b, float** c) {
  if (n > THRESHOLD) {
    /* break up the matrices and call recursive_matmul on sub-matrices */
  } else {
    /* multiply the two matrices right away */
  }
}

/* call this function to do matrix multiplication */
void matmul(float** a, float** b, float** c, int N) {
  /*recursive_matmul(0, 0, 0, 0, 0, 0, N, N, a, b, c);*/
  dumb_matmul(a, b, c, N);
}

int main(int argc, char* argv[]) {
  int n;               /* dimension of the matrix */
  float *sa, *sb, *sc; /* storage for matrix A, B, and C */
  float **a, **b, **c; /* 2-d array to access matrix A, B, and C */
  int i, j;

  /* check the number of arguments */
  if (argc != 4) {
    printf("Usage: %s fileA fileB fileC\n", argv[0]);
    return 1;
  }

  /* read matrix A */
  printf("read matrix A from %s\n", argv[1]);
  read_matrix(argv[1], &a, &sa, &i, &j);
  if (i != j) {
    printf("ERROR: matrix A not square\n");
    return 2;
  }
  n = i;

  /* read matrix B */
  printf("read matrix B from %s\n", argv[2]);
  read_matrix(argv[2], &b, &sb, &i, &j);
  if (i != j) {
    printf("ERROR: matrix B not square\n");
    return 2;
  }
  if (n != i) {
    printf("ERROR: matrix A and B incompatible\n");
    return 2;
  }

  /* initialize matrix C */
  sc = (float*)malloc(n * n * sizeof(float));
  memset(sc, 0, n * n * sizeof(float));
  c = (float**)malloc(n * sizeof(float*));
  for (i = 0; i < n; i++)
    c[i] = &sc[i * n];

  /* do the multiplication */
  matmul(a, b, c, n);

  /* write matrix C */
  write_matrix(argv[3], sc, n, n);

  return 0;
}
