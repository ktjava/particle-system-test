/*
 * particle.h
 *
 *  Created on: 2016/12/24
 *      Author: tomokuni
 */

#ifndef SRC_PARTICLE_H_
#define SRC_PARTICLE_H_

#include "ofMain.h"
#include "ofMath.h"
#include <cmath>

#define GRAVITY_COEF 0.0000001

class Particle{
	public:
		Particle(float posX, float posY, float velX, float velY, float r);
		void update(ofVec2f mousePosition, bool mouseLeftPressedFlag, bool mouseRightPressedFlag);
		void draw();
	private:
		ofVec2f	position,velocity,acceleration;
		float	radius;
};

#endif /* SRC_PARTICLE_H_ */
