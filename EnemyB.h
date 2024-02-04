#pragma once
#include "Obj.h"
class EnemyB : public Obj
{
public:
   

    void Update()override;
    void Draw()override;
    EnemyB();

	Vector2 GetPos() { return pos_; };
	Vector2 GetSpeed() { return speed_; };
	float GetRadius() { return radius_; };
	bool GetIsHit() { return isHit_; };

	void SetPosition(Vector2 pos)override;
	void SetSpeed(Vector2 speed)override;
	void SetRadius(float radius)override;
	void SetIsHit(bool isHit)override;

};

