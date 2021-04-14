﻿#pragma once
#include <vector>

#include "../../managers/resourceManager.h"
#include "../../openGL/indexBufferObj.h"
#include "../../openGL/shader.h"
#include "../../openGL/vertexArrayObj.h"
#include "../../openGL/vertexBufferLayout.h"
#include "../../openGL/vertexBufferObj.h"
#include "glm/vec2.hpp"

class GameObject {
protected:
	enum class Shape {
		None = -1,
		Brick
	};

	VertexArrayObj* m_Vao;
	VertexBufferObj* m_Vbo;
	VertexBufferLayout* m_Layout;
	IndexBufferObj* m_Ibo;
	
	glm::vec2 m_Position;
	
	std::vector<glm::vec2> m_Mesh;
	
	Shape m_Type;

	std::string m_ShaderName;
	std::string m_TextureName;

protected:
	virtual void createMesh(const glm::vec2& size);

public:
	GameObject(const glm::vec2& position, const std::string& texture, const std::string& shader);
	virtual ~GameObject();
	
	inline const void* getMeshData() const { return m_Mesh.data(); }
	inline const VertexArrayObj* getVAO() const { return m_Vao; }
	inline const VertexBufferObj* getVBO() const { return m_Vbo; }
	inline const IndexBufferObj* getIBO() const { return m_Ibo; }
	inline const VertexBufferLayout* getLayout() const { return m_Layout; }
	inline Shader* getShader() const { return ResourceManager::getShader(m_ShaderName); }
};