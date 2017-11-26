#include "AddFolderPresenter.h"
#include "Utilities.h"

#include <queue>

AddFolderPresenter::AddFolderPresenter(IAddFolderView ^ view, AnnotationModel * model) : m_view(view), m_model(model)
{
    m_view->NewFolderAdded += gcnew SendPathData(this, &AddFolderPresenter::OnNewFolderAdded);
}

AddFolderPresenter::~AddFolderPresenter()
{
}

void AddFolderPresenter::OnNewFolderAdded(System::String ^ root_path, bool is_recursive)
{
    using namespace System::Collections;
    System::Collections::ArrayList^ image_paths = gcnew ArrayList();
    GetFilesInFolder(root_path, image_paths, SupportedImageExtensions(), is_recursive);
    m_view->AddPaths(root_path, image_paths, is_recursive);
    m_model->AddFolder(MarshalString(root_path), is_recursive);
}