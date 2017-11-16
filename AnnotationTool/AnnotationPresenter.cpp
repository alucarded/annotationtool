#include "AnnotationPresenter.h"



AnnotationPresenter::AnnotationPresenter(IAnnotationView^ view, AnnotationModel * model)
{
}


AnnotationPresenter::~AnnotationPresenter()
{
    delete m_model;
}
