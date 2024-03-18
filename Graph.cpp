#include "Graph.h"




void Edge::setDestination(int destination) {
	this->destination = destination;
}

void Edge::setWeight(int weight) {
	this->weight = weight;
}

int Edge::getDestination() {
	return destination;
}

int Edge::getWeight() {
	return weight;
}