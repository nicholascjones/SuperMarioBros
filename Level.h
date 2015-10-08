//Level.h
//12 4 2015

#include "Sprite.h"
#include "Block.h"
#include "mainFunctions.h"
#include <iostream>
#include <SDL2/SDL.h>
#include "Goomba.h"
#include "Turtle.h"
#include <unistd.h>
#include "Mushroom.h"
#include "Scenery.h"

using namespace std;

#ifndef LEVEL_H
#define LEVEL_H

class Level {
public:
	Level();
	void playLevel(); //play the level, like the title implies
	void display(); //displays on screen based on outputs
	void checksMario(); //i wonder what this does
	void checksEnemy(); //samzies
	void scrollScreen(); //this scrolls the screen, who knew

protected:
	Sprite sp; //instantiate dat 

	int numBlocks; //initialtize all stuffs
	Block blk[50];
	SDL_Rect blockRect[50];
	SDL_Rect blockSrcRect[50];

	int numShrooms;
	Mushroom shroom[1];
	SDL_Rect shroomRect[1];
	SDL_Rect shroomSrcRect[1];
	bool gotShroom[1];

	int numGoombas;
	Goomba goomba[500]; //500 is temp max
	SDL_Rect goombaRect[500];
	SDL_Rect goombaSrcRect[500];
	bool newGoomba;

	int numTurtles;
	Turtle turtle[500]; //500 is temp max
	SDL_Rect turtleRect[500];
	SDL_Rect turtleSrcRect[500];
	bool newTurtle;

	int numClouds;
	Scenery cloud[500];
	SDL_Rect cloudRect[500];
	SDL_Rect cloudSrcRect[500];
	bool newCloud;

	SDL_Rect srcRect;
	SDL_Rect dstRect;

	SDL_Rect flagRect;
	SDL_Rect flagSrcRect;
	int mapDistMove;
	int go;


};
#endif

