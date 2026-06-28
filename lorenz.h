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
#define CAM_POS (Vector3){300,300,300}
#define Z_UP (Vector3){0,1,0}
#define RAMDOM_METRIC 20
#define NUM_PARTICLE 300

typedef struct particle{
    Vector3 position;
    Color color;
    Vector3 trail[NUM_TRAIL];
    int trail_head;
}Particle;

void camera_init(Camera3D *camera, Vector3 positon, Vector3 target);
void particles_init(Particle particles[NUM_PARICLE]);

#endif
