#include "GSMenu.h"
#include "Camera.h"

GSMenu::GSMenu() : GameStateBase(StateType::STATE_MENU), 
	m_background(nullptr), m_listButton(std::list<std::shared_ptr<GameButton>>{}), m_textGameName(nullptr)
{
}


GSMenu::~GSMenu()
{
}



void GSMenu::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg_main_menu.tga");

	// background
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);

	// play button
	texture = ResourceManagers::GetInstance()->GetTexture("btn_play.tga");
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2);
	button->SetSize(200, 200);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PLAY);
		});
	m_listButton.push_back(button);
	// option button
	texture = ResourceManagers::GetInstance()->GetTexture("btn_menu.tga");
	std::shared_ptr<GameButton> button_menu = std::make_shared<GameButton>(model, shader, texture);
	button_menu->Set2DPosition(240, 600);
	button_menu->SetSize(55, 55);
	button_menu->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_OPTION);
		});
	m_listButton.push_back(button_menu);
	// credit button
	texture = ResourceManagers::GetInstance()->GetTexture("btn_help.tga");
	std::shared_ptr<GameButton> button_credit = std::make_shared<GameButton>(model, shader, texture);
	button_credit->Set2DPosition(240, 700);
	button_credit->SetSize(55, 55);
	button_credit->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_CREDIT);
		});
	m_listButton.push_back(button_credit);

	// exit button
	texture = ResourceManagers::GetInstance()->GetTexture("btn_close.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth - 50, 50);
	button->SetSize(50, 50);
	button->SetOnClick([]() {
		exit(0);
		});
	m_listButton.push_back(button);

	// game title
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Brightly Crush Shine.otf");
	m_textGameName = std::make_shared< Text>(shader, font, "NMH-Songoku", Vector4(0.0f, 0.5f, 0.0f, 5.0f), 3.0f);
	m_textGamePlay = std::make_shared< Text>(shader, font, "Play", Vector4(0.5f, 0.5f, 0.0f, 1.0f), 1.0f);
	m_textGameOption = std::make_shared< Text>(shader, font, "Option", Vector4(0.5f, 0.5f, 0.0f, 1.0f), 1.0f);
	m_textGameCredit = std::make_shared< Text>(shader, font, "Credit", Vector4(0.5f, 0.5f, 0.0f, 1.0f), 1.0f);

	m_textGameName->Set2DPosition(Vector2(15, 230));
	m_textGamePlay->Set2DPosition(Vector2(75, 400));
	m_textGameOption->Set2DPosition(Vector2(130, 610));
	m_textGameCredit->Set2DPosition(Vector2(130, 710));
}

void GSMenu::Exit()
{
}


void GSMenu::Pause()
{
}

void GSMenu::Resume()
{
}


void GSMenu::HandleEvents()
{
}

void GSMenu::HandleKeyEvents(int key, bool bIsPressed)
{
}

void GSMenu::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if (button->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}
}

void GSMenu::HandleMouseMoveEvents(int x, int y)
{
}

void GSMenu::Update(float deltaTime)
{
	m_background->Update(deltaTime);
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}

void GSMenu::Draw()
{
	m_background->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	m_textGameName->Draw();
	m_textGamePlay->Draw();
	m_textGameOption->Draw();
	m_textGameCredit->Draw();
}
