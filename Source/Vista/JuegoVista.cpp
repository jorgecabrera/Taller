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
	for (map<pair<int,int>,Tile*>::iterator it = this->juego->getMap()->getTiles()->begin(); it != this->juego->getMap()->getTiles()->end();++it){
		Tile* tileActual = (*it).second;
		//transformo coordenadas cartesianas a isométricas
		posY = (tileActual->getPosX()+tileActual->getPosY()) * DefaultSettings::getTileSize() / 2 + this->offSetY;
		posX = (tileActual->getPosX()-tileActual->getPosY()) * DefaultSettings::getTileSize() + DefaultSettings::getScreenWidth() / 2 + offSetX;	//comienzo a dibujar de la mitad de la pantalla
		picassoHelper->renderObject(file,posX,posY,  DefaultSettings::getTileSize() * 2, DefaultSettings::getTileSize());
	}
}

	void JuegoVista::actualizarMapa() {

		int posicionX = 0;
		int posicionY = 0;

		SDL_GetMouseState(&posicionX, &posicionY);
		cout << "posicion del mouse: (" << posicionX << ", " << posicionY << ") "
				<< endl;
		cout << "offSet X: (" << offSetX << ") " << endl;
		cout << "offSet Y: (" << offSetY << ") " << endl;

		if (posicionX >= DefaultSettings::getMargenDerechoUno()
				&& posicionX < DefaultSettings::getMargenDerechoDos()
				&& !(offSetX < DefaultSettings::getLimiteDerecho())) {
			offSetX -= DefaultSettings::getVelocidadScrollUno();
			cout << "### scrolllllllllll velocidad uno: (" << posicionX << ", "
					<< posicionX << ") " << endl;
		}

		if (posicionX >= DefaultSettings::getMargenDerechoDos()
				&& !(offSetX < DefaultSettings::getLimiteDerecho())) {
			offSetX -= 1 * DefaultSettings::getVelocidadScrollDos();
			cout << "### scrolllllllllll velocidad dos: (" << posicionX << ", "
					<< posicionX << ") " << endl;
		}

		if ((posicionX >= DefaultSettings::getMargenIzquierdoUno())
				&& (posicionX < DefaultSettings::getMargenIzquierdoDos())
				&& !(offSetX > DefaultSettings::getLimiteIzquierdo())) {
			offSetX += DefaultSettings::getVelocidadScrollUno();
		}

		if (posicionX <= DefaultSettings::getMargenIzquierdoDos()
				&& !(offSetX > DefaultSettings::getLimiteIzquierdo())) {
			offSetX += DefaultSettings::getVelocidadScrollDos();
		}

		if ((posicionY <= DefaultSettings::getMargenSuperiorUno())
				&& (posicionY > DefaultSettings::getMargenSuperiorDos())
				&& !((offSetY > DefaultSettings::getLimiteSuperior()))) {
			offSetY += DefaultSettings::getVelocidadScrollUno();
		}

		if (posicionY <= DefaultSettings::getMargenSuperiorDos()
				&& !((offSetY > DefaultSettings::getLimiteSuperior()))) {
			offSetY += DefaultSettings::getVelocidadScrollDos();
		}

		if (posicionY >= DefaultSettings::getMargenInferiorUno()
				&& (posicionY < DefaultSettings::getMargenInferiorDos())
				&& !((offSetY < DefaultSettings::getLimiteInferior()))) {
			offSetY -= DefaultSettings::getVelocidadScrollUno();
		}

		if ((posicionY >= DefaultSettings::getMargenInferiorDos())
				&& !((offSetY < DefaultSettings::getLimiteInferior()))) {
			offSetY -= DefaultSettings::getVelocidadScrollDos();
		}

		drawIsometricMap("../Taller/Images/grass_new.png");

	}

void JuegoVista::drawEntities(){
	pair<int,int> isometricPosition;
	for(map<pair<int,int>,EntidadPartida*>::iterator it=this->juego->getMap()->getEntities()->begin();it!=this->juego->getMap()->getEntities()->end();++it){
		EntidadPartida* entidad = (*it).second;
		isometricPosition = picassoHelper->getIsometricPosition(entidad);
		picassoHelper->renderObject(entidad->getPathImage(), (isometricPosition.first+ this->offSetX) , (isometricPosition.second+ this->offSetY) ,entidad->getWidth() * 2 * DefaultSettings::getTileSize(), (entidad->getLength()-1) * DefaultSettings::getTileSize() * 2);
	}
}

void JuegoVista::render(){

	picassoHelper->clearView();
	string imagePath = "../Taller/Images/grass_new.png";
	actualizarMapa();
	drawIsometricMap(imagePath);
	drawEntities();
	this-> renderProtagonista();
	picassoHelper->renderView();
}

void JuegoVista::renderProtagonista(){
	string imagePath = "../Taller/Images/ricardo.png";
	picassoHelper->renderObject(imagePath,this->juego->getProtagonista()->getX(),this->juego->getProtagonista()->getY(),DefaultSettings::getTileSize(),DefaultSettings::getTileSize());
}

JuegoVista::JuegoVista(Juego* juego) {
	this->juego = juego;
	this->offSetX = 0;
	this->offSetY = 0;
	/*this->pheight = 50;
	this->pwidth = 50;
	this->offh = pheight;
	this->offw = (pwidth / 2);*/

	picassoHelper = PicassoHelper::GetInstance(juego);
	picassoHelper->createContext();

}

JuegoVista::~JuegoVista() {
	picassoHelper->~PicassoHelper();
}


