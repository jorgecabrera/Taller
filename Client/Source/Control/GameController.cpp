/*
 * GameController.cpp
 *
 *  Created on: Sep 11, 2015
 *      Author: juan
 */

#include "../../Headers/Control/GameController.h"

GameController::GameController(){
	gameSettings = GameSettings::GetInstance();
	this->utils = UtilsController::GetInstance();
	this->juegoVista = new JuegoVista();
	this->event = new SDL_Event();
	this->initialPosMouseX = 0;
	this->initialPosMouseY = 0;
	this->finalPosMouseX = 0;
	this->finalPosMouseY = 0;
	this->runCycles = 0;
	this->maxFramesPerSecond = 50; // maxima cantidad de frames del juego principal
	this->gameRunning=false;
	this->gameStatus = RUNNING;
	this->pressedMouseButton = "";
}

list<Message*> GameController::getMessagesFromEvent(string userName){
	list<Message*> messages;
	
	while(SDL_PollEvent(event)){
		if( event->type == SDL_QUIT){
			this->juegoVista->getMenuVista()->deselectedEntity();
			Message* message = new Message();
			msg_game body;
			body.set_id(0);
			body.set_nombre(userName);
			body.set_tipo("exit");
			message->setContent(body);
			messages.push_back(message);
			return messages;
		}
		if( event->type == SDL_MOUSEBUTTONDOWN && event->button.button == SDL_BUTTON_LEFT) {
			pressedMouseButton = "left";
			SDL_GetMouseState(&initialPosMouseX,&initialPosMouseY);
			return messages;
		}

		if( event->type == SDL_MOUSEBUTTONDOWN && event->button.button == SDL_BUTTON_RIGHT) {
			pressedMouseButton = "right";
			SDL_GetMouseState(&initialPosMouseX,&initialPosMouseY);
			return this->action();
		}
		if( event->type == SDL_MOUSEBUTTONUP && pressedMouseButton == "left"){
			//siempre que hago una nueva seleccion borro la lista de seleccionados
			this->idsEntitiesSelected.clear();
			this->juegoVista->getMenuVista()->deselectedEntity();
			SDL_GetMouseState(&finalPosMouseX,&finalPosMouseY);
			//si se movio el mouse
			if (initialPosMouseX != finalPosMouseX || initialPosMouseY != finalPosMouseY) {
				this->pressedMouseButton ="";
				this->selectBox();
				return messages;
			//si no se movio el mouse
			}else {
				this->pressedMouseButton ="";
				this->individualSelection();
				//TODO esto claramente esta mal...hay que hacerle un refactor a todo el metodo, o 
				//analizar la mejor solucion para este caso
				return messages;
			}
		}
	}
	return messages;
}

void GameController::readyToAttack(list<Message*>* messages){
	map<int, EntidadDinamicaVista*>* entities = this->juegoVista->getDinamicEntities();
	for(map<int, EntidadDinamicaVista*>::iterator it = entities->begin(); it != entities->end() ;++it){
		if( it->second->getTarget() != 0 ){
			EntidadPartidaVista* target = this->juegoVista->getEntityById( it->second->getTarget() );
			if( target == NULL ){
				it->second->setTarget(0);
				it->second->prepareToFight(false);
				return;
			}
			pair<int,int> targetPosition = this->utils->getIsometricPosition(target->getPosition().first, target->getPosition().second);
			if(  this->utils->getDistance(it->second->getScreenPosition(), targetPosition) <= 50 && !it->second->isReadyToAttack() ){
				Message* message = new Message();
				msg_game body;
				body.set_id(it->second->getId());
				body.set_tipo("attack");
				body.set_target(target->getId());
				message->setContent(body);
				messages->push_back(message);
				it->second->prepareToFight(true);
			}
		}
	}
}

