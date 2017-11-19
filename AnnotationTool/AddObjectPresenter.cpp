#include "AddObjectPresenter.h"

#include "Utilities.h"

AddObjectPresenter::AddObjectPresenter(IAddObjectView^ view, AnnotationModel * model) : m_view(view), m_model(model)
{
    view->ObjectAdded += gcnew SendObjectData(this, &AddObjectPresenter::OnObjectAdded);
}


AddObjectPresenter::~AddObjectPresenter()
{

}

void AddObjectPresenter::OnObjectAdded(System::String ^ name, double aspect_ratio)
{
    std::string std_name(MarshalString(name));
    m_model->AddObject(std_name, aspect_ratio);
    m_view->AddObject(name);
}
