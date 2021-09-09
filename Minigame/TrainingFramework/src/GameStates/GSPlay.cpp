#include "GSPlay.h"
#include "Shader.h"
#include "Texture.h"
#include "Model.h"
#include "Camera.h"
#include "Font.h"
#include "Sprite2D.h"
#include "Sprite3D.h"
#include "Text.h"
#include "GameButton.h"

#define NUM_MONSTER 5

// Offset nham tao ra cac vi tri truoc sau, tren duoi, chu ko xuat hien cung mot thoi diem.
int offsetX[NUM_MONSTER] = { 100, 200, 300, 150, 250 };  // Offset vi tri xuat hien cua monster theo truc X
int offsetY[NUM_MONSTER] = { 100, -100, 250, -250, 400 }; // Offset vi tri xuat hien cua monster theo truc Y.

// Ten cac monster tao su da dang.
std::string MonsterList[NUM_MONSTER] = { "cell_160.tga", "Frieza.tga",
                                          "cell_160.tga", "Frieza.tga", "cell_160.tga" };

GSPlay::GSPlay()
{

}


GSPlay::~GSPlay()
{
}


void GSPlay::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg_play1.tga");
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");

	// background
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition((float)Globals::screenWidth / 2, (float)Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);

	// player
	auto model_player = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	texture = ResourceManagers::GetInstance()->GetTexture("goku_180.tga");
	m_player = std::make_shared<Sprite2D>(model_player, shader, texture);
	m_player->Set2DPosition(100.0, 300.0);
	m_player->SetSize(60, 100);

	// Monster
	Vector2 vStart;
	vStart.x = Globals::screenWidth;
	vStart.y = Globals::screenHeight *0.5;

	for (int i = 0; i < NUM_MONSTER; i++)
	{
		auto mModel = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
		auto mTexture = ResourceManagers::GetInstance()->GetTexture(MonsterList[i]);
		std::shared_ptr<Sprite2D> mMonster;
		mMonster = std::make_shared<Sprite2D>(mModel, shader, mTexture);
		mMonster->SetSize(120, 60);
		vStart.x += offsetX[i];
		vStart.y += offsetY[i];

		mMonster->Set2DPosition(vStart);
		m_MonsterList.push_back(mMonster);
	}

	// button clode
	texture = ResourceManagers::GetInstance()->GetTexture("btn_close.tga");
	std::shared_ptr<GameButton>  button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth - 50, 50);
	button->SetSize(50, 50);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->PopState();
		});
	m_listButton.push_back(button);

	// score
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Brightly Crush Shine.otf");
	m_score = std::make_shared< Text>(shader, font, "score: 10", TextColor::BLACK, 1.0);
	m_score->Set2DPosition(Vector2(5, 25));

}

void GSPlay::Exit()
{
}


void GSPlay::Pause()
{

}

void GSPlay::Resume()
{
}


void GSPlay::HandleEvents()
{
}

void GSPlay::HandleKeyEvents(int key, bool bIsPressed)
{
	if (bIsPressed == true)
	{
		if (key == KEY_LEFT)
		{
			// Khi di chuyen trai, phai thi thay do hinh dang goku
			auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
			auto model_player = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
			auto texture1 = ResourceManagers::GetInstance()->GetTexture("goku moving left.tga");

			Vector3 vPos1 = m_player->GetPosition();
			m_player = std::make_shared<Sprite2D>(model_player, shader, texture1);

			m_player->Set2DPosition(vPos1.x, vPos1.y);
			m_player->SetSize(150, 86);

			// di chuyen sang trai voi toc do 35
			m_player->SubX(35);
		}
		else if (key == KEY_RIGHT)
		{
			// Khi di chuyen trai, phai thi thay do hinh dang goku
			auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
			auto model_player = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
			auto texture1 = ResourceManagers::GetInstance()->GetTexture("goku moving_right.tga");

			Vector3 vPos1 = m_player->GetPosition();
			m_player = std::make_shared<Sprite2D>(model_player, shader, texture1);

			m_player->Set2DPosition(vPos1.x, vPos1.y);
			m_player->SetSize(150, 86);

			// di chuyen sang phai voi toc do 35
			m_player->AddX(35);
		}
		else if (key == KEY_UP)
		{
			Vector3 vPos = m_player->GetPosition();
			auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
			auto model_player = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
			auto texture = ResourceManagers::GetInstance()->GetTexture("goku_180.tga");
			m_player = std::make_shared<Sprite2D>(model_player, shader, texture);
			m_player->Set2DPosition(vPos.x, vPos.y);
			m_player->SetSize(60, 100);

			// di chuyen sang trai voi toc do 35
			m_player->SubY(35);
		}
		else if (key == KEY_DOWN)
		{
			Vector3 vPos = m_player->GetPosition();

			auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
			auto model_player = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
			auto texture = ResourceManagers::GetInstance()->GetTexture("goku_180.tga");
			m_player = std::make_shared<Sprite2D>(model_player, shader, texture);
			m_player->Set2DPosition(vPos.x, vPos.y);
			m_player->SetSize(60, 100);

			// di chuyen sang trai voi toc do 35
			m_player->AddY(35);
		}
	}
	else
	{
		Vector3 vPos = m_player->GetPosition();

		auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
		auto model_player = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
		auto texture = ResourceManagers::GetInstance()->GetTexture("goku_180.tga");
		m_player = std::make_shared<Sprite2D>(model_player, shader, texture);
		m_player->Set2DPosition(vPos.x, vPos.y);
		m_player->SetSize(60, 100);
	}
}

