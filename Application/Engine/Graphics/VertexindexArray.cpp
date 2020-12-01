#include "pch.h"
#include "VertexIndexArray.h"

namespace nc
{

bool VertexIndexArray::Create(const std::string& name, void* null)
{
	VertexArray::Create(name, null); 

	return true; 
}
void VertexIndexArray::Destroy()
{

		VertexArray::Destroy();
		glDeleteBuffers(1, &m_ibo);
		// delete the index buffer m_ibo with glDeleteBuffers
}

void VertexIndexArray::CreateIndexBuffer(GLenum indexType, GLsizei count, void* data)
{
			// set m_indexType to indexType
			// set m_indexCount to count
			m_indexType = indexType;
			m_indexCount = count;

			// generate vertex buffer m_ibo with glGenBuffers
			glGenBuffers(count, &m_ibo);
			// bind the m_ibo vertex buffer with glBindBuffer(GL_ELEMENT_ARRAY_BUFFER
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
			size_t indexSize = (m_indexType == GL_UNSIGNED_SHORT) ? sizeof(GLushort) : sizeof(GLuint);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * indexSize, data, GL_STATIC_DRAW);
}
void VertexIndexArray::Draw(GLenum primitiveType)
{
	// bind vertex array m_vao with glBindVertexArray
	glBindVertexArray(m_vao);
	// call glDrawElements with the parameters (primitiveType, m_indexCount, m_indexType, 0)
	glDrawElements(m_vao, m_indexCount, m_indexType, 0);
}

}
