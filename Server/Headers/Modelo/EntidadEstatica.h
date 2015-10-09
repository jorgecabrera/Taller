/*
 * EntidadEstatica.h
 *
 *  Created on: 30 de ago. de 2015
 *      Author: jorge
 */

#ifndef SOURCE_MODELO_ENTIDADESTATICA_H_
#define SOURCE_MODELO_ENTIDADESTATICA_H_

#include "EntidadPartida.h"

using namespace std;

class EntidadEstatica: public EntidadPartida {
private:
	bool edificable;

public:
	EntidadEstatica();
	void destruir();
	EntidadEstatica(int width,int length, bool esEdificable, const string &sourceImage);
	EntidadEstatica(int width,int length, bool esEdificable);
	virtual ~EntidadEstatica();
};

#endif /* SOURCE_MODELO_ENTIDADESTATICA_H_ */
