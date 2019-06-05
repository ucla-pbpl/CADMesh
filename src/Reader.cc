
// CADMesh //
#include "Reader.hh"


namespace CADMesh
{

namespace File
{

Reader::Reader(G4String reader_name) : name_(reader_name)
{
}


Reader::~Reader()
{
}


G4String Reader::GetName()
{
    return name_;
}


std::shared_ptr<Mesh> Reader::GetMesh()
{
    if (meshes_.size() > 0)
    {
        return meshes_[0];
    }

    return nullptr;
}


std::shared_ptr<Mesh> Reader::GetMesh(size_t index)
{
    if (index < meshes_.size())
    {
        return meshes_[index];
    }

    return nullptr;
}


std::shared_ptr<Mesh> Reader::GetMesh(G4String name)
{
    for (unsigned i=0; i<meshes_.size(); ++i) {
        if (meshes_[i]->GetName() == name)
            return meshes_[i];
    }

    return nullptr;    
}


Meshes Reader::GetMeshes()
{
    return meshes_;
}


size_t Reader::AddMesh(std::shared_ptr<Mesh> mesh)
{
    meshes_.push_back(mesh);

    return meshes_.size();
}


void Reader::SetMeshes(Meshes meshes)
{
    meshes_ = meshes;
}


}

}

