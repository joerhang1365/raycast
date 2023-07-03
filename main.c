#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "constants.h"
#include "wall.h"
#include "raycast.h"
#include "object.h"

#define FRAMERATE 60

int main()
{
   // window initialization
   SDL_Window *window = NULL;
   if(SDL_Init(SDL_INIT_VIDEO) > 0)
   {
      printf("video initialization error\n");
      return 1;
   }
   else
   {
      window = SDL_CreateWindow
         (
            "raycast rendering",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN
         );
      if(window == NULL)
      {
         printf("window creation error\n");
         return 1;
      }
   }

   // renderer initialization
   SDL_Renderer *renderer = NULL;
   renderer = SDL_CreateRenderer
      (
         window,
         -1,
         SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
       );
   if(renderer == NULL)
   {
      printf("renderer creation error\n");
      return 1;
   }

   // key event initialization
   SDL_Event event;
   vector2 mouse;

   // walls
   wall walls[4];
   wall_create(&walls[0], 100, 100, 200, 300);
   wall_create(&walls[1], 0, 640, 45, 30);
   wall_create(&walls[2], 435, 345, 132, 124);
   wall_create(&walls[3], 76, 234, 432, 65);

   // player
   object player;
   object_create(&player, 340, 340);

   // loop
   bool run = true;
   float frame_time = 0;
   float delta_time = 0;
   int previous_time = 0;
   int current_time = 0;
   while(run)
   {
      // key events
      while(SDL_PollEvent(&event) != 0)
      {
         if(event.type == SDL_QUIT)
         {
            run = false;
         }
         else if(event.type == SDL_MOUSEMOTION)
         {
            int x;
            int y;
            SDL_GetMouseState(&x, &y);
            mouse.x = x;
            mouse.y = y;
         }
         else
         {

         }
      }

      // update
      previous_time = current_time;
      current_time = SDL_GetTicks();
      delta_time = (current_time - previous_time) / 1000.0f;
      frame_time += delta_time;
      if(frame_time >= (float) 1 / FRAMERATE)
      {
         frame_time = 0;

         object_update(&player, mouse.x, mouse.y);
         object_raycast(&player, walls, 4);
      }

      // render
      // clear screen
      SDL_SetRenderDrawColor(renderer, 1.0f, 1.0f, 1.0f, 1.0f);
      SDL_RenderClear(renderer);

      for(int i = 0; i < 4; i++)
      {
         wall_render(walls[i], renderer);
      }
      object_render(player, renderer);

      // draw to screen
      SDL_RenderPresent(renderer);
   }

   // destroy components
   SDL_DestroyWindow(window);
   SDL_DestroyRenderer(renderer);
   window = NULL;
   renderer = NULL;
   SDL_Quit();

   return 0;
}
