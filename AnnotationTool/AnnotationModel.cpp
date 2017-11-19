#include "AnnotationModel.h"



AnnotationModel::AnnotationModel()
{
}


AnnotationModel::~AnnotationModel()
{
}

void AnnotationModel::SetProjectDetails(const std::string& name, const std::string& desc, int mode)
{
    m_project_name = name;
    m_description = desc;
    m_mode = static_cast<Mode>(mode); // TODO: choose mode per object?
}

void AnnotationModel::SetCurrentObject(const std::string & name)
{
    // TODO:
}
