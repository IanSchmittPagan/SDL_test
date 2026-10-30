
/* TO-DO: 
----------------------------------------------------------------------------------------------------
1) genera las imagenes afuera del while loop. (Para conservar memoria)
2) Aprende como usar SDL_GetWindowSize(window, &width, &height);

 */

// =================================================================================================
// library imports:

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <cstring>
#include <iostream>

// =================================================================================================
// Comienzo del archivo:
// =================================================================================================

int main()
{
    SDL_Init(SDL_INIT_VIDEO); //Initializes SDL
    TTF_Init(); //Initializes TTF for fonts

// font de titulo:
    TTF_Font* font = TTF_OpenFont("../fonts/SFNSMono.ttf", 35); //  (..) Se refiere a subiendo al directorio anterior.
// font de linea:
    TTF_Font* font_l = TTF_OpenFont("../fonts/SFNSMono.ttf", 30);
    SDL_Color white = {255, 255, 255, 255};

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Lineas del juego: 

    SDL_Window* window = SDL_CreateWindow(
        "Cursed Knight.exe",
        800,
        500,
        SDL_WINDOW_RESIZABLE
    ); // Ventana 

    SDL_FRect titleRect = {250, 50, 300, 40};
    SDL_FRect introRect = {100, 200, 600, 50};
    SDL_Renderer* renderer = SDL_CreateRenderer(window,nullptr);

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 // Para el titulo:
    
    const char* text = "THE CURSED KNIGHT"; // pantalla de titulo:
    SDL_Surface* title = TTF_RenderText_Solid(font, text, strlen(text), white);
    SDL_Texture* titleTexture = SDL_CreateTextureFromSurface(renderer, title);

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Lineas:

    const char* line_1 = "You are a knight cursed with a plague unlike any other.";
    const char* line_2 = "You must make your way to the tarn within the ancient mountain.";
    const char* line_3 = "Its water is supposedly blessed and contains miraculous healing properties.";
    const char* line_4 = "Beware, however...";
    const char* line_5 = "There is ruin and danger all around you.";
    const char* line_6 = "You awaken from your slumber on your small cot.";
    const char* line_7 = "You can feel your condition getting worse.";
    const char* line_8 = "The gashes in your skin are becoming more painful.";
    const char* line_9 = "No matter, you must continue regardless.";
    const char* line_10 = "What will you do?";
    
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Generando las imagenes: 

    SDL_Surface* text_line_1 = TTF_RenderText_Solid_Wrapped(font_l, line_1, strlen(line_1), white, 600);
    SDL_Texture* LineTexture_1 = SDL_CreateTextureFromSurface(renderer, text_line_1);

    SDL_Surface* text_line_2 = TTF_RenderText_Solid_Wrapped(font_l, line_2, strlen(line_2), white, 600);
    SDL_Texture* LineTexture_2 = SDL_CreateTextureFromSurface(renderer, text_line_2);

    SDL_Surface* text_line_3 = TTF_RenderText_Solid_Wrapped(font_l, line_3, strlen(line_3), white, 600);
    SDL_Texture* LineTexture_3 = SDL_CreateTextureFromSurface(renderer, text_line_3);

    SDL_Surface* text_line_4 = TTF_RenderText_Solid_Wrapped(font_l, line_4, strlen(line_4), white, 600);
    SDL_Texture* LineTexture_4 = SDL_CreateTextureFromSurface(renderer, text_line_4);

    SDL_Surface* text_line_5 = TTF_RenderText_Solid_Wrapped(font_l, line_5, strlen(line_5), white, 600);
    SDL_Texture* LineTexture_5 = SDL_CreateTextureFromSurface(renderer, text_line_5);

    SDL_Surface* text_line_6 = TTF_RenderText_Solid_Wrapped(font_l, line_6, strlen(line_6), white, 600);
    SDL_Texture* LineTexture_6 = SDL_CreateTextureFromSurface(renderer, text_line_6);

    SDL_Surface* text_line_7 = TTF_RenderText_Solid_Wrapped(font_l, line_7, strlen(line_7), white, 600);
    SDL_Texture* LineTexture_7 = SDL_CreateTextureFromSurface(renderer, text_line_7);

    SDL_Surface* text_line_8 = TTF_RenderText_Solid_Wrapped(font_l, line_8, strlen(line_8), white, 600);
    SDL_Texture* LineTexture_8 = SDL_CreateTextureFromSurface(renderer, text_line_8);

    SDL_Surface* text_line_9 = TTF_RenderText_Solid_Wrapped(font_l, line_9, strlen(line_9), white, 600);
    SDL_Texture* LineTexture_9 = SDL_CreateTextureFromSurface(renderer, text_line_9);

    SDL_Surface* text_line_10 = TTF_RenderText_Solid_Wrapped(font_l, line_10, strlen(line_10), white, 600);
    SDL_Texture* LineTexture_10 = SDL_CreateTextureFromSurface(renderer, text_line_10);

// -------------------------------------------------------------------------------------------------
// Verificando errores:

    if (titleTexture == nullptr){
    SDL_Log("Texture creation failed: %s", SDL_GetError());
    }
    if (title == nullptr){
    SDL_Log("Text rendering failed: %s", SDL_GetError());
    }



// =================================================================================================
// Pantalla SDL: COMIENZO DEL JUEGO
// =================================================================================================

    Uint64 startTime = SDL_GetTicks();

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

// -------------------------------------------------------------------------------------------------

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        int width;
        int height;

        SDL_GetWindowSize(window, &width, &height);

        Uint64 t = SDL_GetTicks() - startTime; 

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // INTRODUCCIÓN:
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

SDL_Texture* currentTexture = nullptr;
SDL_FRect destRect; 


      if (t < 3000)
{
    currentTexture = titleTexture;
    destRect = titleRect;
    
}
else if (t < 6000)
{   
    currentTexture = LineTexture_1;
    destRect = introRect;
}
else if (t < 9000)
{
    currentTexture = LineTexture_2;
    destRect = introRect;
}
else if (t < 12000)
{
    currentTexture = LineTexture_3;
    destRect = introRect;
}
else if (t < 15000)
{
    currentTexture = LineTexture_4;
    destRect = introRect;
}
else if (t < 18000)
{
    currentTexture = LineTexture_5; 
    destRect = introRect;
}
else if (t < 21000)
{
    currentTexture = LineTexture_6;
    destRect = introRect;
}
else if (t < 24000)
{
    currentTexture = LineTexture_7;
    destRect = introRect;
}
else if (t < 27000)
{
    currentTexture = LineTexture_8;
    destRect = introRect;
}
else if (t < 30000)
{
    currentTexture = LineTexture_9;
    destRect = introRect;
}
else if (t < 33000)
{
    currentTexture = LineTexture_10;
    destRect = introRect;
}

if (currentTexture != nullptr)
{
    float textureWidth;
    float textureHeight;

    SDL_GetTextureSize(currentTexture, &textureWidth, &textureHeight);

    destRect = {
        (width - textureWidth) / 2.0f,
        (height - textureHeight) / 2.0f,
        textureWidth,
        textureHeight
    };

    SDL_RenderTexture(renderer, currentTexture, nullptr, &destRect);
}
    // Presentar el resultado:
    SDL_RenderPresent(renderer);

// Para resolver el problema de la pantalla expandida:

    SDL_Delay(16);




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // PRIMER ACTO:
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    }
    

    SDL_DestroyRenderer(renderer); 
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
