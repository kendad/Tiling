//#include<SDL.h>
//#include<SDL_image.h>
//#include<iostream>
//#include<fstream>
//#include<string>
//
//#undef main
//
//const int LEVEL_WIDTH = 1000;//we will have total of 20 tiles  this side
//const int LEVEL_HEIGHT = 1000;//we will have 10 tiles this side
//
//const int SCREEN_WIDTH = 400;
//const int SCREEN_HEIGHT = 400;
//
//const int TILE_BLUE = 0;
//const int TILE_BROWN = 1;
//const int TILE_GREEN = 2;
//const int TILE_GOLDEN = 3;
//
//const int TOTAL_TILES = 200;
//
//SDL_Window* gWindow;
//SDL_Renderer* gRenderer;
//
//
//bool detectCollision(SDL_Rect a, SDL_Rect b);
////void setTheLevel(Tile* tile[]);
//
//
//class Tile {
//public:
//	Tile(int type, int x = 0, int y = 0, int width = 50, int height = 100);
//	void render(SDL_Rect& camera, int r, int g, int b, int a);
//	int mType;
//	SDL_Rect collisionBox;
//private:
//	int mPosX, mPosY;
//	int mWidth, mHeight;
//};
//
//bool dotTouchesObject(SDL_Rect box, Tile* tiles[]) {
//	for (int i = 0; i < TOTAL_TILES; i++) {
//		if ((tiles[i]->mType == TILE_GREEN) || (tiles[i]->mType == TILE_BROWN) || (tiles[i]->mType == TILE_GOLDEN)) {
//			if (detectCollision(box, tiles[i]->collisionBox)) {
//				return true;
//			}
//		}
//	}
//	return false;
//}
//
//
//Tile::Tile(int type, int x, int y, int width, int height) {
//	this->mPosX = x;
//	this->mPosY = y;
//	this->mWidth = width;
//	this->mHeight = height;
//	this->mType = type;
//	this->collisionBox = { this->mPosX,this->mPosY,this->mWidth,this->mHeight };
//}
//void Tile::render(SDL_Rect& camera, int r, int g, int b, int a) {
//	if (detectCollision(camera, this->collisionBox)) {
//		//if the camera has hit the tiles then we display them
//		SDL_SetRenderDrawColor(gRenderer, r, g, b, a);
//		SDL_RenderFillRect(gRenderer, &this->collisionBox);
//	}
//}
//
//class Dot {
//public:
//	Dot(int x = 0, int y = 0, int width = 50, int height = 100);
//	SDL_Rect dotBox = { mPosY,mPosY,mWidth,mHeight };
//
//	void render();
//	void move(Tile* tiles[]);
//	void setCameraPositionOnChar(SDL_Rect& camera);
//	void handelUserInput(SDL_Event& e);
//	SDL_Rect collisionBox;
//private:
//	int mPosX;
//	int mPosY;
//	int mWidth, mHeight;
//	int mVelX, mVelY;
//	int dotVelocity;
//
//};
//
//Dot::Dot(int x, int y, int width, int height) {
//	this->mPosX = x;
//	this->mPosY = y;
//	this->mWidth = width;
//	this->mHeight = height;
//	this->mVelX = 0;
//	this->mVelY = 0;
//	this->dotVelocity = 1;
//	this->collisionBox = { this->mPosX,this->mPosY,this->mWidth,this->mHeight };
//}
//
//void Dot::render() {
//	SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
//	SDL_RenderFillRect(gRenderer, &this->collisionBox);
//}
//
//void Dot::move(Tile* tiles[]) {
//	this->collisionBox.x += this->mVelX;
//	if ((this->collisionBox.x < 0) || (this->collisionBox.x + this->mWidth > LEVEL_WIDTH) || (dotTouchesObject(this->collisionBox, tiles))) {
//		std::cout << "Collision detected" << this->collisionBox.x << "\n";
//		this->collisionBox.x -= this->mVelX;
//	}
//
//	this->collisionBox.y += this->mVelY;
//	if ((this->collisionBox.y < 0) || (this->collisionBox.y + this->mHeight > LEVEL_HEIGHT) || (dotTouchesObject(this->collisionBox, tiles))) {
//		std::cout << "Collision detected" << this->collisionBox.y << "\n";
//		this->collisionBox.y -= this->mVelY;
//	}
//}
//
//void Dot::setCameraPositionOnChar(SDL_Rect& camera) {
//	//Center the camera over the dot
//	camera.x = (this->collisionBox.x + this->mWidth / 2) - SCREEN_WIDTH / 2;
//	camera.y = (this->collisionBox.y + this->mHeight / 2) - SCREEN_HEIGHT / 2;
//
//	//Keep the camera in bounds
//	if (camera.x < 0)
//	{
//		camera.x = 0;
//	}
//	if (camera.y < 0)
//	{
//		camera.y = 0;
//	}
//	if (camera.x > LEVEL_WIDTH - camera.w)
//	{
//		camera.x = LEVEL_WIDTH - camera.w;
//	}
//	if (camera.y > LEVEL_HEIGHT - camera.h)
//	{
//		camera.y = LEVEL_HEIGHT - camera.h;
//	}
//}
//
//void Dot::handelUserInput(SDL_Event& e) {
//	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
//	{
//
//		switch (e.key.keysym.sym)
//		{
//		case SDLK_UP: this->mVelY -= this->dotVelocity; break;
//		case SDLK_DOWN: this->mVelY += this->dotVelocity; break;
//		case SDLK_LEFT: this->mVelX -= this->dotVelocity; break;
//		case SDLK_RIGHT: this->mVelX += this->dotVelocity; break;
//		}
//	}
//
//	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
//	{
//
//		switch (e.key.keysym.sym)
//		{
//		case SDLK_UP: this->mVelY += this->dotVelocity; break;
//		case SDLK_DOWN: this->mVelY -= this->dotVelocity; break;
//		case SDLK_LEFT: this->mVelX += this->dotVelocity; break;
//		case SDLK_RIGHT: this->mVelX -= this->dotVelocity; break;
//		}
//	}
//}
//
//bool detectCollision(SDL_Rect a, SDL_Rect b) {
//	//the sides of the rectangle
//	int leftA, leftB;
//	int rightA, rightB;
//	int topA, topB;
//	int bottomA, bottomB;
//
//	//calculate the sides of rectA
//	leftA = a.x;
//	rightA = a.x + a.w;
//	topA = a.y;
//	bottomA = a.y + a.h;
//
//	//calculate the sides of rectB
//	leftB = b.x;
//	rightB = b.x + b.w;
//	topB = b.y;
//	bottomB = b.y + b.h;
//
//	//if any of the sides of A are outside of B then no collison
//	//we are thinking in terms of a
//	if (bottomA <= topB) { return false; }
//	if (topA >= bottomB) { return false; }
//	if (rightA <= leftB) { return false; }
//	if (leftA >= rightB) { return false; }
//
//	//else
//	return true;
//}
//
//void setTiles(Tile* tiles[]) {
//	int newX = 0;//this  are the offset
//	int newY = 0;
//	//open the map
//	std::ifstream map("../assets/tileMaps/simple.map");
//
//	for (int i = 0; i < TOTAL_TILES; i++) {
//		int tileType = -1;
//		map >> tileType;
//		if ((tileType >= 0) && (tileType < TOTAL_TILES)) {
//			tiles[i] = new Tile(tileType, newX, newY);
//		}
//		else {
//			break;
//		}
//
//		newX += 50;
//		if (newX >= LEVEL_WIDTH) {
//			newX = 0;
//			newY += 100;
//		}
//	}
//
//	map.close();
//}
//
//
//int main() {
//	SDL_Init(SDL_INIT_EVERYTHING);
//	//gWindow = SDL_CreateWindow("Collision Detection",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,0);
//	gWindow = SDL_CreateWindow("Collision Detection", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, LEVEL_WIDTH, LEVEL_HEIGHT, 0);
//	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
//
//	Dot dot;
//	SDL_Event e;
//
//	Tile* tileSet[TOTAL_TILES];
//	setTiles(tileSet);
//
//	//SDL_Rect camera = {0,0,SCREEN_WIDTH,SCREEN_HEIGHT};
//	SDL_Rect camera = { 0,0,LEVEL_WIDTH,LEVEL_HEIGHT };
//
//	bool isRunning = true;
//
//	while (isRunning) {
//		while (SDL_PollEvent(&e)) {
//			if (e.type == SDL_QUIT) {
//				isRunning = false;
//			}
//			dot.handelUserInput(e);
//		}
//
//		dot.move(tileSet);
//		dot.setCameraPositionOnChar(camera);
//
//		SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
//		SDL_RenderClear(gRenderer);
//
//		//Render the level
//		for (int i = 0; i < TOTAL_TILES; i++) {
//			int r = 0;
//			int g = 0;
//			int b = 0;
//			int type = tileSet[i]->mType;
//			if (type == TILE_BLUE) {
//				r = 0; g = 0; b = 255;
//			}
//			if (type == TILE_BROWN) {
//				r = 150; g = 75; b = 0;
//			}
//			if (type == TILE_GREEN) {
//				r = 0; g = 255; b = 0;
//			}
//			if (type == TILE_GOLDEN) {
//				r = 255; g = 215; b = 0;
//			}
//			int a = 255;
//			tileSet[i]->render(camera, r, g, b, a);
//		}
//
//		dot.render();
//
//
//
//		SDL_RenderPresent(gRenderer);
//
//	}
//
//	return 0;
//}