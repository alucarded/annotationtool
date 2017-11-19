#pragma once

public delegate void SetObject(System::String^ obj_name);
public delegate void SetImage(System::String^ image_path);

public interface class IAnnotationView
{
public:
    virtual void UpdateProject(System::String^ name, System::String^ description, int mode) = 0;
    virtual void AddPaths(System::String^ root_path, System::Collections::ArrayList^ image_names, bool is_recursive) = 0;
    virtual void DisplayImage(System::Drawing::Image^ image) = 0;
    event SetObject^ ObjectNodeSelected;
    event SetImage^ ImageNodeSelected;
};

