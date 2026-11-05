#pragma once
class Player
{
private:
    float m_x = 0.0f;
    float m_y = 0.0f;

    float m_speed = 450.0f;

    float m_width = 64.0f;
    float m_height = 64.0f;

    int m_texture = -1;

public:
	void Init();
	void Update(float deltaTime);
	void Render();
	void Release();	
};

