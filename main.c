#include "lorenz.h"

int main(int argc, char** argv){
	
	const int height = 800;
	const int width = 1200;

	InitWindow(width, height,"NAME NAME NAME");
	assert(IsWindowReady());

	Camera3D camera;
	Vector3 camera_pos=CAM_POS;
	Vector3 camera_target=TARGET_CAM;

	camera_init(&camera,camera_pos,camera_target);

	Particle particles[NUM_PARTICLE];
	particles_init(particles);

	double elapsed_time=0;
	double start_time;
	double frame_time = 1/(double)FPS;

	while(!WindowShouldClose()){
		if(elapsed_time >= frame_time){
			start_time=GetTime();
			BeginDrawing();
			BeginMode3D(camera);
			ClearBackground(TERMINAL_GREEN);
			updating_positions(particles,frame_time);
			updating_trails(particles,TRAIL_PER_FRAME,frame_time);
			for(int i=0;i<NUM_PARTICLE;i++){
				DrawSphere(particles[i].position,PARTICLE_SIZE,WHITE);
				for(int j=0;j<NUM_TRAIL-1;j++){
					int current_index = (particles[i].trail_head -1 - j + NUM_TRAIL) % NUM_TRAIL;
					Vector3 current = particles[i].trail[current_index];
					int prev_index = (particles[i].trail_head - 2 - j + NUM_TRAIL) % NUM_TRAIL;
					Vector3 prev_point = particles[i].trail[prev_index];
					DrawLine3D(current,prev_point,WHITE);
				}
			}
			EndMode3D();
			EndDrawing();
		}
		elapsed_time = GetTime() - start_time;
		if(elapsed_time < frame_time){
			usleep((frame_time - elapsed_time)*1000000);
		}
		elapsed_time = GetTime() - start_time;
	}
}
