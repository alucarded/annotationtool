#pragma once

#include "IAnnotationView.h"
#include "AnnotationModel.h"

#pragma managed

public ref class AnnotationPresenter
{
public:
    AnnotationPresenter(IAnnotationView^ view, AnnotationModel * model);
    ~AnnotationPresenter();

    void OnObjectNodeSelected(System::String^ obj_name, double % aspect_ratio);
    void OnImageNodeSelected(System::String^ image_path);
    void OnAnnotationDrawn(int x, int y, int w, int h);
    void OnProjectLoaded(System::String^ file_path);
private:
    IAnnotationView^ m_view;
    AnnotationModel * m_model;
};

