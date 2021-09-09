#include "Sprite2D.h"
#include "Shader.h"
#include "Model.h"
#include "Camera.h"
#include "Texture.h"
#include "Application.h"

Sprite2D::Sprite2D(GLint id, std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture)
	: BaseObject(id, model, shader, texture), m_iWidth(100), m_iHeight(50), m_vboId(0)
{
	Init();
}

Sprite2D::Sprite2D(GLint id, std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, Vector4 color)
	: BaseObject(id, model, shader, color), m_iWidth(100), m_iHeight(50), m_vboId(0)
{
	Init();
}

Sprite2D::Sprite2D(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture)
	: BaseObject(-1, model, shader, texture), m_iWidth(100), m_iHeight(50), m_vboId(0)
{
	Init();
}

Sprite2D::~Sprite2D()
{
}

void Sprite2D::Init()
{
	SetCamera(Application::GetInstance()->GetCamera());
	CalculateWorldMatrix();
	m_bBulletAlive = true;
	m_bMonsterAlive = true;
	m_bPlayerAlive = true;
}

void Sprite2D::Draw()
{
	if (m_pCamera == nullptr) return;
	glUseProgram(m_pShader->m_program);
	glBindBuffer(GL_ARRAY_BUFFER, m_pModel->GetVertexObject());
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_pModel->GetIndiceObject());

	GLuint iTempShaderVaribleGLID = -1;
	Matrix wvpMatrix;

	wvpMatrix = m_worldMatrix * m_pCamera->GetLookAtCameraMatrix();

	if (m_pTexture != nullptr)
	{
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, m_pTexture->Get2DTextureAdd());
		if (m_pShader->m_iTextureLoc[0] != -1)
			glUniform1i(m_pShader->m_iTextureLoc[0], 0);
	}
	else
	{
		iTempShaderVaribleGLID = -1;
		iTempShaderVaribleGLID = m_pShader->GetUniformLocation((char*)"u_color");
		if (iTempShaderVaribleGLID != -1)
			glUniform4f(iTempShaderVaribleGLID, m_color.x, m_color.y, m_color.z, m_color.w);
	}


	iTempShaderVaribleGLID = -1;
	iTempShaderVaribleGLID = m_pShader->GetAttribLocation((char*)"a_posL");
	if (iTempShaderVaribleGLID != -1)
	{
		glEnableVertexAttribArray(iTempShaderVaribleGLID);
		glVertexAttribPointer(iTempShaderVaribleGLID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), VETEX_POSITION);
	}

	iTempShaderVaribleGLID = -1;
	iTempShaderVaribleGLID = m_pShader->GetAttribLocation((char*)"a_uv");
	if (iTempShaderVaribleGLID != -1)
	{
		glEnableVertexAttribArray(iTempShaderVaribleGLID);
		glVertexAttribPointer(iTempShaderVaribleGLID, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), VETEX_UV);
	}

	iTempShaderVaribleGLID = -1;
	iTempShaderVaribleGLID = m_pShader->GetUniformLocation((char*)"u_alpha");
	if (iTempShaderVaribleGLID != -1)
		glUniform1f(iTempShaderVaribleGLID, 1.0);

	iTempShaderVaribleGLID = -1;
	iTempShaderVaribleGLID = m_pShader->GetUniformLocation((char*)"u_wvpMatrix");
	if (iTempShaderVaribleGLID != -1)
		glUniformMatrix4fv(iTempShaderVaribleGLID, 1, GL_FALSE, wvpMatrix.m[0]);



	glDrawElements(GL_TRIANGLES, m_pModel->GetNumIndiceObject(), GL_UNSIGNED_INT, 0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindTexture(GL_TEXTURE_2D, 0);

}

void Sprite2D::Update(GLfloat deltatime)
{

}

void Sprite2D::MovingBullet(GLfloat xVal)
{
	if (m_bBulletAlive == true)
	{
		Vector2 vPos;
		vPos.x = m_position.x + xVal;
		vPos.y = m_position.y;
		if (vPos.x < Globals::screenWidth)
		{
			Set2DPosition(vPos);
		}
		else
		{
			m_bBulletAlive = false;
		}
	}
	
}


void Sprite2D::MovingMonster(GLfloat xVal)
{
	if (m_bMonsterAlive == true)
	{
		Vector2 vPos;
		vPos.x = m_position.x - xVal;
		vPos.y = m_position.y;
		if (vPos.x > 0)
		{
			Set2DPosition(vPos);
		}
		else
		{
			m_bMonsterAlive = false;
		}
	}
}

void Sprite2D::Set2DPosition(GLint x, GLint y)
{
	m_position = Vector3((float)x, (float)y, 0.0f);
	CalculateWorldMatrix();
}

