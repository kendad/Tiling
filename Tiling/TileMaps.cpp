//#include<SDL.h>
//#include<SDL_image.h>
//#include<stdio.h>
//#include<string>
//#include<fstream>
//
//#undef main
//
////SCREEN DIMENSIONS
//const int SCREEN_WIDTH = 640;
//const int SCREEN_HEIGHT = 480;
//
////LEVEL DIMENSIONS
//const int LEVEL_WIDTH = 1280;
//const int LEVEL_HEIGHT = 960;
//
////Tile Constants
//const int TILE_WIDTH = 80;
//const int TILE_HEIGHT = 80;
//const int TOTAL_TILES = 192;//total number of tiles to render on the map//(1280/80)+(960/80)
//const int TOTAL_TILE_SPRITES = 12;//total number of sprites in the sprite image
//
////The different tile sprites
//const int TILE_RED = 0;
//const int TILE_GREEN = 1;
//const int TILE_BLUE = 2;
////
//const int TILE_CENTER = 3;
////
//const int TILE_TOP = 4;
////
//const int TILE_TOPRIGHT = 5;
//const int TILE_RIGHT = 6;
//const int TILE_BOTTOMRIGHT = 7;
////
//const int TILE_BOTTOM = 8;
////
//const int TILE_BOTTOMLEFT = 9;
//const int TILE_LEFT = 10;
//const int TILE_TOPLEFT = 11;
//
////Texture Wrapper Class
//class LTexture {
//public:
//	//Intit the variables
//	LTexture();
//	//Deallocates Memory
//	~LTexture();
//
//	//loads the image
//	bool loadFromFile(std::string path);
//
//	//Deallocates texture
//	void free();
//
//	//Render Texture at given points
//	void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
//
//	//Getters
//	//gets the image dimensions
//	int getWidth();
//	int getHeight();
//
//private:
//	SDL_Texture* mTexture;
//	//Image dimensions
//	int mWidth;
//	int mHeight;
//};
//
////TILE CLASS
//class Tile {
//public:
//	Tile(int x, int y, int titleType);
//
//	//shows the tile type
//	void render(SDL_Rect& camera);
//
//	//Get the tileType
//	int getType();
//
//	//get the collision box
//	SDL_Rect getBox();
//
//private:
//	//collison box for the tile
//	SDL_Rect mBox;
//	//the tile type
//	int mType;
//};
//
////DOT CLASS
//class Dot {
//public:
//	//Dimension of the dot
//	static const int DOT_WIDTH = 20;
//	static const int DOT_HEIGHT = 20;
//
//	//Max Velocity of the dot
//	static const int DOT_VEL = 1;
//
//	Dot();
//
//	//handel users input
//	void handleEvent(SDL_Event& e);
//
//	//moves the dot and check for collision against the tiles
//	void move(Tile* tiles[]);
//
//	//Centers the camera over the dot
//	void setCamera(SDL_Rect& camera);
//
//	//Shows the dot on the screen
//	void render(SDL_Rect& camera);
//
//private:
//	//collison box for the dot
//	SDL_Rect mBox;
//	//the velocity of the dot
//	int mVelX, mVelY;
//};
//
//
///////////////////////////////////////////
//// 
////starts up sdl
//bool init();
//
////Loads Media
//bool loadMedia(Tile* tiles[]);
//
////Frees media and shut down SDL
//void close(Tile* tiles[]);
//
////Box Collision Detection
//bool checkCollision(SDL_Rect a, SDL_Rect b);
//
////Checks if an sdlRect has collided against a set of Tiles
//bool touchesWall(SDL_Rect box, Tile* tiles[]);
//
////Sets the tile from the tile map
//bool setTiles(Tile* tiles[]);
//
/////////////////////////////////////////////////
//
//SDL_Window* gWindow = NULL;
//SDL_Renderer* gRenderer = NULL;
//
//LTexture gDotTexture;
//LTexture gTileTexture;
//SDL_Rect gTileClips[TOTAL_TILE_SPRITES];//array of the tile sprites
//
//////////////////////////////////////////////////
//
////DEFINING THE LTEXTURE CLASS
//void LTexture::free() {
//	//if texture exits then free it 
//	if (!mTexture != NULL) {
//		SDL_DestroyTexture(mTexture);
//		mTexture = NULL;
//		mWidth = 0;
//		mHeight = 0;
//	}
//}
//
//LTexture::LTexture() {
//	mTexture = NULL;
//	mWidth = NULL;
//	mHeight = NULL;
//}
//
//LTexture::~LTexture() {
//	free();
//}
//
//bool LTexture::loadFromFile(std::string path) {
//	//get rid of any  prexisting texture
//	free();
//
//	//the final Texture
//	SDL_Texture* newTexture = NULL;
//
//	//Load the image
//	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
//	//create a new texture from surface
//	newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
//	//loads the textures dimensions
//	mWidth = loadedSurface->w;
//	mHeight = loadedSurface->h;
//	//get rid of the surface
//	SDL_FreeSurface(loadedSurface);
//
//	mTexture = newTexture;
//	return mTexture != NULL;
//}
//
//void LTexture::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip) {
//	//this is the destination rect
//	SDL_Rect renderQuad = { x,y,mWidth,mHeight };
//
//	//clip is the source rect
//	if (clip != NULL) {
//		renderQuad.w = clip->w;
//		renderQuad.h = clip->h;
//	}
//
//	//render to the screen
//	SDL_RenderCopyEx(gRenderer, mTexture, clip, &renderQuad, angle, center, flip);
//}
//
//int LTexture::getWidth() {
//	return mWidth;
//}
//
//int LTexture::getHeight() {
//	return mHeight;
//}
//
//
////DEFINING THE TILE CLASS
//Tile::Tile(int x, int y, int titleType) {
//	//get the offsets
//	mBox.x = x;
//	mBox.y = y;
//
//	//set the collision box
//	mBox.w = TILE_WIDTH;
//	mBox.h = TILE_HEIGHT;
//
//	//get the tile type
//	mType = titleType;
//}
//
//void Tile::render(SDL_Rect& camera) {
//	//check if the tile is on screen
//	if (checkCollision(camera, mBox)) {
//		gTileTexture.render(mBox.x - camera.x, mBox.y - camera.y, &gTileClips[mType]);
//	}
//}
//
//int Tile::getType() {
//	return mType;
//}
//
//SDL_Rect Tile::getBox() {
//	return mBox;
//}
//
////////////////////////////////////////////////
//
//Dot::Dot() {
//	//init the collison box
//	mBox.x = 0;
//	mBox.y = 0;
//	mBox.w = DOT_WIDTH;
//	mBox.h = DOT_HEIGHT;
//	//Init the velocity
//	mVelX = 0;
//	mVelY = 0;
//}
//
//void Dot::handleEvent(SDL_Event& e)
//{
//	//If a key was pressed
//	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
//	{
//		//Adjust the velocity
//		switch (e.key.keysym.sym)
//		{
//		case SDLK_UP: mVelY -= DOT_VEL; break;
//		case SDLK_DOWN: mVelY += DOT_VEL; break;
//		case SDLK_LEFT: mVelX -= DOT_VEL; break;
//		case SDLK_RIGHT: mVelX += DOT_VEL; break;
//		}
//	}
//	//If a key was released
//	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
//	{
//		//Adjust the velocity
//		switch (e.key.keysym.sym)
//		{
//		case SDLK_UP: mVelY += DOT_VEL; break;
//		case SDLK_DOWN: mVelY -= DOT_VEL; break;
//		case SDLK_LEFT: mVelX += DOT_VEL; break;
//		case SDLK_RIGHT: mVelX -= DOT_VEL; break;
//		}
//	}
//}
//
//void Dot::move(Tile* tiles[]) {
//	mBox.x += mVelX;
//	//if the dot went too far to left/right or touched a wall
//	if ((mBox.x < 0) || (mBox.x + DOT_WIDTH > LEVEL_WIDTH) || (touchesWall(mBox, tiles))) {
//		mBox.x -= mVelX;
//	}
//
//	mBox.y += mVelY;
//	if ((mBox.y < 0) || (mBox.y + DOT_HEIGHT > LEVEL_HEIGHT) || touchesWall(mBox, tiles))
//	{
//		mBox.y -= mVelY;
//	}
//}
//
//void Dot::setCamera(SDL_Rect& camera)
//{
//	//Center the camera over the dot
//	camera.x = (mBox.x + DOT_WIDTH / 2) - SCREEN_WIDTH / 2;
//	camera.y = (mBox.y + DOT_HEIGHT / 2) - SCREEN_HEIGHT / 2;
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
//void Dot::render(SDL_Rect& camera) {
//	gDotTexture.render(mBox.x - camera.x, mBox.y - camera.y);
//}
//
////////////////////////////////////////////
////DEFINING THE BASIC FUNCTIONS
//
//bool init() {
//	SDL_Init(SDL_INIT_EVERYTHING);
//	gWindow = SDL_CreateWindow("TileMaps",
//		SDL_WINDOWPOS_UNDEFINED,
//		SDL_WINDOWPOS_UNDEFINED,
//		SCREEN_WIDTH,
//		SCREEN_HEIGHT,
//		0);
//	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
//	SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
//	return true;
//}
//
//bool loadMedia(Tile* tiles[]) {
//	//load the textures
//	gDotTexture.loadFromFile("../assets/tileMaps/dot.bmp");
//	gTileTexture.loadFromFile("../assets/tileMaps/tiles.png");
//
//	//set the tile maps
//	setTiles(tiles);
//	return true;
//}
//
//void close(Tile* tiles[]) {
//	//deallocate tiles
//	for (int i = 0; i < TOTAL_TILES; i++) {
//		if (tiles[i] != NULL) {
//			delete tiles[i];
//			tiles[i] = NULL;
//		}
//	}
//
//	//Destroy window	
//	SDL_DestroyRenderer(gRenderer);
//	SDL_DestroyWindow(gWindow);
//	gWindow = NULL;
//	gRenderer = NULL;
//
//	//Quit SDL subsystems
//	IMG_Quit();
//	SDL_Quit();
//
//}
//
//bool checkCollision(SDL_Rect a, SDL_Rect b) {
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
//bool setTiles(Tile* tiles[]) {
//	bool tilesLoaded = true;
//	//the  tile offset
//	int x = 0; int y = 0;
//	//open the map
//	std::ifstream map("../assets/tileMaps/lazy.map");
//
//	for (int i = 0; i < TOTAL_TILES; ++i) {
//		int tileType = -1;
//		//read the tile from the map file
//		map >> tileType;
//		//if the number is a valid tileNumber
//		if ((tileType >= 0) && (tileType < TOTAL_TILE_SPRITES)) {
//			tiles[i] = new Tile(x, y, tileType);
//		}
//		else {
//			tilesLoaded = false;
//			break;
//		}
//
//		//place the boxes in a serial manner
//		x += TILE_WIDTH;
//		if (x >= LEVEL_HEIGHT) {
//			x = 0;
//			y += TILE_HEIGHT;
//		}
//	}
//
//	if (tilesLoaded) {
//		gTileClips[TILE_RED].x = 0;
//		gTileClips[TILE_RED].y = 0;
//		gTileClips[TILE_RED].w = TILE_WIDTH;
//		gTileClips[TILE_RED].h = TILE_HEIGHT;
//
//		gTileClips[TILE_GREEN].x = 0;
//		gTileClips[TILE_GREEN].y = 80;
//		gTileClips[TILE_GREEN].w = TILE_WIDTH;
//		gTileClips[TILE_GREEN].h = TILE_HEIGHT;
//
//		gTileClips[TILE_BLUE].x = 0;
//		gTileClips[TILE_BLUE].y = 160;
//		gTileClips[TILE_BLUE].w = TILE_WIDTH;
//		gTileClips[TILE_BLUE].h = TILE_HEIGHT;
//
//		gTileClips[TILE_TOPLEFT].x = 80;
//		gTileClips[TILE_TOPLEFT].y = 0;
//		gTileClips[TILE_TOPLEFT].w = TILE_WIDTH;
//		gTileClips[TILE_TOPLEFT].h = TILE_HEIGHT;
//
//		gTileClips[TILE_LEFT].x = 80;
//		gTileClips[TILE_LEFT].y = 80;
//		gTileClips[TILE_LEFT].w = TILE_WIDTH;
//		gTileClips[TILE_LEFT].h = TILE_HEIGHT;
//
//		gTileClips[TILE_BOTTOMLEFT].x = 80;
//		gTileClips[TILE_BOTTOMLEFT].y = 160;
//		gTileClips[TILE_BOTTOMLEFT].w = TILE_WIDTH;
//		gTileClips[TILE_BOTTOMLEFT].h = TILE_HEIGHT;
//
//		gTileClips[TILE_TOP].x = 160;
//		gTileClips[TILE_TOP].y = 0;
//		gTileClips[TILE_TOP].w = TILE_WIDTH;
//		gTileClips[TILE_TOP].h = TILE_HEIGHT;
//
//		gTileClips[TILE_CENTER].x = 160;
//		gTileClips[TILE_CENTER].y = 80;
//		gTileClips[TILE_CENTER].w = TILE_WIDTH;
//		gTileClips[TILE_CENTER].h = TILE_HEIGHT;
//
//		gTileClips[TILE_BOTTOM].x = 160;
//		gTileClips[TILE_BOTTOM].y = 160;
//		gTileClips[TILE_BOTTOM].w = TILE_WIDTH;
//		gTileClips[TILE_BOTTOM].h = TILE_HEIGHT;
//
//		gTileClips[TILE_TOPRIGHT].x = 240;
//		gTileClips[TILE_TOPRIGHT].y = 0;
//		gTileClips[TILE_TOPRIGHT].w = TILE_WIDTH;
//		gTileClips[TILE_TOPRIGHT].h = TILE_HEIGHT;
//
//		gTileClips[TILE_RIGHT].x = 240;
//		gTileClips[TILE_RIGHT].y = 80;
//		gTileClips[TILE_RIGHT].w = TILE_WIDTH;
//		gTileClips[TILE_RIGHT].h = TILE_HEIGHT;
//
//		gTileClips[TILE_BOTTOMRIGHT].x = 240;
//		gTileClips[TILE_BOTTOMRIGHT].y = 160;
//		gTileClips[TILE_BOTTOMRIGHT].w = TILE_WIDTH;
//		gTileClips[TILE_BOTTOMRIGHT].h = TILE_HEIGHT;
//	}
//
//	map.close();
//	return tilesLoaded;
//}
//bool touchesWall(SDL_Rect box, Tile* tiles[]) {
//	//go throung all the tiles
//	for (int i = 0; i < TOTAL_TILES; ++i) {
//		if ((tiles[i]->getType() >= TILE_CENTER) && (tiles[i]->getType() <= TILE_TOPLEFT)) {
//			//if the collison box touches the wall tile
//			if (checkCollision(box, tiles[i]->getBox())) {
//				return true;
//			}
//		}
//	}
//	//if no tiles were touched 
//	return false;
//}
//
//int main() {
//	init();
//	Tile* tileSet[TOTAL_TILES];//the level tiles
//	loadMedia(tileSet);
//
//	bool quit = false;
//	SDL_Event e;
//	Dot dot;
//	SDL_Rect camera = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };
//
//	while (!quit) {
//		while (SDL_PollEvent(&e) != 0) {
//			if (e.type == SDL_QUIT) {
//				quit = true;
//			}
//			//handel user input
//			dot.handleEvent(e);
//		}
//		//move the dot
//		dot.move(tileSet);
//		dot.setCamera(camera);
//
//		//clear the screen
//		SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
//		SDL_RenderClear(gRenderer);
//
//		//Render the level
//		for (int i = 0; i < TOTAL_TILES; ++i) {
//			tileSet[i]->render(camera);
//		}
//
//		//render the dot
//		dot.render(camera);
//
//		//update the screen
//		SDL_RenderPresent(gRenderer);
//	}
//
//	close(tileSet);
//
//	return 0;
//}