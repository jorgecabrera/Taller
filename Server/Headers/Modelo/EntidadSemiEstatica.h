/*
 * EntidadSemiEstatica.h
 *
 *  Created on: 22 de set. de 2015
 *      Author: jorge
 */

#ifndef SOURCE_MODELO_ENTIDADSEMIESTATICA_H_
#define SOURCE_MODELO_ENTIDADSEMIESTATICA_H_

#include "EntidadPartida.h"
#include "SDL2/SDL.h"

namespace std {

class EntidadSemiEstatica: public EntidadPartida {
private:
	int widthPixel;
	int lengthPixel;
	int framesPerSecond;
	float destinoY;
	int frame;
	int framesInLineFile;

	//Delay entre el fin de un ciclo de frames y el inicio de otro, la idea es setearlo en base al yaml
	int delay;
	//variable de control para indicar si estoy en medio del periodo de delay
	bool inDelayPeriod;
	// indice de segundo del delay por el cual voy
	int delayIndex;
public:
	EntidadSemiEstatica();
	EntidadSemiEstatica(int width, int length,float widthPixel,float lengthPixels, int fps,const string &tipoEntidad,const string &pathImage);

	int getWidthPixel();
	int getLengthPixel();
	pair<int,int>* getPosition();
	void setFramesInLineFile(int qty);
	int getFramesInLineFile();
	int getFramesPerSecond();
	void setDelay(int delayFrames);
	SDL_Rect getPositionOfSprite(int ciclos);
	void drawMe(pair<int,int> isometricPosition, int offSetX, int offSetY, int ciclos);

	virtual ~EntidadSemiEstatica();
};

} /* namespace std */

#endif /* SOURCE_MODELO_ENTIDADSEMIESTATICA_H_ */
