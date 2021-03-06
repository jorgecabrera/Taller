/*
 * JuegoVista.cpp
 *
 *  Created on: 1 de set. de 2015
 *      Author: jorge
 */

#include "../../Headers/Vista/JuegoVista.h"

JuegoVista::JuegoVista() {
	gameSettings = GameSettings::GetInstance();
	this->offset.first = 0;
	this->offset.second = 0;
	this->menuVista = new MenuVista();
	this->loginVista = new LoginVista();
	this->availablePosForBuilding = true;
	this->entityForBuild = "";
	this->miniMapVista = new MiniMapVista();
}

MenuVista* JuegoVista::getMenuVista(){
	return this->menuVista;
}

bool JuegoVista::isAvailablePosForBuilding(){
	return this->availablePosForBuilding;
}

map<int, EntidadDinamicaVista*>* JuegoVista::getDinamicEntities(){
	return &this->personajes;
}

void JuegoVista::createView(){
	picassoHelper = PicassoHelper::GetInstance(gameSettings->getScreenWidth(), gameSettings->getScreenHeight());
}

string JuegoVista::renderUserInputView(string initialMessage){
	string userInput = this->loginVista->askInfoUser(initialMessage);
	return userInput;
}

void JuegoVista::renderFinishLogin(string finalMessage){
	this->loginVista->renderFinishLogin(finalMessage);
}

void JuegoVista::render(int runCycles, ResourceCounter* resourceCounter, string userName){
	this->picassoHelper->clearView();
	this->drawIsometricMap();
	this->setFoggedTiles(userName);
	this->drawDinamicEntities(runCycles);
	this->drawStaticEntities(runCycles);
	this->drawSemiStaticsEntities(runCycles);
	this->drawFog();
	this->drawMenu();
	this->drawResources(resourceCounter);
	this->drawMiniMap();
	this->drawEntityForBuild();
	this->picassoHelper->renderView();
}

void JuegoVista::renderFinalMessage(string finalMessage){
	PicassoHelper::GetInstance()->renderText(GameSettings::GetInstance()->getScreenWidth()/3,GameSettings::GetInstance()->getScreenHeight()/2,finalMessage.size()*20,40,finalMessage,255,255,255);
	this->picassoHelper->renderView();
}

void JuegoVista::drawEntityForBuild(){
	if(this->entityForBuild != ""){
		int offsetX = this->getOffset()->first;
		int offsetY = this->getOffset()->second;
		pair< int,int > cartesianPosition = this->tilesForBuilding.front();
		int width = this->gameSettings->getEntityConfig(this->entityForBuild)->getAncho();
		int height = this->gameSettings->getEntityConfig(this->entityForBuild)->getAlto();
		string path = this->gameSettings->getEntityConfig(this->entityForBuild)->getPath();
		size_t found = path.find("Molino");
		if(found!=string::npos){
			path=path.replace(path.find("Molino"), sizeof("Molino")-1, "MolinoSolo");
			//Sumo uno porque el molino de 1 de alto y para dibujarlo se hace 0
			height += 1;
		}
		pair<int,int> isometricPosition = UtilsController::GetInstance()->getIsometricPosition(cartesianPosition.first-width*2, cartesianPosition.second-height);
		PicassoHelper::GetInstance()->renderObject(path, (isometricPosition.first+ offsetX) , (isometricPosition.second+ offsetY) ,width * 2 * DefaultSettings::getTileSize(), (height-1) * DefaultSettings::getTileSize() * 2, this->availablePosForBuilding);
	}
}

void JuegoVista::drawFog() {
	int posX = 0;
	int posY = 0;
	int offsetX = this->getOffset()->first;
	int offsetY = this->getOffset()->second;

	for(list<TileVista*>::iterator itTiles = this->tiles.begin(); itTiles!=this->tiles.end(); ++itTiles){
		posY = ((*itTiles)->getPosX()+(*itTiles)->getPosY()) * gameSettings->getTileSize() / 2 + offsetY;
		posX = ((*itTiles)->getPosX()-(*itTiles)->getPosY()) * gameSettings->getTileSize() + gameSettings->getScreenWidth() / 2 + offsetX;	//comienzo a dibujar de la mitad de la pantalla

		if ((*itTiles)->getSeen()){
			if ( (*itTiles)->getFogged()) {
				this->picassoHelper->renderFogOfWar(this->gameSettings->getPathOfFoggedTile(),posX,posY, gameSettings->getTileSize() * 2+2, gameSettings->getTileSize()+1);
			}
		} else {
			this->picassoHelper->renderObject(this->gameSettings->getPathOfCoveredTile(),posX,posY, gameSettings->getTileSize() * 2+2, gameSettings->getTileSize()+1);
		}
	}
}

