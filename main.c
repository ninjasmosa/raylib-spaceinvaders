#include "raylib.h"

const int screenWidth = 600;
const int screenHeight = 800;

// Define position of the player and their speed
Rectangle player = { (float)screenWidth / 2, 750, 50, 50 };
float playerSpeed = 2.0f;

// Projectile properties
int projectileActive = 0; // Flag to check if the projectile is active
int projectileSpeed = 20;
Vector2 projectilePosition = { 0, 0 }; // Initial position of the projectile
float projectileSize = 5.0f;

// Define enemies
struct enemy {
    Rectangle rect;
    int alive;
};

struct enemy enemy1 = { { 50, 50, 40, 25 }, 1 };
struct enemy enemy2 = { { 150, 50, 40, 25 }, 1 };
struct enemy enemy3 = { { 250, 50, 40, 25 }, 1 };
struct enemy enemy4 = { { 350, 50, 40, 25 }, 1 };
struct enemy enemy5 = { { 450, 50, 40, 25 }, 1 };
struct enemy enemy6 = { { 550, 50, 40, 25 }, 1 };
struct enemy enemy7 = { { 50, 100, 40, 25 }, 1 };
struct enemy enemy8 = { { 150, 100, 40, 25 }, 1 };
struct enemy enemy9 = { { 250, 100, 40, 25 }, 1 };
struct enemy enemy10 = { { 350, 100, 40, 25 }, 1 };
struct enemy enemy11 = { { 450, 100, 40, 25 }, 1 };
struct enemy enemy12 = { { 550, 100, 40, 25 }, 1 };
struct enemy enemy13 = { { 50, 150, 40, 25 }, 1 };
struct enemy enemy14 = { { 150, 150, 40, 25 }, 1 };
struct enemy enemy15 = { { 250, 150, 40, 25 }, 1 };
struct enemy enemy16 = { { 350, 150, 40, 25 }, 1 };
struct enemy enemy17 = { { 450, 150, 40, 25 }, 1 };
struct enemy enemy18 = { { 550, 150, 40, 25 }, 1 };
/* Previously enemies were defined by stating here their Vector2 positions with size defined in a DrawRectangleV
    Rectangle structs are used now for the purposes of collision detection, that function uses a Rectangle struct
*/

int enemySpeed = 1;

// Define barriers
struct barrier {
    Rectangle rect;
    int health;
};

struct barrier barrier1 = { { 125, 600, 75, 20 }, 5 };
struct barrier barrier2 = { { 275, 600, 75, 20 }, 5 };
struct barrier barrier3 = { { 425, 600, 75, 20 }, 5 };

// Functions are below

// Player interactions for movement and shooting
void movePlayer() {
    // Player movement logic
    if (IsKeyDown(KEY_RIGHT)) player.x += playerSpeed;
    if (IsKeyDown(KEY_LEFT)) player.x -= playerSpeed;
}

void shoot() {
    if (IsKeyPressed(KEY_SPACE) && !projectileActive) {
        projectileActive = 1;
        projectilePosition.x = player.x + player.width / 2 - projectileSize / 2;
        projectilePosition.y = player.y;
    }
}

