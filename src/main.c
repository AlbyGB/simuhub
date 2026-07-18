#include <GL/gl.h>
#include <stdio.h>
#include <raylib.h>
#include <math.h>

void debug_float(const float q) {
    printf("%f\n", q);
}

void print_argv(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        printf("%s ", argv[i]);
    }
}

int main(int argc, char **argv) {
    const unsigned int width = 1000;
    const unsigned int height = 800;

    const unsigned int fps = 60;

    // posizione cerchio
    Vector2 deltaCircle = {100, 0};

    // velocità
    float speed = 0;
    float acc = 9.8;
    
    InitWindow(width, height, "test");
    SetTargetFPS(fps);

    float tempo_tot = 0;
    float dt = 0;

    while (!WindowShouldClose()) {

        // printf("%f\n", GetFrameTime());

        dt = GetFrameTime();

        tempo_tot += dt;
        
        deltaCircle.y += 1.0/2.0 * acc * pow(tempo_tot, 2);

        if (deltaCircle.y > height) {
            tempo_tot = 0;
            deltaCircle.y = 0;
        }
        
        debug_float(deltaCircle.y);

        // inizio del disegno
        BeginDrawing();

        ClearBackground(RAYWHITE);
        
        DrawCircleV(deltaCircle, 60, RED);
        
        EndDrawing();
    }

    CloseWindow();

    printf("Finestra Chiusa\n");
    
    return 0;
}
