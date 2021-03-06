#pragma once

#include "INewProjectView.h"
#include "AnnotationModel.h"

#pragma managed

public ref class NewProjectPresenter
{
public:
    NewProjectPresenter(INewProjectView^ view, AnnotationModel * model);
    ~NewProjectPresenter();

    void OnNewProjectCreated(System::String^ name, System::String^ description, int mode);
private:
    INewProjectView^ m_view;
    AnnotationModel * m_model;
};

