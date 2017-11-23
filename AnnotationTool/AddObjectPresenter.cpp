#include "AddObjectPresenter.h"

#include "Utilities.h"

AddObjectPresenter::AddObjectPresenter(IAddObjectView^ view, AnnotationModel * model) : m_view(view), m_model(model)
{
    view->ObjectAdded += gcnew SendObjectData(this, &AddObjectPresenter::OnObjectAdded);
}


AddObjectPresenter::~AddObjectPresenter()
{

}

void AddObjectPresenter::OnObjectAdded(System::String ^ name, System::String ^ description, double aspect_ratio)
{
    m_model->AddObject(MarshalString(name), MarshalString(description), aspect_ratio);
    m_view->AddObject(name, description);
}
