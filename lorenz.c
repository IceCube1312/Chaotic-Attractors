#include "lorenz.h"

void camera_init(Camera3D *camera, Vector3 positon, Vector3 target){
    camera->positon = positon;
    camera->target = target;
    camera->fovy = FOV;
    camera->up = Z_UP;
    camera->projection = CAMERA_PERSPECTIVE;
}

void particles_init(Particle particles[NUM_PARICLE]){
    srand(time(NULL));
    for(int i=0;i<NUM_PARTICLE;i++){
        double x = (rand % (2* RAMDOM_METRIC))-RAMDOM_METRIC;
        double y = (rand % (2* RAMDOM_METRIC))-RAMDOM_METRIC;
        double z = (rand % (2* RAMDOM_METRIC))-RAMDOM_METRIC;
        particles.position[i]=(Vector3){x,y,z};
    }
}
