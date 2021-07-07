//#include<iostream>
//#include<SDL.h>
//#include<SDL_image.h>
//
//#undef main
//
//SDL_Window* window;
//SDL_Renderer* renderer;
//
//SDL_Texture* capguy_walking_texture;
//SDL_Rect sourceRect;//the part the we want to show on the destination rect
//SDL_Rect destinationRect;//only for rendering so is the same as the screen width and height
//
////The dimensions of the level
//const int LEVEL_WIDTH = 1280;
//const int LEVEL_HEIGHT = 960;
//
////Screen dimension constants
//const int SCREEN_WIDTH = 640;
//const int SCREEN_HEIGHT = 480;
//
//bool isRunning = true;
//
////THE DOT
//class Dot {
//public:
//    static const int DOT_WIDTH = 20;
//    static const int DOT_HEIGHT = 20;
//
//    static const int DOT_VEL = 1;
//
//    Dot();
//
//    void handleEvent(SDL_Event& e);
//
//    void move();
//
//    void render(int camX, int camY);
//
//    int getPosX();
//    int getPosY();
//
//private:
//    int mPosX, mPosY;
//    int mVelX, mVelY;
//};
//
//Dot::Dot() {
//    this->mPosX = 0;
//    this->mPosY = 0;
//    this->mVelX = 0;
//    this->mVelY = 0;
//}
//
//void Dot::handleEvent(SDL_Event& e)
//{
//    while (SDL_PollEvent(&e)) {
//        if (e.type == SDL_QUIT || e.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
//            isRunning = false;
//        }
//        //If a key was pressed
//        if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
//        {
//            //Adjust the velocity
//
//            switch (e.key.keysym.sym)
//
//            {
//            case SDLK_UP: mVelY -= DOT_VEL; break;
//            case SDLK_DOWN: mVelY += DOT_VEL; break;
//            case SDLK_LEFT: mVelX -= DOT_VEL; break;
//            case SDLK_RIGHT: mVelX += DOT_VEL; break;
//            }
//        }
//
//        //If a key was released
//        else if (e.type == SDL_KEYUP && e.key.repeat == 0)
//        {
//            //Adjust the velocity
//            switch (e.key.keysym.sym)
//            {
//            case SDLK_UP: mVelY += DOT_VEL; break;
//            case SDLK_DOWN: mVelY -= DOT_VEL; break;
//            case SDLK_LEFT: mVelX += DOT_VEL; break;
//            case SDLK_RIGHT: mVelX -= DOT_VEL; break;
//            }
//        }
//    }
//}
//
//void Dot::move()
//{
//
//    //Move the dot left or right
//    mPosX += mVelX;
//    //If the dot went too far to the left or right
//    if ((mPosX < 0) || (mPosX + DOT_WIDTH > LEVEL_WIDTH))
//    {
//        //Move back
//        mPosX -= mVelX;
//    }
//
//    //Move the dot up or down
//    mPosY += mVelY;
//
//    //If the dot went too far up or down
//    if ((mPosY < 0) || (mPosY + DOT_HEIGHT > LEVEL_HEIGHT))
//    {
//        //Move back
//        mPosY -= mVelY;
//    }
//}
//
//int Dot::getPosX()
//{
//    return mPosX;
//}
//
//int Dot::getPosY()
//{
//    return mPosY;
//}
//
//void Dot::render(int camX, int camY) {
//    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
//    SDL_Rect dotFigure;
//    dotFigure.w = this->DOT_WIDTH;
//    dotFigure.h = this->DOT_HEIGHT;
//    dotFigure.x = this->mPosX - camX;
//    dotFigure.y = this->mPosY - camY;
//    SDL_RenderFillRect(renderer, &dotFigure);
//}
//
//
//
//
//
//
//void textureManager() {
//
//    SDL_Surface* tempSurface = IMG_Load("../assets/bg.png");
//    capguy_walking_texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
//    SDL_FreeSurface(tempSurface);
//
//    SDL_QueryTexture(capguy_walking_texture, NULL, NULL,
//        &sourceRect.w, &sourceRect.h);
//
//    sourceRect.w = SCREEN_WIDTH;
//    sourceRect.h = SCREEN_HEIGHT;
//
//    destinationRect.x = sourceRect.x = 0;
//    destinationRect.y = sourceRect.y = 0;
//    destinationRect.w = SCREEN_WIDTH;
//    destinationRect.h = SCREEN_HEIGHT;
//}
//
//
//void render(SDL_Renderer* renderer, Dot dot) {
//    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
//    SDL_RenderClear(renderer);
//
//    //draw stuff here
//    SDL_RenderCopy(renderer, capguy_walking_texture, &sourceRect,
//        &destinationRect);
//    dot.render(sourceRect.x, sourceRect.y);
//
//    SDL_RenderPresent(renderer);
//}
//
//
//int main() {
//    SDL_Init(SDL_INIT_EVERYTHING);
//    window = SDL_CreateWindow("animation", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
//    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//
//    textureManager();
//    SDL_Event event;
//    Dot dot;
//
//    while (isRunning) {
//        dot.handleEvent(event);
//        dot.move();
//        sourceRect.x = (dot.getPosX() + Dot::DOT_WIDTH / 2) - SCREEN_WIDTH / 2;
//        sourceRect.y = (dot.getPosY() + Dot::DOT_HEIGHT / 2) - SCREEN_HEIGHT / 2;
//        if (sourceRect.x < 0) {
//            sourceRect.x = 0;
//        }
//        if (sourceRect.y < 0) {
//            sourceRect.y = 0;
//        }
//        if (sourceRect.x > LEVEL_WIDTH - sourceRect.w)
//        {
//            sourceRect.x = LEVEL_WIDTH - sourceRect.w;
//        }
//        if (sourceRect.y > LEVEL_HEIGHT - sourceRect.h)
//        {
//            sourceRect.y = LEVEL_HEIGHT - sourceRect.h;
//        }
//        render(renderer, dot);
//    }
//
//    SDL_Quit();
//
//    return 0;
//}