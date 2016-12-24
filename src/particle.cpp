/*
 * particle.cpp
 *
 *  Created on: 2016/12/24
 *      Author: tomokuni
 */

#include "particle.h"

Particle::Particle(float posX, float posY, float velX, float velY, float r) :
	position (posX, posY),
	velocity (velX, velY),
	acceleration (0.0, 0.0),
	radius(r)
{

}

void Particle::update(ofVec2f mousePosition, bool mouseLeftPressedFlag, bool mouseRightPressedFlag){
	float rangeX = mousePosition.x - position.x, rangeY = mousePosition.y - position.y, range = sqrt(rangeX*rangeX+rangeY*rangeY), coefA = GRAVITY_COEF / range*range*range;
	if(mouseRightPressedFlag){
		velocity.x *= 0.92;
		velocity.y *= 0.92;
		position.x += 0.09*rangeX;
		position.y += 0.09*rangeY;
	}else if(mouseLeftPressedFlag){
		velocity.x = ofRandom(-5,5);
		velocity.y = ofRandom(-5,5);
		position += velocity;
	}else{
		acceleration.x = coefA * rangeX;
		acceleration.y = coefA * rangeY;
		velocity += acceleration;
		position += velocity;
	}
}

void Particle::draw(){
	ofDrawRectangle(position.x, position.y, radius, radius);
}
