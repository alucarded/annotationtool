#include "NewProjectPresenter.h"
#include "Utilities.h"

NewProjectPresenter::NewProjectPresenter(INewProjectView^ view, AnnotationModel * model) : m_view(view), m_model(model)
{
    view->NewProjectClicked += gcnew SendProjectDetails(this, &NewProjectPresenter::OnNewProjectClicked);
}


NewProjectPresenter::~NewProjectPresenter()
{
}

void NewProjectPresenter::OnNewProjectClicked(System::String ^ name, System::String ^ description, int mode)
{
    std::string std_name, std_desc;
    MarshalString(name, std_name);
    MarshalString(description, std_desc);
    m_model->SetProjectDetails(std_name, std_desc, mode);
    m_view->UpdateProject(name, description, mode);
}