void JuegoVista::drawMenu() {
	this->menuVista->drawMe();
}

void JuegoVista::drawIsometricMap(){
	int posX = 0;
	int posY = 0;
	int offsetX = this->getOffset()->first;
	int offsetY = this->getOffset()->second;

	for(list<TileVista*>::iterator itTiles = this->tiles.begin(); itTiles!=this->tiles.end(); ++itTiles){
		if ((*itTiles)->getSeen()){
			posY = ((*itTiles)->getPosX()+(*itTiles)->getPosY()) * gameSettings->getTileSize() / 2 + offsetY;
			posX = ((*itTiles)->getPosX()-(*itTiles)->getPosY()) * gameSettings->getTileSize() + gameSettings->getScreenWidth() / 2 + offsetX;	//comienzo a dibujar de la mitad de la pantalla
			string pathImageTile = (*itTiles)->getPathImage();
			if ( find(this->tilesForBuilding.begin(),this->tilesForBuilding.end(),make_pair((*itTiles)->getPosX(),(*itTiles)->getPosY())) != this->tilesForBuilding.end() ) {
				//El tile esta en la lista de los "pre-seleccionados" para construir el edificio
				pathImageTile = DefaultSettings::getPathTileAvailable(this->availablePosForBuilding);
			}
			this->picassoHelper->renderObject(pathImageTile,posX,posY, gameSettings->getTileSize() * 2, gameSettings->getTileSize());
			for(map<int,EntidadEstaticaVista*>::iterator itEstaticos = this->buildings.begin(); itEstaticos!=this->buildings.end(); ++itEstaticos){
				pair<int,int> posicionEstaticos = (*itEstaticos).second->getPosition();
				if ( ( posicionEstaticos.first == (*itTiles)->getPosX() ) && ( posicionEstaticos.second == (*itTiles)->getPosY() ) ){
					(*itEstaticos).second->saw();
				}
			}
		}
	}
}

void JuegoVista::drawStaticEntities(int runCycles){
	pair<int,int> isometricPosition;
	int offSetX = this->getOffset()->first;
	int offSetY = this->getOffset()->second;

	for(map<int,EntidadEstaticaVista*>::iterator itEstaticos = this->buildings.begin(); itEstaticos!=this->buildings.end(); ++itEstaticos){
		EntidadEstaticaVista* entidad = (*itEstaticos).second;
		if (entidad->getSeen()) {
			isometricPosition = UtilsController::GetInstance()->getIsometricPosition(entidad);
			entidad->drawMe(isometricPosition,offSetX,offSetY,runCycles);
		}
	}
}

void JuegoVista::drawDinamicEntities(int runCycles){
	EntidadDinamicaVista* entidad;
	for(map<int,EntidadDinamicaVista*>::iterator itDinamicos = this->personajes.begin(); itDinamicos!=this->personajes.end(); ++itDinamicos){
		entidad = (*itDinamicos).second;
		entidad->trasladarse();
		if(isEnemyEntityVisible(entidad->getPosition())){
			entidad->drawMe(this->getOffset(), runCycles);
		}
	}
}

void JuegoVista::drawSemiStaticsEntities(int runCycles){
	for(map<int,EntidadSemiEstaticaVista*>::iterator itSemiStatics = this->semiEstaticos.begin(); itSemiStatics!=this->semiEstaticos.end(); ++itSemiStatics){
		EntidadSemiEstaticaVista* entidad = (*itSemiStatics).second;
		entidad->drawMe(UtilsController::GetInstance()->getIsometricPosition(entidad), this->getOffset(), runCycles);
	}
}

void JuegoVista::updateOffset(int offsetX,int offsetY){
	this->offset.first = offsetX;
	this->offset.second = offsetY;
}

pair<int,int>* JuegoVista::getOffset(){
	return &this->offset;
}

void JuegoVista::addTile(string surface, int x, int y){
	//TODO validar path valido sino poner por default, quizas deberia estar en el server la validacion
	TileVista* newtile = new TileVista(x,y);
	newtile->setPathImage(gameSettings->getEntityConfig(surface)->getPath());
	this->tiles.push_back(newtile);
}

