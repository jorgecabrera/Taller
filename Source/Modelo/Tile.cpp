/*
 * Tile.cpp
 *
 *  Created on: 1 de set. de 2015
 *      Author: jorge
 */

#include "Tile.h"

using namespace std;

Tile::Tile(int x, int y ) {
	this->position.first = x;
	this->position.second = y;
	this->available = true;
}

void Tile::changeStatusAvailable(){
	this->available = this->available == false;
}

bool Tile::isAvailable(){
	return this->available;
}

void Tile::pushSurface(surface_type surface){
	this->superficie = surface;
}

int Tile::getSurfaceSpeed(){
	return this->superficie;
}

pair<int,int>* Tile::getPosition(){
	return &this->position;
}

int Tile::getPosX(){
	return this->position.first;
}

int Tile::getPosY(){
	return this->position.second;
}

void Tile::show(){
	cout << "x:" << this->position.first << ", y:" << this->position.second << "\n";
}

Tile::~Tile() {
	// TODO Auto-generated destructor stub
}

