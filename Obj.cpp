#include "Obj.h"

void Obj::Update() {

};
void Obj::Draw() {

};
void Obj::SetPosition(Vector2 pos) {
	pos_ = pos;
}
void  Obj::SetSpeed(Vector2 speed) {
	speed_ = speed;
}
void  Obj::SetRadius(float radius) {
	radius_ = radius;
}
void Obj::SetIsHit(bool isHit) {
	isHit_ = isHit;
}