void JuegoVista::addStaticEntity(int id, string type, int x, int y, string owner,int health, bool completed, string typeEntity){
	//nueva entidad estática
	if ( this->buildings.find(id) == this->buildings.end() ) {
		EntidadEstaticaVista *newBuilding = new EntidadEstaticaVista(gameSettings->getEntityConfig(type)->getAncho(),
																	gameSettings->getEntityConfig(type)->getAlto());
		newBuilding->setName(type);
		newBuilding->setPosition(x,y);
		newBuilding->setId(id);
		newBuilding->setOwner(owner);
		newBuilding->setHealth(health);
		newBuilding->setBuildingCompleted(true);
		string pathImage="";
		if( type == "flag" ){
			pathImage = getPathFlagImage(this->coloursOfClients[owner]);
		}else{
			pathImage = gameSettings->getEntityConfig(type)->getPath();
		}
		newBuilding->setPathImage(pathImage);

		this->buildings.insert(make_pair(id,newBuilding));
	
	//update de entidad estática
	} else {
		EntidadEstaticaVista* building = this->buildings.at(id);
		if (building->getHealth() > health && building->getOwner() == GameSettings::GetInstance()->getUserName()){
			Mixer::GetInstance()->playEffect();
		} else if ( building->getHealth() < health && building->getOwner() == GameSettings::GetInstance()->getUserName() && typeEntity == "edificios" ) {
			Mixer::GetInstance()->playConstruction();
		}

		if(building->getName()=="food"){
			building->setPathImage("../../Taller/Images/Resources/cowRed.png");
		}
		building->setOwner(owner);
		building->setHealth(health);
		building->setBuildingCompleted(completed);


	}
}

void JuegoVista::addSemiEstaticEntity(int id, string type, int x, int y, string owner,int health, bool completed){
	if ( this->semiEstaticos.find(id) == this->semiEstaticos.end() ) {
		EntidadSemiEstaticaVista* newSemiStatic = new EntidadSemiEstaticaVista(	gameSettings->getEntityConfig(type)->getAncho(),
																				gameSettings->getEntityConfig(type)->getAlto(),
																				gameSettings->getEntityConfig(type)->getPixelsDimension(),
																				gameSettings->getEntityConfig(type)->getPixelsDimension(),
																				gameSettings->getEntityConfig(type)->getFps());
		newSemiStatic->setHealth(health);
		newSemiStatic->setName(type);
		newSemiStatic->setPosition(x,y);
		newSemiStatic->setPathImage(gameSettings->getEntityConfig(type)->getPath());
		newSemiStatic->setDelay(gameSettings->getEntityConfig(type)->getDelay());
		newSemiStatic->setFramesInLineFile(gameSettings->getEntityConfig(type)->getTotalFramesLine());
		newSemiStatic->setId(id);
		newSemiStatic->setOwner(owner);
		newSemiStatic->setBuildingCompleted(completed);
		this->semiEstaticos.insert(make_pair(id,newSemiStatic));
	} else {
		//Entidad ya existia y ahora cambia de dueño
		EntidadSemiEstaticaVista* newSemiStatic = this->semiEstaticos.at(id);
		if (newSemiStatic->getHealth() > health && newSemiStatic->getOwner() == GameSettings::GetInstance()->getUserName()){
			Mixer::GetInstance()->playEffect();
		}
		newSemiStatic->setOwner(owner);
		newSemiStatic->setHealth(health);
		newSemiStatic->setBuildingCompleted(completed);
	}
}

