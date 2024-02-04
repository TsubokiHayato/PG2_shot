#pragma once
#include<Vector2.h>
class Obj//基底クラス
{
protected:
	Vector2 pos_ = {};
	Vector2 speed_ = {};
	float radius_ = 0;
	Vector2 bullet_ = {};
	
	bool isHit_ = false;
public:

	virtual void Update();
	virtual void Draw();

	virtual Vector2 GetPos() { return pos_; };
	virtual Vector2 GetSpeed() { return speed_; };
	virtual float GetRadius() { return radius_; };
	virtual bool GetIsHit(){return isHit_;};

	virtual void SetPosition(Vector2 pos);
	virtual void SetSpeed(Vector2 speed);
	virtual void SetRadius(float radius);
	virtual void SetIsHit(bool isHit);

};