Level::Level() {
	mapDistMove = 0; //more initiliaztion
	numBlocks = 50;
	numGoombas = 2;
	numShrooms = 1;
	numClouds = 500;
	newGoomba = false;
	numTurtles = 2;
	newTurtle = false;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.h = 385;
	srcRect.w = 600;

	dstRect.x = 0;
	dstRect.y = 0;
	dstRect.h = 1000;
	dstRect.w = 1000;

	flagRect.x = 3210;
	flagRect.y = 0;

	flagSrcRect.x = 0;
	flagSrcRect.y = 0;
	flagSrcRect.h = 328;
	flagSrcRect.w = 47;

	shroom[0].setX(700);
	shroom[0].setY(10);
	gotShroom[0] = false;

	blk[0].setXpos(100); //set positions for all blocks
	blk[0].setYpos(210);
	blk[1].setXpos(120);
	blk[1].setYpos(210);
	blk[2].setXpos(140);
	blk[2].setYpos(210);
	blk[3].setXpos(160);
	blk[3].setYpos(230);
	blk[4].setXpos(180);
	blk[4].setYpos(230);
	blk[5].setXpos(200);
	blk[5].setYpos(230);
	blk[6].setXpos(220);
	blk[6].setYpos(250);
	blk[7].setXpos(240);
	blk[7].setYpos(250);
	blk[8].setXpos(260);
	blk[8].setYpos(250);

	blk[9].setXpos(700);
	blk[9].setYpos(230);
	blk[10].setXpos(720);
	blk[10].setYpos(230);
	blk[11].setXpos(780);
	blk[11].setYpos(180);
	blk[12].setXpos(800);
	blk[12].setYpos(180);
	blk[13].setXpos(880);
	blk[13].setYpos(130);
	blk[14].setXpos(900);
	blk[14].setYpos(130);
	blk[15].setXpos(780);
	blk[15].setYpos(80);
	blk[16].setXpos(800);
	blk[16].setYpos(80);
	blk[17].setXpos(700);
	blk[17].setYpos(30);
	blk[18].setXpos(720);
	blk[18].setYpos(30);

	blk[19].setXpos(1400);
	blk[19].setYpos(250);
	blk[20].setXpos(1420);
	blk[20].setYpos(250);
	blk[21].setXpos(1440);
	blk[21].setYpos(250);
	blk[22].setXpos(1760);
	blk[22].setYpos(250);
	blk[23].setXpos(1780);
	blk[23].setYpos(250);
	blk[24].setXpos(1800);
	blk[24].setYpos(250);

	blk[25].setXpos(2100);
	blk[25].setYpos(305);
	blk[26].setXpos(2100);
	blk[26].setYpos(285);
	blk[27].setXpos(2100);
	blk[27].setYpos(265);
	blk[28].setXpos(2100);
	blk[28].setYpos(245);
	// face figure in blocks
	blk[29].setXpos(2400);
	blk[29].setYpos(270);
	blk[30].setXpos(2420);
	blk[30].setYpos(270);
	blk[31].setXpos(2440);
	blk[31].setYpos(270);
	blk[32].setXpos(2420);
	blk[32].setYpos(190);
	blk[33].setXpos(2500);
	blk[33].setYpos(120);
	blk[34].setXpos(2340);
	blk[34].setYpos(120);

	blk[35].setXpos(3000);
	blk[35].setYpos(305);
	blk[36].setXpos(3020);
	blk[36].setYpos(285);
	blk[37].setXpos(3020);
	blk[37].setYpos(305);
	blk[38].setXpos(3040);
	blk[38].setYpos(265);
	blk[39].setXpos(3040);
	blk[39].setYpos(285);
	blk[40].setXpos(3040);
	blk[40].setYpos(305);
	blk[41].setXpos(3060);
	blk[41].setYpos(245);
	blk[42].setXpos(3060);
	blk[42].setYpos(265);
	blk[43].setXpos(3060);
	blk[43].setYpos(285);
	blk[44].setXpos(3060);
	blk[44].setYpos(305);
	blk[45].setXpos(3080);
	blk[45].setYpos(225);
	blk[46].setXpos(3080);
	blk[46].setYpos(245);
	blk[47].setXpos(3080);
	blk[47].setYpos(265);
	blk[48].setXpos(3080);
	blk[48].setYpos(285);
	blk[49].setXpos(3080);
	blk[49].setYpos(305);

	int h = 100;

	for(int i = 0; i < 500; i++){
		goomba[i].setX(570);//initialize all possible goombas
	}

	for(int i = 0; i < 500; i++){
		cloud[i].setX(h);//initialize all possible clouds
		h += 300;
	}

	for(int i = 0; i < 500; i++){ //turtles
		turtle[i].setX(570);
	}

}