void GSPlay::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if(button->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}

	if (bIsPressed == true)
	{
		// Khi ban chuong, thay doi hinh dang cho goku
		auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
		auto model_player = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
		auto texture1 = ResourceManagers::GetInstance()->GetTexture("goku attack.tga");

		Vector3 vPos1 = m_player->GetPosition();
		m_player = std::make_shared<Sprite2D>(model_player, shader, texture1);
		m_player->Set2DPosition(vPos1.x, vPos1.y);
		m_player->SetSize(150, 86);


		// Khi bam chuot xuong.
		// Tao ra doi tung bullet cho Player
		auto mBullet = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
		auto texture = ResourceManagers::GetInstance()->GetTexture("DragonDead.tga");

		int width = m_player->GetWidth();
		int height = m_player->GetHeight();

		std::shared_ptr<Sprite2D>   sBullet;
		sBullet = std::make_shared<Sprite2D>(mBullet, shader, texture);
		sBullet->SetSize(40, 40);

		// Vi tri xuat hien duoc tinh toan dua tren vi tri cua player
		Vector3 vBullet;
		vBullet.x = vPos1.x + width * 0.5 - 10;
		vBullet.y = vPos1.y - 17;
		vBullet.z = vPos1.z;
		sBullet->SetPosition(vBullet);
		m_bullet.push_back(sBullet);  // add vao mang bullet
	}
	else
	{
		// Khi khong ban chuong
		// Tro lai hinh dang binh thuong

		Vector3 vPos = m_player->GetPosition();
		auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
		auto model_player = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
		auto texture = ResourceManagers::GetInstance()->GetTexture("goku_180.tga");
		m_player = std::make_shared<Sprite2D>(model_player, shader, texture);
		m_player->Set2DPosition(vPos.x, vPos.y);
		m_player->SetSize(60, 100);
	}
}

void GSPlay::HandleMouseMoveEvents(int x, int y)
{
}

void GSPlay::Update(float deltaTime)
{
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}

	// Kiem tra trang thai alive cua bullet
	for (int i = 0; i < m_bullet.size(); i++)
	{
		std::shared_ptr<Sprite2D> pBullet = m_bullet.at(i);
		bool bAlive = pBullet->GetIsAliveBullet();
		if (bAlive == true)
		{
			// di chuyen voi toc do 15.0
			pBullet->MovingBullet(15.0);
		}
		else
		{
			// khi di qua screen thi lap tuc xoa bo 
			m_bullet.erase(m_bullet.begin() + i);
		}	
	}

	// Lien tuc kiem tra trang thai alive cua monster
	for (int i = 0; i < m_MonsterList.size(); i++)
	{
		std::shared_ptr<Sprite2D> pMonster = m_MonsterList.at(i);
		bool bAlive = pMonster->GetIsAliveMonster();
		if (bAlive == true)
		{
			// con song thi di chuyen voi toc do 5.0
			pMonster->MovingMonster(5.0);
		}
		else
		{
			// Khi alive = false (chet) (di qua man hinh) thi reset lai vi tri cua monster
			Vector2 vStart;
			vStart.x = Globals::screenWidth;
			vStart.y = Globals::screenHeight * 0.5;
			vStart.x += offsetX[i];
			vStart.y += offsetY[i];
			pMonster->Set2DPosition(vStart);
			pMonster->SetIsAliveMonster(true);
		}
	}
}

void GSPlay::Draw()
{
	m_background->Draw();
	m_score->Draw();
	if (m_player->GetIsAlivePlayer() == true)
	{
		m_player->Draw();
	}
	else
	{
		// Xu ly game over.
		// Tam thoi dang cho quay lai man hinh menu
		for (auto it : m_listButton)
		{
			it->SetGameButton(true);
		}
	}

	// Check va cham giua Monster va Bullet cua Main Player
	for (int ib = 0; ib < m_bullet.size(); ib++)
	{
		std::shared_ptr<Sprite2D> pBullet = m_bullet[ib];

		bool bDestroy = false;
		for (int j = 0; j < m_MonsterList.size(); j++)
		{
			std::shared_ptr<Sprite2D> pMonster = m_MonsterList[j];
			bool bRet = pBullet->CheckCollision(pMonster);
			if (bRet == true)
			{
				pMonster->SetIsAliveMonster(false);
				bDestroy = true;
				break;
			}
		}
		if (bDestroy == true)
		{
			m_bullet.erase(m_bullet.begin() + ib);
		}
		else
		{
			pBullet->Draw();
		}
	}

	// Check va cham giua Player va Monster
	for (auto it : m_MonsterList)
	{

		bool bRet = it->CheckCollision(m_player);
		if (bRet == true)
		{
			// Xay ra va cham thi set thuoc tinh alive cua player = false;
			m_player->SetIsAlivePlayer(false);
			break;
		}

		if (it->GetIsAliveMonster() == true)
		{
			it->Draw();
		}		
	}

	for (auto it : m_listButton)
	{
		it->Draw();
	}
}