void GameController::selectBox() {
	if ( initialPosMouseY <= gameSettings->getScreenHeight()-gameSettings->getAlturaMenuInferior() ){
		pair<int,int>* offset = this->juegoVista->getOffset();
		//TODO chequear cual es el mejor numero para sumarle a i y a j
		for (int i = this->initialPosMouseX; i <= this->finalPosMouseX ; i = i + gameSettings->getTileSize()) {
			for ( int j = this->initialPosMouseY ; j <= this->finalPosMouseY ; j = j + gameSettings->getTileSize()/2) {
				pair<int,int> cartesianPosition = this->utils->convertToCartesian(i-offset->first,j-offset->second);
				//TODO obtener solo entidades dinamicas
				map<string,string> entidadMap = juegoVista->getEntityAt(cartesianPosition);
				if(entidadMap.size()>0){
					if(this->clientName == entidadMap.at("owner")){
						this->idsEntitiesSelected.push_back(atoi(entidadMap.at("id").c_str()));
					}
				}
			}
		}
		this->idsEntitiesSelected.unique();
		//si no pude seleccionar ninguna entidad propia
		if (this->idsEntitiesSelected.empty()) {
			this->juegoVista->getMenuVista()->deselectedEntity();
		} else {
			//this->juegoVista->getMenuVista()->setSelectedsEntitiesDescription(this->idsEntitiesSelected);
			//TODO este metodo deberia renderizar en el menu todos los personajes elegidos
		}
	}
}


void GameController::individualSelection() {
	if ( initialPosMouseY <= gameSettings->getScreenHeight()-gameSettings->getAlturaMenuInferior() ){
		pair<int,int>* offset = this->juegoVista->getOffset();
		pair<int,int> cartesianPosition = this->utils->convertToCartesian( this->initialPosMouseX-offset->first, this->initialPosMouseY-offset->second);
		map<string,string> entidadMap = juegoVista->getEntityAt(cartesianPosition);
		if( entidadMap.size()>0 && this->clientName == entidadMap.at("owner") ){
			//this->idEntitySelected = atoi(entidadMap.at("id").c_str());
			this->idsEntitiesSelected.push_back( atoi(entidadMap.at("id").c_str()));
			this->juegoVista->getMenuVista()->setSelectedEntityDescription(entidadMap);
		
		}else if( entidadMap.size()>0 ){
			//this->idEntitySelected = 0;
			this->idsEntitiesSelected.clear();
			this->juegoVista->getMenuVista()->setSelectedEntityDescription(entidadMap);

		}else{
			this->juegoVista->getMenuVista()->deselectedEntity();
			//this->idEntitySelected=0;
			this->idsEntitiesSelected.clear();
		}
	}
}

list<Message*> GameController::action() {
	list<Message*> messages;
	if (!this->idsEntitiesSelected.empty()) {
		if ( initialPosMouseY >= gameSettings->getScreenHeight()-gameSettings->getAlturaMenuInferior() ){
			//menu
			return this->interactiveMenu(initialPosMouseX,initialPosMouseY);
		} else {
			list<int>::iterator it = this->idsEntitiesSelected.begin();
			EntidadDinamicaVista* entity = this->juegoVista->getDinamicEntityById(*it);
			if (entity != NULL) {
				pair<int,int> cartesianPosition = this->getValidCartesianPosition(entity);
				map<string,string> targetToAttack = this->juegoVista->getEntityAt(cartesianPosition);

				//attack
				if( targetToAttack.size() > 0 && this->clientName.compare(targetToAttack["owner"].c_str()) != 0){
					for (; it != this->idsEntitiesSelected.end() ; ++it ) {
						Message* message = new Message();
						msg_game body;
						body.set_id(*it);
						body.set_tipo("attack");
						body.set_target(atoi(targetToAttack["id"].c_str()));
						message->setContent(body);
						/*stringstream ss;
						ss << "id :" << *it;
						Logger::get()->logInfo("GC","attack",ss.str());*/
						entity->setTarget(atoi(targetToAttack["id"].c_str()));
						messages.push_back(message);
					}
				}else{
					for (; it != this->idsEntitiesSelected.end() ; ++it ) {
						Message* message = new Message();
						msg_game body;
						body.set_id(*it);
						body.set_tipo("update");
						body.set_x(cartesianPosition.first);
						body.set_y(cartesianPosition.second);
						body.set_target(0);
						message->setContent(body);
						/*stringstream ss;
						ss << "id :" << *it;
						Logger::get()->logInfo("GC","update",ss.str());*/

						messages.push_back(message);
					}
				}
			}
		}
	}
	return messages;
}

