/*
 * Message.h
 *
 *  Created on: 3 de oct. de 2015
 *      Author: jorge
 */

#ifndef SOURCE_UTILS_SOCKET_MESSAGE_H_
#define SOURCE_UTILS_SOCKET_MESSAGE_H_

#include "../Logger.h"
#include <string.h>
#include <sstream>
#include <iostream>
#include <arpa/inet.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "messageGame.pb.h"

using namespace std;

class Message {
private:
	msg_game msg;

public:
	Message();
	Message(int identifier, int xPosition, int yPosition);
	Message(int identifier,string tipoMessage, string nombreEntity, int xPosition, int yPosition, int clientConnected);
	Message(string nameEntity, string thePath, int anchoBase, int altoBase, int fps, int delay, int totalFramesLine, int pixelDimension);
	Message(string tipo, string nombreEntity, int xPosition, int yPosition, int mapaAncho, int mapaAlto);
	Message(string tipo, string nombreEntity, int xPosition, int yPosition);
	Message(string nombre);

	virtual ~Message();
	int getSize();
	char* serializeToArray();
	string serializeAsString();
	string toString();
	void setContent(msg_game body);

	//Defino metodos para poder sacar la informacion del mensaje desde afuera de la clase
	string getTipo();
	int getId();
	int getPositionX();
	int getPositionY();
	string getNombre();
	string getImagen();
	int getAnchoBase();
	int getAltoBase();
	int getFps();
	int getDelay();
	int getTotalFramesLine();
	int getPixelsDimension();
	void setAsNewPath(bool value);
	bool isNewPath();
	void setOwner(string userName);
	string getOwner();
	void pingMessage(string nombre);
	void clientDisconect(int id);
	void clientReconnect(int identifier);
	void activeTile( int x, int y);
};

#endif /* SOURCE_UTILS_SOCKET_MESSAGE_H_ */