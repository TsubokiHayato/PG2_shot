#pragma once
#include "Obj.h"

class Player : public Obj {
public:

	void Update()override;
	void Draw()override;

	Player();

	enum ShotMode {
		Fire,//連射
		charge//溜め
	};
	int shotMode;
	bool isShot = false;
	int bullet_radius;
	bool isDead = false;

	//intVector2 mouse;


	Vector2 GetPos() { return pos_; };
	Vector2 GetBulletPos() { return bullet_; };
	Vector2 GetSpeed() { return speed_; };
	float GetRadius() { return radius_; };

	void SetPosition(Vector2 pos);
	void SetBulletPosition(Vector2 bulletPos);
	void SetSpeed(Vector2 speed);
	void SetRadius(float radius);

};

