#include <limits.h>
#include <math.h>
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define CHUNKSIZE 1000
#define PI 3.141592653589793238462643
#define TOTAL_DARTS 10000000

/* message tags */
#define REQUEST 1
#define REPLY 2

int main(int argc, char* argv[]) {
  int iter, in, out, i, max, ranks[1], done;
  double x, y, Pi;
  int numprocs, myid, server, totalin, totalout, workerid;
  int rands[CHUNKSIZE], request;
  MPI_Comm world, workers;
  MPI_Group world_group, worker_group;
  MPI_Status status;

  MPI_Init(&argc, &argv);
  world = MPI_COMM_WORLD;
  MPI_Comm_size(world, &numprocs);
  MPI_Comm_rank(world, &myid);

  server = numprocs - 1; /* last proc is server */
  MPI_Comm_group(world, &world_group);
  ranks[0] = server;
  MPI_Group_excl(world_group, 1, ranks, &worker_group);
  MPI_Comm_create(world, worker_group, &workers);
  MPI_Group_free(&worker_group);

  if (myid == server) { /* I am the rand server */
    srandom(12345);
    do {
      MPI_Recv(&request, 1, MPI_INT, MPI_ANY_SOURCE, REQUEST, world, &status);
      if (request) {
        for (i = 0; i < CHUNKSIZE;) {
          rands[i] = random();
          if (rands[i] <= INT_MAX) i++;
        }
        MPI_Send(rands, CHUNKSIZE, MPI_INT, status.MPI_SOURCE, REPLY, world);
      }
    } while (request > 0);
  } else { /* I am a worker process */
    request = 1;
    done = in = out = 0;
    max = INT_MAX; /* max int, for normalization */
    MPI_Send(&request, 1, MPI_INT, server, REQUEST, world);
    MPI_Comm_rank(workers, &workerid);
    iter = 0;
    while (!done) {
      iter++;
      request = 1;
      MPI_Recv(rands, CHUNKSIZE, MPI_INT, server, REPLY, world, &status);
      for (i = 0; i < CHUNKSIZE - 1;) {
        x = (((double)rands[i++]) / max) * 2 - 1;
        y = (((double)rands[i++]) / max) * 2 - 1;
        if (x * x + y * y < 1.0)
          in++;
        else
          out++;
      }
      MPI_Allreduce(&in, &totalin, 1, MPI_INT, MPI_SUM, workers);
      MPI_Allreduce(&out, &totalout, 1, MPI_INT, MPI_SUM, workers);
      Pi = (4.0 * totalin) / (totalin + totalout);
      done = (totalin + totalout) > TOTAL_DARTS;
      request = (done) ? 0 : 1;
      if (myid == 0) {
        // uncomment the following line if you want to see the debug
        // output
        // printf( "\riter=%d, total=%d, pi=%.20f", iter,
        // totalin+totalout, Pi );
        MPI_Send(&request, 1, MPI_INT, server, REQUEST, world);
      } else {
        if (request) MPI_Send(&request, 1, MPI_INT, server, REQUEST, world);
      }
    }
    MPI_Comm_free(&workers);
  }

  if (myid == 0) {
    printf("\npi=%.20lf in=%d out=%d total=%d\n", Pi, totalin, totalout,
           totalin + totalout);
  }
  MPI_Finalize();
  return 0;
}
