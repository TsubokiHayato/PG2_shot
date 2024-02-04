#include "Player.h"
#include"Novice.h"

Player::Player() {
	pos_.x = 640.0f;
	pos_.y = 650.0f;
	speed_.x = 8.0f;
	speed_.y = 8.0f;
	radius_ = 32.0f;
	bullet_radius = 0;
	shotMode = Fire;

	bullet_.x = -100.0f;
	bullet_.y = -100.0f;
	isShot = false;

}

void Player::Update() {
	char keys[256] = {};
	char preKeys[256] = {};
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);

	if (!isDead) {
		//key入力
		if (keys[DIK_A]) {
			pos_.x -= speed_.x;
		}
		if (keys[DIK_D]) {
			pos_.x += speed_.x;
		}
		if (keys[DIK_W]) {
			pos_.y -= speed_.y;
		}
		if (keys[DIK_S]) {
			pos_.y += speed_.y;
		}
		if (keys[DIK_Q] && !preKeys[DIK_Q]) {

			shotMode = Fire;

		}
		if (keys[DIK_E] && !preKeys[DIK_E]) {

			shotMode = charge;
			bullet_radius = 0;

		}

		switch (shotMode)
		{
		case Fire://連射
			if (!isShot) {
				if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
					isShot = true;
					bullet_radius = 12;
					bullet_ = pos_;
				}
			}

			//
			if (isShot) {

				bullet_.y -= speed_.y * 2;
				if (bullet_.y <= -16.0f) {
					isShot = false;
				}

			}


			break;

		case charge:
			if (!isShot) {

				if (keys[DIK_SPACE]) {
					bullet_.x = pos_.x;
					bullet_.y = pos_.y - bullet_radius - 12;
					if (bullet_radius < 120) {
						bullet_radius++;
					}
				}
				if (!keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {

					isShot = true;
				}
			}

			if (isShot) {

				bullet_.y -= speed_.y * 2;
				if (bullet_.y <= -16.0f) {
					bullet_radius = 0;
					isShot = false;
				}

			}
			break;
		}
	}
	
}
void Player::Draw() {
	if (!isDead) {
		if (isShot) {
			//弾
			Novice::DrawEllipse((int)bullet_.x, (int)bullet_.y, (int)bullet_radius / 2, (int)bullet_radius / 2, 0.0f, 0xff44ffff, kFillModeSolid);
		}
		//プレイヤー
		Novice::DrawEllipse((int)pos_.x, (int)pos_.y, (int)radius_, (int)radius_, 0.0f, 0xffffffff, kFillModeSolid);
	}
}


void Player::SetPosition(Vector2 pos) {
	pos_ = pos;
}

void Player::SetSpeed(Vector2 speed) {
	speed_ = speed;
}
void Player::SetRadius(float radius) {
	radius_ = radius;
}

void Player::SetBulletPosition(Vector2 bulletPos) {
	bullet_ = bulletPos;
}