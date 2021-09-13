#pragma once
#include "BaseObject.h"

struct SpriteRect
{
	int x_;
	int y_;
	int w;
	int h;
};


class Sprite2D : public BaseObject
{
protected:
	GLint		m_iWidth;
	GLint		m_iHeight;
	GLuint		m_vboId;
	bool        m_bBulletAlive;
	bool        m_bMonsterAlive;
	bool        m_bPlayerAlive;
public:
	Sprite2D() : BaseObject(), m_iWidth(0), m_iHeight(0), m_vboId(0) {}
	Sprite2D(GLint id, std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture);
	Sprite2D(GLint id, std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, Vector4 color);
	Sprite2D(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture);
	~Sprite2D();

	void		Init() override;
	void		Draw() override;
	void		Update(GLfloat deltatime) override;
	void		MovingBullet(GLfloat);
	void        MovingMonster(GLfloat xVal);

	bool        GetIsAliveBullet() { return m_bBulletAlive; }
	bool        GetIsAliveMonster() { return m_bMonsterAlive; }
	bool        GetIsAlivePlayer() { return m_bPlayerAlive; }

	void        SetIsAliveMonster(bool b) { m_bMonsterAlive = b; }
	void        SetIsAliveBullet(bool b) { m_bBulletAlive = b; }
	void        SetIsAlivePlayer(bool b) { m_bPlayerAlive = b; }


	bool        CheckCollision(std::shared_ptr<Sprite2D> pObj);
	bool        CheckCollision(const SpriteRect& object1, const SpriteRect& object2);

	void		Set2DPosition(GLfloat x, GLfloat y);
	void		Set2DPosition(Vector2 position);
	void		SetSize(GLint width, GLint height);
	GLint       GetWidth() const { return m_iWidth; }
	GLint       GetHeight() const { return m_iHeight; }
	void		AddX(GLfloat x);
	void        SubX(GLfloat x);
	void		AddY(GLfloat y);
	void		SubY(GLfloat y);
};

