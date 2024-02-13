#include <raylib.h>
#include <string>

int ranX;
int ranY;

void GenerateRandomPositionForFish()
{
    ranX = GetRandomValue(0, 920);
    ranY = GetRandomValue(360,650);
}

int main()
{
    InitWindow(1028,720,"FISH HUNTER");
    InitAudioDevice();
    int score = 0;


    //Crosshair
    Texture2D crosshair = LoadTextureFromImage(LoadImage("textures/crosshair.png"));
    Vector2 crosshairPos;

    //Dock
    Texture2D dock = LoadTextureFromImage(LoadImage("textures/dock.png"));
    Vector2 dockPos = {257,360};

    //Fish
    Texture2D fish = LoadTextureFromImage(LoadImage("textures/brass.png"));
    Vector2 fishPos;
    GenerateRandomPositionForFish();
    fishPos.x = ranX;
    fishPos.y = ranY;
    Rectangle fishBounds = {(float)fishPos.x,(float)fishPos.y,(float)fish.width,(float)fish.height};

    //https://www.fesliyanstudios.com/royalty-free-sound-effects-download/gun-shooting-300
    Sound gunShot = LoadSound("audio/1911-.45-ACP-Close-Single-Gunshot-A-www.fesliyanstudios.com.mp3");

    //Background
    Texture2D background = LoadTextureFromImage(LoadImage("textures/background.png"));


    while(!WindowShouldClose())
    {
       crosshairPos = GetMousePosition();

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            if (CheckCollisionPointRec(crosshairPos, fishBounds))
            {
                PlaySound(gunShot);
                GenerateRandomPositionForFish();
                score -= -1; //+1
                fishPos.x = (float)ranX;
                fishPos.y = (float)ranY;
                fishBounds.x = fishPos.x;
                fishBounds.y = fishPos.y;
            }
        }

        HideCursor();
        BeginDrawing();
            ClearBackground(WHITE);
            DrawTexture(background,0,0,WHITE);
            DrawText(std::to_string(score).c_str(),500,10,25,BLACK); // I am actually going crazy
            DrawText("DrFlower 2/12/24",0,0,24,BLACK);
            //^^^ Convert int to C++ string, then to C string.
            DrawTexture(dock,dockPos.x,dockPos.y,WHITE); //Dock
            DrawTexture(fish,fishPos.x,fishPos.y, WHITE); //Fish
            DrawTexture(crosshair,crosshairPos.x,crosshairPos.y,WHITE); //Crosshair
            
        EndDrawing();
    }
}