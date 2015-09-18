/*
 * UtilsController.cpp
 *
 *  Created on: 17 de set. de 2015
 *      Author: jorge
 */

#include "UtilsController.h"
UtilsController* UtilsController::instance = NULL;


UtilsController::UtilsController() {
	// TODO Auto-generated constructor stub

}

UtilsController* UtilsController::GetInstance(){
	if(!instance)
		instance = new UtilsController();
	return instance;
}

pair<int,int> UtilsController::convertToCartesian(int xScreen,int yScreen){
	int startMapX = DefaultSettings::getScreenWidth() / 2 + DefaultSettings::getTileSize();
	int x = ( yScreen * 2 + xScreen - startMapX) / (DefaultSettings::getTileSize() * 2);
	int y = yScreen / (DefaultSettings::getTileSize() / 2) - x;
	pair<int,int> cartesianPosition;
	cartesianPosition.first = x;
	cartesianPosition.second = y;
	return cartesianPosition;
}

pair<int,int> UtilsController::getIsometricPosition(int x,int y,int width,int length){
	pair<int,int> isometricPosition;
	//hacemos coincidir el vertice superior izquierdo de la entidad con el tile
	isometricPosition.first = ( x - y) * DefaultSettings::getTileSize() + DefaultSettings::getScreenWidth() / 2;
	isometricPosition.second = ( x + y) * DefaultSettings::getTileSize() / 2  ;

	//ahora hay que centrar la entidad con el tile
	isometricPosition.first = isometricPosition.first - (width - 1)  *  DefaultSettings::getTileSize();
	isometricPosition.second = isometricPosition.second - (length - 1) *  DefaultSettings::getTileSize() / 2;
	return isometricPosition;
}

UtilsController::~UtilsController() {
	// TODO Auto-generated destructor stub
}