void Level::playLevel() {
	bool quit = false;

	if( !init() ){ //all dat SDL stuff
		printf( "Failed to initialize!\n" );
	} else {
		//Load media
		if( !loadMedia() ){
			printf( "Failed to load media!\n" );
		} else {
			SDL_Event e;//Event handler

			while(sp.getAliveStatus() && sp.getX() < 3210 - mapDistMove && !quit)  {
				while( SDL_PollEvent( &e ) != 0 ){//Handle events on queue

					switch(e.type){ //let user use arrows

					case SDL_QUIT: //User requests quit
						quit = true;
						break;

					case SDL_KEYDOWN:
						if(e.key.keysym.sym == SDLK_LEFT){
							sp.setMoveVar(1);  }
						if(e.key.keysym.sym == SDLK_RIGHT){
							//user moves right
							sp.setMoveVar(-1);
						}
						if(e.key.keysym.sym == SDLK_UP){
							if(!sp.inAir())
								sp.setDirection(1);  }
						if(e.key.keysym.sym == SDLK_DOWN){
							//user moves down
						}

						break;

					case SDL_KEYUP:
						if(e.key.keysym.sym == SDLK_LEFT)
							sp.setMoveVar(0);
						if(e.key.keysym.sym == SDLK_RIGHT)
							sp.setMoveVar(0);
						break;
					}//end switch

				}//end while
				sp.jump(); //call all important functions
				checksMario();
				sp.move();
				checksEnemy();
				scrollScreen();
				display();

				newGoomba = goomba[0].makeNewGoomba(); //weird, elaborate way to make new goombas

				if(newGoomba == true){
					newGoomba = false; //reset all variables
					goomba[0].setNewGoomba(false);
					 //unless there is overlapping of monsters, make new goomba!
					if(goomba[numGoombas].getX() - goomba[numGoombas-1].getX() > 30 && goomba[numGoombas].getX() - turtle[numTurtles-1].getX() > 30)
					numGoombas++; //increment

					
				}

				for(int i = 0; i < numGoombas; i++)  { //move that little goomba woomba
					goomba[i].moveGoomba();
				}

				newTurtle = turtle[0].makeNewTurtle(); //same thing for turtles

				if(newTurtle == true){
					newTurtle = false;
					turtle[0].setNewTurtle(false);
					
					if(turtle[numTurtles].getX() - turtle[numTurtles-1].getX() > 30 && turtle[numTurtles].getX() - goomba[numGoombas-1].getX() > 30)
					numTurtles++;

				}

				for(int i = 0; i < numTurtles; i++)  {
					turtle[i].moveTurtle();
				}

			}//end while

			if(!quit) {
			usleep(2000000);
			SDL_Event f;
			SDL_Rect heroSrcRect = sp.getHeroSrcRect();
			SDL_Rect heroRect = sp.getHeroRect();
				while (go != 1) {
					SDL_FillRect(gScreenSurface,NULL,0x000000);
					SDL_BlitSurface( winImage, &srcRect, gScreenSurface, &dstRect ); //Apply the image
					SDL_UpdateWindowSurface( gWindow );
					while( SDL_PollEvent( &f ) != 0 ){//Handle events on queue
						switch(f.type){
						case SDL_KEYDOWN:
							if(f.key.keysym.sym == SDLK_SPACE) {
								go = 1;
								close();
								exit(1);
							}
							break;
						}
					}
				}
			}
		}
	} // end elses
	close();
}

