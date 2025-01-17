﻿#include "text.h"

void Text::createMesh() {
	m_Vao = new VertexArrayObj();
	m_Layout = new VertexBufferLayout();
	m_Vbo = new VertexBufferObj(nullptr, 8 * 2 * VertexBufferObjElement::getSizeOfType(GL_FLOAT), GL_DYNAMIC_DRAW);
	m_Layout->push<float>(2);
	m_Layout->push<float>(2);
	m_Vao->addVertexBufferObj(*m_Vbo, *m_Layout);

	unsigned int indices[6] = {
		0, 1, 2,
		2, 3, 0
	};
	m_Ibo = new IndexBufferObj(indices, 6);
}

Text::Text(const std::string& text, const glm::vec2& position, const glm::vec2& size, const std::string& shader)
	: GameObject(position, size, "", shader), m_Text(text)
{
	Position.x -= calculateTextWidth() / 2;
}

Text::~Text() {
}

float Text::calculateTextWidth() {

	const float scale = Size.x;
	float x = Position.x;

	for (auto c = m_Text.begin(); c != m_Text.end(); ++c) {
		std::cout << " " << std::endl;
		const ResourceManager::Character ch = ResourceManager::s_Characters[*c];
		x += (ch.Advance >> 6) * scale;
	}
	return x - Position.x;
}
