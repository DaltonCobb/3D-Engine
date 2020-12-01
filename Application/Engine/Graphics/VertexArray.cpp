#include "pch.h"
#include "VertexArray.h"

namespace nc
{

	bool VertexArray::Create(const std::string& name, void* null)
	{
		glGenVertexArrays(1, &m_vao);
		glBindVertexArray(m_vao);

		return true;
	}

	void VertexArray::Destroy()
	{
		glDeleteVertexArrays(1, &m_vao);
		glDeleteBuffers(m_vbos.size(), m_vbos.data());
	}

	void VertexArray::CreateBuffer(GLsizei size, GLsizei count, void* data)
	{
		count = m_count;

		GLuint vbo = 0;
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);

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

