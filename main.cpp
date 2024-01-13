/*
    Copyright (c) 2024 Sarah Smith
*/

#ifdef _TEST

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#else

#include "raylib.h"
#include "raymath.h"

#include "Constants.h"
#include "Character.h"

int main(int argc, char *argv[])
{
    InitWindow(windowWidth, windowHeight, argv[0]);

    const int numberOfFrames = 13;
    auto skeleton = new Character {
        LoadTexture("Skeleton Walk.png"),
        numberOfFrames
    };

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        const float dT = GetFrameTime();
        skeleton->move(dT);
        skeleton->update(dT);

        BeginDrawing();
        ClearBackground(BLUE);

        skeleton->draw();

        EndDrawing();
    }

    // Free and unload texture
    delete skeleton;

    CloseWindow();
}

#endif