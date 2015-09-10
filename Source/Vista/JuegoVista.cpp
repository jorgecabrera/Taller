/*
 * JuegoVista.cpp
 *
 *  Created on: 1 de set. de 2015
 *      Author: jorge
 */

#include "JuegoVista.h"

void JuegoVista::drawIsometricMap(const string &file){
	int posX = 0;
	int posY = 0;
	for (map<pair<int,int>,Tile>::iterator it = this->mapa->getTiles()->begin(); it != this->mapa->getTiles()->end();++it){
		Tile* tileActual = &((*it).second);
		//transformo coordenadas cartesianas a isométricas
		posY = (tileActual->getPosX()+tileActual->getPosY()) * DefaultSettings::getTileSize() / 2;
		posX = (tileActual->getPosX()-tileActual->getPosY()) * DefaultSettings::getTileSize() + DefaultSettings::getScreenWidth() / 2;	//comienzo a dibujar de la mitad de la pantalla
		picassoHelper->renderObject(file,posX,posY,  DefaultSettings::getTileSize() * 2, DefaultSettings::getTileSize());
	}
}

JuegoVista::JuegoVista(Mapa* mapa) {
	this->mapa = mapa;
	picassoHelper = PicassoHelper::GetInstance();
	picassoHelper->createContext();
    string imagePath = "../Taller/Images/grass_new.png";
	drawIsometricMap(imagePath);

    // Agrego un castillo para probar el path de imagen y para ver como se muestra
    EntidadEstatica* castillo = new EntidadEstatica(3,2,"castillo",true);
	int posY = 0 * castillo->getLength()  - ( castillo->getLength() - 1) * DefaultSettings::getTileSize() ;
	int posX = 0 * castillo->getWidth() + DefaultSettings::getScreenWidth() / 2 -  ( castillo->getWidth() - 1) * DefaultSettings::getTileSize();

    picassoHelper->renderObject(castillo->getPathImage(), posX , posY,(castillo->getWidth()) * 2 * DefaultSettings::getTileSize(), (castillo->getLength()) * DefaultSettings::getTileSize() * 2);
    picassoHelper->renderView();
}

JuegoVista::~JuegoVista() {
	picassoHelper->~PicassoHelper();
}


