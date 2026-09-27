#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <cstring>

int main()
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    TTF_Font* font = TTF_OpenFont("../fonts/SFNSMono.ttf", 32); //  (..) Refers to going up the directory heirarchy.
    const char* text = "THE CURSED KNIGHT";
    SDL_Color white = {255, 255, 255, 255};

    SDL_Window* window = SDL_CreateWindow(
        "Cursed Knight",
        800,
        300,
        0
    );

    SDL_Renderer* renderer = SDL_CreateRenderer(window,nullptr);
    SDL_Surface* title = TTF_RenderText_Solid(font, text, strlen(text), white);
    SDL_Texture* titleTexture = SDL_CreateTextureFromSurface(renderer, title);
    if (titleTexture == nullptr){
    SDL_Log("Texture creation failed: %s", SDL_GetError());
    }
    if (title == nullptr){
    SDL_Log("Text rendering failed: %s", SDL_GetError());
    }

    bool running = true;

    while (running)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
            {
                running = false;
            }
        }
             SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
             SDL_RenderClear(renderer);
             SDL_FRect titleRect = {250, 50, 300, 40};
             SDL_RenderTexture(renderer, titleTexture, nullptr, &titleRect);
             SDL_FRect rectangle_1= {300,200,200,100};
             SDL_SetRenderDrawColor(renderer,255, 0, 0, 255);
             SDL_RenderFillRect(renderer, &rectangle_1);
             SDL_FRect rectangle_2= {600,150,50,75};
             SDL_SetRenderDrawColor(renderer,0,255,255,255);
             SDL_RenderFillRect(renderer, &rectangle_2);
             SDL_RenderPresent(renderer);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