void moveEnemies() {
    // Update enemy positions
    enemy1.rect.x += enemySpeed;
    enemy2.rect.x += enemySpeed;
    enemy3.rect.x += enemySpeed;
    enemy4.rect.x += enemySpeed;
    enemy5.rect.x += enemySpeed;
    enemy6.rect.x += enemySpeed;
    enemy7.rect.x += enemySpeed;
    enemy8.rect.x += enemySpeed;
    enemy9.rect.x += enemySpeed;
    enemy10.rect.x += enemySpeed;
    enemy11.rect.x += enemySpeed;
    enemy12.rect.x += enemySpeed;
    enemy13.rect.x += enemySpeed;
    enemy14.rect.x += enemySpeed;
    enemy15.rect.x += enemySpeed;
    enemy16.rect.x += enemySpeed;
    enemy17.rect.x += enemySpeed;
    enemy18.rect.x += enemySpeed;

    // If the enemy goes off the screen, reset its position to the left and move it down
    if (enemy1.rect.x > 560) { enemy1.rect.x = 0; enemy1.rect.y += 50.0f; };
    if (enemy2.rect.x > 560) { enemy2.rect.x = 0; enemy2.rect.y += 50.0f; };
    if (enemy3.rect.x > 560) { enemy3.rect.x = 0; enemy3.rect.y += 50.0f; };
    if (enemy4.rect.x > 560) { enemy4.rect.x = 0; enemy4.rect.y += 50.0f; };
    if (enemy5.rect.x > 560) { enemy5.rect.x = 0; enemy5.rect.y += 50.0f; };
    if (enemy6.rect.x > 560) { enemy6.rect.x = 0; enemy6.rect.y += 50.0f; };
    if (enemy7.rect.x > 560) { enemy7.rect.x = 0; enemy7.rect.y += 50.0f; };
    if (enemy8.rect.x > 560) { enemy8.rect.x = 0; enemy8.rect.y += 50.0f; };
    if (enemy9.rect.x > 560) { enemy9.rect.x = 0; enemy9.rect.y += 50.0f; };
    if (enemy10.rect.x > 560) { enemy10.rect.x = 0; enemy10.rect.y += 50.0f; };
    if (enemy11.rect.x > 560) { enemy11.rect.x = 0; enemy11.rect.y += 50.0f; };
    if (enemy12.rect.x > 560) { enemy12.rect.x = 0; enemy12.rect.y += 50.0f; };
    if (enemy13.rect.x > 560) { enemy13.rect.x = 0; enemy13.rect.y += 50.0f; };
    if (enemy14.rect.x > 560) { enemy14.rect.x = 0; enemy14.rect.y += 50.0f; };
    if (enemy15.rect.x > 560) { enemy15.rect.x = 0; enemy15.rect.y += 50.0f; };
    if (enemy16.rect.x > 560) { enemy16.rect.x = 0; enemy16.rect.y += 50.0f; };
    if (enemy17.rect.x > 560) { enemy17.rect.x = 0; enemy17.rect.y += 50.0f; };
    if (enemy18.rect.x > 560) { enemy18.rect.x = 0; enemy18.rect.y += 50.0f; };
}

void projectileMove() {
    if (projectileActive) {
        projectilePosition.y -= projectileSpeed;

        if (projectilePosition.y < 0) {
            projectileActive = 0; // Deactivate the projectile if it goes off the screen
        }

        if (barrier1.health > 0 && CheckCollisionCircleRec(projectilePosition, projectileSize, barrier1.rect)) { projectileActive = 0; barrier1.health -= 1; }
        if (barrier2.health > 0 && CheckCollisionCircleRec(projectilePosition, projectileSize, barrier2.rect)) { projectileActive = 0; barrier2.health -= 1; }
        if (barrier3.health > 0 && CheckCollisionCircleRec(projectilePosition, projectileSize, barrier3.rect)) { projectileActive = 0; barrier3.health -= 1; }

        // Check collision with enemies
        if (enemy1.alive == 1 && CheckCollisionCircleRec(projectilePosition, projectileSize, enemy1.rect)) { enemy1.alive = 0; projectileActive = 0; }
        if (enemy2.alive == 1 && CheckCollisionCircleRec(projectilePosition, projectileSize, enemy2.rect)) { enemy2.alive = 0; projectileActive = 0; }
        if (enemy3.alive == 1 && CheckCollisionCircleRec(projectilePosition, projectileSize, enemy3.rect)) { enemy3.alive = 0; projectileActive = 0; }
        if (enemy4.alive == 1 && CheckCollisionCircleRec(projectilePosition, projectileSize, enemy4.rect)) { enemy4.alive = 0; projectileActive = 0; }
        if (enemy5.alive == 1 && CheckCollisionCircleRec(projectilePosition, projectileSize, enemy5.rect)) { enemy5.alive = 0; projectileActive = 0; }
        if (enemy6.alive == 1 && CheckCollisionCircleRec(projectilePosition, projectileSize, enemy6.rect)) { enemy6.alive = 0; projectileActive = 0; }
        if (enemy7.alive == 1 && CheckCollisionCircleRec(projectilePosition, projectileSize, enemy7.rect)) { enemy7.alive = 0; projectileActive = 0; }
        if (enemy8.alive == 1 && CheckCollisionCircleRec(projectilePosition, projectileSize, enemy8.rect)) { enemy8.alive = 0; projectileActive = 0; }
        if (enemy9.alive == 1 && CheckCollisionCircleRec(projectilePosition, projectileSize, enemy9.rect)) { enemy9.alive = 0; projectileActive = 0; }
        if (enemy10.alive == 1 && CheckCollisionCircleRec(projectilePosition, projectileSize, enemy10.rect)) { enemy10.alive = 0; projectileActive = 0; }
        if (enemy11.alive == 1 && CheckCollisionCircleRec(projectilePosition, projectileSize, enemy11.rect)) { enemy11.alive = 0; projectileActive = 0; }
        if (enemy12.alive == 1 && CheckCollisionCircleRec(projectilePosition, projectileSize, enemy12.rect)) { enemy12.alive = 0; projectileActive = 0; }
        if (enemy13.alive == 1 && CheckCollisionCircleRec(projectilePosition, projectileSize, enemy13.rect)) { enemy13.alive = 0; projectileActive = 0; }
        if (enemy14.alive == 1 && CheckCollisionCircleRec(projectilePosition, projectileSize, enemy14.rect)) { enemy14.alive = 0; projectileActive = 0; }
        if (enemy15.alive == 1 && CheckCollisionCircleRec(projectilePosition, projectileSize, enemy15.rect)) { enemy15.alive = 0; projectileActive = 0; }
        if (enemy16.alive == 1 && CheckCollisionCircleRec(projectilePosition, projectileSize, enemy16.rect)) { enemy16.alive = 0; projectileActive = 0; }
        if (enemy17.alive == 1 && CheckCollisionCircleRec(projectilePosition, projectileSize, enemy17.rect)) { enemy17.alive = 0; projectileActive = 0; }
        if (enemy18.alive == 1 && CheckCollisionCircleRec(projectilePosition, projectileSize, enemy18.rect)) { enemy18.alive = 0; projectileActive = 0; }
    }
}