JuegoVista* GameController::getJuegoVista(){
	return this->juegoVista;
}

void GameController::setGameRunning(){
	this->gameRunning=true;
}

void GameController::updateGame(){
	map<int,EntidadDinamicaVista*>* entidades = this->juegoVista->getDinamicEntities();
	for(map<int,EntidadDinamicaVista*>::iterator it = entidades->begin(); it !=entidades->end(); ++it){
		this->updatePosition((*it).second->getId());
	}

	pair<int,int> offset = this->getOffset(this->juegoVista->getOffset()->first,this->juegoVista->getOffset()->second);
	juegoVista->updateOffset(offset.first,offset.second);
}

int GameController::getRunCycles(){
	return this->runCycles;
}

int GameController::getMaxFramesPerSecond(){
	return this->maxFramesPerSecond;
}

pair<int,int> GameController::getOffset(int offSetX, int offSetY){
	int posicionX = 0;
	int posicionY = 0;
	SDL_GetMouseState(&posicionX, &posicionY);

	if (posicionX >= gameSettings->getMargenDerechoUno()	&& posicionX < gameSettings->getMargenDerechoDos() && !(offSetX < gameSettings->getLimiteDerecho())) {
			offSetX -= gameSettings->getVelocidadScrollUno();
	}
	if (posicionX >= gameSettings->getMargenDerechoDos() && !(offSetX < gameSettings->getLimiteDerecho())) {
			offSetX -= 1 * gameSettings->getVelocidadScrollDos();
	}
	if ((posicionX > gameSettings->getMargenIzquierdoDos()) && (posicionX <= gameSettings->getMargenIzquierdoUno()) && !(offSetX > gameSettings->getLimiteIzquierdo())) {
			offSetX += gameSettings->getVelocidadScrollUno();
	}
	if (posicionX <= gameSettings->getMargenIzquierdoDos() && !(offSetX > gameSettings->getLimiteIzquierdo())) {
			offSetX += gameSettings->getVelocidadScrollDos();
	}
	if ((posicionY <= gameSettings->getMargenSuperiorUno()) && (posicionY > gameSettings->getMargenSuperiorDos()) && !((offSetY > gameSettings->getLimiteSuperior()))) {
			offSetY += gameSettings->getVelocidadScrollUno();
	}
	if (posicionY <= gameSettings->getMargenSuperiorDos() && !((offSetY > gameSettings->getLimiteSuperior()))) {
		offSetY += gameSettings->getVelocidadScrollDos();
	}
	if (posicionY >= gameSettings->getMargenInferiorUno() && (posicionY < gameSettings->getMargenInferiorDos()) && !((offSetY < gameSettings->getLimiteInferior()))) {
			offSetY -= gameSettings->getVelocidadScrollUno();
	}
	if ((posicionY >= gameSettings->getMargenInferiorDos()) && !((offSetY < gameSettings->getLimiteInferior()))) {
		offSetY -= gameSettings->getVelocidadScrollDos();
	}
	pair<int,int> curretOffset;
	curretOffset.first = offSetX;
	curretOffset.second = offSetY;
	return curretOffset;
}

pair<int,int> GameController::getValidCartesianPosition(EntidadPartidaVista* entidad){
	pair<int,int>* offset = this->juegoVista->getOffset();
	pair<int,int> cartesianPosition = this->utils->convertToCartesian( this->initialPosMouseX-offset->first, this->initialPosMouseY-offset->second);

	//las coordenadas cartesianas siempre tienen que quedar dentro del mapa
	if( cartesianPosition.first < 0 ){
		cartesianPosition.first = 0;
	}else if( cartesianPosition.first >= gameSettings->getMapWidth()){
		cartesianPosition.first = gameSettings->getMapWidth() - 1 ;
	}
	if( cartesianPosition.second < 0){
		cartesianPosition.second = 0;
	}else if( cartesianPosition.second >= gameSettings->getMapHeight()){
		cartesianPosition.second = gameSettings->getMapHeight() - 1;
	}

	return cartesianPosition;
}

