/*
 * TileVista.cpp
 *
 *  Created on: 1 de set. de 2015
 *      Author: jorge
 */

#include "../../Headers/Modelo/TileVista.h"

using namespace std;

TileVista::TileVista(int x, int y ) {
	this->position.first = x;
	this->position.second = y;
}

pair<int,int>* TileVista::getPosition(){
	return &this->position;
}

int TileVista::getPosX(){
	return this->position.first;
}

int TileVista::getPosY(){
	return this->position.second;
}

string TileVista::getPathImage(){
	return pathImage;
}

void TileVista::setPathImage(string path){
	this->pathImage = path;
}

TileVista::~TileVista() {
}
