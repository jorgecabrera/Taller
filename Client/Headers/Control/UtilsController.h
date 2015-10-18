/*
 * UtilsController.h
 *
 *  Created on: 17 de set. de 2015
 *      Author: jorge
 */

#ifndef SOURCE_CONTROL_UTILSCONTROLLER_H_
#define SOURCE_CONTROL_UTILSCONTROLLER_H_
#include <iostream>
#include "../Modelo/GameSettings.h"

using namespace std;

class UtilsController {
private:
	UtilsController();
	static UtilsController* instance;
	GameSettings* gameSettings;

public:
	static UtilsController* GetInstance();
	/* Transforma de coordenadas de pantalla a coordenadas cartesianas*/
	pair<int,int> convertToCartesian(int xScreen,int yScreen);

	/** Encuentra la posición de pantalla en donde se debería deibujar una entidad que esta en las coordenadas cartesianas
	 * (x,y). Luego la centra con los tiles, y retorna la posicion.**/
	pair<int,int> getIsometricPosition(EntidadPartida* entidad);
	pair<int,int> getIsometricPosition(int x,int y);

	virtual ~UtilsController();

};

#endif /* SOURCE_CONTROL_UTILSCONTROLLER_H_ */