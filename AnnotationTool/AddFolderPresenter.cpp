#include "AddFolderPresenter.h"
#include "Utilities.h"

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
    GetImageFilesInFolder(root_path, image_paths, is_recursive);
    m_view->AddPaths(root_path, image_paths, is_recursive);
    m_model->AddFolder(MarshalString(root_path), is_recursive);
}

// TODO: This functionality should go to separate model class ?
void AddFolderPresenter::GetImageFilesInFolder(System::String ^ root_path, System::Collections::ArrayList^ image_names, bool recursive)
{
    using System::String;
    using namespace System::IO;
    array<String^>^ all_files = Directory::GetFiles(root_path);
    System::Collections::IEnumerator^ en = all_files->GetEnumerator();
    while (en->MoveNext()) {
        String^ file_path = safe_cast<String^>(en->Current);
        FileInfo ^ info = gcnew FileInfo(file_path);
        if (IsImageExtension(info->Extension)) {
            image_names->Add(info->Name);
        }
    }

    // TODO: implement recursive search
}

bool AddFolderPresenter::IsImageExtension(System::String ^ ext)
{
    // TODO:
    return true;
}