#pragma once

#include "IAnnotationView.h"
#include "AnnotationModel.h"

#pragma managed

public ref class AnnotationPresenter
{
public:
    AnnotationPresenter(IAnnotationView^ view, AnnotationModel * model);
    ~AnnotationPresenter();

    void OnObjectNodeSelected(System::String^ obj_name);
    void OnImageNodeSelected(System::String^ image_path);
private:
    IAnnotationView^ m_view;
    AnnotationModel * m_model;
};

