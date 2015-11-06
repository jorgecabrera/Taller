/*
 * EntidadDinamica.cpp
 *
 *  Created on: 30 de ago. de 2015
 *      Author: jorge
 */

#include "../../Headers/Modelo/EntidadDinamica.h"

EntidadDinamica::EntidadDinamica(){
}

EntidadDinamica::EntidadDinamica(string nameEntity,int vel,float x,float y, float widthPixel, float lengthPixels){
	this->caminando = false;
	this->notifiable = false;
	this->position.first = x;
	this->position.second = y;
	this->width = 1;
	this->length = 1;
	this->owner = "";
	this->name = nameEntity;
	this->camino = new list<pair<int,int> >();
	this->ciclos = (DefaultSettings::getTileSize() / vel) + 3;
	this->cicloActual = 0;
	this->newPath = false;
}

void EntidadDinamica::setOwner(string ownerId){
	this->owner = ownerId;
}

string EntidadDinamica::getOwner(){
	return this->owner;
}

void EntidadDinamica::setInitialScreenPosition(float x,float y){
	//TODO: esto no deberia estar en la VISTA nada mas?
	this->screenPosition.first = x;
	this->screenPosition.second = y;
}

void EntidadDinamica::nextPosition(){
	this->setNotifiable(false);
	if( !camino->empty()){
		if( cicloActual % ciclos == 0){
			pair<int,int> nextTile = camino->front();
			camino->pop_front();
			this->setNotifiable(true);
			this->newPath = false;
			this->setPosition(nextTile.first,nextTile.second);
		}
		cicloActual++;
	}
}

pair<int,int>* EntidadDinamica::getPosition(){
	return &this->position;
}

void EntidadDinamica::setNotifiable(bool noti){
	this->notifiable = noti;
}

bool EntidadDinamica::hasToNotify(){
	return notifiable;
}

list<pair<int,int> >* EntidadDinamica::getCamino(){
	return this->camino;
}

void EntidadDinamica::setCamino(list<pair<int,int> >* caminito){
	this->camino->clear();
	this->camino = caminito;
}

void EntidadDinamica::setPathIsNew(bool isNew){
	this->newPath = isNew;
}

bool EntidadDinamica::pathIsNew(){
	return this->pathIsNew();
}

bool EntidadDinamica::isWalking(){
	return this->caminando;
}

EntidadDinamica::~EntidadDinamica() {
}
