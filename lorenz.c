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
	for(int p=0;p<NUM_TRAIL;p++){
		particles[i].trail[p]=particles[i].position;
	}
	particles[i].trail_head=0;
    }
}

void updating_positions(Particle particles[NUM_PARTICLE],double frame_time){
	double delta = frame_time/TRAIL_PER_FRAME;
	for(int i=0;i<NUM_PARTICLE;i++){
		float x = particles[i].position.x; 
		float y = particles[i].position.y; 
		float z = particles[i].position.z;
		Vector3 temp = {x,y,z};
		for(int j=0;j<TRAIL_PER_FRAME;j++){
			x=temp.x;y=temp.y;z=temp.z;
#ifdef HALVORSEN
			temp.x += (-HAL_A * x - 4.0*y - 4.0*z - y*y) * delta;
			temp.y += (-HAL_A * y - 4.0*z - 4.0*x - z*z) * delta;
			temp.z += (-HAL_A * z - 4.0*x - 4.0*y - x*x) * delta;
#else
			temp.x += (PRANTL * (y - x)) * delta;
			temp.y += (x * (RAYLEIGH - z) - y) * delta;
			temp.z += (x * y - BETA * z) * delta;
#endif
			particles[i].trail[particles[i].trail_head]=temp;
			particles[i].trail_head=(particles[i].trail_head+1)%NUM_TRAIL;
		}
		particles[i].position=temp;
	}
}

void Draw_trails(Particle particle){
	for(int j=0;j<NUM_TRAIL-1;j++){
		int current_index = (particle.trail_head -1 - j + NUM_TRAIL) % NUM_TRAIL;
		Vector3 current = particle.trail[current_index];
		int prev_index = (particle.trail_head - 2 - j + NUM_TRAIL) % NUM_TRAIL;
		Vector3 prev_point = particle.trail[prev_index];

#ifdef HALVORSEN
		double ratio = j/(double)NUM_TRAIL;
		int G =  255 * (1-ratio);
		int B = 255 * ratio;
		int R = 255 * (1-ratio);
                DrawCylinderEx(current,prev_point,CYLIN_RAD,CYLIN_RAD,0,(Color){0,G,0,255});
#else
		double ratio = j/(double)NUM_TRAIL;
		int G =  255 * (1-ratio);
		int B = 255 * ratio;
		int R = 255 * ratio;
                DrawCylinderEx(current,prev_point,CYLIN_RAD,CYLIN_RAD,0,(Color){R,255,B,255});
#endif
	}
}