void Level::display() { //displays Sprite
	jumpImage == NULL;
	go = 0;
	SDL_Event f;
	SDL_FillRect(gScreenSurface,NULL,0x000000);
	SDL_BlitSurface( gImage, &srcRect, gScreenSurface, &dstRect ); //Apply the image

	SDL_Rect heroSrcRect = sp.getHeroSrcRect();
	SDL_Rect heroRect = sp.getHeroRect();
	for(int i = 0; i < numClouds; i++)  { //display clouds
		cloudRect[i].x = cloud[i].getX();
		cloudRect[i].y = cloud[i].getY();
		cloudSrcRect[i].w = cloud[i].getWidth();
		cloudSrcRect[i].h = cloud[i].getHeight();
		cloudSrcRect[i].x = 0;
		cloudSrcRect[i].y = 0;
		if (flagRect.x - cloudRect[i].x <= 300) { //if cloud is near the flag, move it so it's invisible
			cloudRect[i].y = 400;
		}
		SDL_BlitSurface( cloudImage, &cloudSrcRect[i], gScreenSurface, &cloudRect[i] );
	}
	SDL_BlitSurface( flagImage, &flagSrcRect, gScreenSurface, &flagRect ); 

	for(int i = 0; i < numShrooms; i++)  { //display mushrooms
		if(!gotShroom[i])  {
			shroomRect[i].x = shroom[i].getX();
			shroomRect[i].y = shroom[i].getY();
			shroomSrcRect[i].w = shroom[i].getWidth();
			shroomSrcRect[i].h = shroom[i].getHeight();
			shroomSrcRect[i].x = 0;
			shroomSrcRect[i].y = 0;
			SDL_BlitSurface( shroomImage, &shroomSrcRect[i], gScreenSurface, &shroomRect[i] );
		}
	}

	for(int i = 0; i < numBlocks; i++)  { //display blocks
		blockRect[i].x = blk[i].getXpos();
		blockRect[i].y = blk[i].getYpos();
		blockSrcRect[i].w = blk[i].getWidth();
		blockSrcRect[i].h = blk[i].getHeight();
		blockSrcRect[i].x = 0;
		blockSrcRect[i].y = 0;
		SDL_BlitSurface( blockImage, &blockSrcRect[i], gScreenSurface, &blockRect[i] );
	}


	for(int i = 0; i < numGoombas; i++)  { //display goombas
		goombaRect[i].x = goomba[i].getX();
		goombaRect[i].y = 302;
		goombaSrcRect[i].w = 24;
		goombaSrcRect[i].h = 24;
		goombaSrcRect[i].x = 0;
		goombaSrcRect[i].y = 0;


		if(goomba[i].dead() == false)	//do not display image if the goomba is dead
			SDL_BlitSurface( goombaImage, &goombaSrcRect[i], gScreenSurface, &goombaRect[i] );
	}

	for(int i = 0; i < numTurtles; i++)  { //similar thing for turtles
		turtleRect[i].x = turtle[i].getX();
		turtleRect[i].y = 302;
		turtleSrcRect[i].w = 24;
		turtleSrcRect[i].h = 24;
		turtleSrcRect[i].x = 0;
		turtleSrcRect[i].y = 0;


		if(turtle[i].dead() == 2) //alive image
			SDL_BlitSurface( turtleImage, &turtleSrcRect[i], gScreenSurface, &turtleRect[i] );
		else if(turtle[i].dead() == 1) //in shell image
			SDL_BlitSurface( shellImage, &turtleSrcRect[i], gScreenSurface, &turtleRect[i] );
		//if dead, no image is displayed
	}

	

	if(sp.getAliveStatus())  { //display marioooo
		if(sp.inAir()) {
			if (sp.isBig()) {
				SDL_BlitSurface( jumpgImage, &heroSrcRect, gScreenSurface, &heroRect );
			} else {
				SDL_BlitSurface( jumpImage, &heroSrcRect, gScreenSurface, &heroRect );
			}
		} else if(sp.getMoveVar()!= 0) {
			if (sp.isBig()) {
				SDL_BlitSurface( walkgImage, &heroSrcRect, gScreenSurface, &heroRect );
			} else {
				SDL_BlitSurface( walkImage, &heroSrcRect, gScreenSurface, &heroRect );
			}
		} else {
			if (sp.isBig()) {
				SDL_BlitSurface( herogImage, &heroSrcRect, gScreenSurface, &heroRect );
			} else {
				SDL_BlitSurface( heroImage, &heroSrcRect, gScreenSurface, &heroRect );
			}
		}
	} else  {
		SDL_BlitSurface( deadImage, &heroSrcRect, gScreenSurface, &heroRect );	// he dead, change image to dead one
		SDL_UpdateWindowSurface( gWindow );
		usleep(2000000);
		while (go != 1) {
			SDL_FillRect(gScreenSurface,NULL,0x000000);
			SDL_BlitSurface( loseImage, &srcRect, gScreenSurface, &dstRect ); //Apply the image
			SDL_UpdateWindowSurface( gWindow );
			while( SDL_PollEvent( &f ) != 0 ){//Handle events on queue
				switch(f.type){
				case SDL_KEYDOWN:
					if(f.key.keysym.sym == SDLK_SPACE) {
						go = 1;
						close();
						exit(1);
					}
					break;
				}
			}
		}
	}
	
	SDL_UpdateWindowSurface( gWindow );//Update the surface
}