void JuegoVista::addDinamicEntity(int id, string type, int x, int y, int active, string owner,int health,int strength,float precision, int targetID){
	if ( this->personajes.find(id) == this->personajes.end() ) {
		//Nueva entidad
		EntidadDinamicaVista* newPersonaje = new EntidadDinamicaVista(	gameSettings->getEntityConfig(type)->getName(),
																		gameSettings->getEntityConfig(type)->getPixelsDimension(),
																		gameSettings->getEntityConfig(type)->getPixelsDimension(),
																		gameSettings->getEntityConfig(type)->getFps());
		//seteo atributos
		newPersonaje->setName(type);
		newPersonaje->setPosition(x,y);
		newPersonaje->setOwner(owner);
		newPersonaje->setHealth(health);
		newPersonaje->setStrength(health);
		newPersonaje->setPrecision(precision);
		//agrego la posicion inicial de pantalla
		pair<float,float> initialScreenPos = UtilsController::GetInstance()->getIsometricPosition(x,y);
		newPersonaje->setInitialScreenPosition(initialScreenPos.first,initialScreenPos.second);
		newPersonaje->setPathImage(gameSettings->getEntityConfig(type)->getPath());

		newPersonaje->setDelay(gameSettings->getEntityConfig(type)->getDelay());
		newPersonaje->setFramesInLineFile(gameSettings->getEntityConfig(type)->getTotalFramesLine());
		newPersonaje->setId(id);
		this->personajes.insert(make_pair(id,newPersonaje));
	} else {
		EntidadDinamicaVista* myPersonaje = this->personajes.at(id);
		if (myPersonaje->getHealth() > health && myPersonaje->getOwner() == GameSettings::GetInstance()->getUserName()){
			Mixer::GetInstance()->playEffect();
		}
		myPersonaje->setOwner(owner);
		myPersonaje->setHealth(health);
		if(targetID==0){
			myPersonaje->prepareToFight(false);
			myPersonaje->setTarget(NULL);
		}
	}
}

void JuegoVista::drawMiniMap() {
	//dibujo el minimap
	for(list<TileVista*>::iterator itTiles = this->tiles.begin(); itTiles!=this->tiles.end(); ++itTiles){
		this->miniMapVista->renderTile(this->miniMapVista->getMiniTilePath(),(*itTiles)->getPosition());
	}

	//dibujo las entidades estaticas
	for(map<int,EntidadEstaticaVista*>::iterator itEstaticos = this->buildings.begin(); itEstaticos!=this->buildings.end(); ++itEstaticos){
		EntidadEstaticaVista* entidad = (*itEstaticos).second;
		colour colourClient = this->coloursOfClients[entidad->getOwner()];
		this->miniMapVista->renderEntity(DefaultSettings::getPathTileColour(convertColourToString(colourClient)), entidad);
	}

	//dibujo los semi estaticos
	for(map<int,EntidadSemiEstaticaVista*>::iterator itSemiStatics = this->semiEstaticos.begin(); itSemiStatics!=this->semiEstaticos.end(); ++itSemiStatics){
		EntidadSemiEstaticaVista* entidad = (*itSemiStatics).second;
		colour colourClient = this->coloursOfClients[entidad->getOwner()];
		this->miniMapVista->renderEntity(DefaultSettings::getPathTileColour(convertColourToString(colourClient)), entidad);
	}

	//dibujo los personajes
	for(map<int,EntidadDinamicaVista*>::iterator itDinamicos = this->personajes.begin(); itDinamicos!=this->personajes.end(); ++itDinamicos){
		EntidadDinamicaVista* entidad = (*itDinamicos).second;
		colour colourClient = this->coloursOfClients[entidad->getOwner()];
		this->miniMapVista->renderEntity(DefaultSettings::getPathTileColour(convertColourToString(colourClient)), entidad);
	}
	for(list<TileVista*>::iterator itTiles = this->tiles.begin(); itTiles!=this->tiles.end(); ++itTiles){
		if ((*itTiles)->getSeen()){
			if ( (*itTiles)->getFogged()) {
				this->miniMapVista->renderTile(this->gameSettings->getPathOfFoggedTile(),(*itTiles)->getPosition());
			}
		} else {
			this->miniMapVista->renderTile(this->miniMapVista->getMiniUnseenTilePath(),(*itTiles)->getPosition());
		}
	}
}

map<int,EntidadDinamicaVista*>* JuegoVista::getPersonajes(){
	return &this->personajes;
}

EntidadPartidaVista* JuegoVista::getEntityById(int id){
	map<int, EntidadEstaticaVista*>::iterator itBuildings = this->buildings.find(id);
	if( itBuildings != this->buildings.end()){
		return itBuildings->second;
	}
	map<int, EntidadSemiEstaticaVista*>::iterator itSemiEstaticos = this->semiEstaticos.find(id);
	if( itSemiEstaticos != this->semiEstaticos.end()){
		return itSemiEstaticos->second;
	}
	map<int, EntidadDinamicaVista*>::iterator itPersonajes = this->personajes.find(id);
	if( itPersonajes != this->personajes.end()){
		return itPersonajes->second;
	}
	return NULL;
}

EntidadDinamicaVista* JuegoVista::getDinamicEntityById(int id){
	map<int,EntidadDinamicaVista*>::iterator itPersonajes = this->personajes.find(id);
	if(itPersonajes!=this->personajes.end()){
		return itPersonajes->second;
	}
	return NULL;
}

