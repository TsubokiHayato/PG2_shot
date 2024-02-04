#include <Novice.h>
#include"Player.h"
#include "Obj.h"
#include"EnemyA.h"
#include"EnemyB.h"

const char kWindowTitle[] = "学籍番号";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Player* player = new Player();
	Obj* enemies[2];
	enemies[0] = new EnemyA();
	enemies[1] = new EnemyB();

	float distX[2];
	float distY[2];
	float dist[2];
	float radius[2];

	float p_distX[2];
	float p_distY[2];
	float p_dist[2];
	float p_radius[2];
	Vector2 re_pos = {};
	re_pos.x = 640.0f;
	re_pos.y = 650.0f;

	enum Scene {
		title,
		stage
	};
	int sceneNo = title;
	bool isEnemyDead[2] = {};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		switch (sceneNo)
		{
		case title:
			for (int i = 0; i < 2; i++) {
				isEnemyDead[i] = false;
				enemies[i]->SetIsHit(false);
				player->isDead = false;
				player->SetPosition(re_pos);
				
			}
			new Player();

			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
				sceneNo = stage;

			}
			Novice::ScreenPrintf(640, 360, "Push to SPACEKey");
			break;
		case stage:
			player->Update();

			for (int i = 0; i < 2; i++) {
				enemies[i]->Update();
			}
			if (player->isShot) {

				for (int i = 0; i < 2; i++) {
					if (!isEnemyDead[i]) {
						// エネミー同士の当たり判定処理
						distX[i] = (player->GetBulletPos().x - enemies[i]->GetPos().x);
						distY[i] = (player->GetBulletPos().y - enemies[i]->GetPos().y);
						dist[i] = float((distX[i] * distX[i]) + (distY[i] * distY[i]));
						radius[i] = player->bullet_radius + enemies[i]->GetRadius();
						if (dist[i] <= radius[i] * radius[i]) {
							enemies[i]->SetIsHit(true);
							isEnemyDead[i] = true;
							player->isShot = false;
						}
					}
				}
			}

			for (int i = 0; i < 2; i++) {
				if (!isEnemyDead[i]) {
					// プレイヤーの当たり判定処理
					p_distX[i] = (player->GetPos().x - enemies[i]->GetPos().x);
					p_distY[i] = (player->GetPos().y - enemies[i]->GetPos().y);
					p_dist[i] = float((p_distX[i] * p_distX[i]) + (p_distY[i] * p_distY[i]));
					p_radius[i] = player->GetRadius() + enemies[i]->GetRadius();
					if (p_dist[i] <= p_radius[i] * p_radius[i]) {
						player->isDead = true;
						sceneNo = title;
						player->isShot = false;
					}
				}
			}


			if (isEnemyDead[0] && isEnemyDead[1]) {
				sceneNo = title;
			}


			player->Draw();

			for (int i = 0; i < 2; i++) {
				enemies[i]->Draw();
			}

			break;
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///


		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
