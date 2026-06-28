#include "lorenz.h"

void camera_init(Camera3D *camera, Vector3 positon, Vector3 target){
    camera->position = positon;
    camera->target = target;
    camera->fovy = FOV;
    camera->up = Z_UP;
    camera->projection = CAMERA_PERSPECTIVE;
}

void particles_init(Particle particles[NUM_PARTICLE]){
    srand(time(NULL));
    for(int i=0;i<NUM_PARTICLE;i++){
        double x = (rand() % (2* RANDOM_METRIC))-RANDOM_METRIC;
        double y = (rand() % (2* RANDOM_METRIC))-RANDOM_METRIC;
        double z = (rand() % (2* RANDOM_METRIC))-RANDOM_METRIC;
        particles[i].position=(Vector3){x,y,z};
    }
}

void updating_positions(Particle particles[NUM_PARTICLE],double frame_time){
	for(int i=0;i<NUM_PARTICLE;i++){
		float x = particles[i].position.x; 
		float y = particles[i].position.y; 
		float z = particles[i].position.z; 
		particles[i].position.x += (PRANTL* (y-x)) * frame_time;
		particles[i].position.y += (x*(RAYLEIGH-z) -y) * frame_time;
		particles[i].position.z += (x*y - BETA * z) * frame_time;
	}
}
