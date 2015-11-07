/*
 * ResourceCounter.cpp
 *
 *  Created on: Oct 28, 2015
 *      Author: juan
 */

#include "../../Headers/Modelo/ResourceCounter.h"

ResourceCounter::ResourceCounter() {
	int cantInicial = 10;

	this->alimento = cantInicial;
	this->oro = cantInicial;
	this->madera = cantInicial;
	this->roca = cantInicial;

}

void ResourceCounter::recolectarAlimento(){
	this->alimento++;
}

void ResourceCounter::recolectarMadera(){
	this->madera++;
}

void ResourceCounter::recolectarOro(){
	this->oro++;
}

void ResourceCounter::recolectar(string recurso){
	if(recurso == "gold")
		this->oro++;
	if(recurso == "wood")
		this->madera++;
	if(recurso == "chori")
		this->alimento++;
	if(recurso == "rock")
		this->roca++;
}

int ResourceCounter::getOro(){
	return this->oro;
}

int ResourceCounter::getAlimento(){
	return this->alimento;
}

int ResourceCounter::getMadera(){
	return this->madera;
}

int ResourceCounter::getRoca(){
	return this->roca;
}

ResourceCounter::~ResourceCounter() {
	// TODO Auto-generated destructor stub
}