void Sprite2D::Set2DPosition(Vector2 position)
{
	m_position = Vector3(position.x, position.y, 0.0f);
	CalculateWorldMatrix();
}

void Sprite2D::AddX(GLfloat x)
{
	Vector2 vPos;
	vPos.x = m_position.x + x;
	vPos.y = m_position.y;
	if (vPos.x < Globals::screenWidth)
	{
		Set2DPosition(vPos);
	}
}

void Sprite2D::SubX(GLfloat x)
{
	Vector2 vPos;
	vPos.x = m_position.x - x;
	vPos.y = m_position.y;
	if (vPos.x >= 0)
	{
		Set2DPosition(vPos);
	}
}

void Sprite2D::AddY(GLfloat y)
{
	Vector2 vPos;
	vPos.x = m_position.x;
	vPos.y = m_position.y + y;
	if (vPos.y < Globals::screenHeight)
	{
		Set2DPosition(vPos);
	}
}

void Sprite2D::SubY(GLfloat y)
{
	Vector2 vPos;
	vPos.x = m_position.x;
	vPos.y = m_position.y - y;
	if (vPos.y >= 0)
	{
		Set2DPosition(vPos);
	}
}

void Sprite2D::SetSize(GLint width, GLint height)
{
	m_iWidth = width;
	m_iHeight = height;
	m_scale = Vector3((GLfloat)m_iWidth, (GLfloat)m_iHeight, 1.0f);
	CalculateWorldMatrix();
}


bool Sprite2D::CheckCollision(std::shared_ptr<Sprite2D> pObj)
{
	int xp = m_position.x;
	int yp = m_position.y;
	int width = m_iWidth;
	int height = m_iHeight;
	SpriteRect rect1;
	rect1.x_ = xp + m_iWidth * 0.5;
	rect1.y_ = yp + m_iHeight * 0.5;
	rect1.w = width;
	rect1.h = height;

	int xpObj = pObj->GetPosition().x;
	int ypObj = pObj->GetPosition().y;

	int widthObj = pObj->GetWidth();
	int heightObj = pObj->GetHeight();

	SpriteRect rect2;
	rect2.x_ = xpObj + widthObj * 0.5;
	rect2.y_ = ypObj + heightObj * 0.5;
	rect1.w = widthObj;
	rect1.h = heightObj;

	bool ret = CheckCollision(rect1, rect2);

	return ret;
}


bool Sprite2D::CheckCollision(const SpriteRect& object1, const SpriteRect& object2)
{
	int left_a = object1.x_;
	int right_a = object1.x_ + object1.w;
	int top_a = object1.y_;
	int bottom_a = object1.y_ + object1.h;

	int left_b = object2.x_;
	int right_b = object2.x_ + object2.w;
	int top_b = object2.y_;
	int bottom_b = object2.y_ + object2.h;

	// Case 1: size object 1 < size object 2
	if (left_a > left_b && left_a < right_b)
	{
		if (top_a > top_b && top_a < bottom_b)
		{
			return true;
		}
	}

	if (left_a > left_b && left_a < right_b)
	{
		if (bottom_a > top_b && bottom_a < bottom_b)
		{
			return true;
		}
	}

	if (right_a > left_b && right_a < right_b)
	{
		if (top_a > top_b && top_a < bottom_b)
		{
			return true;
		}
	}

	if (right_a > left_b && right_a < right_b)
	{
		if (bottom_a > top_b && bottom_a < bottom_b)
		{
			return true;
		}
	}

	if (left_a > left_b && left_a < right_b)
	{
		if (top_a == top_b && bottom_a == bottom_b)
		{
			return true;
		}
	}

	// Case 2: size object 1 > size object 2
	if (left_b > left_a && left_b < right_a)
	{
		if (top_b > top_a && top_b < bottom_a)
		{
			return true;
		}
	}

	if (left_b > left_a && left_b < right_a)
	{
		if (bottom_b > top_a && bottom_b < bottom_a)
		{
			return true;
		}
	}

	if (right_b > left_a && right_b < right_a)
	{
		if (top_b > top_a && top_b < bottom_a)
		{
			return true;
		}
	}

	if (right_b > left_a && right_b < right_a)
	{
		if (bottom_b > top_a && bottom_b < bottom_a)
		{
			return true;
		}
	}

	if (left_b > left_a && left_b < right_a)
	{
		if (top_a == top_b && bottom_a == bottom_b)
		{
			return true;
		}
	}

	// Case 3: size object 1 = size object 2
	if (top_a == top_b && right_a == right_b && bottom_a == bottom_b)
	{
		return true;
	}

	return false;
}