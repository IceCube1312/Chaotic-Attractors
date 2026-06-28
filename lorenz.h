#ifndef IOIOIOIOIO
#define IOIOIOIOIO

#include <raymath.h>
#include <raylib.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define NUM_TRAIL 300
#define FOV 90
#define CAM_POS (Vector3){50,0,50}
#define Z_UP (Vector3){0,1,0}
#define RANDOM_METRIC 20
#define NUM_PARTICLE 30
#define FPS 1000
#define PRANTL 10
#define RAYLEIGH 28
#define BETA 2.67
#define TERMINAL_GREEN (Color){1, 22, 5, 255}
#define PARTICLE_SIZE 0.1
#define INF 9999999999
#define NINF -9999999999

typedef struct particle{
    Vector3 position;
    Color color;
    Vector3 trail[NUM_TRAIL];
    int trail_head;
}Particle;

void camera_init(Camera3D *camera, Vector3 positon, Vector3 target);
void particles_init(Particle particles[NUM_PARTICLE]);
void updating_positions_and_trails(Particle particles[NUM_PARTICLE],double frame_time);
#endif
