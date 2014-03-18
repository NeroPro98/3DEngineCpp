#ifndef MESHRENDERER_H_INCLUDED
#define MESHRENDERER_H_INCLUDED

#include "gameComponent.h"
#include "mesh.h"
#include "basicShader.h"

class MeshRenderer : public GameComponent
{
public:
	MeshRenderer(Mesh& mesh, Material& material)
	{
		m_mesh = &mesh;
		m_material = &material;
	}

	virtual void Render(const Transform& transform, Shader* shader, RenderingEngine* renderingEngine) 
	{
		shader->Bind();
		shader->UpdateUniforms(transform, *m_material, renderingEngine);
		m_mesh->Draw();
	}
protected:
private:
	Mesh* m_mesh;
	Material* m_material;
};

#endif // MESHRENDERER_H_INCLUDED