map<string,string> JuegoVista::getEntityAttributes(EntidadPartidaVista* entidad){
	map<string,string> mapInThisPosition = map<string,string>();
	stringstream ss;
	ss.str("");
	ss << entidad->getId();
	mapInThisPosition.insert(make_pair("id",ss.str()));
	mapInThisPosition.insert(make_pair("name", entidad->getName()));
	mapInThisPosition.insert(make_pair("path", entidad->getPathImage()));
	mapInThisPosition.insert(make_pair("owner", entidad->getOwner()));
	ss.str("");
	ss << entidad->getHealth();
	mapInThisPosition.insert(make_pair("health", ss.str()));
	return mapInThisPosition;
}

void JuegoVista::deleteEntityById(int id){
	map<int, EntidadDinamicaVista*>::iterator itEnemy = this->personajes.find(id);
	if( itEnemy != this->personajes.end() ){
		Mixer::GetInstance()->playDeath();
		this->personajes.erase(itEnemy);
		return;		
	}
	map<int,EntidadEstaticaVista*>::iterator itEstaticos = this->buildings.find(id);
	if( itEstaticos != this->buildings.end() ){
		this->buildings.erase(itEstaticos);
		return;
	}
}

map<string,string> JuegoVista::getEntityAt(pair<int,int> position){
	int x = position.first;
	int y = position.second;
	for(map<int,EntidadDinamicaVista*>::iterator itDinamicos = this->personajes.begin(); itDinamicos!=this->personajes.end(); ++itDinamicos){
		pair<int,int> entityPosition = (*itDinamicos).second->getPosition();
		if(entityPosition.first==x && entityPosition.second==y){
			return this->getEntityAttributes((*itDinamicos).second);
		}
	}
	for(map<int,EntidadEstaticaVista*>::iterator itEstaticos = this->buildings.begin(); itEstaticos!=this->buildings.end(); ++itEstaticos){
		pair<int,int> entityPosition = (*itEstaticos).second->getPosition();
		int width = (*itEstaticos).second->getWidth();
		int length = (*itEstaticos).second->getLength();
		if(entityPosition.first<=x and (entityPosition.first+width-1)>=x){
			if(entityPosition.second<=y and (entityPosition.second+length-1)>=y){
				return this->getEntityAttributes((*itEstaticos).second);
			}
		}
	}
	for(map<int,EntidadSemiEstaticaVista*>::iterator itSemiDinamicos = this->semiEstaticos.begin(); itSemiDinamicos!=this->semiEstaticos.end(); ++itSemiDinamicos){
		pair<int,int> entityPosition = (*itSemiDinamicos).second->getPosition();
		if(entityPosition.first==x && entityPosition.second==y){
			return this->getEntityAttributes((*itSemiDinamicos).second);
		}
	}
	return map<string,string>();
}

void JuegoVista::setVisibleTile(int x,int y) {
	for (list<TileVista* >::iterator it = tiles.begin(); it != tiles.end(); ++it) {
		if ( (x == (*it)->getPosX()) && (y == (*it)->getPosY())) {
			(*it)->saw();
		}
	}
}

void JuegoVista::setFoggedTiles(string userName) {
	for(list<TileVista*>::iterator itTiles = this->tiles.begin(); itTiles!=this->tiles.end(); ++itTiles){
		if ((*itTiles)->getSeen()) {
			(*itTiles)->setFogged(true);
		}
	}

	for(map<int,EntidadDinamicaVista*>::iterator itDinamicos = this->personajes.begin(); itDinamicos!=this->personajes.end(); ++itDinamicos){
		EntidadDinamicaVista * entidad = (*itDinamicos).second;
		if(entidad->getOwner()==userName){
			pair<int,int> position = entidad->getPosition();
				int rangeEntity = this->gameSettings->getRangeVisibility();// TODO aca se deberia usar entidad->getRangeVisibility(), para esto cada entidad deberia saber su rango de visibilidad
				for (int x = position.first - rangeEntity; x <= position.first + rangeEntity; x++) {
					if ( (x>=0) && (x < gameSettings->getMapWidth())) {
						for (int y = position.second-rangeEntity ; y <= position.second+rangeEntity ; y++) {
							if ((y>=0) && (y < this->gameSettings->getMapHeight())) {
								if((x+y >= position.first + position.second - rangeEntity) && (x+y <= position.first + position.second + rangeEntity)
								&& (x-y >= position.first - position.second - rangeEntity) && (x-y <= position.first - position.second + rangeEntity)) {
									for(list<TileVista*>::iterator itTiles = this->tiles.begin(); itTiles!=this->tiles.end(); ++itTiles){
										if ((*itTiles)->getFogged() && (*itTiles)->getPosX() == x && (*itTiles)->getPosY() == y) {
											(*itTiles)->setFogged(false);
										}
									}
								}
							}
						}
					}
				}
		}
	}
}

