#pragma once

#include "IAnnotationView.h"
#include "AnnotationModel.h"

#pragma managed

public ref class AnnotationPresenter
{
public:
    AnnotationPresenter(IAnnotationView^ view, AnnotationModel * model);
    ~AnnotationPresenter();

private:
    IAnnotationView^ m_view;
    AnnotationModel * m_model;
};

