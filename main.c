#include "lorenz.h"

int main(int argc, char** argv){
	
	const int height = 800;
	const int width = 1200;

	InitWindow(width, height,"NAME NAME NAME");
	assert(IsWindowReady());

	Camera3D camera;
	Vector3 camera_pos=CAM_POS;
	Vector3 camera_target=Vector3Zero;

	camera_init(&camera,camera_pos,camera_target);

	Particle particles[NUM_PARTICLE];
	particles_init(particles);

