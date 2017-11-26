#pragma once

#include "IAddFolderView.h"
#include "AnnotationModel.h"

#pragma managed

public ref class AddFolderPresenter
{
public:
    AddFolderPresenter(IAddFolderView^ view, AnnotationModel * model);
    ~AddFolderPresenter();

private:
    void OnNewFolderAdded(System::String^ root_path, bool is_recursive);

private:
    IAddFolderView^ m_view;
    AnnotationModel * m_model;
};