/*
 * Client.cpp
 *
 *  Created on: 3 de oct. de 2015
 *      Author: jorge
 */

#include "../../Headers/Modelo/Client.h"

Client::Client(string ip, int port) {
	this->ip = ip;
	this->port = port;
	this->sockfd = socket(PF_INET, SOCK_STREAM, 0);			//create socket
	this->status = DISCONECTED;								//desconected
}

int Client::connectToServer(){
	int error;
	stringstream ss;
	if ( this->sockfd < 0) {
		ss.clear();
		ss << "Error initializing socket ." << gai_strerror(this->sockfd) << endl;
		Logger::get()->log("Client","connectToServer",ss.str());
		return ERROR;
	}

	//CREATE SOCKET
	struct sockaddr_in s_addr;
	memset(&s_addr, 0, sizeof(s_addr));
	s_addr.sin_family = AF_INET;							//address family internet
	s_addr.sin_port = htons(port);							//set server's port number
	s_addr.sin_addr.s_addr = inet_addr(this->ip.c_str());	//set server's IP

	if ( s_addr.sin_addr.s_addr < 0 ){
		ss.clear();
		ss << "IP connection error ." << gai_strerror(s_addr.sin_addr.s_addr) << endl;
		Logger::get()->log("Client","connectToServer",ss.str());
		return ERROR;
	}
	if ( (error = connect(this->sockfd,(struct sockaddr *)&s_addr, sizeof(s_addr))) < 0){
		ss.clear();
		ss << "Error connecting to server ." << gai_strerror(error) << endl;
		Logger::get()->log("Client","connectToServer",ss.str());
		this->status = DISCONECTED;
		return ERROR;
	}else{
		cout << "Conexion con el servidor "<< inet_ntoa(s_addr.sin_addr)<<endl;
		this->status = CONECTED; // conectado :)
	}

	//INITIALIZE THREAD
	this->readThread = new MessageSocketReader(this->sockfd);
	this->writeThread = new MessageSocketWriter(this->sockfd);
	this->readThread->start((MessageSocketReader*) this->readThread );
	this->writeThread->start((MessageSocketWriter*) this->writeThread);

	return OK;
}

void Client::sendMessage(Message msg){
	if (this->status == CONECTED)
		this->writeThread->sendMessage(msg);
}

void Client::readMessage(Message msg){

}

void Client::communicateWithServer(){
	/*Message* mensaje = new Message("");
	this->socketUtils->readMessage(mensaje);
	cout << "CLI Mensaje recibido CLIENT: "<< mensaje->toString() << endl;
	mensaje->setBody("CLI mensaje del CLIENTE AGE OF EMPIRES");
	this->socketUtils->writeQueue->->writeMessage(mensaje);
	this->socketUtils->readMessage(mensaje);
	cout << "CLI Mensaje recibido CLIENT: "<<mensaje->toString()<< endl;*/
}

int Client::getStatus(){
	return this->status;
}

bool Client::isConected(){
	return this->status == CONECTED;
}

Client::~Client() {
	//this->socketUtils->~SocketUtils();
	shutdown(this->sockfd, 2);	//2 blocks recv and sending
	close(this->sockfd);
}

void Client::processReceivedMessages(){
	list<Message*> pendingMessages = this->readThread->getMessagePendingProcess();
	for(list<Message*>::iterator it=pendingMessages.begin(); it!=pendingMessages.end(); ++it){
		string tipoMensaje = (*it)->getTipo();
		if(tipoMensaje=="window"){
			//Seteo la dimension de la ventana
			GameSettings::GetInstance()->setScreenDimension((*it)->getPositionX(),(*it)->getPositionY());
		}else if (tipoMensaje=="config"){
			//Genero una entidad de configuracion y lo envio al GameSettings
			saveEntitiesConfig((*it));
		}else if (tipoMensaje=="update"){
			//TODO agregar comportamiento para mensajes de cambios de posicion
		}else if (tipoMensaje=="tile"){
			//TODO agregar comportamiento para mensajes de creacion de tile
		}else if (tipoMensaje=="edificios"){
			//TODO agregar comportamiento para mensajes de creacion de edificios/estaticos
		}else if (tipoMensaje=="semiestaticos"){
			//TODO agregar comportamiento para mensajes de creacion de semiestaticos
		}else if (tipoMensaje=="personajes"){
			//TODO agregar comportamiento para mensajes de creacion de personajes/dinamicos
		}else{
			cout << "No se que hacer con el tipo: " << tipoMensaje <<endl;
		}
	}
}

void Client::saveEntitiesConfig(Message* msg){
	EntidadConfig* entidad = new EntidadConfig(msg->getNombre(),
												msg->getImagen(),
												msg->getAnchoBase(),
												msg->getAltoBase(),
												msg->getFps(),
												msg->getDelay(),
												msg->getTotalFramesLine(),
												msg->getPixelsDimension());
	GameSettings::GetInstance()->addEntitisConfig(entidad);
}

int Client::getCountMessageToRead(){
	return this->readThread->getCountMessages();
}
