/*
 * MessageSocketReader.h
 *
 *  Created on: 13 de oct. de 2015
 *      Author: jorlando
 */

#ifndef SOURCE_UTILS_SOCKET_MESSAGESOCKETREADER_H_
#define SOURCE_UTILS_SOCKET_MESSAGESOCKETREADER_H_
#define ERROR -1
#define OK 0
#include "../Thread.h"
#include "SocketQueue.h"
#include "SocketUtils.h"
#include "Message.h"

using namespace std;

class MessageSocketReader: public Thread {
private:
	SocketQueue queue;
	SocketUtils* socket;
public:
	MessageSocketReader(int sockfd);
	int run(void* data);
	virtual ~MessageSocketReader();
	void writeMessage(Message msg);
};

#endif /* SOURCE_UTILS_SOCKET_MESSAGEREADER_H_ */