bool JuegoVista::isEnemyEntityVisible(pair< int, int> pos) {
	for(list<TileVista*>::iterator itTiles = this->tiles.begin(); itTiles!=this->tiles.end(); ++itTiles){
		if ((*itTiles)->getFogged() && (*itTiles)->getPosX() == pos.first && (*itTiles)->getPosY() == pos.second) return false;
	}
	return true;
}

void JuegoVista::drawResources(ResourceCounter* resourceCounter) {
	map<string,int> resources;
	resources["food"] = resourceCounter->getFood();
	resources["wood"] = resourceCounter->getWood();
	resources["gold"] = resourceCounter->getGold();
	resources["rock"] = resourceCounter->getRock();
	this->menuVista->drawResources(resources);
}

void JuegoVista::setColour(string owner,int iColour) {
	colour c = static_cast<colour>(iColour);
	this->coloursOfClients[owner] = c;
}

void JuegoVista::deleteEntitiesOfClient(string clientName){
	for(map<int,EntidadDinamicaVista*>::iterator itDinamicos = this->personajes.begin(); itDinamicos!=this->personajes.end(); ++itDinamicos){
		if(itDinamicos->second->getOwner()==clientName){
			this->personajes.erase(itDinamicos);
		}
	}
}

string JuegoVista::getPathFlagImage(colour colorClient){
	return DefaultSettings::getPathFlagImage(this->convertColourToString(colorClient));
}

string JuegoVista::convertColourToString(colour colorClient){
	switch(colorClient){
	case red: return "red";
	case blue: return "blue";
	case yellow: return "yellow";
	case lightGreen: return "lightGreen";
	default: return "";
	}
}

void JuegoVista::setResourceCounter(ResourceCounter* resourceCounter) {
	this->resourceCounter = resourceCounter;
}

ResourceCounter* JuegoVista::getResourceCounter() {
	return this->resourceCounter ;
}

void JuegoVista::addTileForBuilding(int x, int y){
	if(x < 0 || y < 0 || y >= this->gameSettings->getMapHeight() || x >= this->gameSettings->getMapWidth()){
		this->availablePosForBuilding = false;
	}else{
		this->tilesForBuilding.push_back(make_pair(x,y));
		if( ((this->getEntityAt(make_pair(x,y))).size() > 0) ){
			this->availablePosForBuilding = false;
		}
	}
}

void JuegoVista::clearTilesForBuilding(){
	this->availablePosForBuilding = true;
	this->tilesForBuilding.clear();
}

void JuegoVista::clearAllDataForBuilding(){
	this->entityForBuild = "";
	this->clearTilesForBuilding();
}

bool JuegoVista::isAvailablePosForBuild(){
	return this->availablePosForBuilding;
}

void JuegoVista::setEntityForBuild(string entityName){
	this->entityForBuild = entityName;
}

void JuegoVista::entitiesToRenderInMenu(list<EntidadPartidaVista*> entities, string client) {
	map<EntidadPartidaVista*,int> map;
	for (list<EntidadPartidaVista*>::iterator itList = entities.begin(); itList != entities.end() ; ++itList) {
		map[(*itList)]++;
		if (	((*itList)->getName() == "Barracks" ||
				(*itList)->getName() == "Castle" ||
				(*itList)->getName() == "aldeano" ) &&
				(*itList)->getOwner() == client)
			this->menuVista->setCreatorEntitySelected((*itList));
	}
	this->menuVista->setSelectedEntities(map);
}

JuegoVista::~JuegoVista() {
//	this->picassoHelper()->~PicassoHelper();
	delete(this->menuVista);
	this->menuVista=NULL;
	delete(this->miniMapVista);
	this->miniMapVista=NULL;
	delete(this->picassoHelper);
	this->picassoHelper=NULL;
	this->gameSettings=NULL;
	this->resourceCounter=NULL;
}
