/*
 * SocketQueue.cpp
 *
 *  Created on: 8 de oct. de 2015
 *      Author: jorge
 */

#include "../../../Headers/Utils/Socket/SocketQueue.h"

SocketQueue::SocketQueue() {
	this->lock = SDL_CreateMutex();
}

void SocketQueue::queuing(Message* msg){
	/*
	 *If the mutex is already locked by another thread, then SDL_LockMutex
	 *will not return until the thread that locked it unlocks it
	 **/
	this->lockQueue();
	this->myQueue.push(msg);
	this->unlockQueue();
}

Message* SocketQueue::pullTail(){
	this->lockQueue();
	Message* message = this->pullTailWithoutLock();
	this->unlockQueue();
	return message;
}

bool SocketQueue::isEmpty(){
	return this->myQueue.empty();
}

Message* SocketQueue::pullTailWithoutLock(){
	Message *message = this->myQueue.front();
	this->myQueue.pop();
	return message;
}

void SocketQueue::lockQueue(){
	//SDL_LockMutex(lock);
	SDL_mutexP(lock);
}

void SocketQueue::unlockQueue(){
	//SDL_UnlockMutex(lock);
	SDL_mutexV(lock);
}

SocketQueue::~SocketQueue() {
	while(!this->myQueue.empty()){
		Message* msg = this->myQueue.front();
		this->myQueue.pop();
		msg->~Message();
	}
	SDL_DestroyMutex(this->lock);
}