// Level system, called when all enemies defeated
// Resets enemy positions and increases their speed, also resets player position and barrier health
void reset() {
    ++enemySpeed;
    enemy1.alive = 1; enemy2.alive = 1; enemy3.alive = 1; enemy4.alive = 1; enemy5.alive = 1; enemy6.alive = 1;
    enemy7.alive = 1; enemy8.alive = 1; enemy9.alive = 1; enemy10.alive = 1; enemy11.alive = 1; enemy12.alive = 1;
    enemy13.alive = 1; enemy14.alive = 1; enemy15.alive = 1; enemy16.alive = 1; enemy17.alive = 1; enemy18.alive = 1;

    enemy1.rect.x = 50; enemy1.rect.y = 50;
    enemy2.rect.x = 150; enemy2.rect.y = 50;
    enemy3.rect.x = 250; enemy3.rect.y = 50;
    enemy4.rect.x = 350; enemy4.rect.y = 50;
    enemy5.rect.x = 450; enemy5.rect.y = 50;
    enemy6.rect.x = 550; enemy6.rect.y = 50;
    enemy7.rect.x = 50; enemy7.rect.y = 100;
    enemy8.rect.x = 150; enemy8.rect.y = 100;
    enemy9.rect.x = 250; enemy9.rect.y = 100;
    enemy10.rect.x = 350; enemy10.rect.y = 100;
    enemy11.rect.x = 450; enemy11.rect.y = 100;
    enemy12.rect.x = 550; enemy12.rect.y = 100;
    enemy13.rect.x = 50; enemy13.rect.y = 150;
    enemy14.rect.x = 150; enemy14.rect.y = 150;
    enemy15.rect.x = 250; enemy15.rect.y = 150;
    enemy16.rect.x = 350; enemy16.rect.y = 150;
    enemy17.rect.x = 450; enemy17.rect.y = 150;
    enemy18.rect.x = 550; enemy18.rect.y = 150;

    barrier1.health = 5; barrier2.health = 5; barrier3.health = 5;
    
    player.x = (float)screenWidth / 2;
    player.y = 750;
}

