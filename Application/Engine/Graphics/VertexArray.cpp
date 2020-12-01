#include "pch.h"
#include "VertexArray.h"

namespace nc
{

bool VertexArray::Create(const std::string& name, void* null)
{
	// generate vertex array m_vao with glGenVertexArrays
	glGenVertexArrays(1, &m_vao);
	// bind vertex array m_vao with glBindVertexArray
	glBindVertexArray(m_vao);

	return true;
}

void VertexArray::Destroy() 
{
	// delete vertex array m_vao with glDeleteVertexArrays
	glDeleteVertexArrays(1, &m_vao);
	// delete vertex buffers m_vbos with glDeleteBuffers(m_vbos.size(), m_vbos.data());
	glDeleteBuffers(m_vbos.size(), m_vbos.data());
}

void VertexArray::CreateBuffer(GLsizei size, GLsizei count, void* data)
{
	// set m_count to count;GLuint vbo = 0;
	count = m_count;
	GLuint vbo = 0;
	// generate vertex buffer vbo with glGenBuffers
	glGenBuffers(1, &vbo);
	// bind vertex buffer glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	// set buffer data glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	// push back vbo onto m_vbos vector
	m_vbos.push_back(m_vao);
}

void VertexArray::SetAttribute(int index, GLint size, GLsizei stride, size_t offset)
{
	glEnableVertexAttribArray(index);
	glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride, (void*)(offset));
}

void VertexArray::Draw(GLenum primitiveType)
{
	// bind vertex array m_vao with glBindVertexArray
	glBindVertexArray(m_vao);
	// call glDrawArrays with the parameters (primitive type, 0, m_count)
	glDrawArrays(m_vao, 0, m_count);
}
}