void GameController::updatePosition(int id){
	EntidadDinamicaVista* entity = this->juegoVista->getDinamicEntityById(id);
	if( !(entity->getCamino()->empty()) && !(entity->isWalking())){
		pair<int,int> nuevaPos = entity->getCamino()->front();
		entity->getCamino()->pop_front();

		entity->setPosition(nuevaPos.first,nuevaPos.second);
		pair<int,int> destinoIsometrico = this->utils->GetInstance()->getIsometricPosition(nuevaPos.first,nuevaPos.second);
		entity->setScreenPosition(destinoIsometrico.first,destinoIsometrico.second);
	}
}

void GameController::delay(){
	this->runCycles++;
	if(this->gameRunning){
		SDL_Delay(50); // para que sean 50 frames x segundos
	}else{
		SDL_Delay(1000); // espero 1 segundo porque aun no esta en juego
	}
}

void GameController::delay(int delayMs){
	this->runCycles++;
	SDL_Delay(delayMs);
}

bool GameController::gameIsRunning(){
	return this->gameRunning;
}

void GameController::setClientName(string name){
	this->clientName = name;
}

void GameController::winGame(){
	this->gameStatus = WIN;
}

void GameController::loseGame(){
	this->gameStatus = LOSE;
}

void GameController::disconnectedGame(){
	this->gameStatus = DISCONNECTED;
}

void GameController::showFinalMessage(){
	string finalMessage= "";
	if(this->gameStatus == WIN){
		finalMessage = "Victory is yours";
	}else if(this->gameStatus == LOSE){
		finalMessage = "You Died";
	}else if (this->gameStatus == DISCONNECTED){
		finalMessage = "Server disconnected";
	}
	if(finalMessage!=""){
		this->getJuegoVista()->renderFinalMessage(finalMessage);
		this->delay(5000);
	}
}

list<Message*> GameController::interactiveMenu(int initialPosMouseX,int initialPosMouseY) {
	list<Message*> messages;
	pair<int, string> buildingAndEntitie = this->juegoVista->getMenuVista()->getTypeOfNewEntity(initialPosMouseX,initialPosMouseY);
	if (buildingAndEntitie.second != "") {
		ResourceCounter* resourceCounter = this->juegoVista->getResourceCounter();
		map<string,int> costs = this->gameSettings->getCostsOf(buildingAndEntitie.second);
		if (	costs["chori"] <= resourceCounter->getAlimento() &&
				costs["rock"] <= resourceCounter->getRoca() &&
				costs["gold"] <= resourceCounter->getOro() &&
				costs["wood"] <= resourceCounter->getMadera() ) {
			//gasto los recursos
			for (map<string,int>::iterator it = costs.begin(); it != costs.end(); ++it){
				for (int resource = (*it).second; resource!=0 ; resource --) {
					resourceCounter->gastar((*it).first);
				}
			}
			Message* message = new Message();
			msg_game body;
			body.set_id(buildingAndEntitie.first);
			body.set_tipo("create");
			body.set_nombre(buildingAndEntitie.second);
			message->setContent(body);
			message->setOwner(this->clientName);
			messages.push_back(message);
		}
	}
	return messages;
}

GameController::~GameController() {
	//delete(this->juegoVista);
	this->juegoVista=NULL;
//	this->utils->~UtilsController();
	delete(this->utils);
	this->utils = NULL;
//	this->gameSettings->~GameSettings();
	delete(this->gameSettings);
	this->gameSettings = NULL;
	this->event->quit;
	delete(this->event);
	this->event = NULL;
}