void Level::checksMario()  {

	for(int i = 0; i < numBlocks; i++)  {//if mario hits a block
		if(blk[i].isHit(sp.getX()+4, sp.getY()) || blk[i].isHit(sp.getX()+20, sp.getY()))
			sp.setDirection(-1); //reset his direction

		if(blk[i].isOn(sp.getX()+4, sp.getY()+32) || blk[i].isOn(sp.getX()+20, sp.getY()+32)) {//if mario is on top of block
			sp.setDirection(0);
			sp.resetJumpCounter();
		}

		if(blk[i].isHitLeft(sp.getX()+24, sp.getY()+16) && sp.getMoveVar() == -1)
			sp.setMoveVar(0);

		if(blk[i].isHitRight(sp.getX(), sp.getY()+16) && sp.getMoveVar() == 1)
			sp.setMoveVar(0);

	}

	for(int j = 0; j < numShrooms; j++)  //if mario gets the mushroom, make him into Luigi!
		if(shroom[j].isTouch(sp.getX(), sp.getY()) || shroom[j].isTouch(sp.getX()+24, sp.getY()) || shroom[j].isTouch(sp.getX(), sp.getY()+32) || shroom[j].isTouch(sp.getX(), sp.getY()+32))  {
			sp.grow();
			gotShroom[j] = true;
		}
}