void checkIfWon() {
    if (enemy1.alive == 0 && enemy2.alive == 0 && enemy3.alive == 0 && enemy4.alive == 0 && enemy5.alive == 0 &&
            enemy6.alive == 0 && enemy7.alive == 0 && enemy8.alive == 0 && enemy9.alive == 0 &&
            enemy10.alive == 0 && enemy11.alive == 0 && enemy12.alive == 0 && enemy13.alive == 0 && enemy14.alive == 0 && enemy15.alive == 0 &&
            enemy16.alive == 0 && enemy17.alive == 0 && enemy18.alive == 0) {
            reset();
        }
}

void checkIfLost() {
    if (enemy1.rect.y + enemy1.rect.height >= 600 || enemy2.rect.y + enemy2.rect.height >= 600 || enemy3.rect.y + enemy3.rect.height >= 600 || enemy4.rect.y + enemy4.rect.height >= 600 ||
        enemy5.rect.y + enemy5.rect.height >= 600 || enemy6.rect.y + enemy6.rect.height >= 600 || enemy7.rect.y + enemy7.rect.height >= 600 ||
        enemy8.rect.y + enemy8.rect.height >= 600 || enemy9.rect.y + enemy9.rect.height >= 600 || enemy10.rect.y + enemy10.rect.height >= 600 ||
        enemy11.rect.y + enemy11.rect.height >= 600 || enemy12.rect.y + enemy12.rect.height >= 600 || enemy13.rect.y + enemy13.rect.height >= 600 ||
        enemy14.rect.y + enemy14.rect.height >= 600 || enemy15.rect.y + enemy15.rect.height >= 600 || enemy16.rect.y + enemy16.rect.height >= 600 ||
        enemy17.rect.y + enemy17.rect.height >= 600 || enemy18.rect.y + enemy18.rect.height >= 600) {
            // On gameover. reset the level without increasing the enemy speed
            reset();
            --enemySpeed;
    }
}

int main(void) {
    InitWindow(screenWidth, screenHeight, "Space");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        movePlayer();
        moveEnemies();
        shoot();
        projectileMove();
        checkIfWon();
        checkIfLost();        

        // Drawing code starts here
        BeginDrawing();
        ClearBackground(BLACK);

        // Draw enemies if they are alive
        if (enemy1.alive == 1) DrawRectangleRec(enemy1.rect, RED);
        if (enemy2.alive == 1) DrawRectangleRec(enemy2.rect, RED);
        if (enemy3.alive == 1) DrawRectangleRec(enemy3.rect, RED);
        if (enemy4.alive == 1) DrawRectangleRec(enemy4.rect, RED);
        if (enemy5.alive == 1) DrawRectangleRec(enemy5.rect, RED);
        if (enemy6.alive == 1) DrawRectangleRec(enemy6.rect, RED);
        if (enemy7.alive == 1) DrawRectangleRec(enemy7.rect, RED);
        if (enemy8.alive == 1) DrawRectangleRec(enemy8.rect, RED);
        if (enemy9.alive == 1) DrawRectangleRec(enemy9.rect, RED);
        if (enemy10.alive == 1) DrawRectangleRec(enemy10.rect, RED);
        if (enemy11.alive == 1) DrawRectangleRec(enemy11.rect, RED);
        if (enemy12.alive == 1) DrawRectangleRec(enemy12.rect, RED);
        if (enemy13.alive == 1) DrawRectangleRec(enemy13.rect, RED);
        if (enemy14.alive == 1) DrawRectangleRec(enemy14.rect, RED);
        if (enemy15.alive == 1) DrawRectangleRec(enemy15.rect, RED);
        if (enemy16.alive == 1) DrawRectangleRec(enemy16.rect, RED);
        if (enemy17.alive == 1) DrawRectangleRec(enemy17.rect, RED);
        if (enemy18.alive == 1) DrawRectangleRec(enemy18.rect, RED);

        // Green rectangle is the player
        DrawRectangleRec(player, GREEN);

        // Yellow rectangles act as barriers
        if (barrier1.health > 0) DrawRectangleRec(barrier1.rect, YELLOW);
        if (barrier2.health > 0) DrawRectangleRec(barrier2.rect, YELLOW);
        if (barrier3.health > 0) DrawRectangleRec(barrier3.rect, YELLOW);

        if (projectileActive) {
            DrawCircleV(projectilePosition, projectileSize, WHITE);
        }

        DrawText(TextFormat("Level: %i", enemySpeed), 200, 10, 20, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}