/*
 * Juego.cpp
 *
 *  Created on: 30 de ago. de 2015
 *      Author: jorge
 */

#include "../../Headers/Modelo/Juego.h"

using namespace std;

Juego::Juego() {
	gameSettings = GameSettings::GetInstance();
	this->juegoFinalizado = false;
	this->mapa = new Mapa();

	this->currentAge = gameSettings->getAgeOfEmpires();
	this->protagonista = new EntidadDinamica(gameSettings->getTipoProtagonista(),
			gameSettings->getVelocidadPersonaje(),
			gameSettings->getPosXProtagonista(),
			gameSettings->getPosYProtagonista(),
			gameSettings->getProtagonistaPixelDimension(),
			gameSettings->getProtagonistaPixelDimension(),
			gameSettings->getProtagonistaFPS());

	this->protagonista->setFramesInLineFile(gameSettings->getProtagonistaFramesInFile());
	this->protagonista->setPathImage(gameSettings->getProtagonistaPath());
	this->protagonista->setDelay(gameSettings->getProtagonistaDelay());
	this->offset.first = 0;
	this->offset.second = 0;
	pair<float,float> isometricas = this->getIsometricPosition(protagonista);
	protagonista->setInitialScreenPosition(isometricas.first + gameSettings->getTileSize() ,isometricas.second);
}

pair<int,int>* Juego::getOffset(){
	return &this->offset;
}

Mapa* Juego::getMap(){
	return this->mapa;
}

EntidadDinamica* Juego::getProtagonista(){
	return this->protagonista;
}

void Juego::actualizarProtagonista(){
	protagonista->trasladarse();
}

string Juego::getCurrentAge(){
	return this->currentAge;
}

void Juego::actualizarOffset(int offsetX,int offsetY){
	this->offset.first = offsetX;
	this->offset.second = offsetY;
}

void Juego::setDestinoProtagonista(int x,int y, int screenPosX, int screenPosY){
	//Actualiza las coordenadas cartesianas del protagonista
	this->protagonista->setPosition(x,y);
	//Actualizo las coordenadas de pantalla del protagonista
	this->protagonista->setScreenPosition(screenPosX - this->offset.first,screenPosY - this->offset.second);
}

void Juego::terminarJuego(){
	this->juegoFinalizado = true;
}
bool Juego::getStatusPartida(){
	return this->juegoFinalizado;
}

pair<int,int> Juego::getIsometricPosition(EntidadPartida* entidad){
	pair<int,int> isometricPosition;
	//hacemos coincidir el vertice superior izquierdo de la entidad con el tile
	isometricPosition.first = (entidad->getPosition()->first - entidad->getPosition()->second) * gameSettings->getTileSize() + gameSettings->getScreenWidth() / 2;
	isometricPosition.second = (entidad->getPosition()->first + entidad->getPosition()->second) * gameSettings->getTileSize() / 2  ;

	//ahora hay que centrar la entidad con el tile
	isometricPosition.first = isometricPosition.first - (entidad->getWidth() - 1)  *  gameSettings->getTileSize();
	isometricPosition.second = isometricPosition.second - (entidad->getLength() - 1) *  gameSettings->getTileSize() / 2;
	return isometricPosition;
}

Juego::~Juego() {
//	this->protagonista->~EntidadDinamica();
	delete(this->protagonista);
//	this->mapa->~Mapa();
	delete(this->mapa);
	this->protagonista = NULL;
	this->mapa = NULL;
	this->gameSettings=NULL;
	//this->gameSettings->~GameSettings();
}