void Level::checksEnemy()  {

	for(int i = 0; i < numGoombas; i++)  {//all the checks for goomba

		if(!goomba[i].dead() && goomba[i].isOn(sp.getX(), sp.getY()+32) || goomba[i].isOn(sp.getX()+24, sp.getY()+32)) {
			goomba[i].setAlive();//kill goomba if mario lands on top of him
			sp.setDirection(1);
		}

		if(!goomba[i].dead() && goomba[i].isHitLeft(sp.getX()+24, sp.getY()+16)){
			sp.damage(); //give damage to mario if he hits the left side of goomba
			if(sp.getAliveStatus()) //check if mario is luigi, because then he does not die
				goomba[i].setAlive();
		}

		if(!goomba[i].dead() && goomba[i].isHitRight(sp.getX(), sp.getY()+16)){//same thing but for right side
			sp.damage();
			if(sp.getAliveStatus())
				goomba[i].setAlive();
		}
		
		for(int j = 0; j < numBlocks; j++)  {//if goomba hits a block, change direction
			if(!goomba[i].dead() && goomba[i].isHitLeft(blk[j].getXpos()+20, blk[j].getYpos())){
				goomba[i].setMoveVar(-goomba[i].getMoveVar());
			}

			if(!goomba[i].dead() && goomba[i].isHitRight(blk[j].getXpos(), blk[j].getYpos())){
				goomba[i].setMoveVar(-goomba[i].getMoveVar());
			}//end if
		}//end for
		
		///////////////////////////////////////////////////////////////////////////
			//check if other goombas hit this goomba, change direction if so
		for(int z = i+1; z < numGoombas; z++){
			if(!goomba[i].dead() && goomba[i].isHitLeft(goomba[z].getX()+24, goomba[z].getY()+16)){
				goomba[i].setMoveVar(-goomba[i].getMoveVar());
				goomba[z].setMoveVar(-goomba[z].getMoveVar());
			}
			

			if(!goomba[i].dead() && goomba[i].isHitRight(goomba[z].getX(), goomba[z].getY()+16)){
				goomba[i].setMoveVar(-goomba[i].getMoveVar());
				goomba[z].setMoveVar(-goomba[z].getMoveVar());
			}
		
		}//end for
		
			//check if turtles hit this goomba, if so, change direction
			
		for(int y = 0; y < numTurtles; y++){
			if(!goomba[i].dead() && goomba[i].isHitLeft(turtle[y].getX()+24, turtle[y].getY())){
				goomba[i].setMoveVar(-goomba[i].getMoveVar());
				//turtle[y].setMoveVar(-turtle[y].getMoveVar());
				if(turtle[y].dead() == 1) turtle[y].setPushed(true);
			}
			

			if(!goomba[i].dead() && goomba[i].isHitRight(turtle[y].getX(), turtle[y].getY()+16)){
				goomba[i].setMoveVar(-goomba[i].getMoveVar());
				//turtle[y].setMoveVar(-turtle[y].getMoveVar());
			}
		
		}//end for
		
		
		////////////////////////////////////////////////////////////////////////////
	}


	for(int i = 0; i < numTurtles; i++)  { //all the checks for turtles
		if(turtle[i].dead() == 0)
			turtle[i].setX(-20);//first turtle is a mystery, so make it disappear!
		if(turtle[i].dead() != 0 && turtle[i].isOn(sp.getX(), sp.getY()+32) || turtle[i].isOn(sp.getX()+24, sp.getY()+32)) {
			turtle[i].damage(); //give turtle damage if mario is on top of him
			sp.setDirection(1);
		}

		if(turtle[i].dead() != 0 && turtle[i].isHitLeft(sp.getX()+24, sp.getY()+16)){
			sp.damage();
			if(sp.getAliveStatus())  { //if mario is currently luigi
				turtle[i].damage();
				turtle[i].damage();
			}
		}

		if(turtle[i].dead() != 0 && turtle[i].isHitRight(sp.getX(), sp.getY()+16)){ //same thing, but for right side
			sp.damage();
			if(sp.getAliveStatus())  {
				turtle[i].damage();
				turtle[i].damage();
			}
		}
		for(int j = 0; j < numBlocks; j++)  { //if turtle runs into blocks, change direction
			if(turtle[i].dead() !=0 && turtle[i].isHitLeft(blk[j].getXpos()+20, blk[j].getYpos())){
				turtle[i].setMoveVar(-turtle[i].getMoveVar());
			}

			if(turtle[i].dead() !=0 && turtle[i].isHitRight(blk[j].getXpos(), blk[j].getYpos())){
				turtle[i].setMoveVar(-turtle[i].getMoveVar());
			}
		}

		//if in shell and is hit on the right by the next turtles
		for(int k = i+1; k < numTurtles; k++){
			if(turtle[i].dead() != 0 && turtle[i].isHitRight(turtle[k].getX(), turtle[k].getY())){
				if(turtle[i].dead() == 1) turtle[i].setPushed(true);
				else turtle[i].setMoveVar(-turtle[i].getMoveVar());
			}
		}

		//if in shell and is hit on the right/left by goombas
		for(int m = 0; m < numGoombas; m++){
			if(turtle[i].dead() != 0 && turtle[i].isHitRight(goomba[m].getX(), goomba[m].getY())){
				if(turtle[i].dead() == 1) turtle[i].setPushed(true);
				else turtle[i].setMoveVar(-turtle[i].getMoveVar());
			}

		}

////////////////////////////////////////////////////

	}

}

void Level::scrollScreen()  { //function to scroll the screen

	if(mapDistMove < 2650)  {  // outer stops scrolling at end of map
		if(sp.getX() > 350)  {
			mapDistMove += sp.getX() - 350;
	/* Each for loops moves every object over as Mario progresses through the game
		the mapDistMove variable keeps track of how far Mario has moved across the map */
			flagRect.x = flagRect.x - sp.getX() + 350;
			for(int i = 0; i < numBlocks; i++)  {
				blk[i].setXpos(blk[i].getXpos() - sp.getX() + 350);
			}
	
			for(int i = 0; i < numGoombas; i++)  {
				goomba[i].setX(goomba[i].getX() - sp.getX() + 350);
			}
	
			for(int i = 0; i < numTurtles; i++)  {
				turtle[i].setX(turtle[i].getX() - sp.getX() + 350);
			}
	
			for(int i = 0; i < numShrooms; i++)  {
				shroom[i].setX(shroom[i].getX() - sp.getX() + 350);
			}
	
			for(int i = 0; i < numClouds; i++)  {
				cloud[i].setX(cloud[i].getX() - sp.getX() + 350);
			}
			sp.setX(350);
		}
	}
}








