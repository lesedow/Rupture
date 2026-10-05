#pragma once

#include "Precompiled.hh"
#include "Graphics/GL/GLTypes.hh"
#include "Graphics/GL/GLBuffer.hh"

namespace Rupture::Graphics::GL
{
	class VertexArrayObject
	{
	private:
		GLuint m_ID;
		GLint m_LastEnabledAttrib;
		std::unordered_map<std::string, GLBuffer> m_Buffers;
	public:
		VertexArrayObject();
		~VertexArrayObject();
	public:
		void EnableAtttributes(GLuint count) const;
		void EnableAtttributes(GLuint from, GLuint to) const;

		template <class T>
		void SetGenericVertexData(std::string_view name) const
		{
			GLBuffer buffer(GL_ARRAY_BUFFER);
			m_Buffers.emplace(name, std::move(buffer));

			auto attributes = T::GetAttributes();
			for (const auto& attr: attributes)
			{

				m_LastEnabledAttrib++;
			}
		}

		template <class T>
		void SetInstancedVertexData(GLuint divisor) const
		{

		}
		
		void Bind() const;
		void Unbind() const;
	};
}