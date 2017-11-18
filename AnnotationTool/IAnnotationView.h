#pragma once
public interface class IAnnotationView
{
public:
    virtual void UpdateProject(System::String^ name, System::String^ description, int mode) = 0;
};

