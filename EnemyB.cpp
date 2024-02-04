#include "EnemyB.h"
#include<Novice.h>


EnemyB::EnemyB() {
	pos_.x = 640.0f;
	pos_.y = 300.0f;
	radius_ = 32.0f;
	speed_.x = -8.0f;
	speed_.y = 0.0f;
	isHit_ = false;
}
void EnemyB::Update() {
	if (!isHit_) {
		pos_.x += speed_.x;
		if (pos_.x > 1280 - radius_ / 2) {
			speed_.x *= -1;
		}
		if (pos_.x < 0.0f + radius_ / 2) {
			speed_.x *= -1;
		}
	}
}

void EnemyB::Draw() {
	if (!isHit_) {
		Novice::DrawEllipse((int)pos_.x, (int)pos_.y, (int)radius_, (int)radius_, 0.0f, 0x0000ff, kFillModeSolid);
	} else {
		Novice::DrawEllipse((int)pos_.x, (int)pos_.y, (int)radius_, (int)radius_, 0.0f, 0xff0022, kFillModeSolid);
	}
}

void EnemyB::SetPosition(Vector2 pos) {
	pos_ = pos;
}

void EnemyB::SetSpeed(Vector2 speed) {
	speed_ = speed;
}
void EnemyB::SetRadius(float radius) {
	radius_ = radius;
}
void EnemyB::SetIsHit(bool isHit) {
	isHit_ = isHit;
}
