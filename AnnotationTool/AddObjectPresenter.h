#pragma once

#include "IAddObjectView.h"
#include "AnnotationModel.h"

#pragma managed

public ref class AddObjectPresenter
{
public:
    AddObjectPresenter(IAddObjectView^ view, AnnotationModel * model);
    ~AddObjectPresenter();

    void OnObjectAdded(System::String^ name, System::String ^ description, double aspect_ratio);
private:
    IAddObjectView^ m_view;
    AnnotationModel * m_model;
};

