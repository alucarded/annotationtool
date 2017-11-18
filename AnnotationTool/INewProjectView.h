#pragma once

public delegate void SendProjectDetails(System::String^ name, System::String^ description, int mode);

public interface class INewProjectView
{
public:
    virtual void UpdateProject(System::String^ name, System::String^ description, int mode) = 0;
    event SendProjectDetails^ NewProjectCreated;
};