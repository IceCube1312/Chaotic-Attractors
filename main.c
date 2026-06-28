#include "lorenz.h"

int main(int argc, char** argv){
	
	const int height = 800;
	const int width = 1200;

	InitWindow(width, height,"NAME NAME NAME");
	assert(IsWindowReady());

	Camera3D camera;
	Vector3 camera_pos=CAM_POS;
	Vector3 camera_target=Vector3Zero();

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
	                DrawLine3D((Vector3){INF,0,0},(Vector3){NINF,0,0},RED);
                        DrawLine3D((Vector3){0,INF,0},(Vector3){0,NINF,0},BLUE);
                        DrawLine3D((Vector3){0,0,INF},(Vector3){0,0,NINF},GREEN);
			updating_positions(particles,frame_time);
			for(int i=0;i<NUM_PARTICLE;i++){
				DrawSphere(particles[i].position,PARTICLE_SIZE,WHITE);
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
