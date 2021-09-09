#pragma once
#include "GameStateBase.h"

class Sprite2D;
class Sprite3D;
class Text;
class GameButton;

#define KEY_RIGHT 39
#define KEY_LEFT  37
#define KEY_UP    38
#define KEY_DOWN  40


class GSPlay : public GameStateBase
{
public:
	GSPlay();
	~GSPlay();

	void	Init() override;
	void	Exit() override;

	void	Pause() override;
	void	Resume() override;

	void	HandleEvents() override;
	void	HandleKeyEvents(int key, bool bIsPressed) override;
	void	HandleTouchEvents(int x, int y, bool bIsPressed) override;
	void	HandleMouseMoveEvents(int x, int y) override;
	void	Update(float deltaTime) override;
	void	Draw() override;

private:
	std::shared_ptr<Sprite2D>	m_background;
	std::shared_ptr<Text>		m_score;
	std::shared_ptr<Sprite2D>   m_player;
	std::vector<std::shared_ptr<Sprite2D>> m_bullet;
	std::vector<std::shared_ptr<Sprite2D>> m_MonsterList;
	std::list<std::shared_ptr<GameButton>>	m_listButton;

};

