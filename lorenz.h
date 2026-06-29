#ifndef IOIOIOIOIO
#define IOIOIOIOIO

#include <raymath.h>
#include <raylib.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#ifdef HALVORSEN
#define HAL_A 1.4
#define CAM_POS (Vector3){4,4,4}
#define Z_UP (Vector3){0,1,0}
#define TARGET_CAM (Vector3){0,1,0}
#define RANDOM_METRIC 5
#define NUM_PARTICLE 50
#define CYLIN_RAD 0.1
#define FPS 60
#define PARTICLE_SIZE 0.001

#else
#define CAM_POS (Vector3){30,0,30}
#define Z_UP (Vector3){0,1,0}
#define PRANTL 10
#define RAYLEIGH 28
#define BETA 2.67
#define TARGET_CAM (Vector3){0,9,30}
#define RANDOM_METRIC 20
#define NUM_PARTICLE 50
#define CYLIN_RAD 0.1
#define FPS 60
#define PARTICLE_SIZE 0.1
#endif

#define NUM_TRAIL 300
#define FOV 90
#define TERMINAL_GREEN (Color){1, 22, 5, 255}
#define INF 9999999999
#define NINF -9999999999
#define TRAIL_PER_FRAME 10
#define HEIGHT 1080
#define WIDTH 1980

typedef struct particle{
    Vector3 position;
    Color color;
    Vector3 trail[NUM_TRAIL];
    int trail_head;
}Particle;

void camera_init(Camera3D *camera, Vector3 positon, Vector3 target);
void particles_init(Particle particles[NUM_PARTICLE]);
void updating_positions(Particle particles[NUM_PARTICLE],double frame_time);
void Draw_trails(Particle particle);
#endif
