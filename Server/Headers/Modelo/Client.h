/*
 * Client.h
 *
 *  Created on: 12 de oct. de 2015
 *      Author: jorlando
 */

#ifndef SOURCE_MODELO_CLIENT_H_
#define SOURCE_MODELO_CLIENT_H_

#define DISCONECTED -1
#define CONECTED 0

#include "../Utils/Socket/MessageSocketWriter.h"
#include "../Utils/Socket/MessageSocketReader.h"
#include "../Utils/Socket/Message.h"
#include "../Utils/Socket/SocketQueue.h"
#include "DefaultSettings.h"
#include <ctime>
#include <list>

class Client {
	int clientId;
	MessageSocketWriter* writeThread;
	MessageSocketReader* readThread;
	list<pair<int,int> > seenTiles;
	string userName;
	time_t lastReported;
	int status;
public:
	Client(int identifier, SocketQueue* queueUnique);
	void writeMessagesInQueue(list<Message*> messagesList);
	void writeMessagesInQueue(Message* message);
	void startCommunication();
	string readUserName();
	string getUserName();
	void setUserName(string myName);
	void responseUserName(string status);
	void reporting();
	bool isActive();
	int getTimeSinceLastReport();
	void disconect();
	void connect();
	int getStatus();
	/*
	*agrega los nuevos tiles en la lista de tiles vistos, y luego los devuelve
	* */
	list<pair<int,int> > setSeenTiles( list<pair<int,int> > newSeenTiles);
	list<pair<int,int> >getSeenTiles();
	list<Message*> getListSeenTilesAsMessages();
	~Client();

};

#endif /* SOURCE_MODELO_CLIENTHANDLER_H_ */