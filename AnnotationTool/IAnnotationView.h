#pragma once
public interface class IAnnotationView
{
public:
    virtual void UpdateProject(System::String^ name, System::String^ description, int mode) = 0;
    virtual void AddPaths(System::String^ root_path, System::Collections::ArrayList^ image_names, bool is_recursive) = 0;
};

