#include "Player.h"
#include <glc2d.h>

void Player::Init()
{
    // 화면 하단 중앙 배치
    m_x = (947.0f - m_width) / 2.0f;
    m_y = 1500.0f;

    // 기존에 성공했던 이미지 경로 사용
    m_texture = g2_TextureLoad(
        "..\\resource\\player.png", 0
    );
}

void Player::Update(float deltaTime)
{
    const KEYCODE* keys = g2_GetKeyboard();

    // 왼쪽 이동
    if (keys[VK_LEFT] == EINPUT_DOWN ||
        keys[VK_LEFT] == EINPUT_PRESS ||
        keys['A'] == EINPUT_DOWN ||
        keys['A'] == EINPUT_PRESS)
    {
        m_x -= m_speed * deltaTime;
    }

    // 오른쪽 이동
    if (keys[VK_RIGHT] == EINPUT_DOWN ||
        keys[VK_RIGHT] == EINPUT_PRESS ||
        keys['D'] == EINPUT_DOWN ||
        keys['D'] == EINPUT_PRESS)
    {
        m_x += m_speed * deltaTime;
    }

    // 화면 왼쪽 경계
    if (m_x < 0.0f)
        m_x = 0.0f;

    // 화면 오른쪽 경계
    if (m_x > 947.0f - m_width)
        m_x = 947.0f - m_width;
}

void Player::Render()
{
    if (m_texture == -1)
        return;

    int width = g2_TextureWidth(m_texture);
    int height = g2_TextureHeight(m_texture);

    if (width <= 0 || height <= 0)
        return;

    VEC2 position(m_x, m_y);

    VEC2 scale(
        m_width / width,
        m_height / height
    );

    g2_Draw2D(
        m_texture,
        nullptr,
        &position,
        &scale
    );
}

void Player::Release()
{
    if (m_texture != -1)
    {
        g2_TextureRelease(m_texture);
        m_texture = -1;
    }
}