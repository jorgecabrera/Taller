/*
 * SocketQueue.h
 *
 *  Created on: 8 de oct. de 2015
 *      Author: jorge
 */

#ifndef SOURCE_UTILS_SOCKET_SOCKETQUEUE_H_
#define SOURCE_UTILS_SOCKET_SOCKETQUEUE_H_

#include <queue>
#include <string>
#include "SDL2/SDL.h"
#include "Message.h"

using namespace std;
class SocketQueue {
private:
	queue<Message*> myQueue;
	SDL_mutex* lock;
public:
	SocketQueue();
	/*
	 *intenta encolar mensajes en la cola, sí no está lockeada
	 */
	void queuing(Message *msg);
	/*
	 *devuelve mensajes de la cola
	 */
	Message* pullTail();
	bool isEmpty();
	int getSize();
	virtual ~SocketQueue();
	void lockQueue();
	void unlockQueue();
	Message* pullTailWithoutLock();
};

#endif /* SOURCE_UTILS_SOCKET_SOCKETQUEUE_H_ */